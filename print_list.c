#include "main.h"

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: it is a pointer to the listint_t list.
 * Return: count
 */
size_t print_listint(_str_list *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		printf("%s\n", h->cmd_list);
		h = h->next;
		count++;
	}
	return (count);
}
