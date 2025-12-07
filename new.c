#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 5
int c;
struct student
{
char name[25],usn[12],branch[10],phon[11];
int sem;
struct student *next;
};
typedef struct student node;
int countnodes(node *head)
{
node *p;
p=head;
c=0;
while(p!=NULL)
{
p=p->next;
c++;
}
return c;
}
node *getnode()
{
node *nn;
nn=(node*)malloc(sizeof(node));
printf("Enter student details \n");
printf("Name:");
scanf("%s",nn->name);
printf("USN:");
scanf("%s",nn->usn);
printf("Branch:");
scanf("%s",nn->branch);
printf("Phone NO:");
scanf("%s",nn->phon);
printf("SEM:");
scanf("%d",&nn->sem);
nn->next=NULL;
return nn;
}
node *display(node *head)
{
node *p;
if(head==NULL)
printf("No student data\n");
else
{
    p=head;
printf("Name\tUSN\t\tBranch\tPhoneNO\tSEM\n");
while(p!=NULL)
{
printf("%s\t%s\t%s\t%s\t%d\n",p->name,p->usn,p->branch,p->phon,p->sem);
p=p->next;
}
printf("The number of nodes in list is %d",countnodes(head));
}
return head;
}
node *create(node *head)
{
node *nn;
if(countnodes(head)==MAX)
{
printf("List is overflow");
}
else if(head==NULL)
{
nn=getnode(head);
head=nn;
}
else
{
    nn=getnode(head);
nn->next=head;
head=nn;
}
return head;
}
node *insertfront(node *head)
{
    node *nn;
if(countnodes(head)==MAX)
{
printf("List is overflow");
}
else
{

nn=create(head);
head=nn;

}
return head;
}
node *insertrear(node *head)
{
node *nn,*p;
if(countnodes(head)==MAX)
printf("List is overflow\n");
else
{
p=head;
if(head==NULL)
{
nn=getnode(head);
head=nn;
}
else
{
while(p->next!=NULL)
{
p=p->next;
}
nn=getnode(head);
p->next=nn;
}
}
return head;
}
node *deletefront(node *head)
{
node *p;
if(head==NULL)
{
printf("No data\n");
}
else
{
p=head;
head=head->next;
}
free(p);
return head;
}
node *deleterear(node *head)
{
node *p,*q;
if(head==NULL)
{
printf("No data\n");
}
else if(countnodes(head)==1)
{
p=head;
head=NULL;
free(p);
printf("Node is Deleted");
}
else
{
p=head;
while((p->next)->next!=NULL)
{
p=p->next;
}
q=p->next;
p->next=NULL;
free(q);
}
return head;
}
node *insert(node *head)
{
int ch;
do
{
printf("\tMenu\n1.Insert front\n2.Insert rear\n3.exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:head=insertfront(head);
break;
case 2:head=insertrear(head);
break;
default:break;
}
head=display(head);
}while(ch>=1&&ch<=2);
return head;
}
node *delete(node *head)
{
int ch;
do
{
printf("\tMenu\n1.Delete front\n2.Delete rear\n3.exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:head=deletefront(head);
break;
case 2:head=deleterear(head);
break;
default:break;
}
head=display(head);
}while(ch>=1&&ch<=2);
return head;
}
node *stack(node *head)
{
int ch;
do
{
printf("\tMenu\n1.Insert front\n2.Delete front\n3.exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:head=insertfront(head);
break;
case 2:head=deletefront(head);
break;
default:break;
}
head=display(head);
}while(ch>=1&&ch<=2);
return head;
}
void main()
{
int ch,i,n;
node *head;
head=NULL;
do
{
printf("\n\t*...Student Data...*");
printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Stack\n6.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter number of students\n");
scanf("%d",&n);
for(i=0;i<n;i++)
head=create(head);
break;
case 2:head=display(head);
break;
case 3:head=insert(head);
break;
case 4:head=delete(head);
break;
case 5:head=stack(head);
break;
case 6:exit(0);
default:printf("Invalid choice\n");
}
}while(ch>=1&&ch<=6);
}


