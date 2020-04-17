# Tarea *[Poner aquí el número de la tarea]*. *[Poner aquí el título de la tarea]*

---

##### Integrantes:
1. Luis Emilio Alcantara Guzman - A01027304 - Campus Santa FE


---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución
Problema 4

El problema número 4 nos plantea lo siguiente: Suponiendo que el sistema monetario de un país está formado por monedas de valores v1,v2,...,vn, el problema del cambio de dinero consiste en descomponer cualquier cantidad dada M en monedas de ese país utilizando el menor número posible de monedas. Este problema se implemento con un algoritmo ávido.

Dentro del programa se tiene una estructura llamada “solución”, el cual tiene 2 atributos: cantidadMoneda y ValorMoneda. Esta estructura es utilizada para poder almacenar la solución. 
Al inicio del programa se necesita llamar a un método auxiliar (OrdenarMonedas) el cual ordenará las monedas de mayor a menor en base al valor que tiene la moneda. Una vez realizado este método se pasa al método principal.
El método principal del programa es regresarCambio, este recibe la cantidad que tienes que devolver en cambio y un vector que contiene los valores de cada moneda. Dentro del método se realiza un ciclo que recorrerá las monedas que se tienen en el vector siempre y cuando la cantidad que se debe devolver no se haya alcanzado. En cada iteración se verifica si la moneda en la posición actual del vector puede ser utilizada para formar la cantidad del cambio y si se puede utilizar más de una vez, en caso de poderse se aumenta un contador; si se agregó la moneda se crea una variable auxiliar donde se tendrá el valor de la moneda y el número de veces que se utilizó la misma. Al finalizar estas operaciones se aumenta la posición del vector y se asigna el contador de la siguiente moneda en 0.
Al finalizar el ciclo se llamará a un método auxiliar llamado printSolucion en el cual se imprimirá el vector solución que se creó en el método anterior.

La complejidad del algoritmo principal es O(n), dado que se encuentra en un ciclo (while), el cual va a recorrer n elementos en el peor de los casos, siendo “n” el número de monedas que se tienen en el sistema monetario. Todas las operaciones que se encuentran dentro del ciclo son de complejidad constante, esto hace que el algoritmo no tenga un aumento en la complejidad.

Problema 7

El problema número 7 nos plantea lo siguiente: Dada una secuencia de palabras p1, p2, ..., pn de longitudes l1, l2, ..., ln se desea agruparlas en líneas de longitud L. Las palabras están separadas por espacios cuya amplitud ideal (en milímetros) es b, pero los espacios pueden reducirse o ampliarse si es necesario (aunque sin solapamiento de palabras), de tal forma que una línea pi, pi+1, ..., pj tenga exactamente longitud L. Sin embargo, existe una penalización por reducción o ampliación en el número total de espacios que aparecen o desaparecen. El costo de fijar la línea pi, pi+1, ..., pj es (j – i)|b’ – b|, siendo b’ el ancho real de los espacios, es decir (L – li – li+1 – ... – lj)/(j – i). No obstante, si j = n (la última palabra) el costo será cero a menos que b’ < b (ya que no es necesario ampliar la última línea). Este problema se implementó con un algoritmo ávido.

El método que se utiliza para obtener la solución es “solucionParrafo”  el cual recibe 3 argumentos: longitud, espacio y un vector que contiene la longitud de cada palabra. Al inicio del método se declaran variables auxiliares utilizadas para mantener un control de cuanto espacio tiene la línea actual, el número de líneas que se han utilizado y el que coste que ha tenido la línea.
Se utiliza un ciclo (while) que va a recorrer todas las palabras que se tienen en el vector, dentro de este ciclo se verificará si la palabra cabe en la línea actual; en caso de que esta quepa se agregará a la línea y se aumentará una variable para que verifique en las siguientes iteraciones si la palabra cabe aún en la línea actual o si se tiene que cerrar esa línea e iniciar una nueva. En caso de que la palabra que se está verificando sea la última, se cerrará la línea dado que no hay otro elemento que se pueda agregar.  En caso de que la palabra que se está revisando no se pueda insertar en la línea actual, se cerrará la línea y se hará el cálculo de cuantos espacios se tuvieron que aumentar para que la línea se quedara en la longitud deseada.

Este algoritmo tiene complejidad O(n) dado que el bucle solo se repite el número de palabras que se tienen, las operaciones dentro del ciclo no afectan la complejidad dado que cada una tiene complejidad constante, manteniendo la complejidad del algoritmo.


### 2.1 Pasos a seguir para utilizar la aplicación

1.	Clonar repositorio

    Lo primero que se debe de hacer para poder probar las soluciones es clonar el repositorio de GitHub, para esto debes entrar a la        terminar y posicionarte en la carpeta donde deseas que se copie el repositorio. 
	Una vez dentro de esta ejecuta el siguiente comando:
	git clone https://github.com/tec-csf/tc2017-t3-primavera-2020-NotEmilioAG99.git
    
	Al finalizar este comando deberás cambiar de directorio utilizando el comando:
	cd tc2017-t3-primavera-2020-NotEmilioAG99/Sources
    
2.	Compilar el programa

    Una vez realizados los comandos anteriores deberás compilar los programas, para esto debes utilizar el comando:
	g++ ProblemaCambio.cpp -o p4
    
	ó
    
	g++ Problema7.cpp -o p4
    
	El comando a utilizar depende del programa que se desea compilar.
3.	Ejecutar el programa
    
    Para ejecutar el programa y ver su funcionamiento deberás escribir:

    ./p4 
    
    ó
    
    ./p7 
    
    Esto depende del programa que se desea ejecutar.



## 3. Referencias

Guerequeta, R., & Vallecillo, A. (2020). Tecnicas de diseño de algoritmos [Ebook] (2nd ed.). Málaga: Servicio de Publicaciones de la Universidad de Málaga. Recuperado de http://www.lcc.uma.es/~av/Libro/
