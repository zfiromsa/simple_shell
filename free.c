#include "main.h"

void free_list(_str_list **head)
{
    _str_list *tmp;

    while (*head != NULL)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
    
}

