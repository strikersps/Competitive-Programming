/*  Problem Statement: https://www.codechef.com/problems/FLOW018
    Author: Suraj Sharma
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

typedef struct link_list {
    uint16_t num;
    struct link_list*next,*prev;
} link_list_t;

link_list_t* make_node(uint16_t);
bool insert_node(link_list_t**,link_list_t**,link_list_t*);
void traverse_list(link_list_t*);
bool delete_list(link_list_t**);
void compute_factorial(uint16_t);

int main(void) {
    uint16_t test,n;
    scanf("%hu",&test);
    assert(test>0);
    while(test--) {
        scanf("%hu",&n);
        assert(n>=0);
        compute_factorial(n);
    }
    return 0;
}

void compute_factorial(uint16_t n) {
    link_list_t *head,*tail,*temp;
    uint64_t i_prod,carry;
    head = tail = temp = NULL;
    if(insert_node(&head,&tail,make_node(true))) {
        carry = false;
        for(uint16_t i=2;i<=n;++i) {
            for(temp = tail;(temp);(temp = (temp->prev))) {
                i_prod = ((temp->num)*i)+carry;
                carry = false;
                if(i_prod > 9) {
                    carry = (i_prod/10);
                    (temp->num) = (i_prod%10);
                }
                else if(i_prod >= 0) (temp->num) = i_prod;
            }
            while(carry) {
                if(insert_node(&head,&head,(make_node(carry%10)))) carry /=10;
                else fprintf(stderr,"Node not created!\n");
            }
        }
    }
    else fprintf(stderr,"Node Not Inserted!\n");
    traverse_list(head);
    if(delete_list(&head));
    else fprintf(stderr,"List not deleted!\n");
}

link_list_t* make_node(uint16_t data) {
    link_list_t *node = NULL;
    node = malloc(sizeof(link_list_t));
    if(node) {
        (node->num) = data;
        (node->next) = NULL;
        (node->prev) = NULL;
    }
    else fprintf(stderr,"Memory not allocated!\n");
    return node;
}

bool insert_node(link_list_t **head,link_list_t **tail,link_list_t *node) {
    if(!(*head)) (*head) = (*tail) = node;
    else {
        ((*tail)->prev) = node;
        (node->next) = (*tail);
        (*head) = node;
    }
    return true;
}

void traverse_list(link_list_t *start) {
    for(;start;(printf("%d",(start->num)),(start = (start->next))));
    printf("\n");
}

bool delete_list(link_list_t **head) {
    for(link_list_t *temp = (*head);(*head);((*head) = (*head)->next),free(temp),(temp = (*head)));
    return true;
}
