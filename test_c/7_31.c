#include <stdio.h>
#include <stdlib.h>

void* malloc(size_t n);
void* calloc(size_t n, size_t size);
void free(void* ptr);

void f() {
  int n, *ip;

  n = 5;
  ip = (int*)malloc(n * sizeof(int));
  ip = (int*)calloc(n, sizeof(int));
  free(ip);
}

void ff() {
  struct node {
    struct node* next;
  } n;
  struct node *p, *q;
  struct node* head = &n;

  /* WRONG */
  for (p = head; p != NULL; p = p->next) free(p);

  /* OK! */
  for (p = head; p != NULL; p = q) {
    q = p->next;
    free(p);
  }
}
