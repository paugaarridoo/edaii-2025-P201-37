typedef struct {
  int id;
} Links;

typedef struct {
  int id;
  Links list_links;
  char title[50];
  char body[];
} Document;