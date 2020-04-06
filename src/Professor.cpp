#include "Professor.h"

Professor::Professor(int numeroUSP, std::string nome, std::string email, std::string departamento): Pessoa(numeroUSP, nome, email){
	this->departamento = departamento;
}
Professor::Professor(int id, int numeroUSP, std::string nome, std::string email, std::string departamento): Pessoa(id, numeroUSP, nome, email){
	this->departamento = departamento;
}
Professor::~Professor(){}
std::string Professor::getDepartamento() const{
	return this->departamento;
}
void Professor::imprimir() const{
	using namespace std;
	cout << getId() << " - " << getNome();
	cout << getNumeroUSP();
	cout << "Departamento: " << departamento << endl;
	cout << "Seguidores: " << getSeguidores()->size() << endl;
}
