#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
using namespace std;

struct NodoLista {
    int destino;
    int peso;
    NodoLista* siguiente;
    NodoLista(int d, int p);
};

class Grafo {
private:
    int cantidadNodos;
    NodoLista** listaAdyacencia;

public:
    Grafo(int cantidad);
    ~Grafo();

    void agregarArista(int origen, int destino, int peso = 1);
    void recorridoAnchura(int inicio);
    void recorridoProfundidad(int inicio);
    void recorridoProfundidadRecursivo(int nodo, bool* visitado);
    void caminoMasCorto(int inicio);
    void cargarDesdeCSV(const char* archivoCSV);
};

#endif
