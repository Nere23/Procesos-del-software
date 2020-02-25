#include <iostream>
#include <conio.h>
#include <stdlib.h> //utiliza para new
using namespace std;

struct nodo{
	string nombre;
	int edad; 
	nodo *siguiente;
};
void agregar(nodo *&pila, string n, int e);
void sacarn(nodo *&pila, string &, int &);
int main(){
	nodo *pila=NULL;
	int opc;
	string nombre;
	int edad;
	char res;
	do{
	system("cls");
cout<<"1) Ingresar nombre y edad"<<endl;
cout<<"2) Eliminar el nombre y edad"<<endl;

cout<<endl<<"Elige una opcion: ";
cin>>opc;
	switch(opc){
		case 1:
			do{
			cout<<"agregar nombre: ";
			cin>>nombre;
			cout<<"agregar edad: ";
			cin>>edad;
			agregar(pila,nombre,edad);
			cout<<endl<<"Desea otro elemento? s/n: "<<endl;
	            cin>>res;
	        }while(res!='n');	
			break;
		case 2:
			cout<<"sacar elemento de la PILA"<<endl;
	    	while(pila!=NULL){
	    		sacarn(pila,nombre,edad);
	    		if (pila!=NULL){
	    			cout<<nombre<<" "<<edad<<","<<endl; 
				}
			    else{
				cout<<nombre<<" "<<edad<<".";
			    }
		    }   
			
			break;
	}
	cout <<endl<<"Regresar al menu s/n: ";
    cin>>res;
}while(res!='n');
getch();
}

void agregar(nodo *&pila, string n, int e){
	nodo *nvo_nodo=new nodo();

    nvo_nodo -> nombre=n;
    nvo_nodo -> edad=e;
    nvo_nodo->siguiente=pila;
    pila = nvo_nodo;
    cout<<"\nNombre agregado";
    
	
}
void sacarn(nodo *&pila, string &n, int &e){
	nodo *aux = pila;
	n= aux ->nombre;
	e= aux ->edad;
	pila=aux->siguiente;
	delete aux;
}
