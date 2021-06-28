

#include "main.h"

slist_t * apc_subtraction(slist_t ** head_op1, slist_t ** head_op2, int * len1, int * len2, int * result_sign)
{
	//int result_sign = 0;
	slist_t * temp = NULL;
	slist_t * result = NULL;
	int temp_len = 0;
	int borrow = 0, subtraction = 0;
	
	/*
	if (*len1 == *len2)
	{
		if (((*head_op1)->data) < ((*head_op2)->data))
		{
			result_sign = -1;
			temp = *head_op1;
			*head_op1 = *head_op2;
			*head_op2 = temp;

			//temp_len = *len1;
			//*len1 = *len2;
			//*len2 = temp_len;

		}
		
	}
	else if (*len1 < *len2)
	{
		result_sign = -1;
		temp = *head_op1;
		*head_op1 = *head_op2;
		*head_op2 = temp;

		temp_len = *len1;
		*len1 = *len2;
		*len2 = temp_len;
	}
	*/
	
	reverse_list(head_op1);
	//printf("%d\n", (*head_op1)->data);
	reverse_list(head_op2);
	slist_t * temp_head_op1 = *head_op1, *temp_head_op2 = *head_op2;
	//printf("%d\n", temp_head_op2->data);

	while ((temp_head_op1 != NULL) || (temp_head_op2 != NULL))
	{
		//printf("%d\n", temp_head_op1->data);
		if (temp_head_op2 != NULL)
		{
			if ((temp_head_op1->data) < (temp_head_op2->data))
			{
				//printf("%d\n", temp_head_op1->data);
				temp_head_op1->data += 10;
				if(temp_head_op1->link->data != 0)
				{
					(temp_head_op1->link->data)--;
				}
				else if(temp_head_op1->link->data == 0)
				{
					temp_head_op1->link->data += 9;
					temp_head_op1->link->link->data--;
				}
			}
		}
		
		
		//printf("%p\n", temp_head_op2);
		subtraction = (temp_head_op1 ? temp_head_op1->data : 0) - (temp_head_op2 ? temp_head_op2->data : 0);
		//printf("%d\n", subtraction);
		insert_at_first(&result, subtraction);

		if (temp_head_op1)
			temp_head_op1 = temp_head_op1->link;
		if (temp_head_op2)
			temp_head_op2 = temp_head_op2->link;	
	}
	
	if (result->data == 0)
		while (result)
		{
			if (result->data == 0)
				delete_first(&result);
				
			else
				break;
				
		}		
	
		
	
	if (*result_sign == -1)
	{
		insert_at_first(&result, '-');
	}
	
	
	return result;

}