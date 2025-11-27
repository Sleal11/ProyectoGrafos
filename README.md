REALIZADO POR:
SANTIAGO LEAL — CÉDULA 32.741.894

PROYECTO DE GRAFOS
Mini librería para la gestión, carga y recorrido de grafos utilizando diferentes algoritmos fundamentales de teoría de grafos.

DESCRIPCIÓN
Este proyecto implementa una mini librería en C++ que permite trabajar con grafos de forma rápida y sencilla. El sistema está diseñado para cargar grafos desde un archivo CSV, representarlos mediante listas de adyacencia y ejecutar algoritmos clásicos de recorrido y búsqueda de caminos.
El programa incluye:

Carga automática de un grafo desde un archivo .csv

Representación interna mediante listas de adyacencia sin usar vectores

Ejecución de distintos algoritmos de recorrido

Obtención de caminos mínimos usando Dijkstra

Visualización de los resultados directamente al ejecutar el programa

FUNCIONES IMPLEMENTADAS

Recorrido en Anchura (BFS)
Este algoritmo recorre el grafo nivel por nivel iniciando desde un nodo origen. Es útil para verificar conectividad, encontrar caminos mínimos en grafos no ponderados y explorar los nodos en capas.

Recorrido en Profundidad (DFS)
DFS explora el grafo de manera profunda, avanzando lo más lejos posible antes de retroceder. Es útil para detectar componentes conectados, ciclos y explorar estructuras profundas.

Algoritmo de Camino Más Corto (Dijkstra)
Este algoritmo calcula la distancia mínima desde un nodo origen hacia todos los demás nodos del grafo, considerando pesos positivos. El proyecto muestra las distancias finales para cada nodo.

ESTRUCTURA DEL ARCHIVO CSV
El archivo CSV utilizado para cargar el grafo contiene la siguiente estructura en cada línea:

nodo_origen, nodo_destino, peso

Por ejemplo:
0,1,4
0,2,2
1,2,1

El significado de cada valor es:

El primer número representa el nodo origen

El segundo número representa el nodo destino

El tercer número representa el peso de la arista entre ambos

El grafo se interpreta como no dirigido, por lo que cada conexión se agrega en ambas direcciones.

COMPILACIÓN DEL PROYECTO

Una vez que los archivos están organizados en las carpetas correspondientes (include, src, data), el proyecto puede compilarse desde la terminal.
Dentro de la carpeta principal del proyecto, el comando a usar es:

g++ -std=c++11 main.cpp src/grafo.cpp -I include -o grafos

Esto generará el ejecutable llamado “grafos”.

EJECUCIÓN DEL PROYECTO

Para ejecutar el programa, primero asegurarse de que el archivo grafos.csv se encuentra dentro de la carpeta “data”. Luego, simplemente se usa:

./grafos

Al ejecutar, el programa cargará el archivo CSV automáticamente y mostrará:

Recorrido BFS desde el nodo 0

Recorrido DFS desde el nodo 0

Tabla de distancias calculadas por Dijkstra

Todo esto se imprime sin necesidad de un menú interactivo.

OBJETIVO DEL PROYECTO
El propósito del trabajo es aplicar los conocimientos de grafos para implementar una librería sencilla pero funcional, capaz de realizar operaciones básicas y algoritmos de recorrido necesarios para comprender la estructura y funcionamiento de redes y grafos ponderados.
