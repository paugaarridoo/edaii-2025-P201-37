#include <stdlib.h>

typedef struct{
    int id;
} Links;

typedef struct{
    int id;
    Links list_links;
    char title[50];
    char body[];
} Document;

Links* LinksInit(){
    Links* listed_links = (Links*) malloc(sizeof(Links));
    return listed_links;
}