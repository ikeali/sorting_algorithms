#include <stdlib.h>
#include <string.h>
#include "deck.h"

static int compare_cards(const void *card1, const void *card2)
{
    return strcmp(((deck_node_t *)card1)->card->value, ((deck_node_t *)card2)->card->value);
}

void sort_deck(deck_node_t **deck)
{
    size_t count;
    deck_node_t *current;
    deck_node_t **array;
    size_t i;

    if (deck == NULL || *deck == NULL)
        return;

    count = 0;
    current = *deck;
    while (current)
    {
        count++;
        current = current->next;
    }

    array = malloc(count * sizeof(deck_node_t *));
    if (array == NULL)
        return;

    current = *deck;
    for (i = 0; i < count; i++)
    {
        array[i] = current;
        current = current->next;
    }

    qsort(array, count, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < count; i++)
    {
        array[i]->prev = (i > 0) ? array[i - 1] : NULL;
        array[i]->next = (i < count - 1) ? array[i + 1] : NULL;
    }

    *deck = array[0];

    free(array);
}

