#include <iostream>
#include "jogo.h"
#include "tabuleiro.h"

int main() {

	char linha;
	int coluna;
	jogo batalha;
	bool acerto;

std::cout << "|￣￣￣￣￣￣￣￣￣|" << std::endl;
std::cout << "|    BEM VINDO(A) 	|" << std::endl;
std::cout << "|  À BATALHA NAVAL  |" << std::endl;
std::cout << "|    DO CCUSCUZ    	|" << std::endl;
std::cout << "|＿＿＿＿＿＿＿＿＿|| " << std::endl;
std::cout << " ∧＿∧  ||" << std::endl;
std::cout << "( ´ω`) ||" << std::endl;
std::cout << " /　　づ" << std::endl << std::endl;

	batalha.imprimeTabEstado();
	batalha.imprimeTabJogo();

	while (true) {
	
		while (true) {

			std::cout << "Insira a linha que deseja chutar (Apenas letras de A a O) " << std::endl;
			std::cin >> linha;

			if (linha >= 'A' && linha <= 'O') break;

			std::cout << "Linha inválida. " << std::endl;

		}

		while (true) {
			
			std::cout << "Insira a coluna que deseja chutar (Apenas números de 1 a 15)" << std::endl;
			std::cin >> coluna;

			if (coluna >= 1 && coluna <= 15) break;

			std::cout << "Coluna inválida. " << std::endl;

		}
		std::cout << std::endl;

		if ( !batalha.chutar(linha-64, coluna, acerto) )
			std::cout << "Você já chutou esse ponto no mapa, por favor, digita coordenadas que ainda não tenha tentado" << std::endl;
		
		else {
			if (acerto) std::cout << "Parabéns, você acertou o ponto!" << std::endl;

			else std::cout << "Você errou, tente de novo!" << std::endl;
		}

		//O jogo tem ao todo 38 coordenadas de barcos, quando o usuário atinge essa pontuação, ele encerra
		if (batalha.getPontos() == 38) {
			std::cout << "Parabéns, você venceu o jogo!!!";
			break;
		}
	}

}