#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <string>
#include <iostream>
#include <memory>

#include "Perfil.h"
class Perfil;

class Publicacao{
	private:
		Perfil* autor;
		std::string texto;
		int curtidas;
	public:
		Publicacao(Perfil* autor, const std::string& texto);
		virtual ~Publicacao();
		
		Perfil* getAutor() const;
		std::string getTexto() const;
		
		virtual void curtir(Perfil* quemCurtiu);
		virtual int getCurtidas() const;
		
		virtual void imprimir() const;
};

#endif