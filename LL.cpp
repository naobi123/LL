// Single LL program by Roshni RK
// Added a delete_from() module from LL_modified branch
//Adding another comment from LL_modified branch
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node * create_list(struct node*);
struct node * display(struct node*);
struct node * insertBeg(struct node *);
struct node * insertEnd(struct node *);
struct node * insertAfter(struct node *);
struct node * insertBefore(struct node *);
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_FromPos(struct node *);
int main()
{
	
	int choice;
	while(1)
	{
		printf("\nMAIN MENU\n");
		printf("1.Create list\n");
		printf("2.Display\n");
		printf("3.Insert at beg\n");
		printf("4.Insert at end\n");
		printf("5.Insert after a given node\n");
		printf("6.Insert before a given node\n ");
		printf("7. Delete first node\n");
		printf("8. Delete last node\n");
		printf("9. Delete a node after a given value\n");
		printf("10. Delete from a position\n");

		printf("11. Exit\n");
		printf("Enter choice\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
				case 1: start=create_list(start);
				break;
				
				case 2: display(start);
				break;
				
				case 3: start=insertBeg(start);
				break;
				
				case 4: start = insertEnd(start);
				break;
				
				case 5: start = insertAfter(start);
				break;
				
				case 6: start = insertBefore(start);
				break;
				
				case 7: start=delete_beg(start);
				break;
				
				case 8: start=delete_end(start);
				break;
				
				case 9 : start=delete_after(start);
				break;
					case 10 : start=delete_FromPos(start);
				break;
				case 11: exit(1);
		}
		
	}
	
}

struct node *create_list (struct node *start)
{
	struct node *newnode, *ptr; 
	int num;
	
        newnode=(struct node *)malloc(sizeof(struct node));
        /*if(newnode==NULL)
        {
                printf("nOut of Memory Space:n");
                exit(0);
        }*/
        printf("nEnter the data value for the node:t");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(start==NULL)
        {
                start=newnode;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=newnode;
        }
	return (start);
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\t %d\n",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

struct node *insertBeg(struct node *start)
{
	struct node *newnode;
	int num;
	printf("\n Enter tha data\n");
	scanf("%d", &num);
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=num;
	newnode->next=start;
	start=newnode;
	
}

struct node *insertEnd(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("\n Enter tha data\n");
	scanf("%d", &num);
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=num;
	newnode->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=newnode;
	return start;
	
}

struct node *insertAfter(struct node *start)
{
	struct node *newnode,*ptr,*preptr;
	int num,value;
	printf("\n Enter tha data\n");
	scanf("%d", &num);
	printf("\nEnter the value after which the data is to be inserted");
	scanf("%d",&value );
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=num;
	newnode->next=NULL;
	ptr=start;
//	preptr=ptr;
	while(preptr->data!=value)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	return start;
}


struct node *insertBefore(struct node *start)
{
	struct node *newnode,*ptr,*preptr;
	int num,value;
	printf("\n Enter the data\n");
	scanf("%d", &num);
	printf("\nEnter the value after which the data is to be inserted");
	scanf("%d",&value );
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=num;
	newnode->next=NULL;
	ptr=start;
	preptr=ptr;
	while(ptr->data!=value)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	return start;
}

struct node *delete_beg(struct node *)
{
	struct node * ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	printf("\t\n Node is deleted\n");
	return (start);
}

struct node *delete_end(struct node *)
{
	struct node * ptr, *preptr;
	ptr=start;
	while (ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
		
	}
	preptr->next=NULL;
	free(ptr);
	printf("\t\n Last node is deleted\n");
	return (start);
}

struct node *delete_after(struct node *)
{
	struct node * ptr, *preptr;
	int val;
	printf("\n Enter the value after which u want to delete\n");
	scanf("%d", &val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	printf("\t\n  node is deleted\n");
	return (start);
	
}


struct node *delete_FromPos(struct node *)
{
	struct node * ptr, *preptr;
	int pos, i=1;
	ptr=start;
	printf("\n Enter position\n");
	scanf("%d", &pos);
	while (i<pos-1)
	{
		ptr=ptr->next;
		i++;
		
	}
	preptr=ptr->next;
	ptr->next=preptr->next;
	free(preptr);
		printf("\t\n  node is deleted\n");
		return (start);
}






