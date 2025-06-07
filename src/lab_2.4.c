#include "lab_2.4.h" //Per a la definició de la cua de consultes i les seves funcions pertinents
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//Inicialitza la cua amb e¡valors inicials i buida
void ConsultaQueue_init(ConsultaQueue* q) {
    q->inici = 0; //Index primer element (inici) cua
    q->fi = 0; //Index on afegim seguente element 
    q->mida = 0; //Mida actual dels elements que formen la cua 
    for (int i = 0; i < 3; ++i) {
        q->consultes[i].consulta = NULL;
    }
}
//Afegeix una nova consulta a la cua circular
void ConsultaQueue_push(ConsultaQueue* q, const char* consulta) {
    //Allibera la consulta que s'hauria d'insertar si la cua es plena
    if (q->mida == 3 && q->consultes[q->fi].consulta) {
        free(q->consultes[q->fi].consulta);
    }
    q->consultes[q->fi].consulta = strdup(consulta);
    q->fi = (q->fi + 1) % 3;
    if (q->mida < 3) { //Si encara no es plena pot incremetnar la mida
        q->mida++;
    } else { //Si ja es plena, hem de moure l'inici per sobreescriure l0element mé antic 
        q->inici = (q->inici + 1) % 3;
    }
}
//Mostrar totes les consultes de la cua
void ConsultaQueue_mostrar(const ConsultaQueue* q) {
    printf("******* Últimes 3 consultes ********\n");
    for (int i = 0; i < q->mida; ++i) {
        int idx = (q->inici + i) % 3;
        printf(" * %s *\n", q->consultes[idx].consulta);
    }
    printf("************************************\n");
}
//Allibera tota la memoria usada per la cua de consultes 
void ConsultaQueue_lliberar(ConsultaQueue* q) {
    for (int i = 0; i < 3; ++i) {
        free(q->consultes[i].consulta);
        q->consultes[i].consulta = NULL;
    }
    q->inici = q->fi = q->mida = 0;
}