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

void Grafo::recorridoProfundidadRecursivo(int nodo, bool* visitado) {
    visitado[nodo] = true;
    cout << nodo << " ";

    for (NodoLista* aux = listaAdyacencia[nodo]; aux; aux = aux->siguiente) {
        if (!visitado[aux->destino])
            recorridoProfundidadRecursivo(aux->destino, visitado);
    }
}

void Grafo::recorridoProfundidad(int inicio) {
    bool* visitado = new bool[cantidadNodos];
    for (int i = 0; i < cantidadNodos; i++) visitado[i] = false;

    recorridoProfundidadRecursivo(inicio, visitado);
    cout << "\n";

    delete[] visitado;
}

void Grafo::caminoMasCorto(int inicio) {
    int* distancia = new int[cantidadNodos];
    bool* visitado = new bool[cantidadNodos];

    for (int i = 0; i < cantidadNodos; i++) {
        distancia[i] = numeric_limits<int>::max();
        visitado[i] = false;
    }

    distancia[inicio] = 0;

    for (int k = 0; k < cantidadNodos; k++) {
        int nodoActual = -1;
        int mejorDistancia = numeric_limits<int>::max();

        for (int i = 0; i < cantidadNodos; i++) {
            if (!visitado[i] && distancia[i] < mejorDistancia) {
                mejorDistancia = distancia[i];
                nodoActual = i;
            }
        }

        if (nodoActual == -1) break;
        visitado[nodoActual] = true;

        for (NodoLista* aux = listaAdyacencia[nodoActual]; aux; aux = aux->siguiente) {
            if (distancia[nodoActual] != numeric_limits<int>::max() && distancia[nodoActual] + aux->peso < distancia[aux->destino])
                distancia[aux->destino] = distancia[nodoActual] + aux->peso;
        }
    }

    for (int i = 0; i < cantidadNodos; i++)
        cout << "Distancia a " << i << ": " << distancia[i] << "\n";

    delete[] distancia;
    delete[] visitado;
}
