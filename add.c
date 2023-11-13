#include "main.h"

_str_list *add_nodeint_end(_str_list **head, char *cmd)
{
	_str_list *new, *tmp;

	new = malloc(sizeof(_str_list));
	if (new == NULL || cmd == NULL)
		return (NULL);
	new->cmd_list = cmd;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	return (*head);
}

