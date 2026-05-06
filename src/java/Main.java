import java.util.LinkedList;
import java.util.Queue;
// Clase que representa cada nodo del árbol
class Nodo {
    int dato;      // Valor almacenado en el nodo
    Nodo izquierda;// Referencia al hijo izquierdo
    Nodo derecha;  // Referencia al hijo derecho

    // Constructor: inicializa el nodo con un valor y sin hijos
    public Nodo(int dato) {
        this.dato = dato;
        this.izquierda = null;
        this.derecha = null;
    }
}

public class Main {
    // Recorrido Preorden: Raíz → Izquierda → Derecha
    public static void preorden(Nodo raiz) {
        if (raiz == null) return;
        System.out.print(raiz.dato + " ");// Visita la raíz primero
        preorden(raiz.izquierda);   // Recorre subárbol izquierdo
        preorden(raiz.derecha); // Recorre subárbol derecho
    }
    // Recorrido Inorden: Izquierda → Raíz → Derecha
    // Produce los valores en orden ascendente en un BST
    public static void inorden(Nodo raiz) {
        if (raiz == null) return;
        inorden(raiz.izquierda);    // Recorre subárbol izquierdo
        System.out.print(raiz.dato + " ");   // Visita la raíz al centro
        inorden(raiz.derecha);     // Recorre subárbol derecho
    }
    // Recorrido Postorden: Izquierda → Derecha → Raíz
    // Útil para eliminar nodos o procesar hijos antes que el padre
    public static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierda); // Recorre subárbol izquierdo
        postorden(raiz.derecha);// Recorre subárbol derecho
        System.out.print(raiz.dato + " ");// Visita la raíz al final
    }
    // Recorrido BFS: nivel por nivel usando una cola
    // Visita todos los nodos de un nivel antes de pasar al siguiente
    public static void bfs(Nodo raiz) {
        if (raiz == null) return;

        Queue<Nodo> cola = new LinkedList<>();// Cola para nodos pendientes
        cola.add(raiz);

        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();  // Toma el primer nodo
            System.out.print(actual.dato + " ");

         // Agrega los hijos a la cola si existen
            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }

    public static void main(String[] args) {
        // Construcción del árbol base
        //         10
        //        /  \
        //       5    15
        //      / \   / \
        //     2   7 12  20
        Nodo raiz = new Nodo(10);
        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);
        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);

        // Nodos nuevos agregados - ejercicio 2
        //         10
        //        /  \
        //       5    15
        //      / \   / \
        //     2   7 12  20
        //    / \  \    /  \
        //   1   3  8  18   25

        raiz.izquierda.izquierda.izquierda = new Nodo(1);  // hijo izq de 2
        raiz.izquierda.izquierda.derecha = new Nodo(3);    // hijo der de 2
        raiz.izquierda.derecha.derecha = new Nodo(8);      // hijo der de 7
        raiz.derecha.derecha.izquierda = new Nodo(18);     // hijo izq de 20
        raiz.derecha.derecha.derecha = new Nodo(25);       // hijo der de 20

        System.out.println("RECORRIDOS DE ARBOLES BINARIOS - UTA JAVA");
         // Ejecutar y mostrar los 4 recorridos
        System.out.print("Preorden: ");
        preorden(raiz);

        System.out.print("\nInorden: ");
        inorden(raiz);

        System.out.print("\nPostorden: ");
        postorden(raiz);

        System.out.print("\nBFS: ");
        bfs(raiz);

        System.out.println();
    }
}
