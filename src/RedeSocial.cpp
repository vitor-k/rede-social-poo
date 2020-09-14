#include "RedeSocial.h"
#include "Perfil.h"
#include "IdInvalido.h"

RedeSocial::RedeSocial(){
}
RedeSocial::~RedeSocial(){
	std::cout << "Destrutor de RedeSocial: " << perfis.size() << " perfis" << std::endl;
	for(unsigned int i=0; i<perfis.size(); i++){
		delete perfis[i];
	}
}
std::vector<Perfil*>* RedeSocial::getPerfis(){
	return &perfis;
}

void RedeSocial::adicionar(Perfil* p){
	perfis.push_back(p);
}

Perfil* RedeSocial::getPerfil(int id) const{
    if(id <= Perfil::getUltimoId()){
        for(unsigned int i=0; i<perfis.size();i++){
            if(perfis[i]->getId() == id){
                return perfis[i];
            }
        }

    }
    throw IdInvalido();
}

void RedeSocial::imprimir () const{
	std::cout << std::endl << "------------------------------ " << std::endl;
	std::cout << "RedeSocial: " << perfis.size() << " perfis" << std::endl;
	std::cout << "------------------------------ " << std::endl;
	if (perfis.empty()){
		std::cout << "Sem perfis" << std::endl;
		std::cout << "------------------------------ " << std::endl;
	}
	else{
		for (unsigned int i = 0; i < perfis.size(); i++){
			perfis[i]->imprimir();
			std::cout << "------------------------------ " << std::endl;
		}
	}
	std::cout << std::endl;
}
