
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
typedef int data_t;

typedef struct node
{
    data_t data;
    struct node * link;

}slist_t;

enum status
{
    FAILURE,
    SUCCESS,
    MINUS_FLAG,
    LIST_EMPTY

};

int check_validity_operand(char * operand, slist_t ** head);
int check_sign_operand(char * operator);
void check_larger_value(slist_t ** head_op1, slist_t ** head_op2, int * len1, int * len2, int * result_sign);

int insert_at_first(slist_t ** head, data_t data);
int insert_at_last(slist_t ** head, data_t data);
int reverse_list(slist_t ** head);
int print_slist(slist_t * head);
int delete_list(slist_t ** head);
int list_size(slist_t ** head);
int delete_first(slist_t ** head);

void my_strrev(char * operand);


slist_t * apc_addition(slist_t **, slist_t **);
slist_t * apc_subtraction(slist_t **, slist_t **, int *, int *, int *);
slist_t * apc_multiplication(slist_t **, slist_t **, int , int);
slist_t * apc_division(slist_t **, slist_t **, int * , int *, int *);

#endif