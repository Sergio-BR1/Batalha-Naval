#include <iostream>
#include "barco.h"

barco::barco () {
	
}

/*barco::barco(std::string tp) {

	tipo = tp;
	
	//Define o tamanho de acordo com o tipo de barco escolhido
	if (tipo == "Couraçado")
		tamanho = 5;

	else if (tipo == "Cruzador")
		tamanho = 4;

	else if (tipo == "Submarino")
		tamanho = 1;

	else if (tipo == "Hidro-Avião")
		tamanho = 3;
} */

/****************************************************************************************************************************************************************************/

//Define o tamanho do barco
void barco::setTam(int tam) {

	tamanho = tam;
	
}

/****************************************************************************************************************************************************************************/

//Retorna o tamanho do barco
int barco::getTam () {

	return tamanho;

}

/****************************************************************************************************************************************************************************/

//Define o tipo do barco
void barco::setTipo(std::string tp) {

	tipo = tp;


}

/****************************************************************************************************************************************************************************/

//Retorna o tipo do barco
std::string barco::getTipo () {

	return tipo;

}