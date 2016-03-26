#include "swap.c"

void bubble_sort(List **head)
{
    if (head == NULL || (*head == NULL))
        return;

    int num_list = 0;
    int i;
    int sub_i;
    List **pre_sub_head = head;
    List *sub_head;

    sub_head = *head;

    /* Counting num list */
    while (sub_head && sub_head->next) {
        num_list = num_list + 1;
	/* Circular list  */
	if(sub_head->next == *head)
	    break;
        sub_head = sub_head->next;
    }
    
    for (i = num_list; i > 0; i--) {
        sub_head = *head;
        pre_sub_head = head;
        for (sub_i = 0; sub_i < i; sub_i++) {
            if (sub_head->value > sub_head->next->value) {
                sub_head = swap(sub_head,sub_head,sub_head->next);
                *pre_sub_head = sub_head;
            }
            pre_sub_head = &((*pre_sub_head)->next);
            sub_head = sub_head->next;
        }
    }
    return;
}
