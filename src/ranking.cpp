#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Ranking.h"
using namespace std;

int Ranking::leerNumero()
{
    int num;
    cin >> num;
    cin.ignore();
    return num;
}

void Ranking::creaJugador(Jugador nuevoJugador)
{
    ofstream archivo("jugadores.txt", ios::app);
    if (!archivo)
    {
        cout << "No se ha podido abrir el archivo.\n";
        return;
    }

    archivo << nuevoJugador.nombre << " " << nuevoJugador.puntuacion << endl;
    archivo.close();

    jugadores[numJugadores] = nuevoJugador;
    numJugadores++;
}

int Ranking::buscaJugador(const string& nombre)
{
    ifstream archivo("jugadores.txt");
    if (!archivo.is_open())
    {
        cout << "No se ha podido abrir el archivo.\n";
        return -1;
    }

    string nombreArchivo;
    int puntuacion;

    while (archivo >> nombreArchivo >> puntuacion)
    {
        if (nombreArchivo == nombre)
        {
            archivo.close();
            return 1;
        }
    }

    archivo.close();
    return -1;
}

void Ranking::muestraPuntuacion()
{
    ifstream archivo("jugadores.txt");
    if (!archivo.is_open())
    {
        cout << "No se ha podido abrir el archivo.\n";
        return;
    }

    Jugador jugadores[JUGADORESMAX];
    int numJugadores = 0;
    string nombre;
    int puntuacion;

    while (archivo >> nombre >> puntuacion)
    {
        Jugador j;
        j.nombre = nombre;
        j.puntuacion = puntuacion;
        jugadores[numJugadores++] = j;
    }

    archivo.close();

    sort(jugadores, jugadores + numJugadores, [](const Jugador& a, const Jugador& b) {
        return a.puntuacion > b.puntuacion;
        });

    int maximo = min(numJugadores, 10);
    for (int i = 0; i < maximo; i++)
    {
        cout << i + 1 << ". " << jugadores[i].nombre << ": " << jugadores[i].puntuacion << endl;
    }
}

int Ranking::extraePuntuacion(const string& nombre)
{
    ifstream archivo("jugadores.txt");
    if (!archivo.is_open())
    {
        cout << "No se ha podido abrir el archivo.\n";
        return -1;
    }

    string nombreArchivo;
    int puntuacion;

    while (archivo >> nombreArchivo >> puntuacion)
    {
        if (nombreArchivo == nombre)
        {
            archivo.close();
            return puntuacion;
        }
    }

    archivo.close();
    return -1;
}

void Ranking::borrarJugador(const string& nombre)
{
    ifstream archivo("jugadores.txt");
    if (!archivo.is_open())
    {
        cout << "No se ha podido abrir el archivo.\n";
        return;
    }

    ofstream archivoTemp("temp.txt");
    if (!archivoTemp)
    {
        cout << "No se ha podido crear el archivo temporal.\n";
        archivo.close();
        return;
    }

    string nombreArchivo;
    int puntuacion;

    while (archivo >> nombreArchivo >> puntuacion)
    {
        if (nombreArchivo != nombre)
        {
            archivoTemp << nombreArchivo << " " << puntuacion << endl;
        }
    }

    archivo.close();
    archivoTemp.close();

    remove("jugadores.txt");
    rename("temp.txt", "jugadores.txt");

    cout << "Jugador borrado exitosamente.\n";
}
