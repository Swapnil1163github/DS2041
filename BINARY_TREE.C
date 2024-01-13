// BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>

int n, key;
struct node {
  int data;
  struct node *lchild;
  struct node *rchild;
};
typedef struct node NODE;
NODE *root = NULL, *p;

NODE *create(NODE *p, int data);
void preorder(NODE *p);
void inorder(NODE *p);
void postorder(NODE *p);
void search(NODE *p, int key);

int main() {
  int ch;
  do {
    printf("\n1:CREATING A NODE:\n2:INORDER TRAVERSE:\n3.PREORDER "
           "TRAVERSE:\n4.POSTORDER TRAVERSE:\n5:SEARCH A NODE:\n6:EXIT: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("ENTER THE ELEMENT: ");
      scanf("%d", &n);
      root = create(root, n);
      break;

    case 2:
      printf("\nINORDER TREVERSAL: ");
      inorder(root);
      break;

    case 3:
      printf("\nPREORDER TRAVERSAL:  ");
      preorder(root);
      break;

    case 4:
      printf("\nPOSTORDER TRAVERSAL: ");
      postorder(root);
      break;

    case 5:
      printf("\nENTER THE ELEMENT TO SEARCH: ");
      scanf("%d", &key);
      search(root, key);
      break;

    case 6: // EXIT
      break;

    default:
      printf("INVALID CHOICE!");
    }
  } while (ch != 6);
  return 0;
}

NODE *create(NODE *p, int data) {
  if (p == NULL) {
    p = (NODE *)malloc(sizeof(NODE));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
  } else if (data < p->data) {
    p->lchild = create(p->lchild, data);
  } else {
    p->rchild = create(p->rchild, data);
  }
  return p;
}

void preorder(NODE *p) {
  if (p != NULL) {
    printf("--> %d ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void inorder(NODE *p) {
  if (p != NULL) {
    inorder(p->lchild);
    printf("--> %d ", p->data);
    inorder(p->rchild);
  }
}

void postorder(NODE *p) {
  if (p != NULL) {
    postorder(p->lchild);
    postorder(p->rchild);
    printf("--> %d ", p->data);
  }
}

void search(NODE *p, int key) {
  if (p == NULL) {
    printf("\nSEARCH UNSUCCESSFUL\n");
  } else if (key == p->data) {
    printf("SEARCH SUCCESSFUL,%d IS FOUND\n", key);
  } else if (key < p->data) {
    search(p->lchild, key);
  } else if (key > p->data) {
    search(p->rchild, key);
  }
}
