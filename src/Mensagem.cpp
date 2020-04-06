#include "Mensagem.h"
#include "Perfil.h"
#include <stdexcept>

Mensagem::Mensagem(Perfil* autor, std::string texto): Publicacao(autor,texto){
}
Mensagem::~Mensagem(){
	std::cout << "Destrutor de mensagem: " << getTexto() << std::endl;
}

void Mensagem::curtir(Perfil* quemCurtiu){
	if(quemCurtiu != getAutor()){
		Publicacao::curtir();
	}
	else{
		throw std::invalid_argument("Autor nao pode curtir mensagem");
	}
}
