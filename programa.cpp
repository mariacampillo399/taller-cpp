#include <iostream>
#include <string>
using namespace std;

struct Equipo {
    string nombre;
    int partidosJugados;
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;
    int puntos;
};

int totalEquipos = 16;

// 🔹 Reconstruir datos
void reconstruirDatos(Equipo equipos[]) {
    for (int i = 0; i < totalEquipos; i++) {
        equipos[i].partidosEmpatados = equipos[i].puntos - (3 * equipos[i].partidosGanados);
        equipos[i].partidosPerdidos = equipos[i].partidosJugados - equipos[i].partidosGanados - equipos[i].partidosEmpatados;
    }
}

// 🔹 Mostrar tabla
void mostrarTabla(Equipo equipos[]) {
    cout << "\nNombre\t\tPJ\tPG\tPE\tPP\tPts\n";
    for (int i = 0; i < totalEquipos; i++) {
        cout << equipos[i].nombre << "\t"
             << equipos[i].partidosJugados << "\t"
             << equipos[i].partidosGanados << "\t"
             << equipos[i].partidosEmpatados << "\t"
             << equipos[i].partidosPerdidos << "\t"
             << equipos[i].puntos << endl;
    }
}

// 🔹 Ordenar mayor a menor
void ordenarMayor(Equipo equipos[]) {
    for (int i = 0; i < totalEquipos - 1; i++) {
        for (int j = 0; j < totalEquipos - i - 1; j++) {
            if (equipos[j].puntos < equipos[j + 1].puntos) {
                swap(equipos[j], equipos[j + 1]);
            }
        }
    }
}

// 🔹 Ordenar menor a mayor
void ordenarMenor(Equipo equipos[]) {
    for (int i = 0; i < totalEquipos - 1; i++) {
        for (int j = 0; j < totalEquipos - i - 1; j++) {
            if (equipos[j].puntos > equipos[j + 1].puntos) {
                swap(equipos[j], equipos[j + 1]);
            }
        }
    }
}

// 🔹 Mostrar TODOS los equipos con más empates
void masEmpates(Equipo equipos[]) {
    int maxEmpates = equipos[0].partidosEmpatados;

    for (int i = 1; i < totalEquipos; i++) {
        if (equipos[i].partidosEmpatados > maxEmpates) {
            maxEmpates = equipos[i].partidosEmpatados;
        }
    }

    cout << "\nEquipo(s) con más empates (" << maxEmpates << "):\n";

    for (int i = 0; i < totalEquipos; i++) {
        if (equipos[i].partidosEmpatados == maxEmpates) {
            cout << "- " << equipos[i].nombre << endl;
        }
    }
}

// 🔹 Buscar equipo
void buscarEquipo(Equipo equipos[]) {
    string nombre;
    cout << "Ingrese nombre del equipo: ";
    cin.ignore();
    getline(cin, nombre);

    for (int i = 0; i < totalEquipos; i++) {
        if (equipos[i].nombre == nombre) {
            cout << "\nNombre: " << equipos[i].nombre << endl;
            cout << "PJ: " << equipos[i].partidosJugados << endl;
            cout << "PG: " << equipos[i].partidosGanados << endl;
            cout << "PE: " << equipos[i].partidosEmpatados << endl;
            cout << "PP: " << equipos[i].partidosPerdidos << endl;
            cout << "Puntos: " << equipos[i].puntos << endl;
            return;
        }
    }

    cout << "Equipo no encontrado\n";
}

// 🔹 Validar datos
bool validar(Equipo e) {
    if (e.puntos != (3 * e.partidosGanados + e.partidosEmpatados)) return false;
    if (e.partidosJugados != (e.partidosGanados + e.partidosEmpatados + e.partidosPerdidos)) return false;
    return true;
}

// 🔹 Agregar equipo
void agregarEquipo(Equipo equipos[]) {
    if (totalEquipos >= 20) {
        cout << "No se pueden agregar más equipos\n";
        return;
    }

    Equipo nuevo;

    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);

    cout << "PJ: "; cin >> nuevo.partidosJugados;
    cout << "PG: "; cin >> nuevo.partidosGanados;
    cout << "PE: "; cin >> nuevo.partidosEmpatados;
    cout << "PP: "; cin >> nuevo.partidosPerdidos;
    cout << "Puntos: "; cin >> nuevo.puntos;

    if (!validar(nuevo)) {
        cout << "ERROR: Datos inconsistentes\n";
        return;
    }

    equipos[totalEquipos] = nuevo;
    totalEquipos++;
    cout << "Equipo agregado correctamente\n";
}

// 🔹 MAIN
int main() {

    Equipo equipos[20] = {
        {"Andrómeda FC",12,4,0,0,13},
        {"Vulcano Academia",11,2,0,0,10},
        {"Orión Confederación",11,4,0,0,14},
        {"Sirio Estrellas",10,6,0,0,20},
        {"Caronte Titanes",11,1,0,0,6},
        {"Quíron Cometas",10,5,0,0,17},
        {"Pegaso Púlsares",11,7,0,0,24},
        {"Osos Cósmicos",11,5,0,0,18},
        {"Vía Láctea Nómadas",11,6,0,0,20},
        {"Leónidas FC",11,5,0,0,16},
        {"Cangrejo Fortaleza",11,4,0,0,16},
        {"Cefeo Cúmulo",11,3,0,0,14},
        {"Atlético Interestelar",11,4,0,0,16},
        {"Deportivo Galáctico",11,2,0,0,8},
        {"Estrella Estelar",11,5,0,0,17},
        {"Inter Galaxia",10,2,0,0,10}
    };

    reconstruirDatos(equipos);

    int opcion;

    do {
        cout << "\n1. Tabla mayor a menor\n";
        cout << "2. Tabla menor a mayor\n";
        cout << "3. Equipo(s) con más empates\n";
        cout << "4. Buscar equipo\n";
        cout << "5. Agregar equipo\n";
        cout << "0. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ordenarMayor(equipos);
                mostrarTabla(equipos);
                break;
            case 2:
                ordenarMenor(equipos);
                mostrarTabla(equipos);
                break;
            case 3:
                masEmpates(equipos);
                break;
            case 4:
                buscarEquipo(equipos);
                break;
            case 5:
                agregarEquipo(equipos);
                break;
        }

    } while (opcion != 0);

    return 0;
}