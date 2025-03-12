// Problema este rezolvata pentru valori in intervalul [1, 254];

#include <stdio.h>
#include <stdlib.h>

unsigned char Cautare_Liniara(unsigned char* Pointer_la_Elemente, unsigned char Numar_Elemente, unsigned char Element_Cautat){
    unsigned char index;

    for(index=0;index<Numar_Elemente;index++)
        if(*(Pointer_la_Elemente+index)==Element_Cautat){
            return index;
        }

    return 255;
}

int main(){

unsigned char *Pointer_la_Elemente;

unsigned char Numar_Elemente;
do{
    printf("Introdu numarul de elemente (in intervalul [1, 254]): ");
    scanf("%hhu", &Numar_Elemente);
}while(Numar_Elemente<1 || Numar_Elemente>254);

Pointer_la_Elemente=(unsigned char*)malloc(Numar_Elemente*sizeof(unsigned char));

if(Pointer_la_Elemente==NULL){
    printf("Eroare la alocarea de memorie.");
    free(Pointer_la_Elemente);
    return 0;
}

unsigned char index;

for(index=0;index<Numar_Elemente;index++){
    do{
        printf("Introdu elementul cu numarul %hhu (in intervalul [1, 254]): ", index+1);
        scanf("%hhu", Pointer_la_Elemente+index);
    }while(*(Pointer_la_Elemente+index)<1 || *(Pointer_la_Elemente+index)>254);
}

unsigned char Element_Cautat;

printf("Introdu elementul pe care doresti sa il cauti: ");
scanf("%hhu", &Element_Cautat);

unsigned char Returnare_Functie=Cautare_Liniara(Pointer_la_Elemente, Numar_Elemente, Element_Cautat);

if(Returnare_Functie==255)
    printf("Elementul cautat nu se afla in array.");
else
    printf("Elementul %hhu se afla pe pozitia %hhu", Element_Cautat, Returnare_Functie+1);

free(Pointer_la_Elemente);

return 0;
}