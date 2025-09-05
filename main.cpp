#include "blackjack.h"
#include <stdlib.h>
#include <time.h>


int main() {
    srand( time (0) );

    Baralho baralhoPrincipal;
    inicializarBaralho(baralhoPrincipal);

    Baralho maoJogador;
    maoJogador.ultimo = -1;

    Baralho maoDealer;
    maoDealer.ultimo = -1;

    Carta carta1 = sortearCarta(baralhoPrincipal);

    printarBaralho(baralhoPrincipal);
    cout << endl;
    cout << "primeira carta: ";
    cout << carta1.valor;
    cout << carta1.naipe;
    
    // efetuar loop para distribuicao de cartas iniciais do jogo !!












}