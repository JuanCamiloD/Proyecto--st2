#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>


struct nodo{
	
	int numero;
	struct nodo *siguiente;
};


typedef struct nodo *Puntero;

class Cola {
	public:
		Cola(void);
		void Encolar(int);
		int Desencolar(void);
		bool ColaVacia(void);
		void MostrarCola(void);
		void VaciarCola(void);
		
	private:
	 	Puntero delante;
		Puntero atras;
			
};


Cola::Cola(void){
	delante = NULL;
	atras = NULL;
}

bool  Cola::ColaVacia(){
	if(delante==NULL){
		return true;
	}else{
		return false;
	}
}
void Cola::Encolar(int x){
	
	Puntero p_aux;
	
	p_aux = new(struct nodo);
	p_aux->numero = x;
	p_aux->siguiente = NULL;
	
	if(delante == NULL){
		delante = p_aux;
		
	}else {
		atras->siguiente = p_aux;
	}
	
	atras = p_aux;
}

int Cola::Desencolar(void){
	int n;
	Puntero p_aux;
	
	p_aux = delante;
	n = p_aux->numero;
	delante = (delante)->siguiente;
	delete(p_aux);
	return n;
}


void Cola::MostrarCola(void){
	
	Puntero p_aux;
	p_aux = delante;
	while(p_aux != NULL){
		printf("\n\t");
		printf("%d\n",p_aux->numero);
		p_aux = p_aux->siguiente;
	}
} 

void Cola::VaciarCola(void){
	
	Puntero p_aux,r_aux;
	p_aux = delante;
	while(p_aux != NULL){
		r_aux = p_aux;
		p_aux = p_aux ->siguiente;
		delete (r_aux);
	}
	delante = NULL;
	atras = NULL;
}


int menu(void){
	
	printf("\n\n\t --------------------------\n");
	printf("\t|    IMPLEMENTACION DE UNA COLA |\n");
	printf("\t| ------------------------------|\n");
	printf("\t|                               |\n");
	printf("\t|  1. ENCOLAR                   |\n");
	printf("\t|  2. DESENCOLAR                |\n");
	printf("\t|  3. MOSTRAR COLA              |\n");
	printf("\t|  4. VACIAR COLA               |\n");
	printf("\t|  5. SALIR                     |\n");
	printf("\t|                               |\n");
	printf("\t|-------------------------------|\n");
	printf("\t Ingrese una opcion:  ");
	
}

int main(void){
	system("color 1f");
	Cola cola;
	int x;
	int op;
	
	do{
		
	menu();
	scanf("%d",&op);
	switch(op){
		case 1: 
			printf("\n\t INGRESE NUMERO A ENCONLAR");
			scanf("%d",&x);
			
			cola.Encolar(x);
			printf("\n\n\t Agregando numero %d",x);
			printf("\n\n\t");
			break;
		case 2:
			if(cola.ColaVacia()==true ){
				printf("\n\n\t Cola vacia...!");
			}else{
				x = cola.Desencolar();
				printf("\n\n\t Eliminando numero %d",x);
				printf("\n\n\t");
				
			}
			break;
		case 3: 
			printf("\n\n\t MOSTRASNDO COLA");
			printf("\n\n");
			if(cola.ColaVacia()!=true){
				cola.MostrarCola();
			}else{
				printf("\n\n\t Cola vacia...!");
				printf("\n\n");
				
			}
			break;
		case 4: 
		cola.VaciarCola();
		printf("\n\n\t Cola eliminada...");
		printf("\n\n");
		break;
		
		default:
			printf("\n\n");
			printf("\n\n\t Ingrese una opcion valida.......!");
	}
	system("pause"); system("cls");
	}while(op!=5);
	
	return 0;
}
