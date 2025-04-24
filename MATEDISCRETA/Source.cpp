#include <iostream>
using namespace std;

const int MAX = 120;

void inicializarMatriz(bool matriz[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = false;
}

int valorPseudoAleatorio(int semilla, int limite) {
    semilla = (semilla * 37 + 11) % 1000;
    return semilla % limite;
}

void generarRelaciones(bool matriz[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        int conexiones = (i * 7 + 3) % 5 + 1;
        int contador = 0;
        int intento = 0;

        while (contador < conexiones && intento < n * 2) {
            int j = valorPseudoAleatorio(i * intento + 17, n);
            if (j != i && !matriz[i][j]) {
                matriz[i][j] = true;
                matriz[j][i] = true;
                contador++;
            }
            intento++;
        }
    }
}

void imprimirMatriz(bool matriz[MAX][MAX], int n) {
    cout << "\nMatriz de relaciones:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    do {
        cout << "Ingrese el numero de empleados (minimo 5, maximo 120): ";
        cin >> n;
    } while (n < 5 || n > 120);

    bool matriz[MAX][MAX];
    inicializarMatriz(matriz, n);
    generarRelaciones(matriz, n);
    imprimirMatriz(matriz, n);

    int pacienteCero;
    do {
        cout << "\nSeleccione al empleado que se contagia primero (0 a " << n - 1 << "): ";
        cin >> pacienteCero;
    } while (pacienteCero < 0 || pacienteCero >= n);

    cout << "Empleado #" << pacienteCero << " ha adquirido la enfermedad.\n";

    cin.ignore(); 
    cin.get();    
}
