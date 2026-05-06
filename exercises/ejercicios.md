# Ejercicios para clase

## Ejercicio 1
Dado el árbol:

```text
        10
       /  \
      5    15
     / \   / \
    2   7 12 20
```

Escriba manualmente:

- Preorden : 10, 5, 2, 7, 15, 12, 20
- Inorden : 2, 5, 7, 10, 12, 15, 20
- Postorden : 2, 7, 5, 12, 20, 15, 10
- BFS : 10, 5, 15, 2, 7, 12, 20

## Ejercicio 2
Modifique el árbol anterior agregando los nodos 1, 3, 18 y 25. Ejecute nuevamente los recorridos.

```text
            10
           /  \
          5    15
         / \   / \
        2   7 12  20
       / \       /  \
      1   3     18   25
```

- Preorden : 10, 5, 2, 1, 3, 7, 15, 12, 20, 18, 25
- Inorden : 1, 2, 3, 5, 7, 10, 12, 15, 18, 20, 25
- Postorden : 1, 3, 2, 7, 5, 12, 18, 25, 20, 15, 10
- BFS : 10, 5, 15, 2, 7, 12, 20, 1, 3, 18, 25


## Ejercicio 3
Implemente una función que cuente la cantidad total de nodos del árbol.

En C++
```text
    int contarNodos(Nodo* raiz) {
        if (raiz == nullptr)
         return 0;

        return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
    }
```
En Java
```text
    public static int contarNodos(Nodo raiz) {
    if (raiz == null) 
    return 0;

    return 1 + contarNodos(raiz.izquierda) + contarNodos(raiz.derecha);
    }
```
Si el nodo es nulo retorna 0. Si no, cuenta 1 (el nodo actual) más todos los nodos del subárbol izquierdo y derecho recursivamente. Con el árbol del ejercicio 1 retorna 7.

## Ejercicio 4
Implemente una función que cuente las hojas del árbol.
En C++
```text
    int contarHojas(Nodo* raiz) {
    if (raiz == nullptr) 
    return 0;

    if (raiz->izquierda == nullptr && raiz->derecha == nullptr) 
    return 1;

    return contarHojas(raiz->izquierda) + contarHojas(raiz->derecha);
    }
```
En Java
```text
    public static int contarHojas(Nodo raiz) {
    if (raiz == null) 
    return 0;

    if (raiz.izquierda == null && raiz.derecha == null) 
    return 1;

    return contarHojas(raiz.izquierda) + contarHojas(raiz.derecha);
    }
```
Si el nodo es nulo retorna 0. Si el nodo no tiene hijos izquierdo ni derecho es una hoja y retorna 1. De lo contrario suma las hojas del subárbol izquierdo y derecho.

## Ejercicio 5 aplicado al proyecto final
Represente los módulos de un sistema web como un árbol binario. Ejemplo:

```text
            Sistema Web
           /           \
     Usuarios        Inventario
      /    \          /      \
 Registrar Buscar  Productos Reportes
```

Explique qué recorrido usaría para:

1. Mostrar el menú principal.
   Preorden porque visita primero la raíz antes que los submenús
2. Procesar primero los módulos internos.
   Postorden porque procesa primero los hijos antes que el padre
3. Mostrar módulos nivel por nivel.
   BFS porque recorre el árbol nivel a nivel usando una cola
