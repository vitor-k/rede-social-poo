#include "Disciplina.h"

Disciplina::Disciplina(std::string nome, Professor* responsavel, Disciplina* preRequisito) : Perfil(0, nome, "")
{
    this->responsavel =  responsavel;
    this->preRequisito = preRequisito;

    this->adicionarSeguidor(responsavel);
}
Disciplina::Disciplina(std::string nome, Professor* responsavel) : Perfil(0, nome, "")
{
    this->responsavel =  responsavel;
    this->preRequisito = NULL;

    this->adicionarSeguidor(responsavel);
}

Disciplina::~Disciplina(){
    std::cout << "Disciplina destruida\n";
}

Disciplina* Disciplina::getPreRequisito() const {
    if(preRequisito != NULL){
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
	return true;
}

void Disciplina::imprimir() const{
    using namespace std;
    cout << getNumeroUSP() << " - " << getNome() << endl;
    cout << "Pre-requisito:" << (getPreRequisito() ? getPreRequisito()->getNome() : " - ") << endl;
    cout << "Seguidores: " << getQuantidadeDeSeguidores() << endl;
}
