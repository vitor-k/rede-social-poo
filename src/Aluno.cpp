#include "Aluno.h"

Aluno::Aluno(int numeroUSP, std::string nome, std::string email) : Pessoa(numeroUSP, nome, email)
{
    //ctor
}
Aluno::Aluno(int id, int numeroUSP, std::string nome, std::string email) : Pessoa(id, numeroUSP, nome, email)
{
    //ctor
}

Aluno::~Aluno()
{
    std::cout<< "Destrutor de aluno" << std::endl;
    //dtor
}

void Aluno::imprimir() const{
    using namespace std;
	cout << endl << getId() << " - " << getNome() << endl;
    cout << getNumeroUSP() << endl;

    cout << "Seguidores: " << getSeguidores()->size() << endl;
}