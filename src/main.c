#include "LAB 1 PUNTO 3.c"
#include "LAB 1 PUNTO 4.c"
#include "LAB 2 PUNTO 2.c"
#include "LAB 3 PUNTO 1.c"
#include "LAB 3 PUNTO 2.c"
#include "LAB 3 PUNTO 3.c"
#include "sample_lib.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

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
