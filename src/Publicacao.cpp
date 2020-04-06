#include "Publicacao.h"
#include "Perfil.h"

Publicacao::Publicacao(Perfil* autor, const std::string& texto){
	this->autor = autor;
	this->texto = texto;
	curtidas = 0;
}
Publicacao::~Publicacao(){
	std::cout << "Destrutor de publicacao: " << texto << std::endl;
}

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
	std::cout << texto;
	std::cout << "(" << autor->getNome() << ")";
	std::cout << "[" << curtidas << "]" << std::endl;
}


