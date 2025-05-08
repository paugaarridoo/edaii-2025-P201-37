#include "document.c"
#include "document.h"
#include "sample_lib.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct Hashmap{
  Node* hashmap;
  int size;
  int count;
} *Hashmap;

typedef struct{
  char *word;
  int *document_ids;
  int *document_cuenta;
} ReverseindexHashmap;

void createaleak() {
  char *foo = malloc(20 * sizeof(char));
  printf("Allocated leaking string: %s", foo);
}

int main() {
  printf("*****************\nWelcome to EDA 2!\n*****************\n");

  // how to import and call a function
  printf("Factorial of 4 is %d\n", fact(4));
  // createaleak();

  return 0;
}
