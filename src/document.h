#ifndef DOCUMENT_H
#define DOCUMENT_H

typedef struct {
  int id;
} Links;

typedef struct {
  int id;
  Links list_links;
  char title[50];
  char body[];
} Document;

typedef struct Query {
  char* query_string;
} Query;

typedef struct Node {
  Query* query;
  struct Node* next;
} Node;
Node* insert_query(Node* head, char* query_string) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->query = (Query*)malloc(sizeof(Query));
  new_node->query->query_string = query_string;
  new_node->next = head;
  return new_node;
};

Links *LinksInit();
Document *document_desserialize(char *path);

#endif