#include<iostream>
#include <vector>
using namespace std;
    //definición de una estructura para poder despleghar la solución.
struct Solucion{
 int cantidadMoneda;
 int valorMoneda;
};
        /* Metodo utilizado para imprimir la solución del problema.
         * @param imprime: vector que contiene el número de monedas utilizadas y el valor de cada una. 
         */
void printSolucion(vector<Solucion> imprime)
{
    for(int i = 0; i<imprime.size();i++)
    {
        cout<<"Numero de monedas "<<imprime.at(i).cantidadMoneda<<" ";
        cout<<"Valor de moneda " <<imprime.at(i).valorMoneda<<" ";
        cout<<endl;
    }
}
        /* Metodo utilizado para ordenar las monedas que se tienen de mayor a menor .
         * @param monedas: Vector que contiene el valor de las monedas que tiene el sistema monetario (apuntador a un vector).  
         */
void ordenarMonedas(vector <int> * monedas)
{
    //Creacion de variable auxiliar para poder guardar de manera temporal un valor en caso de ser necesario.
    int aux;
    //Implementación del método burbuja para ordenar de mayor a menor 
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
         /* Metodo utilizado para encontrar la cantidad de monedas que se van a regresar y el valor de las mismas.
         * @param monedas: Vector que contiene el valor de las monedas que tiene el sistema monetario . 
         * @param cantidad: Valor que se utilizará para encontrar eel número de monedas que se deben regresar.   
         */
void regresarCambio(vector <int> monedas,int cantidad)
{
    vector<Solucion> cambio;
    Solucion aux;
    int total = 0, i=0,contMon = 0;
    //ciclo para validar si se llegó al valor del cambio y avanzar en el vector de monedas
    while(total<cantidad && i<monedas.size())
    {
        //verifica si se puede utilizar la misma moneda más de una vez
       while((total + monedas.at(i))<=cantidad)
       {
           total+=monedas.at(i);
           contMon++;
       }
      if(contMon !=0)
      {
          //se crea un auxiliar con el número de monedas y la cantidad de la moneda para ser insertado en el vector de solución
          aux.cantidadMoneda = contMon;
          aux.valorMoneda = monedas.at(i);
          cambio.push_back(aux);
      }
       i++;
       contMon = 0;           
    }
    //Se llama al método que desplegará la respuesta
    printSolucion(cambio);
}
int main ()
{
    //se llena el vector donde se almacenan las monedas que se tienen en el sistema monetario
    vector <int> monedas;
    monedas.push_back(1);
    monedas.push_back(11);
    monedas.push_back(25);
    monedas.push_back(5);
    monedas.push_back(50);
    //Se llama al metódo de ordanare para obtener la mejor respuesta posible 
    ordenarMonedas(&monedas);
    //Se llama al método que desplegará la respuesta
    regresarCambio(monedas,15);
    return 0;
}