#include<iostream>
#include<stdlib.h>
#include<ctype.h>//para funcion isalpha y toupper
#include<unistd.h>
#include<string.h>
//#include<chrono>
//#include<thread>
#include<fstream>//para utilizar ofstream y ifstream


using namespace std;

struct Nodo{
   char dato;
   Nodo *siguiente;	
};

void insertarLista(Nodo *&,char);
void mostrarLista(Nodo *);
void eliminarLista(Nodo *&,char&);
int adivinando_la_palabra(char,char *,char *,int);
void cargar_palabra_a_completar(char *,char *,int);
void mostrar_palabra(char *,int);
int contador_de_letras(char*,int);
void validar_letra(char &);
void mostrarCartel(int,int&,int&);
bool comprobarpalabras(char *,char *,int);
void elejirPal(char*,int&,int);
void conMay(char *,int);



int main(){
	Nodo *lista=NULL;
	
	
	char palSelec[40],letra;
	int opc=0,total_let=0,palAdivinadas=0,contPal_adiv=1,niv=1,cant=0;
	do{
		int vidas=4,aciertos=0,contAciertos=0,segundos=30;
		
		cout<<"Opcion 1: Comenzar juego"<<endl;
    cout<<"Opcion 2: jugar con un Amigo"<<endl;
    cout<<"Opcion 3: Salir"<<endl;
    cout<<">>";
    cin>>opc;
    system("clear");
    	
 	switch(opc){
		case 1:do{
					elejirPal(palSelec,niv,contPal_adiv);
					cant=strlen(palSelec);
					conMay(palSelec,cant);
    			
				   fflush(stdin);
    			   
    			   
				   char pal_a_comp[cant];
				   cargar_palabra_a_completar(palSelec,pal_a_comp,cant);
				   total_let=contador_de_letras(palSelec,cant);
				   fflush(stdin);
			   	   cout<<"           °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	           cout<<"           °°                           >>>>>>>>> NIVEL: "<<niv<<"<<<<<<<<<                  °°"<<endl;
             cout<<"           °° >>>>>>>>> LA PALABRA O FRASE A ADIVINAR TIENE: "<<total_let<<" LETRAS <<<<<<<<<< °°"<<endl;
	           cout<<"           °° >>>>>>>>>>>>>>>>>>>>>>     USTED TIENE "<<vidas<<" VIDAS     <<<<<<<<<<<<<<<<<<< °°"<<endl;
             cout<<"           °°                                                                                  °°"<<endl;
	           cout<<"           °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	               sleep(2);
	               system("clear");
	           do{
	            
           		  cout<<"\n";
		            cout<<"\n";
		            cout<<">>>>>  ";mostrar_palabra(pal_a_comp,cant);cout<<"  <<<<<";
		            cout<<endl;
		            cout<<"\ntiene: "<<vidas<<" vidas"<<endl;
		            cout<<"lleva: "<<aciertos<<" letras acertadas"<<endl;
		            cout<<"Letras utilizadas: ";
					mostrarLista(lista);
					      /*cout<<"Tiempo: "<<tempo.tomarTiemp();*/
		            
					cout<<"\nIngrese una letra >>",
		            cin>>letra;
		            letra=toupper(letra);
		            
		            validar_letra(letra);
		            insertarLista(lista,letra);
	               	contAciertos=adivinando_la_palabra(letra,palSelec,pal_a_comp,cant);
				    fflush(stdin);
				    system("clear");
				    mostrarCartel(contAciertos,vidas,aciertos);
				}while((vidas!=0)&&(comprobarpalabras(palSelec,pal_a_comp,cant)==false)&&(segundos!=0));  
   	               
   	               
		            while(lista!=NULL){
	        	    eliminarLista(lista,letra);
			        }
		            
		            contPal_adiv++;
		            
					aciertos=0;
					
            }while((vidas!=0)&&(contPal_adiv!=9)); 
				   if(contPal_adiv==9){
				   	cout<<"GANASTE!!!!!!"<<endl;
				   	cout<<"SUPERASTE LOS 3 NIVELES!!!"<<endl;
				    sleep(4);
				    system("clear");
				   }
				   else if(vidas==0){
				   	cout<<"PERDISTE!!!"<<endl;
				   	cout<<"VUELVE A INTENTARLO!!!"<<endl;
				   sleep(4);
				   	system("clear");
				   }
				   //getch();
				   break;
    case 2:cout<<"Ingrese la palabra que desea adivinar>> ";
    		   cin>>palSelec;
    		   cant=strlen(palSelec);
    		   conMay(palSelec,cant);
    		   
           system("clear");
    			   
				   char pal_a_adiv[cant];
				   cargar_palabra_a_completar(palSelec,pal_a_adiv,cant);
				   total_let=contador_de_letras(palSelec,cant);
				   fflush(stdin);
			   	   
				   cout<<"           °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
           cout<<"           °° >>>>>>>>> LA PALABRA O FRASE A ADIVINAR TIENE: "<<total_let<<" LETRAS <<<<<<<<<< °°"<<endl;
	         cout<<"           °° >>>>>>>>>>>>>>>>>>>>>>>>>>>     USTED TIENE 4 VIDAS     <<<<<<<<<<<<<<<<<<<<<<<< °°"<<endl;
           cout<<"           °°                                                                                  °°"<<endl;
	         cout<<"           °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	               sleep(2);
	               system("clear");
	                do{
	            
           		  cout<<"\n";
		            cout<<"\n";
		            cout<<">>>>>  ";mostrar_palabra(pal_a_adiv,cant);cout<<"  <<<<<";
		            cout<<endl;
		            cout<<"\ntiene: "<<vidas<<" vidas"<<endl;
		            cout<<"lleva: "<<aciertos<<" letras acertadas"<<endl;
		            cout<<"Letras utilizadas: ";
					mostrarLista(lista);
		            
					cout<<"\nIngrese una letra >>",
		            cin>>letra;
		            letra=toupper(letra);
		            
		            validar_letra(letra);
		            insertarLista(lista,letra);
	               	contAciertos=adivinando_la_palabra(letra,palSelec,pal_a_adiv,cant);
				    fflush(stdin);
				    system("clear");
				    mostrarCartel(contAciertos,vidas,aciertos);
				    conMay(pal_a_adiv,cant);
					
		            
				}while((vidas!=0)&&(comprobarpalabras(palSelec,pal_a_adiv,cant)==false));   
		            while(lista!=NULL){
	        	    eliminarLista(lista,letra);
			        }
					
					if(vidas==0){
		            	cout<<"HAS PERDIDO!!!"<<endl;
		            	cout<<"LA PALABRA A ADIVINAR ERA: "<<palSelec<<endl;
		        sleep(4);
						system("clear");
					}
					else{
						cout<<"HAS GANADO!!!"<<endl;
		            	cout<<"LA PALABRA ADIVINADA ERA: "<<palSelec<<endl;
		       sleep(4);
						system("clear");
					}
			   break;
			   
		}
	}while(opc!=3);

return 0;
}

//EN ESTE SUBPROCESO LO QUE HAGO ES QUE EN EL ARREGLO DE PALABRA A COMPLETAR LE CARGUE GUIONES CADA VEZ QUE HAY UNA LETRA Y UN ESPACIO CUANDO NO LO HAY
void cargar_palabra_a_completar(char *palSel,char *let_vacias,int can){
	for(int i=0;i<can;i++){
		if(*(palSel+i)==' '){
			*(let_vacias+i)=' ';
			
		}
		else {
		*(let_vacias+i)='_';
		
    }
}

}
void mostrar_palabra(char *palabras,int can){
	for(int i=0;i<can;i++){
		cout<<" "<<*(palabras+i)<<" ";
	}
}	
int adivinando_la_palabra(char let,char *palSel,char *palabraVac,int can){		
	int acierto=0;
	 for(int i=0;i<can;i++){
		if(let==*(palSel+i)){
			*(palabraVac+i)=let;
			acierto++;
		  }
		}
	return acierto;
}

int contador_de_letras(char *palSel,int can){
	int cont=0;
	for(int i=0;i<strlen(palSel);i++){
		if(isalpha(palSel[i])>0){
			cont++;
		}
	}
return cont;
}
void validar_letra(char &letra){

while(isalpha(letra)==0){
cout<<"ERROR!!! DEBE INGRESAR UNA LETRA!!!"<<endl;
cout<<"escriba una letra: ";
cin>>letra;
letra=toupper(letra);
	}
}
void insertarLista(Nodo *&lista,char let){
Nodo *nuevo_nodo=new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato=let;
	nuevo_nodo->siguiente=NULL;
	
	if(lista==NULL){//si la lista esta vacia 
		lista=nuevo_nodo;//agregamos el primer elemento a la lista
	}
	else{
		aux=lista;
		while(aux->siguiente!=NULL){//recorremops la lista
			aux=aux->siguiente;//avanzamos posiciones en la lista
		}
		aux->siguiente=nuevo_nodo;//Agregamos un nuevo  nodo a la lista
	}
}
void mostrarLista(Nodo *lista){

while(lista!=NULL){
	cout<<lista->dato<<" ";
	lista=lista->siguiente;
	}
}

void eliminarLista(Nodo *&lista,char& let){
 	Nodo *aux=lista;
 	let=aux->dato;
 	lista=aux->siguiente;
 	delete aux;
}

void mostrarCartel(int contAci,int& vid,int& acie){
 
if(contAci==0){
vid--;
cout<<"QUE LASTIMA LE ERRASTE DE LETRA!!!"<<endl;
cout<<"TIENES UNA VIDA MENOS!!";
sleep(1);
system("clear");
}
else{
acie+=contAci;
cout<<"BIEN ACERTASTE!!!"<<endl;
sleep(1);
system("clear");
}
}

bool comprobarpalabras(char * palSel,char *paladiv,int cant){
	bool vict=false;
  int aciertos=0;
 for(int i=0;i<cant;i++){
  if(*(palSel+i)==*(paladiv+i)){
    aciertos++;
		}
	}
if(aciertos==cant){
		vict=true;
	}
return vict;
}

void elejirPal(char *palSel,int& niv,int contPal_adiv){
  int max=0;
  
  if(contPal_adiv<=3){
  srand(time(NULL));
 	max=1+rand()%(15);;
 	}
 	else if((contPal_adiv>3)&&(contPal_adiv<=6)){
 	niv=2;
 	srand(time(NULL));
 	max=16+rand()%(30);;
 	}
 	else{
 	niv=3;
 	srand(time(NULL));
 	max=31+rand()%(45);;
 	}
 	ifstream archivo("palabras.txt");
 	string texto;
 	int i=0;
 
    if(archivo.fail()){//este condicional se usa para ver si hubo un error al abrir el archivo
 		cout<<"no se pudo abrir el archivo";
 		exit(1);
	 }
	  
	 while(getline(archivo,texto)){
	 if(max == i){
   strcpy(palSel,texto.c_str());//string tiene un método llamado c_str() que devuelve un puntero de tipo const char* a su memoria interna.
   }
   i++;
	 }
	  archivo.close(); 
}
	
void conMay(char *pal,int cant){

for(int i=0;i<cant;i++){
*(pal+i)=toupper(*(pal+i));
}
}

