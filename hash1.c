#include<stdio.h>

void midsquare()
{
    int c[10],flag[10],n,l,sum,key,i,x;
    for ( i = 0; i < 10; i++)
    {
        c[i]=0;
        flag[i]=0;
    }
    printf("\nHow many values you want to enter in hash table");
    scanf("%d",&n);
    printf("\nEnter actual values");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&key);
        sum=key*key;
        l=key;
        key=sum;
        if (sum>10)
        {
            if (sum>100)
            {
                do
                {
                    x=key%10;
                    sum=x;
                    key=key/10;
                } while (key>10);
                
            }
            else
            {
                do
                {
                    x=key%10;
                    sum=x;
                    key=key/10;
                } while (key>0);
                
            }
            printf("\n The hash address of %d is %d\n",l,sum);
            if (c[sum]==0)
            {
                c[sum]=l;
            }
            else
            {
                flag[sum]=-1;
            }
         
        }
    }
    printf("\n The contents of hash table are\n");
    for ( i = 0; i < 10; i++)
    {
        if (flag[i]==-1)
        {
            printf("\n%d=%d",i,c[i]);
            printf("\tcollision");
        }
        else
        {
            printf("\n%d=%d",i,c[i]); 
        }
    }
}
void division()
{
    int a[10],flag[10],i,n,l,sum,key;
    for ( i = 0; i < 10; i++)
    {
        a[i]=0;
        flag[i]=0;
    }
    printf("\n How many values you wwant to enter in hash table");
    scanf("%d",&n);
    printf("\nenter actual key values");
    for ( i = 0; i < n; i++)
    {
        scanf("\n%d",&key);
        sum=key%11;
        if (a[sum]==0)
        {
            a[sum]=key;
        }
        else
        {
            flag[sum]=-1;
        }
        printf("\n The address of %d is %d\n",key,sum);
        
    }
    printf("\n The contents of hash table are:");
    for ( i = 0; i < 10; i++)
    {
        if(flag[i]==-1)
        {
            printf("\n%d=%d",i,a[i]);
            printf("\t Collision");
        }
        else
        {
            printf("\n%d=%d",i,a[i]);
        }   
    }
}

void folding()
{
    int b[10],flag[10],l,i,x,sum,key,n;
    for ( i = 0; i < 10; i++)
    {
        b[i]=0;
        flag[i]=0;
    }
    printf("\n How many values you want to enter in hash table");
    scanf("%d",&n);
    printf("\nEnter the key values");
    for ( i = 0; i < n; i++)
    {
        scanf("\n%d\n",&key);
        l=key;
        sum=0;
        do
        {
            x=key%10;
            sum=sum+x;
            key=key/10;
        } while (key>0);
        if (sum<10)
        {
            sum=sum;
        }
        else
        {
            do
            {
                x=key%10;
                sum=x;
                key=key/10;
            } while (key>10);
        }
        printf("\nThe hash address of %d is %d\n",l,sum);
        if (b[sum]==0)
        {
            b[sum]=l;
        }
        else
        {
            flag[sum]=-1;
        }  
    }
    printf("\nThe contents of hash tables are\n");
    for ( i = 0; i < n; i++)
    {
        if (flag[i]==-1)
        {
            printf("\n%d=%d",i,b[i]);
            printf("\tcollision");
        }
        else
        {
            printf("\n%d=%d",i,b[i]);
        }
    }
}

void main()
{
    void division();
    void folding();
    void midsquare();

    int ch,q=0;

    do
    {
        printf("\n1]Division\n2]Mid-square\n3]Folding\n4]Exit");
        printf("\nEnter your choice");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:division();
            break;
        
        case 2:midsquare();
            break;
        
        case 3:folding();
            break;
        
        case 4:q=1;
            break;
        }
    } while (q==0);
    
}