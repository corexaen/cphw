#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TREE_APPROACH

#ifdef TREE_APPROACH
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;
typedef struct Tree {
    Node* root;
    int size;
} Tree;
void tree_init(Tree* tree) {
    tree->root = NULL;
    tree->size = 0;
}
bool tree_insert(Tree* tree, int value) {
    Node** current = &tree->root;
    while (*current != NULL) {
        if (value == (*current)->value) {
            return false; // Value already exists
        } else if (value < (*current)->value) {
            current = &(*current)->left;
        } else {
            current = &(*current)->right;
        }
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    tree->size++;
    new_node->left = NULL;
    new_node->right = NULL;
    *current = new_node;
    return true;
}
void tree_free(Node* node) {
    if (node != NULL) {
        tree_free(node->left);
        tree_free(node->right);
        free(node);
    }
}
int count_good_integers(int* weights, int n, int w) {
    int count = 0;
    Tree tree;
    tree_init(&tree);
    for(int i = 0; i < n; i++) {

        if(weights[i] <= w) {
            if(tree_insert(&tree, weights[i])) count++;
        }

        for(int j = i + 1; j < n; j++) {

            if(weights[i] + weights[j] <= w) {
                if(tree_insert(&tree, weights[i] + weights[j])) count++;
            }

            for(int k = j + 1; k < n; k++) {
                
                if(weights[i] + weights[j] + weights[k] <= w) {
                    if(tree_insert(&tree, weights[i] + weights[j] + weights[k])) count++;
                }
            }
        }
    }
    tree_free(tree.root);
    return count;
}
#else
int count_good_integers(int* weights, int n, int w) {
    int count = 0;

    bool* good_integer = (bool*)malloc(w * sizeof(bool));
    memset(good_integer, false, w * sizeof(bool));

    for(int i = 0; i < n; i++) {

        if(weights[i] <= w) {
            if(!good_integer[weights[i] - 1]) count++;
            good_integer[weights[i] - 1] = true;
        }

        for(int j = i + 1; j < n; j++) {

            if(weights[i] + weights[j] <= w) {
                if(!good_integer[weights[i] + weights[j] - 1]) count++;
                good_integer[weights[i] + weights[j] - 1] = true;
            }

            for(int k = j + 1; k < n; k++) {
                
                if(weights[i] + weights[j] + weights[k] <= w) {
                    if(!good_integer[weights[i] + weights[j] + weights[k] - 1]) count++;
                    good_integer[weights[i] + weights[j] + weights[k] - 1] = true;
                }
            }
        }
    }
    free(good_integer);
    return count;
}
#endif

int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    int* weights = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    int result = count_good_integers(weights, n, w);
    printf("%d\n", result);
    free(weights);
    return 0;
}