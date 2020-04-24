#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
   char letter;
   int index, depth;
   struct tree *left, *right;
};

struct tree* create( char key, int index, int depth) {
    struct tree* element = malloc(sizeof(struct tree));
    printf("create: %c %d\n", key, depth);
    element->letter = key;
    element->index = index;
    element->depth = depth;
    element->left = NULL;
    element->right = NULL;
    return element;

}

void add(struct tree* root, char key, int index, int depth) {
    printf("%c %d\n", root->letter, root->depth);
    if(key > root->letter) {
        if(root->right != NULL)add(root->right, key, index, depth + 1);else
            root->right = create(key, index, depth + 1);
    }else {
        if(root->left != NULL)add(root->left, key, index, depth + 1); else
            root->left = create(key, index, depth + 1);
    }
    if(root->left != NULL && root->left->depth > root->depth) root->depth = root->left->depth;
    if(root->right != NULL && root->right->depth > root->depth) root->depth = root->right->depth;
}

struct tree* findLetter(struct tree* root, char key)
{
    printf("letter: %c\n", root->letter);
    if(root == NULL) return root;
    if(key == root->letter) return root;
    if(key > root->letter)return findLetter(root->right, key); else
        return findLetter(root->left, key);
}

int main() {
    int n;
    scanf("%d", &n);
    char word[100];
    int i;
    struct tree* root = NULL;
    scanf(" %s", word);
    printf(" %s\n", word);
    printf(" %c\n", *(word + 2));
    for(i = 0; i < n; i++) {
        if(root == NULL)root = create(word[i], i + 1, 1); else
            add(root, word[i], i + 1, 1);
    }
    printf("right: %c\n", root->right->letter);

    while(1) {
        printf("1: find position\n2: out max depth\n3: exit\n");
        int choose = 3;
        scanf("%d", &choose);
        printf("choose: %d\n", choose);
        switch (choose) {

           case 1: {
                char letter;
                printf("input letter: ");
                scanf(" %c", &letter);
                printf("index %d\n", findLetter(root, letter)->index);
                break;
            }

            case 2: {
                printf("max depth = %d\n", root->depth);
                break;
            }

            case 3: {
                return 0;
            }

            default: {
                printf("Try again\n");
                break;

            }
        }
    }
}