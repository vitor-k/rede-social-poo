#include "Pessoa.h"

Pessoa::Pessoa(int nusp, std::string nome, std::string email) : Perfil(nome), nusp(nusp), email(email){

}
Pessoa::Pessoa(int id, int nusp, std::string nome, std::string email) : Perfil(id, nome), nusp(nusp), email(email){

}

Pessoa::~Pessoa()
{
    //dtor
}

std::string Pessoa::getEmail() const{
	return this->email;
}

int Pessoa::getNumeroUSP() const{
	return this->nusp;
}
