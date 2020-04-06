#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Perfil.h"
#include "Professor.h"
#include <string>

class Disciplina : public Perfil{
	private:
		Professor* responsavel;
		Disciplina* preRequisito;
		
	public:
		Disciplina(std::string nome, Professor* responsavel);
		Disciplina(std::string nome, Professor* responsavel, Disciplina* preRequisito);
		virtual ~Disciplina();
		
		Professor* getResponsavel() const;
		Disciplina* getPreRequisito() const;
}


#endif