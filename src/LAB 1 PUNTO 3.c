#include <stdio.h>

typedef struct {
  int id;
  Links *prev;
  Links *next;
} Links;

typedef struct {
  int id;
  Links list_links;
  char title[50];
  char *body;
} Document;