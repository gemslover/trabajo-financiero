#include <iostream>
#include <cmath> // Para las funciones matemáticas
using namespace std;

// Función para calcular el interés simple
double interesSimple(double principal, double tasa, double tiempo) {
    return principal * tasa * tiempo;
}

// Función para calcular el interés compuesto
double interesCompuesto(double principal, double tasa, double tiempo, int capitalizaciones) {
    return principal * pow((1 + tasa / capitalizaciones), capitalizaciones * tiempo);
}

// Función para gradiente aritmético
double gradienteAritmetico(double gradiente, double tasa, int periodos) {
    double valorPresente = 0;
    for (int t = 1; t <= periodos; ++t) {
        valorPresente += gradiente * pow(1 + tasa, t) / pow(1 + tasa, periodos);
    }
    return valorPresente;   
}

// Función para calcular amortización
double amortizacion(double principal, double tasa, int periodos) {
    return (principal * tasa) / (1 - pow(1 + tasa, -periodos));
}

int main() {
    int opcion;
    cout << "Programa de Finanzas\n";
    cout << "1. Calcular Interés Simple\n";
    cout << "2. Calcular Interés Compuesto\n";
    cout << "3. Calcular Gradiente Aritmético\n";
    cout << "4. Calcular Amortización\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;

    double principal, tasa, tiempo, gradiente;
    int periodos, capitalizaciones;

    switch (opcion) {
        case 1:
            cout << "Interés Simple\n";
            cout << "Ingrese el capital inicial: ";
            cin >> principal;
            cout << "Ingrese la tasa de interés (decimal): ";
            cin >> tasa;
            cout << "Ingrese el tiempo en años: ";
            cin >> tiempo;
            cout << "El interés simple es: " << interesSimple(principal, tasa, tiempo) << endl;
            break;
        
        case 2:
            cout << "Interés Compuesto\n";
            cout << "Ingrese el capital inicial: ";
            cin >> principal;
            cout << "Ingrese la tasa de interés (decimal): ";
            cin >> tasa;
            cout << "Ingrese el tiempo en años: ";
            cin >> tiempo;
            cout << "Ingrese el número de capitalizaciones por año: ";
            cin >> capitalizaciones;
            cout << "El monto total es: " << interesCompuesto(principal, tasa, tiempo, capitalizaciones) << endl;
            break;

        case 3:
            cout << "Gradiente Aritmético\n";
            cout << "Ingrese el valor del gradiente: ";
            cin >> gradiente;
            cout << "Ingrese la tasa de interés (decimal): ";
            cin >> tasa;
            cout << "Ingrese el número de periodos: ";
            cin >> periodos;
            cout << "El valor presente es: " << gradienteAritmetico(gradiente, tasa, periodos) << endl;
            break;

        case 4:
            cout << "Amortización\n";
            cout << "Ingrese el capital inicial: ";
            cin >> principal;
            cout << "Ingrese la tasa de interés (decimal): ";
            cin >> tasa;
            cout << "Ingrese el número de pagos: ";
            cin >> periodos;
            cout << "El pago periódico es: " << amortizacion(principal, tasa, periodos) << endl;
            break;

        default:
            cout << "Opción no válida." << endl;
    }

    return 0;
}

