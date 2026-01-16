*Este proyecto ha sido creado como parte del currículum de 42 por <rcamps-v>.*

# Push\_swap

## Descripción
**Push_swap** es un proyecto de algoritmia de la escuela 42 que tiene como objetivo ordenar un conjunto de datos en una pila, utilizando un conjunto limitado de instrucciones y el menor número posible de movimientos. 

El reto principal consiste en manipular dos pilas (`stack a` y `stack b`) mediante operaciones específicas para lograr que todos los números introducidos como argumentos queden ordenados de menor a mayor en la pila A. Este proyecto permite profundizar en la complejidad algorítmica y la optimización de recursos en C.

## Instrucciones

### Compilación
El proyecto incluye un `Makefile` compatible con las reglas estándar. Para compilar el programa, ejecuta:
```bash
make
```
### Ejecución
Para iniciar el programa, pasa una lista de números enteros como argumentos:
```bash
./push_swap 2 1 3 6 5 8
```
También puedes utilizar una variable para manejar listas más largas:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG
```
### Operaciones permitidas
El programa utiliza las siguientes instrucciones para manipular las pilas:

- `sa`, `sb`, `ss`: Intercambia los dos primeros elementos de las pilas.

- `pa`, `pb`: Pasa el primer elemento de una pila a la otra.

- `ra`, `rb`, `rr`: Desplaza hacia arriba todos los elementos de la pila (rotación).

- `rra`, `rrb`, `rrr`: Desplaza hacia abajo todos los elementos de la pila (rotación inversa).

El programa devolvera la combinacion de movimientos mas corta que ha encontrado para ordenar los numeros searados por saltos de linea.
## Recursos
### Referencias técnicas
- **Algoritmo Radix:** Implementado para gestionar grandes volúmenes de datos (100 y 500 números) mediante la comparación de bits.
- **Listas Enlazadas:** Uso de estructuras dinámicas para representar las pilas de forma eficiente.
- **Valgrind Memcheck:** Herramienta fundamental utilizada durante el desarrollo para garantizar la ausencia de fugas de memoria y errores de acceso.
### Uso de IA
En el desarrollo de este proyecto se ha utilizado Inteligencia Artificial para las siguientes tareas:
- **Documentación:** entendimiento del Algoritmo Radix y su implementación en el proyecto.
- **Depuración de memoria:** Análisis de trazas de Valgrind para identificar fugas en las funciones de parsing y limpieza de nodos.
