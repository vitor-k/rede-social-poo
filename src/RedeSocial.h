#ifndef REDE_SOCIAL_H
#define REDE_SOCIAL_H

#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"
#include <iostream>
#include <string>
#include <vector>

class Perfil;

class RedeSocial{
	private:
		std::vector<Perfil*> perfis;

	public:
		RedeSocial();
		virtual ~RedeSocial();

		std::vector<Perfil*>* getPerfis();
		Perfil* getPerfil(int id) const;

		void adicionar(Perfil* perfil);

		virtual void imprimir() const;

};

#endif
