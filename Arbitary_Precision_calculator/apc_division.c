

#include "main.h"

slist_t * apc_division(slist_t ** head_op1, slist_t ** head_op2, int * len1, int * len2, int * result_sign)
{
	slist_t * temp = NULL;
	slist_t * result_prev = NULL, *result_temp = NULL;
	slist_t * head_quotient = NULL;

	int quotient = 0, len1_temp = 0, len2_temp = 0, temp_len = 0;
	/*
	if (*len1 == *len2)
	{
		if (((*head_op1)->data) < ((*head_op2)->data))
		{
			temp = *head_op1;
			*head_op1 = *head_op2;
			*head_op2 = temp;

			len1_temp = *len2;
			len2_temp = *len1;
			

		}
		
	}
	else if (*len1 < *len2)
	{
		temp = *head_op1;
		*head_op1 = *head_op2;
		*head_op2 = temp;
		
		len1_temp = *len2;
		len2_temp = *len1;
	}
	else
	{
		len1_temp = *len1;
		len2_temp = *len2;
	}
	*/

	//reverse_list(head_op1);
	//reverse_list(head_op2);
	//printf("%d\n", len1_temp);
	//printf("%d\n", len2_temp);
	
	//print_slist(result_temp);
	
	//printf("%d", len1_temp);
	slist_t *temp_head_op2_check = *head_op2, *temp_head_op1_check = *head_op1;
	int count = 0;
	if(*len1 == *len2)
	{
		while(temp_head_op1_check && temp_head_op2_check)
		{
			//If node data equal, proceed to next node
	    		if(temp_head_op1_check->data == temp_head_op2_check->data) 
	    		{
				temp_head_op1_check = temp_head_op1_check->link;
				temp_head_op2_check = temp_head_op2_check->link;
				count++;
			}
	    	}
	}
	if (count == *len1)
	{
		return NULL;
	}
	

	slist_t *temp_head_op2 = *head_op2;
	result_temp = *head_op1;
	len1_temp = *len1;
	while (len1_temp >= *len2)
	{
		
		result_prev = result_temp;
		check_larger_value(&result_temp, &temp_head_op2, &len1_temp, len2, result_sign);
		result_temp = apc_subtraction(&result_temp, &temp_head_op2, &len1_temp, len2, result_sign);
		
		//print_slist(result_temp);
		reverse_list(&temp_head_op2);
		//print_slist(temp_head_op2);
		len1_temp = list_size(&result_temp);
		quotient++;
		
		//printf("%d\n", len1_temp);
		
		delete_list(&result_prev);
		
	}
	
	printf("Quotient: %d\n", quotient);
	printf("Remainder: ");
	return result_temp;
	
	

	
	
}