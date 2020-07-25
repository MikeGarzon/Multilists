#include<iostream>
#include"listaClavesOrdenadas.h"

using namespace std;

struct list{string nombre,receta ; lista<string> ingre;};


int main ()
{   int op, clave = 0 ; int max = 20; string aux, auxi;
    list postre[max];
    lista <list> p;

    //Añadiendo primeros postres
    postre[0].nombre = "Torta Vainilla";
    postre[0].receta = ".....";
    postre[0].ingre.insertar(0,"Harina de trigo  \t Cant: 1 lb"); 
    postre[0].ingre.insertar(1,"Huevos           \t Cant: 4"); 
    postre[0].ingre.insertar(2,"Azucar           \t Cant: 500 grms"); 
    postre[0].ingre.insertar(3,"Escencia vainilla\t Cant: 1ml"); 

    p.insertar(clave,postre[0]); clave++; 

    postre[1].nombre = "Arroz con leche";
    postre[1].receta = ".....";
    postre[1].ingre.insertar(0,"Leche            \t Cant: 1 L"); 
    postre[1].ingre.insertar(1,"Arroz            \t Cant: 500 grms"); 
    postre[1].ingre.insertar(2,"Azucar           \t Cant: 250 grms"); 
    postre[1].ingre.insertar(3,"Leche condensada \t Cant: 3ml"); 
    postre[1].ingre.insertar(4,"Canela           \t Cant: a gusto");

    p.insertar(clave,postre[1]); clave++; 

    postre[2].nombre = "Churro";
    postre[2].receta = ".....";
    postre[2].ingre.insertar(0,"Harina           \t Cant: 1 L"); 
    postre[2].ingre.insertar(1,"Levadura         \t Cant: 500 grms"); 
    postre[2].ingre.insertar(2,"Azucar           \t Cant: 250 grms"); 
    postre[2].ingre.insertar(3,"Arequipe         \t Cant: 3ml"); 

    p.insertar(clave,postre[2]); clave++;
    
    //Imprimiendo los codigos
    cout<<"Recetas hasta el momento"<<endl;
    for (int i = 0; i<clave; i++) {
        cout<<i<<" ";
        if(p.enLista(i))cout<<p.buscar(i).Dato.nombre<<endl;
    }

    //borrar
    cout<<"Ingrese el codigo del postre que desea borrar: "; 
    cin>>op;
    if(p.enLista(op))p.borrar(op);
    else cout<<"Codigo no valido"<<endl;


    //INSERTAR POSTRES
    cout<<"¿Desea añadir otro postre? <1> para si, <0> para no "<<endl; cin>>op;
    if (op == 1 ) {
        int d = 0; string aux,auxi,r;
        cout << "Nombre postre: "; cin >> postre[clave].nombre;
        cout << "Receta: ";
        cin.ignore(); //flush input buffer
        getline(cin,r);
        postre[clave].receta = r; 

        cout << "Numero de ingredientes :";
        cin >> d;
        for (int k = 0; k < d ; k++){
            cout << "Nombre ingrediente "<< k <<" : "; 
            cin.ignore();
            getline(cin,aux);
            cout << "Cantidad: ";
            cin.sync(); //flush otra vez
            getline(cin,auxi);
            aux = aux + "\t Cant: "+auxi;
            postre[clave].ingre.insertar(k,aux);
        }
        p.insertar(clave,postre[clave]); clave++;
    }
    
    //modificando receta
    cout<<"¿modificar alguna receta? <1> para si, <0> para no "<<endl; cin>>op;
    if (op == 1 ) {
        string o;
        cout<<"Ingrese la clave de la receta que desea modificar: ";cin>>op;
        cout<<"Escriba la nueva receta :";
        cin.ignore(); //flush input buffer
        getline(cin,o);
        postre[op].receta = o;
        p.cambiar(op,postre[op]);
    }


    //modificando ingredientes
    cout<<"¿modificar algun ingrediente? <1> para si, <0> para no "<<endl; cin>>op;
    if (op == 1 ) {
        cout<<"Ingrese la clave de la receta que desea modificar: ";cin>>op;
        p.buscar(op).Dato.ingre.imprimir();
        cout<<"Ingrese la clave del ingrediente a modificar (0,1,2,3...) segun orden de aparicion: "; cin>>clave;
        cout << "Nuevo ingrediente: ";
        cin.ignore();
        getline(cin,aux);
        cout << "Cantidad: ";
        cin.sync(); //flush otra vez
        getline(cin,auxi);
        aux = aux + "\t Cant: "+auxi;
        p.buscar(op).Dato.ingre.cambiar(clave,aux);
    }

    //Mostrando la receta del postre a buscar
    cout<<"Ingrese el codigo de la receta que desea saber"<<endl;
    cin>>op;
    if(p.enLista(op)){
        cout<<p.buscar(op).Dato.nombre<<endl;
        cout<<p.buscar(op).Dato.receta<<endl;
        p.buscar(op).Dato.ingre.imprimir();}
    else {cout<<"Receta no encontrada"<<endl;}

    
    return 0;
}
