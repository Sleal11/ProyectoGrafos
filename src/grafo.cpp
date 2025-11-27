#include "grafo.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

// Constructor NodoLista
NodoLista::NodoLista(int d, int p) {
    destino = d;
    peso = p;
    siguiente = NULL;
}

// Constructor Grafo
Grafo::Grafo(int cantidad) {
    cantidadNodos = cantidad;
    listaAdyacencia = new NodoLista*[cantidadNodos];
    for (int i = 0; i < cantidadNodos; i++) listaAdyacencia[i] = NULL;
}

// Destructor Grafo
Grafo::~Grafo() {
    for (int i = 0; i < cantidadNodos; i++) {
        NodoLista* actual = listaAdyacencia[i];
        while (actual) {
            NodoLista* aux = actual;
            actual = actual->siguiente;
            delete aux;
        }
    }
    delete[] listaAdyacencia;
}

void Grafo::agregarArista(int origen, int destino, int peso) {
    NodoLista* nuevo = new NodoLista(destino, peso);
    nuevo->siguiente = listaAdyacencia[origen];
    listaAdyacencia[origen] = nuevo;
}

void Grafo::recorridoAnchura(int inicio) {
    bool* visitado = new bool[cantidadNodos];
    for (int i = 0; i < cantidadNodos; i++) visitado[i] = false;
    int* cola = new int[cantidadNodos];

    int primero = 0, ultimo = 0;
    visitado[inicio] = true;
    cola[ultimo++] = inicio;

    while (primero < ultimo) {
        int actual = cola[primero++];
        cout << actual << " ";

        for (NodoLista* aux = listaAdyacencia[actual]; aux; aux = aux->siguiente) {
            if (!visitado[aux->destino]) {
                visitado[aux->destino] = true;
                cola[ultimo++] = aux->destino;
            }
        }
    }
    cout << "\n";

    delete[] visitado;
    delete[] cola;
}
