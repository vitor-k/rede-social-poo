#include "RedeSocial.h"


RedeSocial::RedeSocial(int numeroMaximoDePerfis){
	max_perfis = numeroMaximoDePerfis;
	n_perfis = 0;
	
	
}
RedeSocial::~RedeSocial(){
}

int RedeSocial::getQuantidadeDePerfis() const{
	return n_perfis;
}
std::vector<std::shared_ptr<Perfil>> RedeSocial::getPerfis() const{
	return perfis;
}

bool RedeSocial::adicionar(std::shared_ptr<Perfil> p){
	if(n_perfis < max_perfis){
		perfis.push_back(p);
		n_perfis++;
		return true;
	}
	return false;
}
bool RedeSocial::adicionar(Perfil* p){
	return this->adicionar(std::shared_ptr<Perfil>(p));
}

void RedeSocial::imprimir() const{
	std::cout << "teste rede social" << std::endl;
}

