#include "lists.h"

/**
 * find_listint_loop - find loop in linked list
 * @head: pointer to head pointer of linked list
 * Return: address of node where loop starts
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *snail, *cheetah;

	snail = cheetah = head;

	while (snail != NULL && cheetah != NULL)
	{
		snail = snail->next;
		cheetah = cheetah->next->next;

		if (snail == cheetah)
		{
			snail = head;
			while (snail != cheetah)
			{
				snail = snail->next;
				cheetah = cheetah->next;
			}
			return (snail);
		}
	}

	return (NULL);
}

