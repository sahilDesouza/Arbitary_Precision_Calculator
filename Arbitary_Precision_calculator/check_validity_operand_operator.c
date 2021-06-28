

#include "main.h"

int check_validity_operand(char * operand, slist_t ** head)
{
	int str_index = strlen(operand) - 1;
	
	int sign = check_sign_operand(operand);

	while (str_index >= 0)
	{
		if ((operand[str_index] >= '0') && (operand[str_index] <= '9'))
		{
			//printf("%d\n",operand[str_index] - '0');
			insert_at_first(head, (operand[str_index] - '0'));
		}
		else
		{
			return FAILURE;
		}
		
		str_index--;
	}
	
}

int check_sign_operand(char * operand)
{
	if ((*operand == '+') || (*operand == '-') || (*operand == '*') || (*operand == '/') || (*operand == 'x'))
    	{
		return *operand;
    	}
	else
	{
		return FAILURE;
	}
	
}

void check_larger_value(slist_t ** head_op1, slist_t ** head_op2, int * len1, int * len2, int * result_sign)
{
	int temp_len = 0;
	
	slist_t * temp = NULL, *temp_head1 = NULL, *temp_head2 = NULL;
	//printf("%d %d\n", *len1, *len2);
	if (*len1 == *len2)
	{
		//printf("hi\n");
		if (((*head_op1)->data) < ((*head_op2)->data))
		{
			temp = *head_op1;
			*head_op1 = *head_op2;
			*head_op2 = temp;

			
			temp_len = *len1;
			*len1 = *len2;
			*len2 = temp_len;
			

		}
		else if (((*head_op1)->data) == ((*head_op2)->data))
		{
			
			temp_head1 = *head_op1;
			temp_head2 = *head_op2;
			while (temp_head1)
			{
				//printf("hi\n");
				//printf("%d\n", temp_head1->data);
				if (temp_head1->data < temp_head2->data)
				{
					temp = *head_op1;
					*head_op1 = *head_op2;
					*head_op2 = temp;

					temp_len = *len1;
					*len1 = *len2;
					*len2 = temp_len;
					*result_sign = -1;
					break;
				}
				
				temp_head1 = temp_head1->link;
				temp_head2 = temp_head2->link;
			}
			
		}
		
	}
	else if (*len1 < *len2)
	{
		*result_sign = -1;
		temp = *head_op1;
		*head_op1 = *head_op2;
		*head_op2 = temp;

		temp_len = *len1;
		*len1 = *len2;
		*len2 = temp_len;
	}
	
	

}