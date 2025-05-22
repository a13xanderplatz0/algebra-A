#include <iostream>
#include <vector>
#include <cmath>
#include <string>
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

// Convierte letras a número
long long letrasANumero(const string& mensaje, int letrasPorBloque) {
    long long numero = 0;
    for (int i = 0; i < mensaje.length(); i++) {
        int valorLetra = toupper(mensaje[i]) - 'A';
        numero = numero * 100 + valorLetra;
    }
    return numero;
}

int main() {
    string mensaje;
    long long e, n;
    int letrasPorBloque;
    
    // Solicitar datos por teclado
    cout << "Ingrese el mensaje a cifrar (solo letras): ";
    cin >> mensaje;
    cout << "Ingrese la clave pública (e): ";
    cin >> e;
    cout << "Ingrese el módulo (n): ";
    cin >> n;
    cout << "Ingrese el número de letras por bloque: ";
    cin >> letrasPorBloque;
    
    // Validar que el mensaje tenga la longitud correcta
    if (mensaje.length() % letrasPorBloque != 0) {
        cout << "Error: La longitud del mensaje no es múltiplo del número de letras por bloque." << endl;
        return 1;
    }
    
    // Procesar el mensaje por bloques
    cout << "\nMensaje cifrado:\n";
    for (int i = 0; i < mensaje.length(); i += letrasPorBloque) {
        string bloque = mensaje.substr(i, letrasPorBloque);
        long long numero = letrasANumero(bloque, letrasPorBloque);
        long long cifrado = modularPow(numero, e, n);
        cout << cifrado << " ";
    }
    cout << endl;
    
    return 0;
}
