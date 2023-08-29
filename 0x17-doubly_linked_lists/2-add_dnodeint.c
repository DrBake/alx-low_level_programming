#include "lists.h"
/**
 * add_dnodeint - add node of the  list
 * @head: head of the linked list
 * @n: data in new node
 * Return: new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{

	dlistint_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (new);
	new->next = (*head);
	new->n = n;
	new->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
