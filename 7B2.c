#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -999 
#define DELETED -1  

int hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i * i) % TABLE_SIZE] != EMPTY &&
           hashTable[(index + i * i) % TABLE_SIZE] != DELETED) {
        i++;
        if (i == TABLE_SIZE) { 
            printf("Hash table is full! Cannot insert %d.\n", key);
            return;
        }
    }
    
    index = (index + i * i) % TABLE_SIZE;
    hashTable[index] = key;
    printf("Key %d inserted at index %d.\n", key, index);
}

void search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i * i) % TABLE_SIZE] != EMPTY) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == key) {
            printf("Key %d found at index %d.\n", key, newIndex);
            return;
        }
        i++;
        if (i == TABLE_SIZE) break; 
    }
    printf("Key %d not found.\n", key);
}

void delete(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i * i) % TABLE_SIZE] != EMPTY) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == key) {
            hashTable[newIndex] = DELETED; 
            printf("Key %d deleted from index %d.\n", key, newIndex);
            return;
        }
        i++;
        if (i == TABLE_SIZE) break; 
    }
    printf("Key %d not found for deletion.\n", key);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else if (hashTable[i] == DELETED)
            printf("Index %d: DELETED\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;
    initializeTable();

    while (1) {
        printf("\n--- Hash Table Operations (Quadratic Probing) ---\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
 }
}
}