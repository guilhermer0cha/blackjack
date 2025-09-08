#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>


const int MAX_CARTAS = 52;

int randNaipe = 0;
int randValor = 0;


struct Carta {
    int valor;
    std::string naipe;
};

struct Baralho {         //// USADA TANTO PARA REPRESENTAR O BARALHO QUANTO PARA MÃO DO DEALER E DO JOGADRO
    Carta cartas[MAX_CARTAS];
    int ultimo;
};

void inicializarBaralho(Baralho &baralho) {
    int index = 0;
    
    for (int n = 0; n <= 3; n++) {
        std::string naipeAtual;
            switch (n) {
                case 0:
                    //naipeAtual = "P"; 
                    naipeAtual = "♣";
                    break;
                case 1:
                    //naipeAtual = "E"; 
                    naipeAtual = "♠";
                    break;
                case 2:
                    //naipeAtual = "O"; 
                    naipeAtual = "♦";
                    break;
                case 3:
                    //naipeAtual = "C";
                    naipeAtual = "♥";
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
        std::cout << baralho.cartas[i].valor;
        std::cout << baralho.cartas[i].naipe;
        std::cout << ' ';
    }
}

Carta sortearCarta(Baralho &baralho) {
    if (baralho.ultimo < 0 ) {
        std::cout << "ERRO!";
    };

    int indiceSorteado = rand() % (baralho.ultimo + 1);

    Carta cartaSorteada = baralho.cartas[indiceSorteado];

    baralho.cartas[indiceSorteado] = baralho.cartas[baralho.ultimo];

    baralho.ultimo--;

    return cartaSorteada;
}

void adicionarCarta(Baralho &mao, Carta carta) {
    if (mao.ultimo >= MAX_CARTAS) {
        std::cout << "ERRO! MÃO CHEIA!";
        return;
    }
    mao.ultimo++;
    mao.cartas[mao.ultimo] = carta;
}

void mostrarMao(Baralho &mao, bool ehDealer, bool primeiraRodada) {
    if ( mao.ultimo == -1 ) {
        std::cout << "ERRO! A MÃO ESTÁ VAZIA";
    }

    if (ehDealer == true && primeiraRodada && true) {
        std::cout << mao.cartas[0].valor;
        std::cout << mao.cartas[0].naipe;

        if ( mao.ultimo >= 1 ) {
            std::cout << " ???";
        }
    } else {
        for ( int i = 0; i <= mao.ultimo; i++ ) {
            std::cout << mao.cartas[i].valor;
            std::cout << mao.cartas[i].naipe;
            std::cout << " ";
        }
    }
}


void iniciarJogo (Baralho &mao, Baralho baralho) {
    for ( int i = 0; i < 2; i++ ) {
        adicionarCarta(mao, sortearCarta(baralho));
    }
}

void pedirCarta (Baralho &mao, Baralho baralho) {
    adicionarCarta(mao, sortearCarta(baralho));
}