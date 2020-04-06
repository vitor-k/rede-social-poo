#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"
#include <string>

class Professor: public Pessoa{
	private:
		std::string departamento;
	public:
		Professor(int numeroUSP, std::string nome, std::string email, std::string departamento);
		Professor(int id, int numeroUSP, std::string nome, std::string email, std::string departamento);
		virtual ~Professor();

		std::string getDepartamento() const;

		virtual void imprimir() const;
};

#endif
