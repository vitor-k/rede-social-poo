#include "Professor.h"

Professor::Professor(int numeroUSP, std::string nome, std::string email, std::string departamento): Perfil(numeroUSP, nome, email){
	this->departamento = departamento;
}
Professor::~Professor(){}
std::string Professor::getDepartamento() const{
	return this->departamento;
}
void Professor::imprimir() const{
	using namespace std;
	cout << getNumeroUSP() << " - " << getNome() << endl;
	cout << "Departamento: " << departamento << endl;
	cout << "Seguidores: " << getQuantidadeDeSeguidores() << endl;
}