#include "blackjack.h"
#include <stdlib.h>
#include <time.h>


int main() {

    srand( time (0) );

    Baralho baralhoPrincipal;               // baralho onde está concentrada todas as cartas do jogo
    inicializarBaralho(baralhoPrincipal);

    Baralho maoJogador;
    maoJogador.ultimo = -1;

    Baralho maoDealer;
    maoDealer.ultimo = -1;

    bool primeiraRodada = true;

    iniciarJogo(maoDealer, baralhoPrincipal);
    iniciarJogo(maoJogador, baralhoPrincipal);

    mostrarMao(maoDealer, true, primeiraRodada);
    cout << endl;

    mostrarMao(maoJogador, false, primeiraRodada);
    primeiraRodada = false;


    
    // efetuar loop para distribuicao de cartas iniciais do jogo !!












}