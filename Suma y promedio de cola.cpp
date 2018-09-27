#include <stdlib.h>
#include <stdio.h>



struct nodo{
	int numero;
	struct nodo *siguiente;
};


typedef struct nodo *Puntero;



void Encolar(int);
int Desencolar(void);
bool ColaVacia(void);
void MostrarCola(void);
void VaciarCola(void);
		

Puntero delante;
Puntero atras;

int vec[100];
int contador = 0;


bool  ColaVacia(){
	if(delante==NULL){
		return true;
	}else{
		return false;
	}
}
void Encolar(int x){
	
	Puntero p_aux;
	
	p_aux = new(struct nodo);
	p_aux->numero = x;
	vec[contador] = x;
	contador++;
	p_aux->siguiente = NULL;
	
	if(delante == NULL){
		delante = p_aux;
		
	}else {
		atras->siguiente = p_aux;
	}
	
	atras = p_aux;
}

int Desencolar(){
	int n;
	Puntero p_aux;
	
	p_aux = delante;
	n = p_aux->numero;
	delante = (delante)->siguiente;
	delete(p_aux);
	return n;
}


void MostrarCola(){
	
	Puntero p_aux;
	p_aux = delante;
	while(p_aux != NULL){
		printf("\n\t");
		printf("%d\n",p_aux->numero);
		p_aux = p_aux->siguiente;
	}
} 

void VaciarCola(){
	
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

void suma(){
	int sumat = 0;
	for (int i=0 ; i<contador;i++){
		sumat+=vec[i];
	}
	
	printf("\t La suma de los numeros es de: %d\n\n",sumat);
	system("pause");
}
void promedio(){
	int sumat = 0;
	float pro=0;
	for (int i=0 ; i<contador;i++){
		sumat+=vec[i];
	}
	pro = sumat / contador;
	printf("\t El promedio de los numeros es de: %.2f\n\n",pro);
	system("pause");
}


int menu(){
	
	printf("\n\n\t---------------------------------\n");
	printf("\t|    IMPLEMENTACION DE UNA COLA |\n");
	printf("\t| ------------------------------|\n");
	printf("\t|                               |\n");
	printf("\t|  1. AGREGAR UN NUMERO         |\n");
	printf("\t|  2. QUITAR NUMERO               |\n");
	printf("\t|  3. MOSTRAR COLA              |\n");
	printf("\t|  4. VACIAR COLA               |\n");
	printf("\t|  5. SUMA DE COLA              |\n");
	printf("\t|  6. PROMEDIO DE COLA          |\n");
	printf("\t|  7. SALIR                     |\n");
	printf("\t|                               |\n");
	printf("\t|-------------------------------|\n");
	printf("\t Ingrese una opcion:  ");
	
}

int main(){
	system("color 1c");
	nodo* delante = NULL;
	nodo* atras = NULL;
	int x;
	int op;
	
	do{
		
	menu();
	scanf("%d",&op);
	switch(op){
		case 1: 
			printf("\n\t INGRESE NUMERO A ENCONLAR\n");
			printf("\t "); scanf("%d",&x);
			
			Encolar(x);
			printf("\n\n\t Agregando numero %d\n",x);
			printf("\n\n\t");
			break;
		case 2:
			if(ColaVacia()==true ){
				printf("\n\n\t Cola vacia...!\n");
			}else{
				x = Desencolar();
				printf("\n\n\t Eliminando numero %d\n",x);
				printf("\n\n\t");
				
			}
			break;
		case 3: 
			printf("\n\n\t MOSTRASNDO COLA\n");
			printf("\n\n");
			if(ColaVacia()!=true){
				MostrarCola();
			}else{
				printf("\n\n\t Cola vacia...!\n");
				printf("\n\n");
				
			}
			break;
		case 4: 
		VaciarCola();
		printf("\n\n\t Cola eliminada...\n");
		printf("\n\n");
			break;
		case 5: suma();
			break;
		case 6: promedio();
			break;
		default:
			printf("\n\n");
			printf("\n\n\t Ingrese una opcion valida.......!\n");
	}
	system("pause"); system("cls");
	}while(op!=7);
	
	return 0;
}
