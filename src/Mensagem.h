#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <iostream>
#include "Publicacao.h"

class Perfil;

class Mensagem: public Publicacao{
	private:

	public:
		Mensagem(Perfil* autor, std::string texto);
		virtual ~Mensagem();

		virtual void curtir(Perfil* quemCurtiu);
};

#endif
