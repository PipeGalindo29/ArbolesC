// Taller Arboles Binarios

// Rafael Felipe Galindo Becerra
// 1003711448
// 1/05/2020


#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct nodo{
	
	int dato;
	
	nodo *derecha;
	nodo *izquierda;
	nodo *padre;
};

//--------------------------------------------------------------------------------------------------------------------------------

struct nodo *arbol = NULL;

//--------------------------------------------------------------------------------------------------------------------------------

nodo *crea_nodo(int n, nodo *padre){
	struct nodo *nuevo;
	nuevo = new(struct nodo);
	
	nuevo->dato = n;
	nuevo->derecha = NULL;
	nuevo->izquierda = NULL;
	nuevo->padre = padre;
}

//--------------------------------------------------------------------------------------------------------------------------------

void insertar_nodo(nodo *&arbol, int n, nodo *padre){
	
	struct nodo *nuevo_nodo;
	
	if(arbol == NULL){
		nuevo_nodo = crea_nodo(n, padre);
		arbol = nuevo_nodo;
	}else{
		int raiz;
		raiz = arbol->dato;
		
		if(n < raiz){
			insertar_nodo(arbol->izquierda, n, arbol);
		}else{
			insertar_nodo(arbol->derecha, n, arbol);
		}
		
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

int size(nodo *&arbol){

	if(arbol == NULL){
	   return 0;	
	}else{
		return (size(arbol->derecha) + 1 + size(arbol->izquierda));
	}
	    
}

//--------------------------------------------------------------------------------------------------------------------------------

int minimo(nodo *&arbol){
	
	struct nodo *nuevo = arbol;
	
	while(nuevo->izquierda != NULL){
		nuevo = nuevo->izquierda;
	}
	
	return nuevo->dato;
}

//--------------------------------------------------------------------------------------------------------------------------------

nodo *nodo_iz(nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izquierda){
		return nodo_iz(arbol->izquierda);
	}else{
		return arbol;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void reemplaza_nodo(nodo *arbol, nodo *nuevo){
	
	if(arbol->padre){
		
		if(arbol->dato == arbol->padre->izquierda->dato){
			arbol->padre->izquierda = nuevo;
		}else{
			
			if(arbol->dato == arbol->padre->derecha->dato){
				arbol->padre->derecha = nuevo;
			}
		}
	}
	if(nuevo){
		nuevo->padre = arbol->padre;
	}
	
}

//--------------------------------------------------------------------------------------------------------------------------------

void borra_nodo(nodo *nodo){
	
	nodo->izquierda = NULL;
	nodo->derecha = NULL;
	
	delete nodo;
}
//--------------------------------------------------------------------------------------------------------------------------------

void elimina_nodo(nodo *elim){
	struct nodo *temp;
	
	if(elim->izquierda and elim->derecha){
		temp = nodo_iz(elim->derecha);
		elim->dato = temp->dato;
		elimina_nodo(temp);
	}else{
		
		if(elim->izquierda){
			reemplaza_nodo(elim, elim->izquierda);
			borra_nodo(elim);
		}else{
			
			if(elim->derecha){
				reemplaza_nodo(elim, elim->derecha);
				borra_nodo(elim);
			}else {
				reemplaza_nodo(elim, NULL);
				borra_nodo(elim);
			}
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void busca_nodo(nodo *arbol, int n){
	
	if(arbol == NULL){
		cout<<"No hay ningun elemento (esta vacio el arbol)"<<endl;
		return;
	}else{
		
		if(n < arbol->dato){
			busca_nodo(arbol->izquierda, n);
		}else{
			
			if(n > arbol->dato){
				busca_nodo(arbol->derecha, n);
			}else{
				elimina_nodo(arbol);
			}	
		}
	}
	
}

//--------------------------------------------------------------------------------------------------------------------------------

void mostrar_arbol(nodo *arbol, int cont){
	
	if(arbol == NULL){
		return;
	}else{
		mostrar_arbol(arbol->derecha, cont+1);
		for(int i=0; i<cont ;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrar_arbol(arbol->izquierda, cont+1);
	}
	
}

//--------------------------------------------------------------------------------------------------------------------------------

int main() {
	
	int op=0, dato, dat_el, contador=0;
	
	cout<<"Menu"<<endl;
	cout<<"1. Insertar datos en el arbol"<<endl;
	cout<<"2. Calcular el numero de nodos del arbol"<<endl;
	cout<<"3. Calcular y retornar el valor minimo del arbol"<<endl;
	cout<<"4. Eliminar un nodo del arbol"<<endl;
	cout<<"5. Mostrar arbol"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<"Seleccione la opcion que desee: "; cin>>op;
	
	switch(op){
		
		case 1: system("CLS");
				cout<<"Ingrese un numero: "; cin>>dato;
				insertar_nodo(arbol, dato, NULL);
				cout<<"Se ha ingresado el dato !!"<<endl;
				main();
		break;
		
		case 2: system("CLS");
				cout<<"La cantidad de nodos que tiene el arbol es: ";
				cout<<size(arbol)<<endl;
				cout<<endl;
				main();
		break;
		
		case 3: system("CLS");
				cout<<"El menor dato del arbol es: ";
				cout<<minimo(arbol)<<endl;
				cout<<endl;
				main();
		break;
		
		case 4: system("CLS");
				cout<<"Digite el numero que desea eliminar: "; cin>>dat_el;
				busca_nodo(arbol, dat_el);
				cout<<endl;
				main();
		break;
		
		case 5: system("CLS");
				cout<<"El arbol completo es: "<<endl;
				mostrar_arbol(arbol, contador);
				cout<<endl;
				main();
		break;
				
		
		
		case 6: system("CLS");
				cout<<"Adios"<<endl;
				return 0;
		break;
		
		
	}
	
	
	return 0;
}

















