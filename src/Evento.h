#ifndef EVENTO_H
#define EVENTO_H

#include "Publicacao.h"

class Evento : public Publicacao{
	private:
		std::string data;
	public:
		Evento(Perfil* autor, std::string data, std::string texto);
		virtual ~Evento();
		
		std::string getData() const;
		
		void imprimir() const;
};

#endif