#include <iostream>
#include "lista.h"

using namespace std;

struct ingredientes{
    string nombre;
    int cantidad;
};
struct postre{
    string nombre;
    lista<ingredientes> j;
};

int main(int argc, char *argv[]){
    int dato1, dato2,j;

    ingredientes auxJ;
    postre auxE[5];

    lista<postre> E;

    cout << "nombre postre";
    cin >> auxE[0].nombre;

    cout << "numero de ingredientes";
    cin >> dato1;

    for (j = 1; j <= dato1; j++){
        cout << "nombre ingrediente";
        cin >> auxJ.nombre;
        cout << "cantidad";
        cin >> dato2;
        auxE[0].j.insertar_final(auxJ);
    }

    E.insertar_final(auxE[0]);
    
}