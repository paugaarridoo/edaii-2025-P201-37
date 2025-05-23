typedef struct Query{
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

void initialize_query(Node** head, const char* query_string) {
    *head = insert_query(*head, query_string);
}