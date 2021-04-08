#pragma once

#include <iostream>
#include "barco.h"

class tabuleiro {
	private:
		int tabul[16][16];

	public:
		
	tabuleiro ();

	bool horizontal(int tam, int linha, int coluna);

	bool vertical(int tam, int linha, int coluna);

	bool horizontalHidro (int linha, int coluna);

	bool verticalHidro (int linha, int coluna);	

	void posicionaBarco(int tam);

	void posicionaHidro ();

	void criaEnc ();
	
	void criaCru ();
	
	void criaDest();
	
	void criaSub ();

	void criaHidro ();

	void imprimeTab ();

	void setPos(int linha, int coluna, int letra);

	int getPos(int linha, int coluna);
};