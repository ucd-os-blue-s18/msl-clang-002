#include <stddef.h>
#include <string.h>

#include "rb_node.h"

/* Static sentinel structure for root and leaves cuts the required storage in half. */
static struct rb_node RB_NULL; // members statically initialized to zero, so color is RB_BLACK

struct rb_node *
rb_find(const struct rb_node *tree, const struct rb_node *node){

    int result = strcmp(node->word, tree->word);

    if(result == 0){
        return tree;
    }

    if(result < 0){
        if(tree->left == NULL){
            return NULL;
        }
        else {
            rb_find(tree->left, node);
        }
    }

    else if(result > 0){
        if(tree->right == NULL){
            return NULL;
        }
        else {
            rb_find(tree->right, node);
        }
    }
}
