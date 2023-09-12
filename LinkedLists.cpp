// Colas (Queues).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <limits> 
using namespace std;

/*
    Hola bienvenido a este programa!
    En este podran ver un ejemplo de la estructura de datos llamada Lista o LinkedList
    la misma funciona con un sistema donde los elementos que van entrando son organizados de forma ascendente.
    La misma puede realizar las operaciones Insertar, para agregar numeros a la Lista y Eliminar para eliminar un numero especifico
    de la misma, incluyendo las demas coincidencias del mismo numero.
    A esto se le agrega la capacidad de buscar un elemento en especifico y que muestre la posicion de la primera instancia del mismo.

    Integrantes:
        1116783-Whisman Lorenzo
        1116842-Jose Reyes
        1105307-Jose Sol
        1114056-Jose Florentino
        1116176-Manuel Guzman
        1115997-Winston Pichardo
        1087257-Jorge Jimenez

        Fecha: 12/9/2023
*/

struct LinkedList {
    int data;
    LinkedList* siguiente;
};

LinkedList* lista = nullptr;

bool estaVacia() {
    // Comprueba si el puntero "lista" apunta a nullptr, lo que indica que la lista está vacía.
    return lista == nullptr; // Retorna true si lista está vacía y false si tiene un elemento.
}

void insertar(int value) {
    LinkedList* newNodo = new LinkedList;
    newNodo->data = value;
    newNodo->siguiente = nullptr;

    if (lista == nullptr || value < lista->data) {
        newNodo->siguiente = lista;
        lista = newNodo;
    }
    else {
        LinkedList* actual = lista;
        while (actual->siguiente != nullptr && actual->siguiente->data < value) {
            actual = actual->siguiente;
        }
        newNodo->siguiente = actual->siguiente;
        actual->siguiente = newNodo;
    }
    cout << "\nNodo de valor " << value << " insertado correctamente." << endl;
}

void buscar(int value) {
    int contador = 0;
    LinkedList* aux = lista;
    while (aux != nullptr) {
        if (aux->data == value) {
            cout << "\nEl valor " << value << " fue encontrado en la lista, en la posicion " << contador << "." << endl;
            return;
        }
        aux = aux->siguiente;
        contador++;
    }
    cout << "\nEl valor " << value << " no fue encontrado en la lista." << endl;
}

void eliminar(int value) {
    if (!estaVacia()) {

        int contador = 0;

        while (true)
        {
            LinkedList* temp;
            LinkedList* anterior = nullptr;

            temp = lista;

            while (temp != nullptr && temp->data != value) {
                anterior = temp;
                temp = temp->siguiente;
            }
            if (temp == nullptr && contador != 0) {
                break;
            }
            else if (temp == nullptr && contador == 0) {
                cout << "\nNo se encontro el valor " << value << " en la lista." << endl;
                break;
            }
            else if (anterior == nullptr) {
                lista = lista->siguiente;
                delete temp;
                contador++;
            }
            else {
                anterior->siguiente = temp->siguiente;
                delete temp;
                contador++;
            }
        }
        if (contador != 0) {
            cout << "\nSe elimino " << contador << " instancia/s del numero " << value << "." << endl;
        }
    }    
    else {
        return;
    }   
}

void display() {
    if (estaVacia()) {
        cout << "\nLa lista está vacía." << endl;
        return;
    }

    LinkedList* actual = lista;
    cout << "\nLista Enlazada: ";
    while (actual != nullptr) {
        cout << actual->data;
        if (actual->siguiente != nullptr) {
            cout << ", ";
        }
        else {
            cout << ".";
        }
        actual = actual->siguiente;
    }
    cout << std::endl;
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
        cout << "\nEntrada inválida: ";
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
    locale::global(locale("en_US.UTF-8"));

    int opcion;

    while (true) {
        cout << "**********************" << endl;
        cout << "\tMenú:\t\n";
        cout << "**********************" << endl;

        cout << "1. Insertar\n";
        cout << "2. Buscar\n";
        cout << "3. Eliminar\n";
        cout << "4. Mostrar Lista\n";
        cout << "5. Salir\n";
        cout << "**********************" << endl;
        cout << "\nIngrese una opción: ";
        opcion = obtener_valido();

        switch (opcion) {
        case 1: {
            int valor;
            cout << "\nIngrese el valor a insertar: ";
            valor = obtener_valido();
            insertar(valor);
            cls();
            break;
        }
        case 2: {
            int valor;
            if (estaVacia())
            {
                cout << "La lista esta vacia.\n" << endl;
                cls();
                break;
            }
            cout << "Ingrese el valor a buscar: ";
            valor = obtener_valido();
            buscar(valor);
            cls();
            break;
        }
        case 3: {
            int valor;
            if (estaVacia())
            {
                cout << "La lista esta vacia.\n" << endl;
                cls();
                break;
            }
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
            cout << "\nOpción no válida. Intente de nuevo.\n" << endl;
            cls();
        }
    }

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
