/*  Problem Statement: https://www.codechef.com/problems/ONP
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_EXPRESSION_LENGTH 401

typedef struct node {
    char operator;
    struct node *next;
} node_t;

void transform_to_rpn(char *const); // Takes the valid expression as input and convert it into the RPN i.e Reverse Polish Notation form.
node_t* make_node(char);
void push_data(node_t**,char);
char pop_data(node_t**);
void delete_stack(node_t**);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 101);
    while(test--) {
        char expression[MAX_EXPRESSION_LENGTH];
        scanf("%s", expression);
        transform_to_rpn(expression);
    }
    return 0;
}

void transform_to_rpn(char *const expression) {
    uint16_t expression_length = 0;
    for(uint16_t i = 0; expression[i]!= '\0'; ++i) {
        if(expression[i] == '(' || expression[i] == ')') {
            ++expression_length;
        }
    }
    expression_length = strlen(expression) - expression_length;
    char rpn_form[expression_length];
    node_t *head = NULL; // Points to the first node of the link-list.
    for(uint16_t i = 0, j = 0; expression[i] != '\0'; ++i) {
        if(expression[i] == '(' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '^' || expression[i] == '/' ||expression[i] == '%') {
            push_data(&head,expression[i]);
        } else if(expression[i] == ')') {
            char optr;
            while((optr = pop_data(&head)) != '(') {
                rpn_form[j] = optr;
                ++j;
            }
        } else {
            rpn_form[j] = expression[i];
            ++j;
        }
    }
    rpn_form[expression_length] = '\0';
    delete_stack(&head);
    puts(rpn_form);
}

node_t* make_node(char data) {
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node) {
        new_node->operator = data;
        new_node->next = NULL;
    } else {
        fprintf(stderr,"Memory not allocated to *new_node pointer!\n");
    }
    return new_node;
}

void push_data(node_t **head,char data) {
    node_t *new_node = make_node(data);
    if(*head) {
        (new_node->next) = (*head);
        (*head) = new_node;
    } else {
        (*head) = new_node;
    }
}

char pop_data(node_t **head) {
    char optr = '\0';
    if(*head) {
        node_t *del_node = (*head);
        optr = (*head)->operator;
        (*head) = (*head)->next;
        free(del_node);
    } else {
        fprintf(stderr,"Stack is empty!\n");
    }
    return optr;
}

void delete_stack(node_t **head) {
    if(*head) {
        node_t *del_node = (*head);
        while(del_node) {
            (*head) = (*head)->next;
            free(del_node);
            del_node = (*head);
        }
    }
}