#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

template <class T>
struct nodo {
	int clave;
	T Dato;
    nodo<T> * sig;};


template <class T>
class lista{nodo <T> *cab;
			int tam;
			
	public: lista(){cab=NULL;}
			bool lista_vacia();
			void insertar(int Clave, T info);
			void imprimir();
			void borrar(int Clave);
			bool enLista(int Clave);
			void cambiar(int Clave, T infoNueva);	
			nodo<T> buscar (int Clave);
};

template <class T>
void lista <T>::insertar(int Clave, T info)
{
    nodo<T> *nuevo = new nodo<T>;
    nuevo->clave = Clave;
    nuevo->Dato = info;
    nuevo->sig = NULL;
    if (cab == NULL) 
    {cab = nuevo;
    }
    else 
    {
        if (Clave<cab->clave) 
        {
            nuevo->sig = cab;
            cab = nuevo;
        }
        else 
        {
            nodo<T> *aux = cab;
            nodo<T> *atras = cab;
            while (Clave >= aux->clave && aux->sig != NULL) 
            {
                atras = aux;
                aux = aux->sig;
            }if (Clave >= aux->clave){
                aux->sig = nuevo;
            }else{
                nuevo->sig = aux;
                atras->sig = nuevo;
            }
        }
    }
}

template <class T>
bool lista<T>::lista_vacia()
{if(cab==NULL)
    return true;
 else
 	return false;
}

template <class T>
bool lista<T>::enLista(int Clave){
	bool esta = false;
	nodo<T> *aux;
	aux = cab;
	while(aux != NULL){
		if(Clave == aux->clave){
			esta = true;
			break;
		}else{
			aux = aux->sig;
		}
	}
	return esta;
}

template <class T>
nodo<T> lista<T>::buscar(int Clave)
{   nodo <T> *aux=cab, *salida=NULL;
	    while(aux != NULL)
    		{
    		if(Clave == aux->clave){
    			salida = aux;
    			//cout<<"Clave: <"<<Clave<<"> Dato: ";
    			break;
    		}else{
				aux = aux->sig;
			}
		
		}
	return *salida;
}

template <class T>
void lista<T>::borrar(int Clave){ 
    nodo <T> *temp, *atras;
    temp = cab;
	if(Clave == cab->clave){
		cab = temp->sig;
        delete temp;
	}else
	{
    while(Clave != temp->sig->clave){
			temp = temp->sig;
			}          
    nodo <T> *aux;
	aux = temp->sig;
    temp->sig = aux->sig;
    delete aux;
	tam--;
	}
}

template <class T>
void lista<T>::imprimir()
{   nodo <T> *aux=cab;
	    while(aux != NULL)
    		{
			//cout<<"Clave: <"<<aux->clave<<"> ";
    		cout<<"Ingrediente: "<<aux->Dato<<endl;
			aux = aux->sig;
			}

}

template <class T>
void lista<T>::cambiar(int Clave, T infoNueva){
    nodo <T> *temp;
    temp = cab;
    while(Clave != temp->clave){
			temp = temp->sig;
			}          
	temp->Dato = infoNueva;
	}

	

#endif
