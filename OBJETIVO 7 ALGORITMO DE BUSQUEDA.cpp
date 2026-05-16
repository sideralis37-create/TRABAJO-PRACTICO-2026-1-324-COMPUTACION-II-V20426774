#include<vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <climits> 

using namespace std;

int busquedalineal (int numeros[], int size, int key)
{
    for(int i = 0; i < size; i++)
    {
        if (key == numeros[i])
        {
            return i;
        }
    }
    return -1;
}

int main ()
{
    int enteros [18] = {3,6,9,8,5,7,1,2,4,1,2,4,5,5,8,9,6,3};
    int target=0;
    int respuesta=0;
    cout<<"*** EN ESTE PROGRAMA EL USUARIO INGRESA UN NUMERO A SER BUSCADO EN UNA LISTA ***"<<'\n'<<endl;
    cout<<"*** PRESIONE <ENTER> PARA CONTINUAR ***"<<'\n'<<endl;
    system("pause");
    system("cls");
    cout<<"INDIQUE EL NUMERO ENTERO QUE DESEA BUSCAR EN LA LISTA: "<<'\n'<<endl;

    cin>>target;
    respuesta = busquedalineal(enteros, 18, target);
    if (respuesta >= 0)
    {
        cout<<"EL NUMERO "<<enteros[respuesta]<<" ESTA EN LA LISTA."<<'\n'<<endl;
        cout<<"EL ELEMENTO SE ENCUENTRA EN LA POSICION: "<<respuesta<<'\n'<<endl;
        cout<<"*** PRESIONE <ENTER> PARA CONTINUAR ****"<<'\n'<<endl;
        system ("pause");
        system("cls");
    }
    else
    {
        cout<<"EL NUMERO "<<target<<" NO FUE ENCONTRADO"<<'\n'<<endl;
        cout<<"*** PRESIONE <ENTER> PARA CONTINUAR ****"<<'\n'<<endl;
        system ("pause");
        system("cls");
    }
    return 0;
}

