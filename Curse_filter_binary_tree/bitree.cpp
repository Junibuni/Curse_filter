#include <stdlib.h>
#include <string.h>

#include "bitree.h"

void bitree_init(BiTree* tree, void(*destroy)(void* data))
{
	tree->size = 0;
	tree->destroy = destroy;
	tree->root = NULL;

	return;
}
void bitree_destroy(BiTree* tree);
int bitree_ins_left(BiTree* tree, BiTreeNode* node, const void* data);
int bitree_ins_right(BiTree* tree, BiTreeNode* node, const void* data);
void bitree_rem_left(BiTree* tree, BiTreeNode* node);
void bitree_rem_right(BiTree* tree, BiTreeNode* node);
int bitree_merge(BiTree* merge, BiTree* left, BiTree* right, const void* data);
