#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

char espadas = 69;
char paus = 80;
char ouros = 79;
char copas = 67;

const int MAX_CARTAS = 52;

int randNaipe = 0;
int randValor = 0;


struct Carta {
    int valor;
    int naipe;
};

struct Baralho {
    Carta cartas[MAX_CARTAS];
    int ultimo;
};

void inicializarBaralho(Baralho &baralho) {
    int index = 0;
    char naipes[] = {'P', 'E', 'C', 'O'};
    
    for (int n = 0; n <= 4; n++) {
        for (int v = 1; v <= 13; v++) {
            baralho.cartas[index].naipe = naipes[n];
            baralho.cartas[index].valor = v;
            index++;

            switch (n) {
                case 0:
                    baralho.cartas[index].naipe = espadas;
                    break;
                case 1:
                    baralho.cartas[index].naipe = paus;
                    break;
                case 2:
                    baralho.cartas[index].naipe = ouros;
                    break;
                case 3:
                    baralho.cartas[index].naipe = copas;
                    break;
            }
        }
    }
    baralho.ultimo = 51;
};

// Carta sortearCarta() {
//     randNaipe = rand() % 4;
//     randValor = rand() % 13;

//     Carta novaCarta;

//     switch (randNaipe) {
//         case 0:
//             novaCarta.naipe = espadas;
//             break;
//         case 1:
//             novaCarta.naipe = paus;
//             break;
//         case 2:
//             novaCarta.naipe = ouros;
//             break;
//         case 3:
//             novaCarta.naipe = copas;
//             break;
//     }

//     novaCarta.valor = randValor;
//     return novaCarta;
// }


void printarBaralho(Baralho baralho) {
    for (int i = 0; i <= baralho.ultimo; i++) {
        cout << baralho.cartas[i].valor;
        printf("%c", baralho.cartas[i].naipe);
        cout << ' ';
    }
}

Carta sortearCarta(Baralho &baralho) {
    if (baralho.ultimo < 0 ) {
        cout << "ERRO!";
    };

    int indiceSorteado = rand() % (baralho.ultimo + 1);

    Carta cartaSorteada = baralho.cartas[indiceSorteado];


}

