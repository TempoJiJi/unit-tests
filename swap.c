#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List_node {
    int value;
    struct List_node *next;
} List_node;

typedef struct List_node List;

List *swap(List *head, List *node_1, List *node_2)
{

    /* Here must be Or not and */
    if (!head ||
        (node_1 == NULL) || (node_2 == NULL) ||
        (node_1 == node_2))
        return head;
    
    int num_pre_node_1_and_node_2 = 0;
    bool is_circular = false;

    List *_head = head;
    List *pre_node_1,*pre_node_2,*tmp_node;

    if (head == node_1) {
        pre_node_1 = NULL;
        num_pre_node_1_and_node_2 = num_pre_node_1_and_node_2 + 1;
    }

    if (head == node_2) {
        pre_node_2 = NULL;
        num_pre_node_1_and_node_2 = num_pre_node_1_and_node_2 + 1;
    }
    
    /* set the break condition for saving time */
    while ( (head && head->next) || num_pre_node_1_and_node_2 < 2) {
        if (head->next == node_1) {
            pre_node_1 = head;
            num_pre_node_1_and_node_2 = num_pre_node_1_and_node_2 + 1;
	    if(node_1->next == _head)
		is_circular = true;
        }

        else if (head->next == node_2) {
            pre_node_2 = head;
            num_pre_node_1_and_node_2 = num_pre_node_1_and_node_2 + 1;
	    if(node_2->next == _head)
		is_circular = true;
        }
        head = head->next;
    }

    head = _head;

    if (num_pre_node_1_and_node_2 != 2)
        return head;
    
    if (pre_node_1 == NULL) {
        pre_node_2->next = node_1;
        tmp_node = node_1->next;
    
	/* circular linked list */
	if(is_circular)
	    node_1->next = node_2;
	else
	    node_1->next = node_2->next;
	
        node_2->next = tmp_node;
        return node_2;
    }

    if (pre_node_2 == NULL) {
        pre_node_1->next = node_2;
        tmp_node = node_2->next;
	if(is_circular)
	    node_2->next = node_1;
	else
	    node_2->next = node_1->next;
        node_1->next = tmp_node;
        return node_1;
    }

    pre_node_2->next = node_1;
    pre_node_1->next = node_2;
    tmp_node = node_2->next;
    node_2->next = node_1->next;
    node_1->next = tmp_node;
    return head;
}

