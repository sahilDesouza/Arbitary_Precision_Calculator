

#include "main.h"

int insert_at_last(slist_t ** head, data_t data)
{
	slist_t * new = malloc(sizeof(struct node) * 1);
	if(new == NULL)
	{
		return FAILURE;
	}

	new->data = data;
	new->link = NULL;
	if (*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}

	slist_t * temp = *head;
	while (temp->link)
	{
		temp = temp->link;
	}
	temp->link = new;

}
int reverse_list(slist_t ** head)
{
	if (*head == NULL)
	{
		return SUCCESS;
	}

	slist_t * temp = *head, *aptr = NULL, *prevPtr = NULL;

	while (temp)
	{	
		aptr = temp->link;
		
		temp->link = prevPtr;
	
		prevPtr = temp;
		temp = aptr;
		
	}
	*head = prevPtr;
	return SUCCESS;
	
	

}

int insert_at_first(slist_t ** head, data_t data)
{
	slist_t * new = malloc(sizeof(slist_t) * 1);
	if (new == NULL)
	{
		return FAILURE;
	}
	new->link = NULL;
	new->data = data;

	if (*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}

	new->link = *head;
	*head = new;
	return SUCCESS;
	
}
int print_slist(slist_t * head)
{
	if (head == NULL)
	{
		printf("0\n");
		return FAILURE;
	}
	
	slist_t * temp = head;
	
	while (temp)
	{
		if (temp->data == '-')
		{
			printf("%c", temp->data);
			temp = temp->link;
			continue;
		}
		
		
		printf("%d", temp->data);
		temp = temp->link;
	}
	printf("\n");
	
}

int list_size(slist_t ** head)
{
	if (*head == NULL)
	{
		return FAILURE;
	}

	data_t count = 0;
	slist_t * temp = *head;

	while (temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
	
	
}

int delete_list(slist_t ** head)
{
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}
	
	slist_t * temp = *head, *prevNode = NULL;
	//loop to traverse through all the nodes 
	//each time clearing the nodes as we go further till the end
	while (temp->link)
	{
		prevNode = temp;
		temp = temp->link;
		free(prevNode);
		
	}
	//current points to last node
	//freeing that node and head is set to NULL
	free(temp);
	*head = NULL;
	return SUCCESS;

}

int delete_first(slist_t ** head)
{
	if (*head == NULL)
	{
		return FAILURE;
	}

	slist_t * temp = *head;

	*head = temp->link;
	free(temp);
	return SUCCESS;

}