
#include "Evento.h"

Evento::Evento(Perfil* autor, std::string data, std::string texto): Publicacao(autor, texto){
	this->data = data;
}

Evento::~Evento(){}

std::string Evento::getData() const{
	return data;
}

void Evento::imprimir() const{
	std::cout << data << " - ";
	Publicacao::imprimir();

}

void Evento::curtir(Perfil* quemCurtiu){
	Publicacao::curtir();
}
// void Evento::imprimir() const{
	// std::cout << "Evento: " << texto << std::endl;
	// std::cout << "Autor: " << autor->getNome() << std::endl;
	// std::cout << "Data: " << data << std::endl;
// }
