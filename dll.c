#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MS 5 
int c;
struct student{
    char usn[10], name[20], dept[20], phon[11];
    float marks1, marks2, marks3, total, average;
    struct student *next;
    struct student *prev;
};
typedef struct student node;


node *getnode(node *head)
{
    node *nn;
    nn=(node*)malloc(sizeof(node));
    printf("Enter the students details\n");
    printf("USN\n");
    scanf("%s",nn->usn);
    printf("Name\n");
    scanf("%s",nn->name);
    printf("Enter 3 subject marks\n");
    scanf("%f%f%f",&nn->marks1, &nn->marks2, &nn->marks3);
    
    nn->next=nn->prev=NULL;
    return head;


}

int countnodes(node *head)
{
    node *p;
    c=0;
    p=head;
    while(p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}

node *create(node *head)
{
    node *nn, *p;
    p=head;
    if(head==NULL)
    {
        nn=getnode(head);
        head=nn;
    }
    else
    {
        nn=getnode(head);
        
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=nn;
        nn->prev=p;
    }
    return head;
}

node *display(node *head)
{
    node *p;
    if(head=NULL)
    {
        printf("No date\n");
    }
    else 
    {
        p=head;
        printf("USN\tName\tDepartment\tPhone no\t\tMarks1\tMarks2\tMarks3\tTotal\tAverage\n");
        while(p!=NULL)
        {
        p->total=p->marks1+p->marks2+p->marks3;
        p->average=p->total/3;
        printf("%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", p->usn, p->name, p->dept, p->phon, p->marks1, p->marks2, p->marks3, p->total, p->average);
        p=p->next;
        }

    }
    printf("The number of nodes in the list is %d\n",countnodes(head));
    return head;
}

node *insertfront(node *head)
{
    node *nn, *p;
    if(countnodes(head)==MS)
    {
        printf("Insertion is not possible\n");
    }
    else
    {
        nn=getnode(head);
        if(head=NULL)
        {
            head=nn;
        }
        else
        {
            p=head;
            nn->next=head;
            head->prev=nn;
            head=nn;

        }
    }
    return head;
}

node *insertrear(node *head)
{
    node *nn, *p;
    if(countnodes(head)==MS)
    {
        printf("Insertion is not possible\n");
    }
    else
    {
        head=create(head);
    }
    return head;
}

node *deletefront(node *head)
{
    node *p;
    if(head==NULL)
    {
        printf("NO date\n");
    }
    else if(countnodes(head)==1)
    {
        p=head;
        head=NULL;
        free(p);
    }
    else
    {
        p=head;
        (head->next)->prev=NULL;
        head=head->next;
        p->next=NULL;
        free(p);
    }
    return head;
}

node *deleterear(node *head)
{
    node *p, *q;
    if(head==NULL)
    {
        printf("No data\n");
    }
    else if(countnodes(head)==1)
    {
        p=head;
        head=NULL;
        free(p);
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        q=p->prev;
        q->next=NULL;
        p->prev=NULL;
        free(p);
    }
    return head;
}

void main()
{
    int ch,i,n;
    node *head;
    head=NULL;
    do
    {
        printf("Enter the students details\n");
        printf("1.Create\n2.Insert front\n3.Insert rear\n4.Delete front\n5.Delete rear\n6.Display\n7.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of students\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                head=create(head);
            }
            break;

            case 2: head=insertfront(head);
            break;

            case 3: head=insertrear(head);
            break;

            case 4: head=deletefront(head);
            break;

            case 5: head=deleterear(head);
            break;

            case 6: head=display(head);
            break;

            case 7:exit(0);

            default: printf("Invalid choice");
        }
    } while (ch>=1&&ch<=7);

    
}


