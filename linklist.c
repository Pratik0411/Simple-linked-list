#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

void display(struct node *);
struct node * insertfirst(int, struct node *);
struct node * insertlast(int, struct node *);
struct node * insertordered(int, struct node *);
struct node * delete(struct node *);
void count(struct node *);
struct node * copyf(struct node *);

void main()
{
	int choice=0;
	int data;
	
	struct node *first, *second;
	first=(struct node *)malloc(sizeof(struct node));
	second=(struct node *)malloc(sizeof(struct node));
	
	first->info=30;
	first->link=second;
	
	second->info=40;
	second->link=NULL;
	
	printf("Predefine Elements\n");
	display(first);
	while(choice<8)
	{
		printf("\nEnter the choice for the operation\n1. insertion at First\n2. insertion at End\n3. insertion at Ordered\n4. Delete\n5. Count\n6. Copy\n7. Display elements\n8. Quite\n");
		scanf("%d", &choice);
		
		switch(choice)
		{	
			case 1:
			printf("\nEnter the element you want to insert at first\n");
			scanf("%d", &data);
			first=insertfirst(data,first);
			display(first);
			break;
			
			case 2:
			printf("\nEnter the element you want to insert at last\n");
			scanf("%d", &data);
			first=insertlast(data, first);
			display(first);
			break;
			
			case 3:			
			printf("\nEnter the element you want to insert at ordered\n");
			scanf("%d", &data);
			first=insertordered(data, first);
			display(first);
			break;
			
			case 4:
			printf("\nFirst node deleted\n");
			//scanf("%d", &data);
			first=delete(first);
			break;
			
			case 5:
			count(first);
			break;
			
			case 6:
			copyf(first);
			break;
			
			case 7:
			display(first);
			break;
		}
	}
}

void display(struct node *first)
{
	struct node *save;
	save=first;
	while(save!=NULL)
	{
		printf("%d, ",save->info);
		save=save->link;
	}
}

struct node* insertfirst(int x, struct node *first)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("Overflow");
		return first;
	}
	else
	{
		new->info=x;
		if(first==NULL)
		{
			new->link=NULL;
			return new;
		}
		else
		{
			new->link=first;
			return new;
		}
	}
}

struct node* insertlast(int x, struct node *first)
{
	struct node *new, *temp;
	new=(struct node *)malloc(sizeof(struct node));
	new->info=x;
	new->link=NULL;
	if(first==NULL)
	{
		printf("Underflow");
		return new;
	}
	else
	{
		temp=first;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=new;
	}
	return first;
}

struct node* insertordered(int x, struct node *first)
{
	struct node *new, *temp;
	new=(struct node *)malloc(sizeof(struct node));
	new->info=x;
	if(first==NULL)
	{
		new->link = NULL;
		return new;
	}
	else if(new->info <= first->info)
	{
		new->link = first;
		return new;
	}
	else
	{
		temp=first;
		while(temp->link!=0 && new->info >= (temp->link)->info)
		{
			temp = temp->link;
		}
		new->link = temp->link;
		temp->link = new;
	}
	return first;
}

struct node* delete(struct node *first)
{
	struct node *temp;
	temp = first;
	first = first->link;
	free(temp);
	return first;
}

void count(struct node *first)
{
	int cnt=0;
	struct node *save;
	save=first;
	while(save!=NULL)
	{
		cnt++;
		save=save->link;
	}
	printf("Count: %d",cnt);
}

struct node* copyf(struct node *first)
{
	struct node * cpynode=(struct node *)malloc(sizeof(struct node));
	if(first==NULL)
	{
		printf("Under-flow");
		return first;
	}
	else
	{
		cpynode->info = first->info;
		cpynode->link = copyf(first->link);
		return cpynode;
	}
}
