#include "deck.h"

/**
 * card_value - Calculates the value of a card
 *
 * @card: Pointer to the card to get the value of
 *
 * Return: The integer value of the card
 */
static int card_value(const card_t *card)
{
	if (!strcmp(card->value, "Ace"))
		return (1);
	if (!strcmp(card->value, "2"))
		return (2);
	if (!strcmp(card->value, "3"))
		return (3);
	if (!strcmp(card->value, "4"))
		return (4);
	if (!strcmp(card->value, "5"))
		return (5);
	if (!strcmp(card->value, "6"))
		return (6);
	if (!strcmp(card->value, "7"))
		return (7);
	if (!strcmp(card->value, "8"))
		return (8);
	if (!strcmp(card->value, "9"))
		return (9);
	if (!strcmp(card->value, "10"))
		return (10);
	if (!strcmp(card->value, "Jack"))
		return (11);
	if (!strcmp(card->value, "Queen"))
		return (12);
	if (!strcmp(card->value, "King"))
		return (13);
	return (0);
}

/**
 * card_cmp - Compares two cards
 *
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: An integer less than, equal to,
 * or greater than zero if the first card
 *         is found to be less than, equal to,
 * or greater than the second card.
 */
static int card_cmp(const void *a, const void *b)
{
	const card_t *ca = *((const card_t **)a);
	const card_t *cb = *((const card_t **)b);

	if (card_value(ca) != card_value(cb))
		return (card_value(ca) - card_value(cb));
	return (ca->kind - cb->kind);
}

/**
 * sort_deck - Sorts a deck of cards
 *
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	card_t *cards[52];
	deck_node_t *node;

	if (!deck || !*deck || !(*deck)->next)
		return;

	node = *deck;
	for (i = 0; i < 52; i++)
	{
		cards[i] = (card_t *)node->card;
		node = node->next;
	}

	qsort(cards, 52, sizeof(card_t *), card_cmp);

	node = *deck;
	for (i = 0; i < 52; i++)
	{
		node->card = cards[i];
		node = node->next;
	}
}
