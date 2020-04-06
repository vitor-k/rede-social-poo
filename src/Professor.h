#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Perfil.h"
#include <string>

class Professor: public Perfil{
	private:
		std::string departamento;
	public:
		Professor(int numeroUSP, std::string nome, std::string email, std::string departamento);
		virtual ~Professor();
		
		std::string getDepartamento() const;
};

#endif