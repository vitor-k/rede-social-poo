#include "Professor.h"


Professor::Professor(int numeroUSP, std::string nome, std::string email, std::string departamento): Perfil(numeroUSP, nome, email){
	this->departamento = departamento;
}
Professor::~Professor(){}
std::string Professor::getDepartamento() const{
	return this->departamento;
}