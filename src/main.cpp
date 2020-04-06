#include <memory>
#include "Perfil.h"
#include "RedeSocial.h"
#include "Professor.h"

int main(){
	RedeSocial rede{5};
	
	std::shared_ptr<Perfil> teste{new Perfil(10274012, "Vini", "vmbenevides@usp.br")};
	
	rede.adicionar(teste);
	rede.imprimir();
	teste->imprimir();
	
	std::shared_ptr<Perfil> teste2{new Professor( 12345678, "Debug", "debug@dd.com", "PSI1000")};
	rede.adicionar(teste2);
	rede.getPerfis()[0]->adicionarSeguidor(rede.getPerfis()[1]);
	
	rede.imprimir();
	teste->imprimir();
	teste2->imprimir();
	
	return 0;
}