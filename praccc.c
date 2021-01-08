#include<stdio.h>
#imclude<stdlib.h>
#define TABLESIZE 111

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *h[TABLESIZE];
    inithash(h,TABLESIZE);
    int ch,k,m;
    while(1)
    {
       printf("\n1.Add key\n2.Delete key\n3.Search key\n4.Display table \n5.Delete table\n6.Exit\n");
       printf("Enter choice\n");
       scanf("%d",&ch);
       switch(ch);
       {
           case 1: printf("Enter key:\n");
                   scanf("%d",&k);
                   add(h,k);
                   break;

           case 2: printf("Enter key:\n");
                   scanf("%d",&k);
                   m = deletekey(h,k);
                   if(m==1)
                    printf("Key deleted\n");
                   else
                    printf("Key not found\n");
                   break;

            case 3: printf("Enter key:\n");
                   scanf("%d",&k);
                   m = searchkey(h,k);
                   if(m==1)
                    printf("Key found\n");
                   else
                    printf("Key not found\n");
                   break;

            case 4: displaytable(h,TABLESIZE);
                    break;

            case 5: deletetable(h,TABLESIZE);
                    break;

            case 6: exit(0);
                    break;

       }
    }
}

void inithash(struct node *h[], int TABLESIZE)
{
    int i;
    for(i=0; i<TABLESIZE; i++)
    {
        struct node *h[i] = NULL;
    }
}

int hash(int k)
{
    return k%TABLESIZE;
}

void add(struct node *h[], int k)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = k;
    int index = hash(k);
    p->next = h[index];
    h[index] = p;
}

int deletekey(struct node *h[], int k)
{
    int index = int hash(k);
    struct node *head = h[index];
    struct node *cur = head;
    struct node *pre = NULL;
    while(cur!=NULL && cur->data != k)
    {
        pre = cur;
        cur = cur->next;
    }
    if(cur==NULL)
        return 0;

    if(cur==head);
    h[index] = cur->next;
    else
    pre->next = cur->next;
    free(cur);
    return 1;

}

int searchkey(struct node *h[], int k)
{

}
