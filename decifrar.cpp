#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Exponenciación modular rápida
long long modularPow(long long base, long long exponente, long long mod) {
    long long resultado = 1;
    base = base % mod;
    while (exponente > 0) {
        if (exponente % 2 == 1)
            resultado = (resultado * base) % mod;
        base = (base * base) % mod;
        exponente /= 2;
    }
    return resultado;
}

// Convierte un número con múltiples pares de dígitos a letras
string numeroABloqueLetras(long long numero, int letrasPorBloque) {
    string resultado = "";
    long long divisor = pow(10, letrasPorBloque * 2 - 2);
    int digitosProcesados = 0;

    while (numero > 0 && digitosProcesados < letrasPorBloque) {
        int dosDigitos = numero / divisor;
        numero %= divisor;
        divisor /= 100;
        digitosProcesados++;

        if (dosDigitos < 0 || dosDigitos > 25) {
            resultado += '?';
        } else {
            resultado += ('A' + dosDigitos);
        }
    }
    return resultado;
}

int main() {
    long long d, n;
    int letrasPorBloque;
    vector<long long> bloquesCifrados;
    
    // Solicitar datos por teclado
    cout << "Ingrese la clave privada (d): ";
    cin >> d;
    cout << "Ingrese el módulo (n): ";
    cin >> n;
    cout << "Ingrese el número de letras por bloque: ";
    cin >> letrasPorBloque;
    
    // Solicitar bloques cifrados
    cout << "Ingrese el número de bloques cifrados: ";
    int numBloques;
    cin >> numBloques;
    
    cout << "Ingrese los bloques cifrados (uno por línea):\n";
    for (int i = 0; i < numBloques; i++) {
        long long bloque;
        cin >> bloque;
        bloquesCifrados.push_back(bloque);
    }
    int cantidadBloques = bloquesCifrados.size();

    cout << "Clave privada (d): " << d << endl;
    cout << "Módulo (n): " << n << endl;
    cout << "Número de bloques cifrados: " << cantidadBloques << endl;
    cout << "Letras por bloque: " << letrasPorBloque << endl;
    cout << "Bloques cifrados: ";
    for (long long bloque : bloquesCifrados) {
        cout << bloque << " ";
    }
    cout << "\n\nDescifrando...\n";
    
    string mensajeDescifrado = "";
    for (long long bloque : bloquesCifrados) {
        long long mensaje = modularPow(bloque, d, n);
        cout << "Bloque " << bloque << " descifrado a: " << mensaje << endl;
        mensajeDescifrado += numeroABloqueLetras(mensaje, letrasPorBloque);
    }

    cout << "\n🔓 Mensaje descifrado final: " << mensajeDescifrado << endl;
    return 0;
}
