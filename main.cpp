#include "blackjack.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand( time (0) );

    Baralho baralhoPrincipal;               // baralho onde está concentrada todas as cartas do jogo
    Baralho maoJogador;
    Baralho maoDealer;

    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {

        inicializarBaralho(baralhoPrincipal);
        maoJogador.ultimo = -1;
        maoDealer.ultimo = -1;

        bool turnoJogador = true;


        // inicio da rodada
        iniciarJogo(maoDealer, baralhoPrincipal);
        iniciarJogo(maoJogador, baralhoPrincipal);

        mostrarMao(maoDealer, true, turnoJogador);
        std::cout << std::endl;
        mostrarMao(maoJogador, false, turnoJogador);
        std::cout << std::endl;

        turnoJogador = true;

        
        // turno jogador
        bool estourou = false;
        char acao;

        if ( calcularPontuacao(maoJogador) > 21 ) {
            estourou = true;
        }

        do {
            std::cout << "O que voce quer fazer? (P para pedir, C para parar): ";
            std::cin >> acao;

            if ( acao == 'p' || acao == 'P' ) {
                pedirCarta(maoJogador, baralhoPrincipal);

                mostrarMao(maoDealer, true, turnoJogador);
                std::cout << std::endl;
                mostrarMao(maoJogador, false, turnoJogador);
                std::cout << std::endl;
            }
        } while (( acao == 'p' || acao == 'P' ) && calcularPontuacao(maoJogador) <= 21 );

        if ( calcularPontuacao(maoJogador) > 21 ) {
            estourou = true;
        }

        turnoJogador = false;

        if ( !estourou ) {
            std::cout << "==== Turno do Dealer ====" << std::endl;
            mostrarMao(maoDealer, true, turnoJogador);
            std::cout << std::endl;
            while (calcularPontuacao(maoDealer) < 17) {
                pedirCarta(maoDealer, baralhoPrincipal);
                mostrarMao(maoDealer, true, turnoJogador);
                std::cout << std::endl;
            }
        }


        if ( estourou ) {
            std::cout << "=== Mão do Dealer ===";
            mostrarMao(maoDealer, true, turnoJogador);
            std::cout << "Você estourou! O dealer venceu." << std::endl;
        } 
        else if ( calcularPontuacao(maoDealer) > 21 ) {
            std::cout << "Parabéns! O Dealer estourou. Você venceu!" << std::endl;
        }
        else if ( calcularPontuacao(maoDealer) == 21 && calcularPontuacao(maoJogador) == 21 ) {
            std::cout << "Empate! Ambos fizeram 21." << std::endl;
        }
        else if ( calcularPontuacao(maoJogador) == 21 ) {
            std::cout << "Parabéns! Você fez 21." << std::endl;
        }
        else if ( calcularPontuacao(maoDealer) == 21 ) {
            std::cout << "Que pena! O Dealer fez 21 e ganhou." << std::endl;
        }
        else if ( calcularPontuacao(maoJogador) > calcularPontuacao(maoDealer) ) {
            std::cout << "Parabéns! Sua pontuação é maior. Você venceu." << std::endl;
        }        
        else if (calcularPontuacao(maoDealer) > calcularPontuacao(maoJogador) ) {
        std::cout << "Que pena! O dealer venceu!" << std::endl;
        }
        else {
            std::cout << "Empate!" << std::endl;
        }


        std::cout << "Quer jogar novamente? (s/n): ";
        std::cin >> continuar;
    }

  












}