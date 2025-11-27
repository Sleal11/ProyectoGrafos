#include "grafo.hpp"
#include <iostream>
using namespace std;

int main() {
    int cantidadNodos = 10;
    Grafo g(cantidadNodos);

    // Cargar el grafo desde CSV fijo
    g.cargarDesdeCSV("data/grafos.csv");

    cout << "\n--- Recorrido en anchura (BFS) desde nodo 0 ---\n";
    g.recorridoAnchura(0);

    cout << "\n--- Recorrido en profundidad (DFS) desde nodo 0 ---\n";
    g.recorridoProfundidad(0);

    cout << "\n--- Camino más corto desde nodo 0 (Dijkstra) ---\n";
    g.caminoMasCorto(0);

    return 0;
}
