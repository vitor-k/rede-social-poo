#include "Perfil.h"
#include "Publicacao.h"
#include "Evento.h"

Perfil::Perfil(int numeroUSP, std::string nome, std::string email){
	this->nusp = numeroUSP;
	this->nome = nome;
	this->email = email; //seria bom ter um sanity check, mas nao esta na especificacao
	
	seguidores = new Perfil*[MAXIMO_SEGUIDORES];
	numSeguidores = 0;
	
	feitas = new Publicacao*[MAXIMO_PUBLICACOES];
	numFeitas = 0;
	
	recebidas = new Publicacao*[MAXIMO_PUBLICACOES];
	numRecebidas = 0;
}

Perfil::~Perfil(){
	std::cout<< "Destrutor de perfil: " << nome << " - Quantidade de publicacoes feitas: " << numFeitas <<std::endl;

    for(int i=0; i<numFeitas; i++){
        delete feitas[i];
    }
	delete[] seguidores;
	delete[] feitas;
	delete[] recebidas;
	
    std::cout << "Perfil " << nome << " deletado" <<std::endl;
}

int Perfil::getNumeroUSP() const{
	return this-> nusp;
}

std::string Perfil::getNome() const{
	return this->nome;
}
std::string Perfil::getEmail() const{
	return this->email;
}

bool Perfil::adicionarSeguidor(Perfil* seguidor){
	if(numSeguidores >= MAXIMO_SEGUIDORES || seguidor == this){
		return false;
	}
	for(int i=0; i<numSeguidores; i++){
		if(seguidores[i] == seguidor){
			return false;
		}
	}
	seguidores[numSeguidores++] = seguidor;

	std::string mensagemNovoSeguidor = "Novo seguidor: ";  //implicit string construction from char*
	mensagemNovoSeguidor.append(seguidor->getNome());
	Publicacao* pub = new Publicacao(this, mensagemNovoSeguidor);
	this->receber(pub);
	
	return true;
}

void Perfil::publicar(Publicacao* p){
	feitas[numFeitas++] = p;
	for(int i=0; i < numSeguidores; i++){
		seguidores[i]->receber(p);
	}
}
bool Perfil::publicar(std::string texto){
	if(numFeitas < MAXIMO_PUBLICACOES){
		Publicacao* pub = new Publicacao(this, texto);
		publicar(pub);
		return true;
	}
	return false;
}
bool Perfil::publicar(std::string texto, std::string data){
	if(numFeitas < MAXIMO_PUBLICACOES){
		Publicacao* pub = new Evento(this, data, texto);
		publicar(pub);
		return true;
	}
	return false;
}

bool Perfil::receber(Publicacao* p){
	if(numRecebidas >= MAXIMO_PUBLICACOES){
		return false;
	}
	
	recebidas[numRecebidas++] = p;
	
	return true;
}

Publicacao** Perfil::getPublicacoesFeitas() const{
	return feitas;
}
int Perfil::getQuantidadeDePublicacoesFeitas() const{
	return this->numFeitas;
}

Publicacao** Perfil::getPublicacoesRecebidas() const{
	return recebidas;
}
int Perfil::getQuantidadeDePublicacoesRecebidas() const{
	return this->numRecebidas;
}

Perfil** Perfil::getSeguidores() const{
	return seguidores;
}
int Perfil::getQuantidadeDeSeguidores() const{
	return this->numSeguidores;
}

void Perfil::imprimir() const{
    using namespace std;
	cout << nusp << " - " << nome << endl;
	cout << "Seguidores: " << numSeguidores << endl;

}
