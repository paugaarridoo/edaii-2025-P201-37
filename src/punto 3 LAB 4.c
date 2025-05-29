typedef struct { //QUICKSORT
    char* doc_id;       // NOMBRE PARA ORDENAR DEL ARCHIVO
    int relevancia;      // función PUNTUAJE QUE SE ATRIBUIRA AL DOC
} Document;
int compara_relevancia(const void* a, const void* b) {
    Document* docA = (Document*)a; //DOCUMENTO A
    Document* docB = (Document*)b; //DOCUMENTO B  LUEGO LOS COMPARARÁ PARA HACER EL QUICKSORT
    return docB->relevance - docA->relevance;  //ATRIBUIMOS EL ORDEN QUE USAREMOS, ESTE SERÁ DESCENDENTE
}
void sort_documents_por_revelancia(Document* docs, int count) {
    qsort(docs, count, sizeof(Document), compara_relevancia); //LLAMAMOS A LA FUNCIÓN PARA QUE SE EJECUTE
}
 
