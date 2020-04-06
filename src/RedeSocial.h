#ifndef REDE_SOCIAL_H
#define REDE_SOCIAL_H

#include <iostream>
#include <vector>
#include <memory>
#include "Perfil.h"

class RedeSocial{
	private:
		int max_perfis;
		int n_perfis;
		
		std::vector<std::shared_ptr<Perfil> > perfis;
		
	public:
		RedeSocial(int numeroMaximoDePerfis);
		virtual ~RedeSocial();
		
		int getQuantidadeDePerfis() const;
		std::vector<std::shared_ptr<Perfil> > getPerfis() const;
		
		bool adicionar(std::shared_ptr<Perfil> p);
		bool adicionar(Perfil* p);
		
		virtual void imprimir() const;
	
};

#endif