#include <iostream>
#include "jogo.h"

jogo::jogo() {

	//Insere os barcos no tabuleiro do jogo
	tab1.criaEnc();

	tab1.criaCru();

	tab1.criaCru();

	tab1.criaDest();
	tab1.criaDest();
	tab1.criaDest();

	tab1.criaSub();
	tab1.criaSub();
	tab1.criaSub();
	tab1.criaSub();

	tab1.criaHidro();
	tab1.criaHidro();
	tab1.criaHidro();
	tab1.criaHidro();
	tab1.criaHidro();

	tab1.criaHidro();
	tab1.criaHidro();
	tab1.criaHidro();
	tab1.criaHidro();
	tab1.criaHidro();

	pontos = 0;
	
}

/****************************************************************************************************************************************************************************/

//Imprime um tabuleiro vazio do mesmo tipo para o usuário, pra que ele não possa ver como está o tabuleiro preenchido
void jogo::imprimeTabEstado() {

	tabAux.imprimeTab();

}

/****************************************************************************************************************************************************************************/

//Imprime o tabuleiro preenchido 
void jogo::imprimeTabJogo() {
	
	tab1.imprimeTab();

}

/****************************************************************************************************************************************************************************/

//Função para ver se o usuário acertou o chute
bool jogo::chutar(int linha, int coluna, bool &acerto) {

	//Caso o chute já tenha sido feito, retorna falso para apresentar a mensagem ao usuário de que ele já fez esse chute
	if ( tabAux.getPos(linha, coluna) != 0 ) return false;

	//Caso contrário, se estiver errado a variável de acerto retorna falso, indicando que o usuário errou e é incluso o código ascii de E no tabuleiro auxiliar
	if( tab1.getPos(linha, coluna) == 0 ) {

		acerto = false;
		tabAux.setPos(linha, coluna, 69);

	}

	//Se o usuário acertar, indica que está certo, inclui o código ascii de X no tabuleiro auxiliar e conta mais um ponto
	else {

		acerto = true;
		tabAux.setPos(linha, coluna, 88);
		pontos++;

	}

	//Imrpime o tabuleiro auxiliar, mostrando o estado atual dos erros e acertos do usuário
	imprimeTabEstado();

	//Indica que o ponto chutado não foi tentado antes
	return true;

}

/****************************************************************************************************************************************************************************/

//Mostra quantos pontos o usuário já fez
int jogo::getPontos() {
	return pontos;
}