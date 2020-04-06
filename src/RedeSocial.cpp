#include "RedeSocial.h"


RedeSocial::RedeSocial(int numeroMaximoDePerfis) : max_perfis(numeroMaximoDePerfis){
	n_perfis = 0;
	
	perfis = new Perfil*[max_perfis];
}
RedeSocial::~RedeSocial(){
	std::cout << "Destrutor de RedeSocial: " << n_perfis << " perfis" << std::endl;
	for(int i=0; i<n_perfis; i++){
		delete perfis[i];
	}
	
	delete[] perfis;
}

int RedeSocial::getQuantidadeDePerfis() const{
	return n_perfis;
}
Perfil** RedeSocial::getPerfis() const{
	return perfis;
}

bool RedeSocial::adicionar(Perfil* p){
	if(n_perfis < max_perfis){
		perfis[n_perfis++] = p;
		
		return true;
	}
	return false;
}

void RedeSocial::imprimir () const{
	std::cout << std::endl << "------------------------------ " << std::endl;
	std::cout << "RedeSocial: " << n_perfis << " perfis" << std::endl;
	std::cout << "------------------------------ " << std::endl;
	if (n_perfis == 0){
		std::cout << "Sem perfis" << std::endl;
		std::cout << "------------------------------ " << std::endl;
	}
	else{
		for (int i = 0; i < n_perfis; i++){
			perfis[i]->imprimir();
			std::cout << "------------------------------ " << std::endl;
		}
	}
	std::cout << std::endl;
}

