#ifndef REDE_SOCIAL_H
#define REDE_SOCIAL_H

#include "Perfil.h"
#include <iostream>

class RedeSocial{
	private:
		const int max_perfis;
		int n_perfis;
		
		Perfil** perfis;
		
	public:
		RedeSocial(int numeroMaximoDePerfis);
		virtual ~RedeSocial();
		
		int getQuantidadeDePerfis() const;
		Perfil** getPerfis() const;
		
		bool adicionar(Perfil* p);
		
		virtual void imprimir() const;
	
};

#endif