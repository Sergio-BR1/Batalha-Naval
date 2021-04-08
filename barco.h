#pragma once

#include <iostream>

class barco {
	private:
		int tamanho;
		std::string tipo;


	public:

		barco ();

		barco (std::string tp);

		void setTam(int tam);

		int getTam();

		void setTipo(std::string tp);

		std::string getTipo();

	
};