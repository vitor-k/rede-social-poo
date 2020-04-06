#include "Disciplina.h"

Disciplina::Disciplina(std::string nome, Professor* responsavel, Disciplina* preRequisito) : Perfil(nome)
{
	this->responsavel =  responsavel;
	this->preRequisito = preRequisito;

	this->adicionarSeguidor(responsavel);
}
Disciplina::Disciplina(std::string nome, Professor* responsavel) : Perfil(nome)
{
	this->responsavel =  responsavel;
	this->preRequisito = nullptr;

	this->adicionarSeguidor(responsavel);
}

Disciplina::Disciplina(int id, std::string nome, Professor* responsavel, Disciplina* preRequisito) : Perfil(id, nome)
{
	this->responsavel =  responsavel;
	this->preRequisito = preRequisito;
}

Disciplina::~Disciplina(){
	std::cout << "Disciplina destruida\n";
}

Disciplina* Disciplina::getPreRequisito() const {
	if(preRequisito != nullptr){
		return preRequisito;
	}
	else{
		return NULL;
	}
}
Professor* Disciplina::getResponsavel() const {
	return responsavel;
}

bool Disciplina::receber(Publicacao* p){
	return false;
}

void Disciplina::imprimir() const{
	using namespace std;
	cout  << getId() << " - " << getNome() <<  endl;
	cout << "Pre-requisito:" << (getPreRequisito() ? getPreRequisito()->getNome() : " - ") << endl;
	cout << "Seguidores: " << (getSeguidores())->size() << endl;
}
