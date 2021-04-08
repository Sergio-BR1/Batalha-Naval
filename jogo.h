#pragma once

#include <iostream>
#include "tabuleiro.h"

class jogo {

	private:
	
		tabuleiro tab1, //tabuleiro principal
							tabAux; //tabuleiro auxiliar, para interação com o usuário
		int pontos; //contagem de pontos durante o jogo

	public:
	
	jogo ();

	int getPontos();

	bool chutar (int linha, int coluna, bool &acerto);

	void imprimeTabEstado();

	void imprimeTabJogo ();

};
