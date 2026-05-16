#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <climits> 

using namespace std;

class nodo                                  //SE DEFINE LA CLASE NODO       
{
    public:
    int tiempo;
    nodo* next;
    nodo()                                  // CONSTRUCTOR DE LA CLASE NODO QUE INICIA LAS VARIABLES 
    {
        tiempo = 0;
        next = NULL;
    }
    nodo(int tiempo)                          // CONSTRUCTOR CON PARAMETROS
    {
        this->tiempo = tiempo;
        this->next = NULL;
    }
};

class crearruta                            // SE DEFINE UNA CLASE QUE CREA LISTAS ENLAZADAS PARA CADA RUTA DEL GRAFO
{
    public:
    nodo* head;
    crearruta()                            // COSTRUCTOR DE LA CLASE CREARRUTA 
    {
        head = NULL;
    }
    
    void insertAtHead(int tiempo)             // FUNCION MIEMBRO QUE INSERTA UN NODO EN LA CABEZA DE LA LISTA
    {
        nodo* newNode = new nodo(tiempo);
        if (head == NULL)                   // LA CABEZA DE LA LISTA APUNTA A NULL
        {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }
    
    void print(int nombre)                  // FUNCION MIEMBRO DE LA CLASE QUE IMPRIME LA LISTA 
    {
        nodo* temp = head;
        if (head == NULL)                  // IMPRIME UN MENSAJE SI LA LISTA ESTA VACIA
        {
            cout << "*** LA LISTA ESTA VACIA ***"<<'\n'<<endl;
            return;
        }
        
        cout <<"*** TIEMPO DE CADA TRAMO DE LA RUTA "<<nombre<<" ***"<<endl;

        while (temp != NULL)               // BUCLE CON EL CUAL SE RECORRE CADA LISTA
        {
            cout << temp->tiempo << " MIN " <<endl;
            temp = temp->next;
        }
        cout<<'\n'<<endl;
    }
    
    void maxmin ()                    // FUNCION MIEMBRO DE LA CLASE QUE BUSCA EL MAXIMO Y EL MINIMO DE LA LISTA 
    {
    int min = INT_MAX;
    int max = INT_MIN;
    nodo* actual = head;
    while (actual != NULL)
    {
        if (actual->tiempo< min)
        {
            min = actual->tiempo;
        }
        if (actual->tiempo> max)
        {
            max = actual->tiempo;
        }
        actual = actual-> next;
    }
    cout<<"*** LA RUTA MAS LARGA SE RECORRE EN :"<<max<<" MINUTOS ***"<<'\n'<<endl;
    cout<<"*** LA RUTA MAS CORTA ENTRE LOS NODOS S Y T SE RECORRE EN :"<<min<<" MINUTOS ***"<<'\n'<<endl;
    }
    
    void print2(int nom[13])                   // FUNCION QUE IMPRIME LA LISTA CON LOS NOMBRES DE LA RUTAS 
    {
        nodo* temp = head;
        cout <<"*** TIEMPO TOTAL DE CADA RUTA ***"<<'\n'<<endl;
        cout <<"*** EL NOMBRE DE CADA RUTA ES LA SECUENCIA DE NODOS RESPECTIVA ***"<<'\n'<<endl;
        
        while (temp != NULL)               // BUCLE QUE RECORRE CADA LISTA 
        {
            for(int i=0;i<13;i++)
            {
                cout <<"RUTA "<<nom[i]<<" :        "<< temp->tiempo <<"MIN"<<endl;
                temp = temp->next;
            }
        }
        cout<<'\n'<<endl;
    }
};                                          // CIERRE DE LA CLASE CREARRUTA

int tiempoderuta (nodo* head) //FUNCION QUE CALCULA LA SUMATORIA DE LOS TIEMPOS DE CADA TRAMO
{                              //ESTA FUNCION RECIBE COMO PARAMETRO EL NODO DE LA CABEZA DE CADA RUTA
    int suma = 0;
    nodo* current = head;
    while (current != NULL)
    {
        suma += current->tiempo;
        current = current->next;
    }
    return suma;            //LA FUNCIÓN DEVUELVE EL VALOR TOTAL DE CADA RUTA COMPLETA
}

int main ()
{
    //SE DEFINEN OBJETOS DE TIPO LISTA ENAZADA EN LOS CUALES SE ALMACENA LA INFORMACION
    //DE CADA RUTA DEL GRAFO

    crearruta rutta1, rutta2, rutta3, rutta4, rutta5, rutta6, rutta7;
    crearruta rutta8, rutta9, rutta10, rutta11, rutta12, rutta13, rutamin;
    
    int t1=0, t2=0, t3=0, t4=0, t5=0, t6=0, t7=0, t8=0, t9=0, t10=0, t11=0, t12=0,t13=0;

    //EN ESTE PROBLEMA SE INICIA CON LA INFORMACION DE CADA RUTA ALMACENADA EN ARREGLOS
    //DEBIDO A QUE EL GRAFO ES UN POCO EXTENSO PUEDE SER CONFUSO PREGUNTAR LA TOTALIDAD
    //DE LOS DATOS AL USUARIO. EXISTEN MUCHOS PROBLEMAS MATEMATICOS QUE SE INICIAN DE ESTA MANERA
    //POR EJEMPLO UN CONJUNTO DE DISTANCIAS, ANGULOS VERTICALES Y HORIONTALES EN UN LEVANTAMIENTO
    //TOPOGRAFICO O GEODESICO, LA ESTACION TOTAL TOMA ESTOS DATOS EN SU MEMORIA Y EL CONJUNTO DE 
    //DISTANCIAS Y ANGULOS SE OBTIENE DE UNA TABLA EN EXCEL.

    int ruta1[4]= {3, 7, 12, 1}; int ruta2[5] = {3, 7, 4, 6, 1}; int ruta3[4] = {10, 7, 6, 1}; 
    int ruta4[5] = {10, 7, 3, 6, 1}; int ruta5[4] = {15, 3, 6, 1}; int ruta6[4] = {3, 15, 6, 1};  
    int ruta7[4] = {3, 15, 3, 2}; int ruta8[4] = {10, 7, 4, 2}; int ruta9[5] = {3, 7, 4, 3, 2}; 
    int ruta10[3] = {15, 4, 2};int ruta11[4] = {15, 3, 3, 2}; int ruta12[5] = {10, 7, 3, 3, 2}; 
    int ruta13[4] = {10, 7, 3, 2};

    cout <<"*** ESTE PROGRAMA DETERMINA LA RUTA MAS CORTA ENTRE LOS PUNTOS S Y T ***"<<'\n'<<endl;
    cout <<"*** LOS DATOS DEL GRAFO SE ENCUENTRAN ALMACENADOS EN ARREGLOS ***"<<'\n'<<endl;
    cout <<"*** LOS TIEMPOS DE RECORRIDO ENTRE CADA NODO ESTAN ALMACENADOS ***"<<'\n'<<endl;
    cout <<"*** PRESIONE <ENTER> PARA CONTINUAR ***"<<'\n'<<endl;
    system("pause");
    system("cls");

    cout <<"*** EN ESTE PUNTO SE ALMACENARAN LOS TIEMPOS DE RECCORRIDO ***"<<'\n'<<endl;
    cout <<"*** Y EL NOMBRE DE CADA NODO EN UNA LISTA ENLAZADA ***"<<'\n'<<endl;
    cout <<"*** CADA LISTA ENLAZADA ES UNA RUTA DIFERENTE ***"<<'\n'<<endl;
    cout <<"*** PRESIONE <ENTER> PARA CONTINUAR ***"<<'\n'<<endl;
    system("pause");
    system("cls");

    //MEDIANTE LOS SIGUIENTES BUCLES FOR SE INSERTAN LOS DATOS CONTENIDOS EN LOS ARREGLOS EN UNA LISTA 
    //ENLAZADA PARA CADA POSIBLE RUTA
    for (int i=0; i<4; i++)
    {
        rutta1.insertAtHead(ruta1[i]);rutta3.insertAtHead(ruta3[i]);
        rutta5.insertAtHead(ruta5[i]); rutta6.insertAtHead(ruta6[i]);
        rutta7.insertAtHead(ruta7[i]); rutta8.insertAtHead(ruta8[i]);
        rutta11.insertAtHead(ruta11[i]); rutta13.insertAtHead(ruta13[i]);
    }

    for (int j=0; j<5; j++)
    {
        rutta2.insertAtHead(ruta2[j]);rutta4.insertAtHead(ruta4[j]);
        rutta9.insertAtHead(ruta9[j]); rutta12.insertAtHead(ruta12[j]);
    }
    
    for (int k=0; k<3; k++)
    {
        rutta10.insertAtHead(ruta10[k]);
    }
    
    cout <<"*** SE ALMACENARON LOS TIEMPOS ENTRE CADA NODO EN LA RUTA RESPECTIVA ***"<<'\n'<<endl;
    cout <<"*** PRESIONE <ENTER> PARA CONTINUAR ***"<<'\n'<<endl;
    system("pause");
    system("cls");

    cout <<"** A CONTINUACION SE MUESTRAN LOS TIEMPOS ENTRE NODOS DE CADA RUTA ***"<<'\n'<<endl;
    
    //SE IMPRIMEN LOS DATOS REFERENTES A CADA RUTA CONTENIDOS EN LA LISTA ENLAZADA RESPECTIVA
    rutta1.print(12579);rutta2.print(124579);rutta3.print(12489);rutta4.print(124689);rutta5.print(12469);
    rutta6.print(12479);rutta7.print(13479);rutta8.print(13689);rutta9.print(134579);rutta10.print(1369);
    rutta11.print(13469);rutta12.print(134689);rutta13.print(13489);
    
    cout <<"*** PRESIONE <ENTER> PARA CONTINUAR ***"<<'\n'<<endl;
    system("pause");
    system("cls");

    //SE CALCULAN LOS TIEMPOS TOTALES DE CADA RUTA Y SE ASIGNAN A UNA VARIABBLE
    
    t1 = tiempoderuta (rutta1.head);t2 = tiempoderuta (rutta2.head);t3 = tiempoderuta (rutta3.head);
    t4 = tiempoderuta (rutta4.head);t5 = tiempoderuta (rutta5.head);t6 = tiempoderuta (rutta6.head);
    t7 = tiempoderuta (rutta7.head);t8 = tiempoderuta (rutta8.head);t9 = tiempoderuta (rutta9.head);
    t10 = tiempoderuta (rutta10.head);t11 = tiempoderuta (rutta11.head);t12=tiempoderuta (rutta12.head);
    t13 = tiempoderuta (rutta13.head);
    
    //SE ADIGNAN LOS TIEMPOS DE CADA RUTA Y LOS NOMBRES A UN ARREGLO RESPECTIVO
    int rutmin[13]={t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13};
    int rutnom[13]={13489, 134689,13469,1369,134579,13689,13479,12479,12469,124689,12489,124579,12579};
    
    //MEDIANTE ESTE BUCLE FOR SE INSERTAN LOS TIEMPOS TOTALES DE CADA RUTA EN UNA LISTA ENLAZADA
    for(int s=0; s<13;s++)
    {
        rutamin.insertAtHead(rutmin[s]);
    }
    
    //SE IMPRIMEN LOS TIEMPOS TOTALES Y EL NOMBRE DE CADA RUTA
    //EL USUARIO PUEDE LEER EL NOMBRE DE LA RUTA Y EL TIEMPO DE RECORRIDO EN MINUTOS
    rutamin.print2(rutnom);
    //SE INVOCA A LA FUNCION MAXMIN PARA QUE CALCULE CUAL ES LA RUTA QUE SE RECORRE EN MENOR TIEMPO
    rutamin.maxmin();
    return 0;
}