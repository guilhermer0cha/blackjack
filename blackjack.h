#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


const int MAX_CARTAS = 52;

int randNaipe = 0;
int randValor = 0;


struct Carta {
    int valor;
    char naipe;
};

struct Baralho {         //// USADA TANTO PARA REPRESENTAR O BARALHO QUANTO PARA MÃO DO DEALER E DO JOGADRO
    Carta cartas[MAX_CARTAS];
    int ultimo;
};

void inicializarBaralho(Baralho &baralho) {
    int index = 0;
    
    for (int n = 0; n <= 3; n++) {
        char naipeAtual;
            switch (n) {
                case 0:
                    naipeAtual = 'P';
                    break;
                case 1:
                    naipeAtual = 'E';
                    break;
                case 2:
                    naipeAtual = 'O';
                    break;
                case 3:
                    naipeAtual = 'C';
                    break;
        }
        for (int v = 1; v <= 13; v++) {
            baralho.cartas[index].naipe = naipeAtual;
            baralho.cartas[index].valor = v;
            index++;
        }
    }
    baralho.ultimo = 51;
};


void printarBaralho(Baralho baralho) {
    for (int i = 0; i <= baralho.ultimo; i++) {
        cout << baralho.cartas[i].valor;
        cout << baralho.cartas[i].naipe;
        cout << ' ';
    }
}

Carta sortearCarta(Baralho &baralho) {
    if (baralho.ultimo < 0 ) {
        cout << "ERRO!";
    };

    int indiceSorteado = rand() % (baralho.ultimo + 1);

    Carta cartaSorteada = baralho.cartas[indiceSorteado];

    baralho.cartas[indiceSorteado] = baralho.cartas[baralho.ultimo];

    baralho.ultimo--;

    return cartaSorteada;
}

void adicionarCarta(Baralho &mao, Carta carta) {
    if (mao.ultimo >= MAX_CARTAS) {
        cout << "ERRO! MÃO CHEIA!";
        return;
    }
    mao.ultimo++;
    mao.cartas[mao.ultimo] = carta;
}