#include <iostream>
#include "SimpleList.cpp"

using namespace std;

int main() {
    SimpleList<int> list;

    cout << "La lista esta vacia? " << list.isEmpty() << endl;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.show();

    cout << "Elementos de la lista: " << list.size() << endl;

    cout << "Elemento en la posicion 2: " << list.get(2) << endl;

    cout << "Eliminando el valor 20:" << endl;
    list.remove(20);
    list.show();

    list.insertAt(2, 45);
    list.show();
    
    list.removeAt(1);
    list.show();

    return 0;
}
