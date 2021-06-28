

#include "main.h"

slist_t * apc_addition(slist_t ** head_op1, slist_t ** head_op2)
{
	
	reverse_list(head_op1);
	reverse_list(head_op2);
	slist_t * result = NULL;
	slist_t * temp_head_op1 = *head_op1, *temp_head_op2 = *head_op2;

	int sum = 0, carry = 0;

	while (temp_head_op1 != NULL || temp_head_op2 != NULL)
	{
		//printf("%d %d\n", temp_head_op1->data, temp_head_op2->data);
		sum = (temp_head_op1 ? temp_head_op1->data : 0) + (temp_head_op2 ? temp_head_op2->data : 0) + carry;
		//printf("%d\n", sum);
		insert_at_first(&result, sum % 10);

		carry = sum / 10;

		if (temp_head_op1)
			temp_head_op1 = temp_head_op1->link;
		if (temp_head_op2)
			temp_head_op2 = temp_head_op2->link;		
	}
	if (carry)
		insert_at_first(&result, carry);
	
	return result;
		

}