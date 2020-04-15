#include<iostream>
#include <vector>
using namespace std;
struct Solucion{
 int cantidadMoneda;
 int valorMoneda;
};
void printSolucion(vector<Solucion> imprime)
{
    for(int i = 0; i<imprime.size();i++)
    {
        cout<<imprime.at(i).cantidadMoneda<<" ";
        cout<<imprime.at(i).valorMoneda<<" ";
        cout<<endl;
    }
}
void ordenarMonedas(vector <int> * monedas)
{
    int aux;
    for(int i=0;i<monedas->size();i++)
    {
        for (int j=0;j<monedas->size()-1;j++)
        {
            if(monedas->at(j)<monedas->at(j+1))
            {
                aux= monedas->at(j);
                monedas->at(j)=monedas->at(j+1);
               monedas->at(j+1)=aux; 
            }
        }
    }
}
void regresarCambio(vector <int> monedas,int cantidad)
{
    vector<Solucion> cambio;
    Solucion aux;
    int total = 0, i=0,contMon = 0;
    while(total<cantidad && i<monedas.size())
    {
       
       while((total + monedas.at(i))<=cantidad)
       {
           total+=monedas.at(i);
           contMon++;
       }
      if(contMon !=0)
      {
          aux.cantidadMoneda = contMon;
          aux.valorMoneda = monedas.at(i);
          cambio.push_back(aux);
      }
       i++;
       contMon = 0;           
    }
    printSolucion(cambio);
}
int main ()
{
    vector <int> monedas;
    monedas.push_back(1);
    monedas.push_back(10);
    monedas.push_back(25);
    monedas.push_back(5);
    monedas.push_back(50);
    ordenarMonedas(&monedas);
    regresarCambio(monedas,91);
    return 0;
}