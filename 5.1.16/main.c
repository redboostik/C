#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char word[20];
    int f;
    struct list *next;
    struct list *prev;
}list;

typedef struct steck {
    struct list *listPos;
    struct steck *prev;
}steck;

struct list* addList (struct list *last) {
    struct list* newElement = malloc(sizeof(struct list) );
    scanf("%s", newElement->word);
    newElement->prev = last;
    newElement->next = NULL;
    newElement->f = 0;
    return newElement;
}

struct steck* addSteck(struct list* itList, struct steck *right) {
    struct steck* newElement = malloc(sizeof(struct steck));
    newElement->listPos = itList;
    newElement->prev = right;
    return newElement;
}

void show(struct steck *watch) {
    struct steck *itSteck = watch;

    while (itSteck != NULL) {
        printf("%s\n", itSteck->listPos->word);
        itSteck = itSteck->prev;
    }
}

int main() {
    int n, i;
    struct list *leftList = NULL, *rightList = NULL;
    printf("n: ");
    scanf("%d", &n);

    for( i = 0; i < n; i++) {
        struct list *temp;
        temp = addList(rightList);
        if(rightList != NULL)rightList->next = temp;
        rightList = temp;
        if(leftList == NULL) leftList = rightList;
    }
    struct list *iterator = leftList;
    struct steck *lastSteck = NULL;

    while (iterator != NULL) {
        lastSteck = addSteck(iterator, lastSteck);
        iterator = iterator->next;
    }
    printf("\nREVERSE\n");
    show(lastSteck);

    struct steck *sortSteck;

    for(i = 0; i < n; i++) {
        iterator = leftList;
        struct list * maxString = NULL;
        while(iterator != NULL) {
            if (iterator->f == 0 && (maxString == NULL || strcmp(maxString->word, iterator->word) < 0)) {
                    maxString = iterator;
                }
            iterator = iterator->next;
        }
        sortSteck = addSteck(maxString, sortSteck);
        maxString->f = 1;
    }

    printf("\nSORT\n");
    show(sortSteck);
    return 0;
}