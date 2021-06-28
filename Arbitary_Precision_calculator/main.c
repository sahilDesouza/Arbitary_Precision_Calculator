
#include "main.h"


int main(int argc, char ** argv)
{

	if (argc != 4)
	{
		printf("Invalid CLA\n Enter 1234 + 5432\n");
		return -1;
	}
	
	//declaring variables for structure heads
	slist_t * head_op1 = NULL, *head_op2 = NULL, *result = NULL;

	//store result from CLA in temporary character buffers
	char operand1[SIZE], operand2[SIZE];

	//argument 2 from CLA contains the operator
	char operator = *argv[2];

	//length of both operand taken
	int len1_op = strlen(argv[1]);
	int len2_op = strlen(argv[3]);
	int result_sign = 0;

	strcpy(operand1, argv[1]);
	strcpy(operand2, argv[3]);

	//check validity for operand1
	if(check_validity_operand(operand1, &head_op1) == FAILURE)
	{
		printf("Operand1 Error\n");
		printf("Enter a valid operand. Ex->12345\n");
		return -1;
	}
	//check validity for operand2
	if(check_validity_operand(operand2, &head_op2) == FAILURE)
	{
		printf("Operand2 Error\n");
		printf("Enter a valid operand. Ex->12345\n");
		return -1;
	}

	//based on operator operation on operands will be performed
	switch (operator)
	{
	case '+':
		result = apc_addition(&head_op1, &head_op2);
		break;
	case '-':
		check_larger_value(&head_op1, &head_op2, &len1_op, &len2_op, &result_sign);
		result = apc_subtraction(&head_op1, &head_op2, &len1_op, &len2_op, &result_sign);
		break;
	case 'x':
		result = apc_multiplication(&head_op1, &head_op2, strlen(argv[1]), strlen(argv[3]));
		break;
	case '/':
		check_larger_value(&head_op1, &head_op2, &len1_op, &len2_op, &result_sign);
		result = apc_division(&head_op1, &head_op2, &len1_op, &len2_op, &result_sign);
		break;
	
	default:
		printf("INVALID operator entered\nValid Operators are '+', '-', 'x', '/'\n");
		break;
	}
	//prints result
	print_slist(result);
    
}