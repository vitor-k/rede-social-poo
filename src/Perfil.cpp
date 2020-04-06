#include "Perfil.h"
#include "Publicacao.h"
#include "Evento.h"
#include "Mensagem.h"

int Perfil::lastId = 0;

Perfil::Perfil(int id, std::string nome){
	this->nome = nome;

	this->id = id;
}

Perfil::Perfil(std::string nome){
	this->nome = nome;

	id = ++lastId;
}

Perfil::~Perfil(){
	std::cout<< "Destrutor de perfil: " << nome << " - Quantidade de publicacoes feitas: " << numFeitas <<std::endl;

	for(Publicacao* pub: feitas){
		delete pub;
	}

	std::cout << "Perfil " << nome << " deletado" <<std::endl;
}

bool Perfil::seguidoPor(Perfil* p){
	for(unsigned int i=0; i<seguidores.size(); i++){
		if(seguidores[i] == p){
			return true;
		}
	}
	return false;
}

void Perfil::adicionarSeguidor(Perfil* seguidor){
	if(seguidor == this){
		throw std::logic_error("Tentando seguir proprio perfil");
	}
	if(seguidoPor(seguidor)){
		throw std::logic_error("Ja eh seguidor");
	}
	seguidores.push_back(seguidor);

	std::string mensagemNovoSeguidor = "Novo seguidor: ";  //implicit string construction from char*
	mensagemNovoSeguidor.append(seguidor->getNome());
	Publicacao* pub = new Mensagem(this, mensagemNovoSeguidor);
	this->receber(pub);
}

void Perfil::publicar(Publicacao* p){
	feitas.push_back(p);
	for(unsigned int i=0; i < seguidores.size(); i++){
		seguidores[i]->receber(p);
	}
}
void Perfil::publicar(std::string texto){
	Publicacao* pub = new Mensagem(this, texto);
	publicar(pub);
}
void Perfil::publicar(std::string texto, std::string data){
	Publicacao* pub = new Evento(this, data, texto);
	publicar(pub);
}

bool Perfil::receber(Publicacao* p){
	recebidas.push_back(p);

	return true;
}

std::list<Publicacao*>* Perfil::getPublicacoesFeitas() const{
	return const_cast<std::list<Publicacao*>*>(&feitas);
}

std::list<Publicacao*>* Perfil::getPublicacoesRecebidas() const{
	return const_cast<std::list<Publicacao*>*>(&recebidas);
}

std::vector<Perfil*>* Perfil::getSeguidores() const{
	return const_cast<std::vector<Perfil*>*>(&seguidores);
}

std::string Perfil::getNome() const{
	return nome;
}

int Perfil::getId() const{
  return id;
}

void Perfil::setUltimoId(int ultimoId){
	lastId = ultimoId;
}
int Perfil::getUltimoId(){
	return lastId;
}
