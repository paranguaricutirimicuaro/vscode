#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Estructura para registrar el historial de partidas
struct Partida {
    string juego;
    string dificultad;
    string resultado;
    int cambioFichas; // Cuánto se ganó o perdió
};

// Prototipos de funciones[cite: 5]
void jugarPiedraPapelTijera(int &fichas, Partida historial[], int &totalPartidas);
void registrarHistorial(Partida historial[], int &totalPartidas, string juego, string dif, string res, int cambio);
void mostrarHistorial(Partida historial[], int totalPartidas);

int main() {
    // Inicializar la semilla para la generación de números aleatorios[cite: 5]
    srand(time(0)); 
    
    // Cantidad inicial determinada de fichas para la sesión[cite: 5]
    int fichas = 100; 
    int opcion;
    
    // Arreglo para almacenar exactamente las últimas 5 partidas[cite: 5]
    Partida historial[5]; 
    int totalPartidas = 0;

    do {
        cout << "\n=================================" << endl;
        cout << "      MAQUINA ARCADE C++         " << endl;
        cout << "=================================" << endl;
        cout << " Fichas disponibles: " << fichas << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Piedra, Papel o Tijera" << endl;
        cout << "2. Adivina el Numero Secreto" << endl;
        cout << "3. Lanzamiento de Dados" << endl;
        cout << "4. Blackjack (21)" << endl;
        cout << "5. Ruleta" << endl;
        cout << "6. Tragamonedas" << endl;
        cout << "7. Ver Historial de Partidas" << endl;
        cout << "8. Salir" << endl;
        cout << "=================================" << endl;
        cout << "Seleccione una opcion: ";
        
        // Validacion basica de entrada
        while (!(cin >> opcion)) {
            cout << "Entrada invalida. Ingrese un numero: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch(opcion) {
            case 1:
                jugarPiedraPapelTijera(fichas, historial, totalPartidas);
                break;
            case 7:
                mostrarHistorial(historial, totalPartidas);
                break;
            case 8:
                cout << "Saliendo del arcade. Te llevas " << fichas << " fichas." << endl;
                break;
            default:
                if (opcion >= 2 && opcion <= 6) {
                    cout << "\nJuego en construccion..." << endl;
                } else {
                    cout << "\nOpcion no valida." << endl;
                }
        }
    } while (opcion != 8);

    return 0;
}

// Ejemplo de implementacion de un juego con el sistema de apuestas
void jugarPiedraPapelTijera(int &fichas, Partida historial[], int &totalPartidas) {
    int apuesta;
    cout << "\n--- PIEDRA, PAPEL O TIJERA ---" << endl;
    
    // Validar que la apuesta no supere las fichas disponibles
    do {
        cout << "Cuantas fichas deseas apostar? (Maximo " << fichas << "): ";
        cin >> apuesta;
    } while (apuesta <= 0 || apuesta > fichas);

    // Lógica temporal del juego para demostrar el flujo
    int resultadoAleatorio = rand() % 2; // 0 o 1
    
    if (resultadoAleatorio == 1) {
        cout << "¡Ganaste " << apuesta << " fichas!" << endl;
        fichas += apuesta; // Se suma a la variable original
        registrarHistorial(historial, totalPartidas, "Piedra, Papel o Tijera", "Normal", "Victoria", apuesta);
    } else {
        cout << "Perdiste " << apuesta << " fichas." << endl;
        fichas -= apuesta; // Se resta de la variable original
        registrarHistorial(historial, totalPartidas, "Piedra, Papel o Tijera", "Normal", "Derrota", -apuesta);
    }
}

// Funcion para gestionar el arreglo de 5 posiciones
void registrarHistorial(Partida historial[], int &totalPartidas, string juego, string dif, string res, int cambio) {
    // Si ya hay 5 partidas, desplazar el historial hacia atras para borrar la mas antigua
    if (totalPartidas == 5) {
        for (int i = 0; i < 4; i++) {
            historial[i] = historial[i+1];
        }
        totalPartidas = 4;
    }
    
    
    historial[totalPartidas].juego = juego;
    historial[totalPartidas].dificultad = dif;
    historial[totalPartidas].resultado = res;
    historial[totalPartidas].cambioFichas = cambio;
    totalPartidas++;
}

void mostrarHistorial(Partida historial[], int totalPartidas) {
    cout << "\n--- HISTORIAL DE LAS ULTIMAS 5 PARTIDAS ---" << endl;
    if (totalPartidas == 0) {
        cout << "No hay partidas registradas." << endl;
        return;
    }
    
    for (int i = 0; i < totalPartidas; i++) {
        cout << i + 1 << ". " << historial[i].juego 
             << " | Dificultad: " << historial[i].dificultad 
             << " | " << historial[i].resultado 
             << " (" << (historial[i].cambioFichas > 0 ? "+" : "") << historial[i].cambioFichas << " fichas)" << endl;
    }
}