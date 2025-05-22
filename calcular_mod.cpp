#include <iostream>
using namespace std;

// Función para exponenciación modular rápida
long long exponenciacionModular(long long base, long long exponente, long long mod) {
    long long resultado = 1;
    base = base % mod;

    while (exponente > 0) {
        if (exponente % 2 == 1) {
            resultado = (resultado * base) % mod;
        }
        base = (base * base) % mod;
        exponente = exponente / 2;
    }

    return resultado;
}

int main() {
    long long base, exponente, mod;

    cout << "Ingresa la base: ";
    cin >> base;

    cout << "Ingresa el exponente: ";
    cin >> exponente;

    cout << "Ingresa el modulo: ";
    cin >> mod;

    long long resultado = exponenciacionModular(base, exponente, mod);
    cout << base << "^" << exponente << " mod " << mod << " = " << resultado << endl;

    return 0;
}
