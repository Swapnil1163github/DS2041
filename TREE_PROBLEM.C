// CHECKING WHETHER GIVEN BINARY TREE IS PERFECT BINARY TREE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *lchild;
  struct node *rchild;
};
typedef struct node NODE;

NODE *new_Node(int data) {
  NODE *node = (NODE *)malloc(sizeof(NODE));
  node->data = data;
  node->lchild = NULL;
  node->rchild = NULL;
  return (node);
}

int depth(NODE *node) {
  int d = 0;
  while (node != NULL) {
    d++;
    node = node->lchild;
  }
  return d;
}

bool Perfect(NODE *root, int d, int level) {
  if (root == NULL) {
    return true;
  } else if (root->lchild == NULL && root->rchild == NULL) {
    return (d == level + 1);
  } else if (root->lchild == NULL || root->rchild == NULL) {
    return false;
  } else {
    return Perfect(root->lchild, d, level + 1) &&
           Perfect(root->rchild, d, level + 1);
  }
}

bool is_Perfect(NODE *root) {
  int d = depth(root);
  return Perfect(root, d, 0);
}

int main() {
  NODE *root = NULL;
  root = new_Node(1);
  root->lchild = new_Node(2);
  root->rchild = new_Node(3);
  root->lchild->lchild = new_Node(4);
  root->lchild->rchild = new_Node(5);
  root->rchild->lchild = new_Node(6);
  root->rchild->rchild = new_Node(8);

  if (is_Perfect(root))
    printf("GIVEN TREE IS A PERFECT BINARY TREE\n");
  else
    printf("GIVEN TREE IS NOT A PERFECT BINARY TREE\n");
}
