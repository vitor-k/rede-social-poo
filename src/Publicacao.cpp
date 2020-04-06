#include "Publicacao.h"


Publicacao::Publicacao(Perfil* autor, const std::string& texto){
	this->autor = autor;
	this->texto = texto;
}
Publicacao::~Publicacao(){}

Perfil* Publicacao::getAutor() const{
	return this->autor;
}
std::string Publicacao::getTexto() const{
	return this->texto;
}

void Publicacao::curtir(Perfil* quemCurtiu){
	if(quemCurtiu != autor){
		this->curtidas++;
	}
}

int Publicacao::getCurtidas() const{
	return this->curtidas;
}

void Publicacao::imprimir() const{
	std::cout << "Teste imprimir publicacao" << std::endl;
}


