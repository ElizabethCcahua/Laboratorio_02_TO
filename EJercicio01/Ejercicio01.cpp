#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// ======================================================
// CLASE 1: ANALIZADOR
// ======================================================
class Analizador {
public:
    bool esOperador(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    bool expresionValida(const string& expresion) {
        int cantidadNumeros = 0;
        bool leyendoNumero = false;

        for (char c : expresion) {

            if (isdigit(c)) {
                if (!leyendoNumero) {
                    cantidadNumeros++;
                    leyendoNumero = true;
                }
            }
            else if (esOperador(c)) {
                leyendoNumero = false;
            }
            else {
                return false;
            }
        }

        return cantidadNumeros >= 2 && cantidadNumeros <= 6;
    }
};


// ======================================================
// CLASE 2: CALCULADORA
// ======================================================
class Calculadora {
public:

    double sumar(double a, double b) {
        return a + b;
    }

    double restar(double a, double b) {
        return a - b;
    }

    double multiplicar(double a, double b) {
        return a * b;
    }

    double dividir(double a, double b) {

        if (b == 0) {
            cout << "Error: division entre cero." << endl;
            return 0;
        }

        return a / b;
    }

    double operar(double a, double b, char operador) {

        switch (operador) {

        case '+':
            return sumar(a, b);

        case '-':
            return restar(a, b);

        case '*':
            return multiplicar(a, b);

        case '/':
            return dividir(a, b);

        default:
            return 0;
        }
    }
};


// ======================================================
// CLASE 3: PROCESADOR
// ======================================================
class Procesador {

private:
    Calculadora calculadora;

public:

    double procesar(const string& expresion) {

        vector<double> numeros;
        vector<char> operadores;

        string numero = "";

        for (char c : expresion) {

            if (isdigit(c)) {
                numero += c;
            }
            else {

                numeros.push_back(stod(numero));
                numero = "";

                operadores.push_back(c);
            }
        }

        numeros.push_back(stod(numero));

        double resultado = numeros[0];

        for (int i = 0; i < operadores.size(); i++) {

            resultado = calculadora.operar(
                resultado,
                numeros[i + 1],
                operadores[i]
            );
        }

        return resultado;
    }
};


// ======================================================
// PROGRAMA PRINCIPAL
// ======================================================
int main() {

    string expresion;

    Analizador analizador;
    Procesador procesador;

    cout << "===================================" << endl;
    cout << "       CALCULADORA CON CLASES       " << endl;
    cout << "===================================" << endl;

    cout << "Ingrese una operacion: ";
    cin >> expresion;

    if (!analizador.expresionValida(expresion)) {

        cout << "\nExpresion no valida." << endl;
        cout << "Debe contener entre 2 y 6 numeros." << endl;

        return 0;
    }

    double resultado = procesador.procesar(expresion);

    cout << "\nOperacion: " << expresion << endl;
    cout << "Resultado: " << resultado << endl;

    return 0;
}