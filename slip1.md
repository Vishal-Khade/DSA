//Doubly.h
#include<stdio.h>
#include<malloc.h>

struct node
{
  int info;
  struct node *right;
  struct node *left;
};

struct node *create(struct node *head)
{
    struct node* temp=NULL, *p=NULL;
    int i,n;

    temp=head;

    printf("Enter the No of Values");
    scanf("%d",&n);

    printf("Enter Actual Values:");

    for(i=0;i<n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->info);
        p->left=p->right=NULL;

        temp->right=p;
        p->left=temp;
        temp=p;
    }
  return head;
}

void display(struct node *head)
{
    struct node *temp1=NULL,*temp2=NULL;
    temp1=head->right;

    do
    {
        printf("%d\t",temp1->info);
        temp2=temp1;
        temp1=temp1->right;
    } while (temp1!=NULL);
    printf("\n");
    do
    {
        printf("%d\t",temp2->info);
        temp2=temp2->left;
    } while (temp2!=head);
}
struct node *insert(struct node* head)
{
    struct node* temp=NULL,*temp1=NULL,*p=NULL;
    int pos, i;

    printf("\nEnter position to insert value:");
    scanf("%d",&pos);

    for(temp=head,i=1;i<pos&&temp!=NULL;i++)
    {
        temp=temp->right;
    }
    if(temp!=NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter actual value to insert");
        scanf("%d",&p->info);
        p->left=p->right=NULL;

        if(temp->right!=NULL)
        {
            temp1=temp->right;
            p->right=temp1;
            temp1->left=p;
            temp->right=p;
            p->left=temp;
        }
        else
        {
            temp->right=p;
            p->left=temp;
        }
    }
    else
    {
        printf("\nPosition not Found");
    }
    return(head);
    
}
int search(struct node *head,int key)
{
    struct node *temp=NULL;
    int pos;
    temp=head->right;
    pos=1;

    do
    {
        if (temp->info==key)
        {
            return pos;
        }
        else
        {
            pos++;
            temp=temp->right;
        }
    } while (temp!=NULL);
    return-1;
}
//doubly.c

#include<stdio.h>
#include<malloc.h>
#include"doublylist.h"

void main()
{
    struct node *create();
    struct node *insert();
    int search();
    void display();

    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->right=head->left=NULL;
    int c,key,q=0,ch;

    do
    {
        printf("\n1.Create\n2.Display\n3.insert\n4.Search\n5.Exit");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:head=create(head);
            break;
        case 2:display(head);
            break;
        case 3:head=insert(head);
            break;
        case 4:
               printf("Enter the value to search");
               scanf("%d",&key);
               key=search(head,key);
               printf("The value is at:%d",key);
            break;
        
        case 5:q=1;
             break;
        }
    } while (q==0);
    
}


//insertion.c
#include<stdio.h>
void insertion (int x[],int n);
void main()
{
    int i,n;
    printf("Enter The Size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Values of Array");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
 insertion(arr,n);
    for ( i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
 
}

void insertion(int x[],int n){

 int i,k,key;
    for ( k = 1; k <n; k++)
    {
        key=x[k];
        for ( i =k-1; x[i]>key && i>=0; i--)
        {
            x[i+1]=x[i];
        }
       x[i+1]=key; 
    }
}
 
