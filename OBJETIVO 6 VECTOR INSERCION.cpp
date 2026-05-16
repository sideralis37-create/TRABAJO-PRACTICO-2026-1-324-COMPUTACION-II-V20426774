#include<vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <climits> 

using namespace std;

void insercion (std::vector<int>& v)
{
    for (size_t i = 1; i<v.size(); i++)
    {
        int k = v[i];
        int j= i-1;
        while (j>=0 && v[j] > k)
        {
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = k;
    }
}
int main ()
{
    std::vector<int> enteros = {3,13,8,25,45,23,98,58};
    cout <<"*** VECTOR SIN ORDENAR ***"<<endl;
    for(int numeros : enteros)
    {
        std::cout <<numeros<<" "<<endl;
    }
    insercion(enteros);
    cout <<"*** VECTOR ORDENADOMEDIANTE EL ALGORITMO DE INSERCION ***"<<endl;
    for(int numeros : enteros)
    {
        std::cout <<numeros<<" "<<endl;
    }
    return 0;
}