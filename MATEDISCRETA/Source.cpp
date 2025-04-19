#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

// Funci�n para generar una matriz booleana sim�trica
void generarRelaciones(vector<vector<bool>>& matriz, int n) {
    srand(time(nullptr)); // Semilla para generaci�n aleatoria

    for (int i = 0; i < n; ++i) {
        int num_conexiones = rand() % 5 + 1; // Entre 1 y 5
        set<int> conexiones;

        while (conexiones.size() < num_conexiones) {
            int j = rand() % n;
            if (j != i) {
                conexiones.insert(j);
            }
        }

        for (int j : conexiones) {
            matriz[i][j] = true;
            matriz[j][i] = true; // Simetr�a
        }
    }
}

// Funci�n para imprimir la matriz
void imprimirMatriz(const vector<vector<bool>>& matriz) {
    cout << "\nMatriz de relaciones (1 = conexi�n, 0 = sin conexi�n):\n";
    for (const auto& fila : matriz) {
        for (bool valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    // Validaci�n de n entre 60 y 120
    do {
        cout << "Ingrese el n�mero de empleados (60 a 120): ";
        cin >> n;
        if (n < 60) { // 60 ->10
            cout << "Debe haber al menos 60 empleados.\n";
        }
    } while (n < 60); // 60 -> 10

    // Crear matriz booleana n x n inicializada en false
    vector<vector<bool>> matriz(n, vector<bool>(n, false));

    // Generar relaciones aleatorias
    generarRelaciones(matriz, n);

    // Imprimir la matriz
    imprimirMatriz(matriz);

    // Elegir al paciente cero
    int pacienteCero;
    do {
        cout << "\nSeleccione al empleado que se contagia primero (0 a " << n - 1 << "): ";
        cin >> pacienteCero;
        if (pacienteCero < 0 || pacienteCero >= n) {
            cout << "N�mero inv�lido.\n";
        }
    } while (pacienteCero < 0 || pacienteCero >= n);

    cout << "Empleado #" << pacienteCero << " ha adquirido la enfermedad.\n";
    cout << "Pulse enter para terminar la simulacion: ";
    cin.ignore(); // Limpia el '\n' pendiente 
    cin.get();    // Espera a que el usuario presione Enter

}
