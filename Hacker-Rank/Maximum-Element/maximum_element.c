/*  Problem Statement: https://www.hackerrank.com/challenges/maximum-element/problem
    Author: striker.
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

struct link_list {
    uint32_t data;
    struct link_list *next;
};
typedef struct link_list link_list_t;

link_list_t* make_node(uint32_t d);
void push_data(link_list_t*,link_list_t**);
void pop_data(link_list_t**);
link_list_t* peek_data(link_list_t**);
void delete_stack(link_list_t**);

int main(void) {
    uint32_t n;
    link_list_t *stack_1_head,*stack_2_head;
    scanf("%"SCNu32,&n);
    assert(n > 0 && n < 100001);
    stack_1_head = stack_2_head = NULL;
    while(n--) {
        uint32_t type;
        scanf("%"SCNu32,&type);
        assert(type > 0 && type < 4);
        switch(type) {
            uint32_t x;
            case 1:
                scanf("%"SCNu32,&x);
                assert(x > 0 && x < 1000000001);
                push_data(make_node(x),&stack_1_head);
                if((!stack_2_head) || ((peek_data(&stack_2_head))->data) <= x) {
                    push_data(make_node(x),&stack_2_head);
                }
                break;
            case 2:
                if(stack_1_head && stack_2_head) {
                    if((peek_data(&stack_1_head)->data) == (peek_data(&stack_2_head)->data)) {
                        pop_data(&stack_2_head);
                    }
                    pop_data(&stack_1_head);
                } else {
                    if(!stack_1_head) {
                        fprintf(stderr,"Fist-stack is empty!\n");
                    }
                    if(!stack_2_head) {
                        fprintf(stderr,"Second-stack is empty!\n");
                    }
                }
                break;
            case 3:
                if(stack_2_head) {
                    printf("%"PRIu32"\n",(peek_data(&stack_2_head)->data));
                } else {
                    fprintf(stderr,"Second-stack is empty!\n");
                }
                break;
            default:
                fprintf(stderr,"Entered query-type is not valid!\n");
                break;
        }
    }
    if(stack_1_head) {
        delete_stack(&stack_1_head);
    }
    if(stack_2_head) {
        delete_stack(&stack_2_head);
    }
    return 0;
}

link_list_t* make_node(uint32_t d) {
    link_list_t *node = malloc(sizeof(link_list_t));
    if(node) {
        (node->data) = d;
        (node->next) = NULL;
    } else {
        fprintf(stderr,"Node not created successfully!\n");
    }
    return node;
}

void push_data(link_list_t *node,link_list_t **head) {
    if(*head) {
        (node->next) = (*head);
        (*head) = node;
    } else {
        (*head) = node;
    }
}

void pop_data(link_list_t **head) {
    if(*head) {
        link_list_t *temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    } else {
        fprintf(stderr,"Stack is empty!\n");
    }
}

link_list_t* peek_data(link_list_t **head) {
    if(*head) {
        return (*head);
    } else {
        fprintf(stderr,"Stack is empty!\n");
        return NULL;
    }
}

void delete_stack(link_list_t **head) {
    if(*head) {
        link_list_t *temp = (*head);
        while(temp) {
            (*head) = (*head)->next;
            free(temp);
            temp = *head;
        }
    } else {
        fprintf(stderr,"Stack is already empty!\n");
    }
}