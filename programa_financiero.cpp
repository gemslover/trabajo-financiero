#include <iostream>
#include <cmath>   
#include <iomanip>  

using namespace std;

// Función para calcular el interés simple
double interesSimple(double principal, double tasa, double tiempo) {
    tasa /= 100;  // Convertimos el porcentaje a decimal
    return principal * tasa * tiempo;
}

// Función para calcular el interés compuesto
double interesCompuesto(double principal, double tasa, double tiempo, int capitalizaciones) {
    tasa /= 100;  // Convertimos el porcentaje a decimal
    return principal * pow((1 + tasa / capitalizaciones), capitalizaciones * tiempo) - principal;
}

// Función para calcular el gradiente aritmético
double gradienteAritmetico(double flujoInicial, double incremento, double tasa, int periodos) {
    tasa /= 100;  // Convertimos el porcentaje a decimal
    return flujoInicial * (pow(1 + tasa, periodos) - 1) / tasa + incremento * (pow(1 + tasa, periodos) - tasa * periodos - 1) / (tasa * tasa);
}

// Función para calcular la amortización de un préstamo
double amortizacion(double principal, double tasa, int periodos) {
    tasa /= 100;  // Convertimos el porcentaje a decimal
    return (principal * tasa) / (1 - pow(1 + tasa, -periodos));
}

int main() {
    cout << "******************************************************\n";
    cout << "*            Bienvenido al Programa Financiero       *\n";
    cout << "*     Calculadora de Interés, Gradientes y Amortización     *\n";
    cout << "*                                                    *\n";
    cout << "******************************************************\n\n";

    int opcion;
    bool continuar = true;

    do {
        cout << "\nSeleccione una opción para calcular:\n";
        cout << "1. Interés Simple\n";
        cout << "2. Interés Compuesto\n";
        cout << "3. Gradiente Aritmético\n";
        cout << "4. Amortización de un Préstamo\n";
        cout << "5. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        // Variables comunes a todas las opciones
        double principal, tasa, tiempo;
        int periodos, capitalizaciones;

        switch (opcion) {
            case 1: // Interés Simple
                cout << "Interés Simple\n";
                cout << "Ingrese el capital inicial: ";
                cin >> principal;
                cout << "Ingrese la tasa de interés (%) (por ejemplo, 5 para 5%): ";
                cin >> tasa;
                cout << "Ingrese el tiempo en años: ";
                cin >> tiempo;
                cout << fixed << setprecision(2);  // Fijamos la precisión a dos decimales
                cout << "El interés simple es: " << interesSimple(principal, tasa, tiempo) << " unidades monetarias.\n";
                break;
            
            case 2: // Interés Compuesto
                cout << "Interés Compuesto\n";
                cout << "Ingrese el capital inicial: ";
                cin >> principal;
                cout << "Ingrese la tasa de interés (%) (por ejemplo, 5 para 5%): ";
                cin >> tasa;
                cout << "Ingrese el tiempo en años: ";
                cin >> tiempo;
                cout << "Ingrese el número de capitalizaciones por año: ";
                cin >> capitalizaciones;
                cout << fixed << setprecision(2);
                cout << "El interés compuesto es: " << interesCompuesto(principal, tasa, tiempo, capitalizaciones) << " unidades monetarias.\n";
                break;
            
            case 3: // Gradiente Aritmético
                double flujoInicial, incremento;
                cout << "Gradiente Aritmético\n";
                cout << "Ingrese el flujo inicial: ";
                cin >> flujoInicial;
                cout << "Ingrese el incremento anual del flujo: ";
                cin >> incremento;
                cout << "Ingrese la tasa de interés (%) (por ejemplo, 5 para 5%): ";
                cin >> tasa;
                cout << "Ingrese el número de periodos: ";
                cin >> periodos;
                cout << fixed << setprecision(2);
                cout << "El valor presente del gradiente aritmético es: " << gradienteAritmetico(flujoInicial, incremento, tasa, periodos) << " unidades monetarias.\n";
                break;
            
            case 4: // Amortización de un Préstamo
                cout << "Amortización de un Préstamo\n";
                cout << "Ingrese el monto del préstamo: ";
                cin >> principal;
                cout << "Ingrese la tasa de interés anual (%) (por ejemplo, 5 para 5%): ";
                cin >> tasa;
                cout << "Ingrese el número de periodos (por ejemplo, meses): ";
                cin >> periodos;
                cout << fixed << setprecision(2);
                cout << "El pago periódico de amortización es: " << amortizacion(principal, tasa, periodos) << " unidades monetarias.\n";
                break;
            
            case 5: // Salir
                cout << "Gracias por utilizar el programa. ¡Hasta luego!\n";
                continuar = false;
                break;
            
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (continuar);

    return 0;
}
