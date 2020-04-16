#include<iostream>
#include <vector>
using namespace std;

void solucionParrafo(int longitud, int espacio, vector<int> palabras)
{
    int palcurso = 0,longcurso =0,costeLinea,numLineas =1,costeTotal=0;
  
    while(palcurso<palabras.size())
    {
        if(palabras.at(palcurso)+longcurso<= longitud)
        {
            longcurso = palabras.at(palcurso)+longcurso + espacio;
            cout<<palabras.at(palcurso)<<" ";
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
           costeLinea = longitud - (longcurso - espacio);
           costeTotal+=costeLinea;
           cout<<"Coste de Linea "<<costeLinea<<endl;
           longcurso =0;
           numLineas++;
        } 
        
    }
    cout<<"Numero de Lineas "<<numLineas<<endl;
    cout<<"Coste total "<<costeTotal<<endl;
}
int main()
{
    vector <int> longitudPalabras;
    longitudPalabras.push_back(10);
    longitudPalabras.push_back(10);
    longitudPalabras.push_back(4);
    longitudPalabras.push_back(8);
    longitudPalabras.push_back(10);
    longitudPalabras.push_back(12);
    longitudPalabras.push_back(12); 
    solucionParrafo(26,2,longitudPalabras);

} 