

#include "main.h"

slist_t * apc_multiplication(slist_t ** head_op1, slist_t ** head_op2, int len1, int len2)
{
	slist_t * temp = NULL;
	slist_t * result = NULL, * result_temp = NULL;
	int i = 0, temp_len = 0;
	if (len1 == len2)
	{
		if (((*head_op1)->data) < ((*head_op2)->data))
		{
			temp = *head_op1;
			*head_op1 = *head_op2;
			*head_op2 = temp;
			
		}
		
	}
	else if (len1 < len2)
	{
		temp = *head_op1;
		*head_op1 = *head_op2;
		*head_op2 = temp;
		temp_len = len1;

	}
	
	reverse_list(head_op1);
	reverse_list(head_op2);
	slist_t * temp_head_op1 = *head_op1, *temp_head_op2 = *head_op2;

	int product = 0, carry = 0, append_zeros = 0;

	while (temp_head_op1 != NULL)
	{
		temp_head_op2 = *head_op2;
		while (temp_head_op2 != NULL)
		{
			product = ((temp_head_op1 ? temp_head_op1->data : 0) * (temp_head_op2 ? temp_head_op2->data : 0)) + carry;
			//printf("%d\n", sum);
			insert_at_first(&result_temp, product % 10);

			carry = product / 10;
			temp_head_op2 = temp_head_op2->link;
		}
		if (carry)
			insert_at_first(&result_temp, carry);
		for (int i = 0; i < append_zeros; i++)
		{
			insert_at_last(&result_temp, 0);
		}
		append_zeros++;
		//printf("%d %d\n", temp_head_op1->data, temp_head_op2->data);
		
		//if (temp_head_op1)
			//temp_head_op1 = temp_head_op1->link;
		//if (temp_head_op2)
			//temp_head_op2 = temp_head_op2->link;
		
		result = apc_addition(&result_temp, &result);

		delete_list(&result_temp);

		temp_head_op1 = temp_head_op1->link;		
	}
	//if (carry)
		//insert_at_first(&result, carry);
	
	return result;
		

}