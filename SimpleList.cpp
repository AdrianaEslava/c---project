#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    
    Node() : data(), next(nullptr) {}
    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class SimpleList {
private:
    Node<T>* head;
    
public:
    SimpleList() : head(nullptr) {}
    
    ~SimpleList() {
        while (!isEmpty()) {
            removeAt(0);
        }
    }
    
    int size() {
        int count = 0;
        Node<T>* aux = head;
        while (aux) {
            count++;
            aux = aux->next;
        }
        return count;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }

    void add(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node<T>* aux = head;
            while (aux->next) {
                aux = aux->next;
            }
            aux->next = newNode;
        }
    }

    bool remove(T data) {
        if (isEmpty()) return false;
        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node<T>* aux = head;
        while (aux->next && aux->next->data != data) {
            aux = aux->next;
        }
        if (!aux->next) return false;
        Node<T>* temp = aux->next;
        aux->next = aux->next->next;
        delete temp;
        return true;
    }

    T get(int index) {
        if (index < 0 || index >= size()) throw out_of_range("Índice fuera de rango");
        Node<T>* aux = head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    void insertAt(int index, T data) {
        if (index < 0 || index > size()) throw out_of_range("Índice fuera de rango");
        Node<T>* newNode = new Node<T>(data);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node<T>* aux = head;
        for (int i = 0; i < index - 1; i++) {
            aux = aux->next;
        }
        newNode->next = aux->next;
        aux->next = newNode;
    }


    T removeAt(int index) {
        if (index < 0 || index >= size()) throw out_of_range("Índice fuera de rango");
        Node<T>* aux = head;
        if (index == 0) {
            head = head->next;
            T data = aux->data;
            delete aux;
            return data;
        }
        Node<T>* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = aux;
            aux = aux->next;
        }
        prev->next = aux->next;
        T data = aux->data;
        delete aux;
        return data;
    }

    void show() {
        Node<T>* aux = head;
        while (aux) {
            cout << aux->data << " -> ";
            aux = aux->next;
        }
        cout << "NULL" << endl;
    }
};