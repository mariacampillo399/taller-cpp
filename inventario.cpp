#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ================= ESTRUCTURA =================

struct Producto {
    string codigo;
    string nombre;
    int cantidad;
};

// ================= FUNCIONES =================

// Mostrar menú
void mostrarMenu() {

    cout << "\n=====================================\n";
    cout << "        SISTEMA GADGETXPRESS\n";
    cout << "=====================================\n";
    cout << "1. Agregar producto\n";
    cout << "2. Listar productos\n";
    cout << "3. Actualizar cantidad\n";
    cout << "4. Reporte bajo inventario\n";
    cout << "5. Salir\n";
    cout << "=====================================\n";
    cout << "Seleccione una opcion: ";
}

// Buscar producto
int buscarProducto(vector<Producto>& inventario, string codigo) {

    for (int i = 0; i < inventario.size(); i++) {

        if (inventario[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

// Agregar producto
void agregarProducto(vector<Producto>& inventario) {

    Producto nuevo;

    cout << "\n=========== AGREGAR PRODUCTO ===========\n";

    cout << "Codigo del producto: ";
    cin >> nuevo.codigo;

    // Validar duplicados
    if (buscarProducto(inventario, nuevo.codigo) != -1) {

        cout << "ERROR: El producto ya existe.\n";
        return;
    }

    cin.ignore();

    cout << "Nombre del producto: ";
    getline(cin, nuevo.nombre);

    cout << "Cantidad disponible: ";
    cin >> nuevo.cantidad;

    inventario.push_back(nuevo);

    cout << "\nProducto agregado correctamente.\n";
}

// Listar productos
void listarProductos(vector<Producto>& inventario) {

    cout << "\n============== INVENTARIO ==============\n";

    if (inventario.empty()) {

        cout << "No hay productos registrados.\n";
        return;
    }

    cout << "CODIGO\tNOMBRE\t\tCANTIDAD\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < inventario.size(); i++) {

        cout << inventario[i].codigo << "\t"
             << inventario[i].nombre << "\t\t"
             << inventario[i].cantidad << endl;
    }

    cout << "----------------------------------------\n";
}

// Actualizar cantidad
void actualizarCantidad(vector<Producto>& inventario) {

    string codigo;
    int nuevaCantidad;

    cout << "\n========== ACTUALIZAR PRODUCTO ==========\n";

    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;

    int posicion = buscarProducto(inventario, codigo);

    if (posicion == -1) {

        cout << "Producto no encontrado.\n";
        return;
    }

    cout << "Nueva cantidad: ";
    cin >> nuevaCantidad;

    inventario[posicion].cantidad = nuevaCantidad;

    cout << "Cantidad actualizada correctamente.\n";
}

// Reporte bajo inventario
void reporteBajoInventario(vector<Producto>& inventario) {

    bool encontrados = false;

    cout << "\n============================================\n";
    cout << "         REPORTE BAJO INVENTARIO\n";
    cout << "============================================\n\n";

    cout << "CODIGO\tNOMBRE\t\tCANTIDAD\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < inventario.size(); i++) {

        if (inventario[i].cantidad < 5) {

            cout << inventario[i].codigo << "\t"
                 << inventario[i].nombre << "\t\t"
                 << inventario[i].cantidad << endl;

            encontrados = true;
        }
    }

    if (!encontrados) {

        cout << "Todos los productos tienen stock suficiente.\n";
    }

    cout << "============================================\n";
}

// ================= MAIN =================

int main() {

    vector<Producto> inventario;

    int opcion;

    do {

        mostrarMenu();
        cin >> opcion;

        switch (opcion) {

            case 1:
                agregarProducto(inventario);
                break;

            case 2:
                listarProductos(inventario);
                break;

            case 3:
                actualizarCantidad(inventario);
                break;

            case 4:
                reporteBajoInventario(inventario);
                break;

            case 5:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}