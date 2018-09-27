#include <stdlib.h>
#include <stdio.h>



struct  clientes {
int id;
int cedula;
char nombre [100];
char direccion [ 100 ];
char telefono [ 100 ];
float opcion;
} cliente[ 100 ],*pcliente=cliente;

struct nodo{
	int numero;
	struct nodo *siguiente;
};


typedef struct nodo *Puntero;

Puntero delante;
Puntero atras;

void Encolar(int);
int Desencolar(void);
bool ColaVacia(void);

void menucliente();
void crearcliente();
void mostrarCliente1();
void mostrarclientes();
int buscarCliente();
int buscarCliente1();
void eliminarcliente();
void modificarcliente();
void copiar(char cadena1[],char cadena2[]);
void suma();

int numcliente=0;
int cap;
float Retiro=4;
float Deposito=2; 
float Consulta = 3.5; 
float Actualizacion= 5; 
float Pagos = 2; 

int main(){
	system("color 1f");
	nodo* delante = NULL;
	nodo* atras = NULL;


     menucliente();
        


    return 0;
}

void menucliente (){
    int opcion;
do{
        system("cls");
      
        printf("\n\tMenu Clientes                         \n");
        printf("\n\t1. Crear Cliente                       \n");
        printf("\n\t2. Ver Clientes                        \n");
        printf("\n\t3. Modificar Cliente                   \n");
        printf("\n\t4. Eliminar Cliente                    \n");
        printf("\n\t5. Buscar Cliente                      \n");
        printf("\n\t6. Ver el tiempo estimado de peticiones\n");
        printf("\n\t0. Menu Principal                      \n");
        printf("\n\tIngrese una opcion:                      ");
       scanf("%d",&opcion);
        system("cls");
        switch(opcion){
            case 1: crearcliente();
            break;
            case 2: mostrarclientes();
            break;
            case 3:modificarcliente();
            break;
            case 4:eliminarcliente();
            break;
            case 5:buscarCliente();
            break;
            case 6:suma();
            break;
            case 0:
            	break;
            default: printf("Opcion invalidad\n");
        }
    }while(opcion != 0);
}


void  crearcliente(){
int t;
fflush (stdin);
 printf ( " -------------- \n " );
 printf ( " CREAR CLIENTE " );
printf ( " --------------- \n " );
 printf ( " Ingrese los datos del cliente \n " );
(cliente+numcliente)->id=numcliente;

 printf ( " Nombre: " );
fgets ((pcliente+numcliente)->nombre, 30 , stdin);
printf ( " Direccion: " );
fgets ((pcliente+numcliente)->direccion , 30 , stdin);
printf ( " Telefono: " );
fgets ((pcliente+numcliente)->telefono , 30 , stdin);
printf ( " Cedula: " );
scanf ("%d",&(pcliente+numcliente)->cedula );
		printf("\n\t Ingrese la solicitud por la cual vino\n");
        printf("\n\t1. Retiro                             \n");
        printf("\n\t2. Deposito                           \n");
        printf("\n\t3. Consulta                           \n");
        printf("\n\t4. Actualizacion                      \n");
        printf("\n\t5. Pagos                              \n");
scanf ("%d",&t );
switch(t){
            case 1: (pcliente+numcliente)->opcion = Retiro;
            break;
            case 2: (pcliente+numcliente)->opcion= Deposito;
            break;
            case 3: (pcliente+numcliente)->opcion= Consulta;
            break;
            case 4: (pcliente+numcliente)->opcion = Actualizacion;
            break;
            case 5: (pcliente+numcliente)->opcion = Pagos;
            break;
        }
numcliente++;
Encolar(numcliente);
printf ( " Cliente registrado con exito \n " );
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
system("pause");
}


void mostrarclientes (){
printf("-----------------\n");
printf("LISTA DE CLIENTES\n");
printf("-----------------\n");
for (int i=0;i<numcliente;i++){
    printf("\ncliente #%d\n",i+1);
    printf("nombre: %s",(pcliente+i)->nombre);
    printf("direccion: %s",(pcliente+i)->direccion);
    printf("telefono: %s",(pcliente+i)->telefono);
    printf("cedula: %d\n",(pcliente+i)->cedula);
    
    }
system("pause");
}
void mostrarCliente(int idCliente){
    
	printf("Mostrar Clientes\n");
	printf("Cliente No. %d\n", (pcliente+idCliente)->id + 1);
	printf("Nombre del Cliente: %s", (pcliente+idCliente)->nombre);
	printf("Direccion del Cliente: %s", (pcliente+idCliente)->direccion);
	printf("Telefono del Cliente: %s", (pcliente+idCliente)->telefono);
	printf("Cedula del Cliente: %d\n", (pcliente+idCliente)->cedula);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
}

int buscarCliente(){
    
	int cedulaBuscar, i;
	printf("Buscar Cliente.  ");
	printf("Ingrese Cedula del cliente: ");
	scanf("%d", &cedulaBuscar);
	system("cls");
	printf("\n");
	for(i = 0; i < numcliente; i++){
		if(cedulaBuscar == (pcliente+i)->cedula){
			mostrarCliente((pcliente+i)->id);
			return (cliente+i)->id;
		}
	}

	printf("El cliente no existe \n");
		printf("\n\n\n\n\n\n\n\n");

	system("pause");
	return -1;
system("pause");
}

int buscarCliente1(){

    system("cls");
   
	int cedulaBuscar, i,n;
	printf("Buscar Cliente.  ");
	printf("Ingrese Cedula del cliente: ");
	scanf("%d", &cedulaBuscar);
	system("cls");
	printf("\n");
	for(i = 0; i < numcliente; i++){
		if(cedulaBuscar == (pcliente+i)->cedula){
            cap=(pcliente+i)->id;
			mostrarCliente((pcliente+i)->id);
			return (cliente+i)->id;
		}
	}
	printf("El cliente no existe \n");
	
		printf("\n\n\n");

	system("pause");
	return -1;

}

void eliminarcliente(){
   
printf("ELIMINAR CLIENTE\n");
int idcliente=buscarCliente();
if(idcliente!=-1){
    if(idcliente<numcliente){
        for(int i=idcliente;i<numcliente;i++){
            (pcliente+i+1)->id = (pcliente+i)->id;
            copiar((cliente+i)->nombre,(pcliente+i+1)->nombre);
            (pcliente+i)->cedula = (pcliente+i+1)->cedula;
            copiar((pcliente+i)->direccion,(pcliente+i+1)->direccion);
            copiar((pcliente+i)->telefono,(pcliente+i)->telefono);
        }
    }
    numcliente--;
    if(ColaVacia()==true ){
				printf("\n\n\t Cola vacia...!\n");
			}else{
				Desencolar();
				
}

}
}

void copiar(char cadena1[],char cadena2[]){
int contador=0;
for(int i=0;i<30;i++){
    if(cadena1[i]=='\n'){
        break;
    }
    contador++;
}
for(int i=0;i<contador;i++){
    cadena1[i]=cadena2[i];
}
}


void modificarcliente(){
    
printf("MODIFICAR CLIENTE\n");
int idcliente=buscarCliente();
if(idcliente!=-1){
printf("Cliente No. %d\n", idcliente + 1);
        fflush(stdin);
	    printf("Nombre del Cliente: ");
		fgets((pcliente+idcliente)->nombre,30,stdin);
		printf("Direccion del Cliente: ");
		fgets((pcliente+idcliente)->direccion,30,stdin);
		printf("Telefono del Cliente: ");
		fgets((pcliente+idcliente)->telefono,30,stdin);
		printf("Cedula del Cliente: ");
		scanf("%d", &(pcliente+idcliente)->cedula);
		printf("\n");
		system("cls");
    }
}

bool  ColaVacia(){
	if(delante==NULL){
		return true;
	}else{
		return false;
	}
}
void Encolar(int numcliente){
	
	Puntero p_aux;
	
	p_aux = new(struct nodo);
	p_aux->numero = numcliente;
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


void suma(){
	float sumat = 0;
	for (int i=0 ; i<numcliente;i++){
		sumat+=(pcliente+i)->opcion;
	}
	
	printf("El tiempo total en la atencion es de: %.2f",sumat);
	system("pause");
}


