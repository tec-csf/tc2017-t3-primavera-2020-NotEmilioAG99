#include<iostream>
#include <vector>
using namespace std;
        /* Metodo utilizado para agregar palabras en una linea dependiendo del tamaño de la palabra y la longitud de la linea.
         * @param longitud: Tamaño definido para cada linea. 
         * @param espacio: Espacio en mm que se debe dejar entre cada palabra en una linea.
         * @param palabras: Vector en el cual se encuentra la longitud de cada palabra que se desea agregar. 
         */
void solucionParrafo(int longitud, int espacio, vector<int> palabras)
{
    // se crean las variables que se utilizaran para saber el número de lineas que se uutilizaron, la longitud que tiene la linea y el coste de cada una
    int palcurso = 0,longcurso =0,costeLinea,numLineas =1,costeTotal=0;
   // se recorre el vector con la longitud de palabra para verificar si la palabra cabe o no en la linea
    while(palcurso<palabras.size())
    {
        //Se revisa si la palabra cabe de manera óptima en la linea 
        if(palabras.at(palcurso)+longcurso<= longitud)
        {
            longcurso = palabras.at(palcurso)+longcurso + espacio;
            cout<<palabras.at(palcurso)<<" ";
            // En caso de ser la última palabra se cierra la linea
            if(palcurso==palabras.size()-1)
            {
            costeLinea = longitud - (longcurso - espacio);
            costeTotal+=costeLinea;
            cout<<"Coste de Linea "<<costeLinea<<endl;
            }
            palcurso++;
        }
        else
        {
          // si no cabe la palabra en la linea, esta se cierra y se realiza el cáluclo del coste de la linea
           costeLinea = longitud - (longcurso - espacio);
           costeTotal+=costeLinea;
           cout<<"Coste de Linea "<<costeLinea<<endl;
           longcurso =0;
           numLineas++;
        } 
        
    }
    // se despliega la cantidad dde lineas que se utilizaron y el coste que tuvo el párrafo completo
    cout<<"Numero de Lineas "<<numLineas<<endl;
    cout<<"Coste total "<<costeTotal<<endl;
}
int main()
{
    //se llena el vector donde se encontrara la longitud de cada palabra
    vector <int> longitudPalabras;
    longitudPalabras.push_back(10);
    longitudPalabras.push_back(10);
    longitudPalabras.push_back(4);
    longitudPalabras.push_back(8);
    longitudPalabras.push_back(10);
    longitudPalabras.push_back(12);
    longitudPalabras.push_back(12); 
    //Se llama al método para que se despliegue la solución en base a la longitud de las palbras que se tienen, la longitud de linea y el espacio entre palabras.
    solucionParrafo(26,2,longitudPalabras);

} 