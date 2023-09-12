/*
Integrantes:
Encabezado:
Fecha: 12/09/23
*/

#include <iostream>
#include <limits> 
using namespace std;

#include <iostream>

struct Nodo {
    int data;
    Nodo* siguiente;
};

Nodo* head = nullptr;

void insertar(int value) {
    Nodo* newNodo = new Nodo;
    newNodo->data = value;
    newNodo->siguiente = nullptr;

    if (head == nullptr || value < head->data) {
        newNodo->siguiente = head;
        head = newNodo;
    } else {
        Nodo* actual = head;
        while (actual->siguiente != nullptr && actual->siguiente->data < value) {
            actual = actual->siguiente;
        }
        newNodo->siguiente = actual->siguiente;
        actual->siguiente = newNodo;
    }
    cout << "Nodo insertado correctamente." << endl;
}

void buscar(int value) {
    Nodo* actual = head;
    while (actual != nullptr) {
        if (actual->data == value) {
            cout << "El valor " << value << " fue encontrado en la lista." << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "El valor " << value << " no fue encontrado en la lista." << endl;
}

bool estaVacia() {
    // Comprueba si el puntero "head" apunta a nullptr, lo que indica que la lista está vacía.
    return head == nullptr; // Retorna true si la lista está vacía.
}

void eliminar(int value) {
    if (estaVacia()) {
        cout << "La lista está vacía, no se puede eliminar nada." << endl;
        return;
    }

    if (head->data == value) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
        cout << "El valor " << value << " fue eliminado de la lista." << endl;
        return;
    }

    Nodo* actual = head;
    while (actual->siguiente != nullptr && actual->siguiente->data != value) {
        actual = actual->siguiente;
    }

    if (actual->siguiente != nullptr) {
        Nodo* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
        cout << "El valor " << value << " fue eliminado de la lista." << endl;
    } else {
        cout << "El valor " << value << " no se encuentra en la lista." << endl;
    }
}

void display() {
    if (estaVacia()) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo* actual = head;
    std::cout << "Lista Enlazada: ";
    while (actual != nullptr) {
        std::cout << actual->data;
        if (actual->siguiente != nullptr) {
            std::cout << ", ";
        } else {
            std::cout << ".";
        }
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

// Función para solicitar al usuario si desea continuar.
bool continuar() {
    cout << "¿Desea continuar? (S/N)\n";
    string ans;
    cin >> ans;
    for (char& c : ans) {
        c = tolower(c); // Convierte la respuesta del usuario a minúsculas.
    }
    if (ans != "s" && ans != "n") {
        do {
            cout << "Opción inválida.\n";
            cin >> ans; // Si la respuesta no es válida, solicita una nueva respuesta.
        } while (ans != "s" && ans != "n");
    }
    return ans == "s"; // Retorna true si la respuesta es "s", indicando continuar.
}

// Función para obtener una entrada válida del usuario.
int obtener_valido() {
    int number;
    while (!(cin >> number)) {
        cout << "Entrada inválida: " << endl;
        cin.clear(); // Limpia el estado de error del flujo de entrada.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada errónea.
    }
    return number;
}

// Función para limpiar la pantalla.
void cls() {
    if (continuar()) {
        cout << "Entendido" << endl;
        system("cls"); // Limpia la pantalla si el usuario desea continuar.
    }
    else {
        cin.ignore(); // Descarta cualquier entrada pendiente.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada errónea.
        exit(0); // Sale del programa.
    }
}

int main() {
    int opcion;

    while (true) {
        cout << "\nMenú:\n";
        cout << "1. Insertar\n";
        cout << "2. Buscar\n";
        cout << "3. Eliminar\n";
        cout << "4. Mostrar Lista\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opción: ";
        opcion = obtener_valido();

        switch (opcion) {
            case 1: {
                int valor;
                cout << "Ingrese el valor a insertar: ";
                valor = obtener_valido();
                insertar(valor);
                cls();
                break;
            }
            case 2: {
                int valor;
                cout << "Ingrese el valor a buscar: ";
                valor = obtener_valido();
                buscar(valor);
                cls();
                break;
            }
            case 3: {
                int valor;
                cout << "Ingrese el valor a eliminar: ";
                valor = obtener_valido();
                eliminar(valor);
                cls();
                break;
            }
            case 4:
                display();
                cls();
                break;
            case 5:
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
