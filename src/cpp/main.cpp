#include <iostream> // Para usar cout
#include <queue> // Para usar la cola en BFS
using namespace std;

// Estructura que representa cada nodo del árbol
struct Nodo {
    int dato;       // Valor almacenado en el nodo
    Nodo* izquierda;// Puntero al hijo izquierdo
    Nodo* derecha; // Puntero al hijo derecho

// Constructor: inicializa el nodo con un valor y sin hijos
    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};
// Recorrido Preorden: Raíz → Izquierda → Derecha
void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " "; // Visita la raíz primero
    preorden(raiz->izquierda);// Recorre subárbol izquierdo
    preorden(raiz->derecha);  // Recorre subárbol derecho
}
// Recorrido Inorden: Izquierda → Raíz → Derecha
// Produce los valores en orden ascendente en un BST
void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierda);    // Recorre subárbol izquierdo
    cout << raiz->dato << " ";   // Visita la raíz al centro
    inorden(raiz->derecha);     // Recorre subárbol derecho
}
// Recorrido Postorden: Izquierda → Derecha → Raíz
// Útil para eliminar nodos o procesar hijos antes que el padre
void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);  // Recorre subárbol izquierdo
    postorden(raiz->derecha);    // Recorre subárbol derecho
    cout << raiz->dato << " ";   // Visita la raíz al final
}
// Recorrido BFS: nivel por nivel usando una cola
// Visita todos los nodos de un nivel antes de pasar al siguiente
void bfs(Nodo* raiz) {
    if (raiz == nullptr) return;

    queue<Nodo*> cola; // Cola para guardar nodos pendientes
    cola.push(raiz);  // Empieza por la raíz


    while (!cola.empty()) {
        Nodo* actual = cola.front(); // Toma el primer nodo de la cola
        cola.pop();                 // Lo elimina de la cola

        cout << actual->dato << " ";
        // Agrega los hijos a la cola si existen
        if (actual->izquierda != nullptr) cola.push(actual->izquierda);
        if (actual->derecha != nullptr) cola.push(actual->derecha);
    }
}

int main() {
    // Construcción del árbol base
    //         10
    //        /  \
    //       5    15
    //      / \   / \
    //     2   7 12  20
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha = new Nodo(7);
    raiz->derecha->izquierda = new Nodo(12);
    raiz->derecha->derecha = new Nodo(20);

    // Nodos nuevos agregados - ejercicio 2
    //         10
    //        /  \
    //       5    15
    //      / \   / \
    //     2   7 12  20
    //    / \  \    /  \
    //   1   3  8  18   25

    raiz->izquierda->izquierda->izquierda = new Nodo(1);  // hijo izq de 2
    raiz->izquierda->izquierda->derecha = new Nodo(3);    // hijo der de 2
    raiz->izquierda->derecha->derecha = new Nodo(8);      // hijo der de 7
    raiz->derecha->derecha->izquierda = new Nodo(18);     // hijo izq de 20
    raiz->derecha->derecha->derecha = new Nodo(25);       // hijo der de 20


    cout << "RECORRIDOS DE ARBOLES BINARIOS - UTA C++" << endl;
    // Ejecutar y mostrar los 4 recorridos
    cout << "Preorden: ";
    preorden(raiz);

    cout << "\nInorden: ";
    inorden(raiz);

    cout << "\nPostorden: ";
    postorden(raiz);

    cout << "\nBFS: ";
    bfs(raiz);

    cout << endl;
    return 0;
}
