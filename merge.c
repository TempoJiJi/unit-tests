#include "swap.c"

int get_value(List *list, int n)
{
    int i;
    for(i=0; i<n; i++)
        list = list->next;
    return list->value;
}

void Merge(List **head, int low, int high)
{
    int combined[10000],i,j;
    int k = 0, mid = (low+high)/2;
    List *list;
    list = *head;
    for(i=low, j=mid+1; i<=mid || j<=high;) {
        if(i>mid)
            combined[k++] = get_value(list,j++);
        else if(j>high)
            combined[k++] = get_value(list,i++);
        else if(get_value(list,i) >= get_value(list,j))
            combined[k++] = get_value(list,j++);
        else
            combined[k++] = get_value(list,i++);
    }
    k=0;
    for(i=0; i<low; i++)
        list = (list->next);
    for(i=low; i<=high; i++) {
        list->value = combined[k++];
        list = list->next;
    }
}

void Sort(List **list, int low, int high)
{
    if(high > low) {
        Sort(list, low, (low+high)/2);
        Sort(list, ((low+high)/2)+1, high);
        Merge(list, low, high);
    }
}

void merge_sort(List **head)
{
    if (head == NULL || (*head==NULL))
        return;
    int n = 0;
    List *_head;
    _head = *head;
    while (_head && _head->next) {
        n++;
        /*  Circular linked list  */
        if (_head->next == *head)
            break;
        _head = _head->next;
    }
    Sort(head, 0, n);
}

