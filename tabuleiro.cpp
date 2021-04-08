#include <iostream>
#include <cstdlib>
#include "tabuleiro.h"


tabuleiro::tabuleiro () { //Inicia o tabuleiro setando 0 para todas as posições não preenchidas
	
	int letra = 64; //1 Caractere antes do A na tabela Ascii

	tabul[0][0] = 9; //Símbolo de TAB na tabela Ascii

	//Setando as numerações das colunas e as letras das linhas do tabuleiro, respectivamente. As linhas foram colocadas em números de 65 a 78, sendo de A a O os números de cada letra na tabela Ascii
	for (int i = 1; i < 16; i++) {

		tabul[0][i] = i;

		letra++;

		tabul[i][0] = letra;

	}	

	//Setando o mapa colocando 0 em todas as posições
	for(int i=1; i < 16; i++) {

		for (int j=1; j < 16; j++) { 

			tabul[i][j] = 0;

		}

	}


}

/****************************************************************************************************************************************************************************/
bool tabuleiro::horizontal (int tam, int linha, int coluna) {

	//Verifica se é possível inserir o barco da direita para a esquerda, partindo do ponto que foi sorteado 
	if (coluna - tam >= 0 ) {
		
		bool flag = false;

		//Verifica se não tenha nenhuma parte de barco no intervalo desejado
		for (int i = coluna; i > coluna - tam; i--) {
		
			if (tabul[linha][i] == 1) {
		
				flag = true; //Caso haja parte de algum barco no intervalo desejado, garante que ele não será colocado lá
		
				break;
		
			}
		
		}
		
		//Caso não haja parte de barco no intervalo desejado, inclui o barco lá encerra e a função
		if (flag == false) {

			
			for (int i= coluna; i >coluna - tam; i--) tabul[linha][i] = 1;
			
			return true;
		
		}

	}

	//Verifica se é possível inserir o barco da esquerda para a direita, partindo do ponto que foi sorteado 
	if (coluna + tam <= 15) {
		
		bool flag = false;

		//Verifica se não tenha nenhuma parte de barco no intervalo desejado
		for (int i = coluna; i < coluna + tam; i++) {
		
			if (tabul[linha][i] == 1) {
		
				flag = true;  //Caso haja parte de algum barco no intervalo desejado, garante que ele não será colocado lá
		
		
				break;
		
			}
		
		}

		//Caso não haja parte de barco no intervalo desejado, inclui o barco lá encerra e a função
		if (flag == false) {

			
			for (int i= coluna; i < coluna + tam; i++) tabul[linha][i] = 1;

			return true;
		
		}

	}
	
	//Caso não seja possível inserir o barco em nenhum dos 2 sentidos, retorna falso
	return false;

}

/****************************************************************************************************************************************************************************/
bool tabuleiro::vertical (int tam, int linha, int coluna) {

	//Verifica se é possível inserir o barco de baixo para a cima, partindo do ponto que foi sorteado 
	if (linha - tam >= 0 ) {
		
		bool flag = false;

		//Verifica se não tenha nenhuma parte de barco no intervalo desejado
		for (int i = linha; i > linha - tam; i--) {
		
			if (tabul[i][coluna] == 1) {
		
				flag = true; //Caso haja parte de algum barco no intervalo desejado, garante que ele não será colocado lá
		
				break;
		
			}
		
		}
		
		//Caso não haja parte de barco no intervalo desejado, inclui o barco lá encerra e a função
		if (flag == false) {

			
			for (int i= linha; i > linha - tam; i--) tabul[i][coluna] = 1;
			
			return true;
		
		}

	}

	//Verifica se é possível inserir o barco de cima para baixo, partindo do ponto que foi sorteado 
	if (linha + tam <= 15) {
		
		bool flag = false;

		//Verifica se não tenha nenhuma parte de barco no intervalo desejado
		for (int i = linha; i < linha + tam; i++) {
		
			if (tabul[i][coluna] == 1) {
		
				flag = true;  //Caso haja parte de algum barco no intervalo desejado, garante que ele não será colocado lá
		
		
				break;
		
			}
		
		}

		//Caso não haja parte de barco no intervalo desejado, inclui o barco lá encerra e a função
		if (flag == false) {

			
			for (int i= coluna; i < coluna + tam; i++) tabul[linha][i] = 1;

			return true;
		
		}

	}
	
	//Caso não seja possível inserir o barco em nenhum dos 2 sentidos, retorna falso
	return false;

}

/****************************************************************************************************************************************************************************/

//Função de colocar barcos no tabuleiro
void tabuleiro::posicionaBarco(int tam) {

	srand(time(NULL));
	//Escolhe coordenadas do ponto inicial do barco aleatoriamente
	while (true) {
		

		int linha = 1 + rand() % 14;
		
		int coluna = 1 + rand() % 14;

		//Caso o ponto esteja vazio, escolhe verifica se é possível colocar o barco de alguma forma a partir dele, a princípio sorteando a orientação e o sentido
		if (tabul[linha][coluna] == 0) {
			
			int orientacao = 1 + rand() % 1;

			if (orientacao == 1) {
				if (vertical(tam, linha, coluna))	return;

				else
					if (horizontal(tam, linha, coluna)) return;
			}

			else if (horizontal(tam, linha, coluna)) return;
			
			else 
				if(vertical(tam, linha, coluna)) return;
		}	
	}
	
}

/****************************************************************************************************************************************************************************/

//Criação do encouraçado
void tabuleiro::criaEnc () {
	


	barco coura;

	coura.setTipo("Encouraçado");
	posicionaBarco(5);

}

/****************************************************************************************************************************************************************************/

//Criação do cruzador
void tabuleiro::criaCru () {
	
	barco cruza;

	cruza.setTipo("Cruzador");
	posicionaBarco(4);
		

}

/****************************************************************************************************************************************************************************/

//Criação do destroyer
void tabuleiro::criaDest() {
	barco dest;

	dest.setTipo("Destroyer");
	posicionaBarco(2);

}

/****************************************************************************************************************************************************************************/

//Criação do submarino
void tabuleiro::criaSub () {

	barco sub;
	
	sub.setTipo("Submarino");
	
	srand(time(NULL));
	//Escolhe coordenadas do ponto inicial do Submarino aleatoriamente (Não quis usar o posicionaBarco, porque o submarino só ocupa uma posição no mapa, tornando desncessária toda aquela verificação)
	while (true) {
		

		int linha = 1 + rand() % 14;
			
		int coluna = 1 + rand() % 14;

		//Caso o ponto esteja vazio, coloca o Submarino lá e encerra a função
		if(tabul[linha][coluna] == 0) {
			tabul[linha][coluna] = 1;
			return;
		}

	}
}

/****************************************************************************************************************************************************************************/

//Criação do hidro-avião
void tabuleiro::criaHidro () {

	barco hidro;
	
	hidro.setTipo("Hidro-Avião");
	hidro.setTam(3);

	posicionaHidro();
	
}

/****************************************************************************************************************************************************************************/

//Impressão do tabuleiro
void tabuleiro::imprimeTab() {	

	//Imrpime como char o primeiro elemento, com o código ascii para tab
	std::cout << char(tabul[0][0]) << " ";

	//Optei por imprimir a primeira linha fora, já que nas seguintes, por questão de espaçamento da primeira linha edas posiões do tabuleiro
	for (int i = 1; i < 16; i++) std::cout << tabul[0][i] << "	 ";

	std::cout << std::endl << std::endl;

	//Imprime posições do tabuleiro
	for (int i = 1; i < 16; i++) {
		//Transforma os códigos da tabela ascii das letras do tabuleiro e imprime
		std::cout << char(tabul[i][0]) << "    ";
		for (int j = 1; j < 16; j++) {

			if (tabul[i][j] == 69 or tabul[i][j] == 88) std::cout << char(tabul[i][j]) << " 	 "; //Códigos de E e X, caso o usuário acerte, é marcado um X no tabuleiro e caaso erre, é marcado um E

			else std::cout << tabul[i][j] << " 	 ";
			
		}

		std::cout << std::endl;
	}													
	std::cout << std::endl << std::endl << 
							"===============================================================" << std:: endl <<
							"===============================================================" << std::endl;
	
}

/****************************************************************************************************************************************************************************/

//Coloca X ou E no tabuleiro, de acordo com acerto ou erro
void tabuleiro::setPos(int linha, int coluna, int letra) {
	
	tabul[linha][coluna] = letra;
	
}

/****************************************************************************************************************************************************************************/

//retorna o que tem na determinada posição do tabuleiro
int tabuleiro::getPos(int linha, int coluna) {

	return tabul[linha][coluna];
}

/****************************************************************************************************************************************************************************/

//Posiciona o hidro-avião no tabuleiro, usei essa função porque o hidro tem uma estrutura especial
void tabuleiro::posicionaHidro() {
	srand(time(NULL));
	//Escolhe coordenadas do ponto inicial do hidro-avião aleatoriamente
	while (true) {
		

		int linha = 1 + rand() % 14;
		
		int coluna = 1 + rand() % 14;

		//Caso o ponto esteja vazio, escolhe verifica se é possível colocar o hidro de alguma forma a partir dele, a princípio sorteando a orientação e o sentido
		if (tabul[linha][coluna] == 0) {
			
			int orientacao = 1 + rand() % 1;

			if (orientacao == 1) {
				if (verticalHidro(linha, coluna))	return;

				else if (horizontalHidro(linha, coluna)) return;
			}

			else if (horizontalHidro(linha, coluna)) return;
			
			else if(verticalHidro(linha, coluna)) return;
		}	
	}
}

/****************************************************************************************************************************************************************************/
//Função para colocar o hidro na vertical
bool tabuleiro::verticalHidro(int linha, int coluna) {
	
	//Verifica se é possível inserir o hidro-avião do ponto sorteado até em cima sem que a parte de cima atinja a borda ou se posicione em algum lugar ocupado 
	if (tabul[linha-2][coluna] == 0 && linha-2 > 0) {

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até em cima e com o bico virado para a esquerda sem que o mesmo atinja a borda ou se posicione em algum lugar ocupado  
		 if (coluna-1 > 0 && tabul[linha-1][coluna-1] == 0) {

			tabul[linha][coluna] = tabul[linha-1][coluna-1] = tabul[linha-2][coluna] = 1;
			return true;

		}

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até em cima e com o bico virado para a direita sem que o mesmo atinja a borda ou se posicione em algum lugar ocupado  
		 else if (coluna+1 < 15 && tabul[linha-1][coluna+1] == 0) {

			tabul[linha][coluna] = tabul[linha-1][coluna+1] = tabul[linha-2][coluna] = 1;
			return true;

		}
		
		
	}

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até em baixo sem que a parte de baixo atinja a borda ou se posicione em algum lugar ocupado 
	if (tabul[linha+2][coluna] == 0 && linha+2 > 0) {

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até em baixo e com o bico virado para a esquerda sem que o mesmo atinja a borda ou se posicione em algum lugar ocupado  
		 if (coluna-1 > 0 && tabul[linha+1][coluna-1] == 0) {

			tabul[linha][coluna] = tabul[linha+1][coluna-1] = tabul[linha+2][coluna] = 1;
			return true;

		}

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até em baixo e com o bico virado para a direita sem que o mesmo atinja a borda ou se posicione em algum lugar ocupado  
		 else if (coluna+1 < 15 && tabul[linha+1][coluna+1] == 0) {

			tabul[linha][coluna] = tabul[linha+1][coluna+1] = tabul[linha+2][coluna] = 1;
			return true;

		}
		
		
	}

	return false;
		
	
}

/****************************************************************************************************************************************************************************/

//Função para colocar o hidro na horizontal
bool tabuleiro::horizontalHidro(int linha, int coluna) {
	
	//Verifica se é possível inserir o hidro-avião do ponto sorteado até a esquerda sem que a parte esquerda atinja a borda ou se posicione em algum lugar ocupado 
	if (tabul[linha][coluna-2] == 0 && coluna-2 > 0) {

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até a esquerda e com o bico virado para cima sem que o mesmo atinja a borda ou se posicione em algum lugar ocupado  
		 if (linha-1 > 0 && tabul[linha-1][coluna-1] == 0) {

			tabul[linha][coluna] = tabul[linha-1][coluna-1] = tabul[linha][coluna-2] = 1;
			return true;

		}

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até em a esquerda e com o bico virado para baixo sem que o mesmo atinja a borda ou se posicione em algum lugar ocupado  
		 else if (linha+1 < 15 && tabul[linha+1][coluna-1] == 0) {

			tabul[linha][coluna] = tabul[linha+1][coluna-1] = tabul[linha][coluna-2] = 1;
			return true;

		}
		
		
	}

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até a direita sem que a parte direita atinja a borda ou se posicione em algum lugar ocupado 
	if (tabul[linha][coluna+2] == 0 && coluna+2 > 0) {

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até a direita e com o bico virado para cima sem que o mesmo atinja a borda ou se posicione em algum lugar ocupado  
		 if (linha-1 > 0 && tabul[linha-1][coluna+1] == 0) {

			tabul[linha][coluna] = tabul[linha-1][coluna+1] = tabul[linha][coluna+2] = 1;
			return true;

		}

		//Verifica se é possível inserir o hidro-avião do ponto sorteado até em baixoa direita e com o bico virado para baixo sem que o mesmo atinja a borda ou se posicione em algum lugar ocupado  
		 else if (linha+1 < 15 && tabul[linha+1][coluna+1] == 0) {

			tabul[linha][coluna] = tabul[linha+1][coluna+1] = tabul[linha][coluna+2] = 1;
			return true;

		}
		
		
	}

	return false;
		
	
}