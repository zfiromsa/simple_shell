#include "main.h"

void add_nodeint_end(_str_list **head, char *cmd)
{
	_str_list *new, *tmp;

	new = malloc(sizeof(_str_list));
	if (new == NULL)
		exit(0);
	new->cmd_list = cmd;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		exit(0);
	}
	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	exit(0);
}

