#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 

typedef struct Node {
    int key;
    struct Node* next;
} Node;
Node* hashTable[TABLE_SIZE];
int hashFunction(int key) {
    return key % TABLE_SIZE;
}
void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->key = key;
    newNode->next = hashTable[index]; 
    hashTable[index] = newNode;

    printf("Key %d inserted successfully.\n", key);
}

void search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp) {
        if (temp->key == key) {
            printf("Key %d found in the hash table.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found.\n", key);
}

void delete(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp) {
        if (temp->key == key) {
            if (prev) {
                prev->next = temp->next;  
            } else {
                hashTable[index] = temp->next;  
            }
            free(temp);
            printf("Key %d deleted successfully.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found for deletion.\n", key);
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int choice, key;

    while (1) {
        printf("\n--- Hash Table Operations ---\n");
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