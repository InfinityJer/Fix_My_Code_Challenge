#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp, *prev;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    tmp = *head;
    prev = NULL;
    i = 0;

    while (tmp != NULL && i < index)
    {
        prev = tmp;
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)
        return (-1);

    if (prev == NULL)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        prev->next = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = prev;
    }

    free(tmp);
    return (1);
}
