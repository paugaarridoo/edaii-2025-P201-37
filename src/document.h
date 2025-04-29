#ifndef DOCUMENT_H
#define DOCUMENT_H

typedef struct{
    int id;
} Links;

typedef struct{
    int id;
    Links list_links;
    char title[50];
    char body[];
} Document;

typedef struct{
    char word[50];
} QueryItem;

typedef struct{
    QueryItem linked_list;
} Query;

Links* LinksInit();
Document *document_desserialize(char *path);

#endif