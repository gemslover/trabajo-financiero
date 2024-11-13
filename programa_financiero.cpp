#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

// Función para calcular el interés simple
double interesSimple(double capital, double tasa, int tiempo) {
    return capital * tasa * tiempo;
}

// Función para calcular el interés compuesto
double interesCompuesto(double capital, double tasa, int tiempo, int n) {
    return capital * pow(1 + (tasa / n), n * tiempo);
}

// Función para calcular el valor presente de un gradiente aritmético
double gradienteAritmetico(double flujo, double incremento, double tasa, int n) {
    return flujo / tasa * (1 - pow(1 + tasa, -n)) + incremento / (tasa * tasa) * (1 - pow(1 + tasa, -n) - n * pow(1 + tasa, -n));
}

// Función para calcular los pagos de amortización usando el método francés
double amortizacionFrancesa(double capital, double tasa, int periodos) {
    return capital * (tasa / (1 - pow(1 + tasa, -periodos)));
}

// Función para calcular los pagos de amortización decreciente
void amortizacionDecreciente(double capital, double tasa, int periodos) {
    double cuotaCapital = capital / periodos;  // La parte fija de capital a pagar cada periodo
    cout << "Amortización Decreciente:" << endl;
    cout << "Periodo\tCuota de Interés\tCuota de Capital\tPago Total\n";
    
    for (int i = 1; i <= periodos; ++i) {
        double cuotaInteres = (capital - cuotaCapital * (i - 1)) * tasa;  // Interés calculado sobre saldo pendiente
        double pagoTotal = cuotaCapital + cuotaInteres;
        cout << i << "\t" << fixed << setprecision(2) << cuotaInteres << "\t\t\t" << cuotaCapital << "\t\t\t" << pagoTotal << endl;
    }
}

// Función para calcular la Tasa Interna de Retorno (TIR)
double tasaInternaRetorno(const vector<double>& flujos) {
    double tir = 0.1; // Valor inicial de TIR estimada
    double incremento = 0.0001; // Precisión de cálculo
    double npv = 0.0; // Valor neto presente
    int maxIter = 10000; // Límite de iteraciones para evitar bucles infinitos

    for (int iter = 0; iter < maxIter; ++iter) {
        npv = 0.0;
        for (size_t i = 0; i < flujos.size(); ++i) {
            npv += flujos[i] / pow(1 + tir, i); // Calcula el NPV con la TIR estimada
        }

        if (fabs(npv) < 1e-5) break; // Detener si el NPV es cercano a cero

        tir += (npv > 0 ? incremento : -incremento); // Ajuste de TIR si NPV es positivo o negativo
    }

    return tir * 100; // Devuelve la TIR en porcentaje
}

int main() {
    int opcion;
    bool continuar = true;
    
    cout << "Bienvenido al software de Cálculo Financiero en C++" << endl;
    cout << "Esta herramienta le ayudará a realizar cálculos financieros básicos para analizar inversiones." << endl;
    
    while (continuar) {
        cout << "\nSeleccione una opción de cálculo:" << endl;
        cout << "1. Interés Simple" << endl;
        cout << "2. Interés Compuesto" << endl;
        cout << "3. Gradiente Aritmético" << endl;
        cout << "4. Amortización (Sistema Francés)" << endl;
        cout << "5. Amortización Decreciente" << endl;
        cout << "6. Tasa Interna de Retorno (TIR)" << endl;
        cout << "7. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                double capital, tasa;
                int tiempo;
                cout << "Ingrese el capital inicial: ";
                cin >> capital;
                cout << "Ingrese la tasa de interés (en decimal): ";
                cin >> tasa;
                cout << "Ingrese el tiempo (en años): ";
                cin >> tiempo;
                double resultado = interesSimple(capital, tasa, tiempo);
                cout << "El interés simple es: " << fixed << setprecision(2) << resultado << endl;
                break;
            }
            case 2: {
                double capital, tasa;
                int tiempo, n;
                cout << "Ingrese el capital inicial: ";
                cin >> capital;
                cout << "Ingrese la tasa de interés anual (en decimal): ";
                cin >> tasa;
                cout << "Ingrese el tiempo (en años): ";
                cin >> tiempo;
                cout << "Ingrese el número de capitalizaciones por año: ";
                cin >> n;
                double resultado = interesCompuesto(capital, tasa, tiempo, n);
                cout << "El monto con interés compuesto es: " << fixed << setprecision(2) << resultado << endl;
                break;
            }
            case 3: {
                double flujo, incremento, tasa;
                int n;
                cout << "Ingrese el flujo inicial: ";
                cin >> flujo;
                cout << "Ingrese el incremento por período: ";
                cin >> incremento;
                cout << "Ingrese la tasa de interés (en decimal): ";
                cin >> tasa;
                cout << "Ingrese el número de períodos: ";
                cin >> n;
                double resultado = gradienteAritmetico(flujo, incremento, tasa, n);
                cout << "El valor presente del gradiente aritmético es: " << fixed << setprecision(2) << resultado << endl;
                break;
            }
            case 4: {
                double capital, tasa;
                int periodos;
                cout << "Ingrese el capital a amortizar: ";
                cin >> capital;
                cout << "Ingrese la tasa de interés por periodo (en decimal): ";
                cin >> tasa;
                cout << "Ingrese el número de periodos: ";
                cin >> periodos;
                double pago = amortizacionFrancesa(capital, tasa, periodos);
                cout << "El pago periódico en amortización francesa es: " << fixed << setprecision(2) << pago << endl;
                break;
            }
            case 5: {
                double capital, tasa;
                int periodos;
                cout << "Ingrese el capital a amortizar: ";
                cin >> capital;
                cout << "Ingrese la tasa de interés por periodo (en decimal): ";
                cin >> tasa;
                cout << "Ingrese el número de periodos: ";
                cin >> periodos;
                amortizacionDecreciente(capital, tasa, periodos);
                break;
            }
            case 6: {
                int n;
                cout << "Ingrese el número de flujos de efectivo (incluyendo el valor negativo inicial): ";
                cin >> n;
                vector<double> flujos(n);
                cout << "Ingrese los valores de los flujos de efectivo (negativo para la inversión inicial):" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << "Flujo " << i + 1 << ": ";
                    cin >> flujos[i];
                }
                double tir = tasaInternaRetorno(flujos);
                cout << "La Tasa Interna de Retorno (TIR) es: " << fixed << setprecision(2) << tir << "%" << endl;
                break;
            }
            case 7:
                cout << "Gracias por utilizar el software de Cálculo Financiero. ¡Hasta luego!" << endl;
                continuar = false;
                break;
            default:
                cout << "Opción no válida. Por favor, intente nuevamente." << endl;
        }
    }
    return 0;
}