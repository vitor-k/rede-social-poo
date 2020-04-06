#include "Perfil.h"


Perfil::Perfil(int numeroUSP, std::string nome, std::string email){
	this->nusp = numeroUSP;
	this->nome = nome;
	this->email = email; //sanity check?
	
	n_seguidores = 0;
	
	n_feitas = 0;
	
	n_recebidas = 0;
}

Perfil::~Perfil(){
	std::cout << nome << " was destroyed" << std::endl;
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

bool Perfil::adicionarSeguidor(std::weak_ptr<Perfil> seguidor){
	std::shared_ptr<Perfil> shared_seguidor = static_cast<std::shared_ptr<Perfil>>(seguidor);
	if(n_seguidores >= MAXIMO_SEGUIDORES || shared_seguidor.get() == this){
		return false;
	}
	for(int i=0; i<n_seguidores; i++){
		if(std::shared_ptr<Perfil>(seguidores[i]).get() == shared_seguidor.get()){
			return false;
		}
	}
	
	seguidores.push_back(std::weak_ptr<Perfil>(seguidor));
	n_seguidores++;

	std::string mensagemNovoSeguidor = "Novo seguidor: ";  //implicit construction
	mensagemNovoSeguidor.append(shared_seguidor->getNome());
	
	std::shared_ptr<Publicacao> pub{ new Publicacao(this, mensagemNovoSeguidor)};
	
	feitas.push_back(pub);
	n_feitas++;
	
	return true;
}

bool Perfil::publicar(std::string texto){
	if(n_feitas < MAXIMO_PUBLICACOES){
		std::shared_ptr<Publicacao> pub{ new Publicacao(this , texto)};
		// feitas[n_feitas++] = pub;
		feitas.push_back(pub);
		n_feitas++;
		
		for(int i=0; i < n_seguidores; i++){
			std::shared_ptr<Perfil>(seguidores[i])->receber(pub);
		}
		return true;
	}
	else{
		return false;
	}
}
// bool Perfil::publicar(std::string texto, std::string data);

bool Perfil::receber(std::weak_ptr<Publicacao> p){
	if(n_recebidas >= MAXIMO_PUBLICACOES){
		return false;
	}
	
	recebidas.push_back(p);
	n_recebidas++;
	
	return true;
}

std::vector<std::shared_ptr<Publicacao> > Perfil::getPublicacoesFeitas() const{
	return this->feitas;
}
int Perfil::getQuantidadeDePublicacoesFeitas() const{
	return this->n_feitas;
}

std::vector<std::weak_ptr<Publicacao> > Perfil::getPublicacoesRecebidas() const{
	return this->recebidas;
}
int Perfil::getQuantidadeDePublicacoesRecebidas() const{
	return this->n_recebidas;
}

std::vector<std::weak_ptr<Perfil> > Perfil::getSeguidores() const{
	return this->seguidores;
}
int Perfil::getQuantidadeDeSeguidores() const{
	return this->n_seguidores;
}

void Perfil::imprimir() const{
	std::cout << "Ola, meu nome eh " << nome << std::endl;
	std::cout << "Numero usp: " << nusp << std::endl;
	std::cout << "email: " << email << std::endl;
	
	for(int i=0; i<n_feitas; i++){
		std::cout << std::shared_ptr<Publicacao>(feitas[i])->getTexto() << std::endl;
	}
}


