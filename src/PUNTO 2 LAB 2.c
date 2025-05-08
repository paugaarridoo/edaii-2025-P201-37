void initialize_query(Node** head, const char* query_string) {
    *head = insert_query(*head, query_string);
}