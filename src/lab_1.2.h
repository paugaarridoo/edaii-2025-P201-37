#pragma once
#include <stdio.h>
#include "lab_1.1.h"

typedef struct {
    int id;
    char* titol;
    char* contingut;
    LinkList links;
} Document;

int Document_init_from_file(Document* doc, const char* filepath);
void Document_lliberar(Document* doc);

