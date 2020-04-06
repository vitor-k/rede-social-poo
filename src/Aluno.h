#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"
#include "Publicacao.h"

class Aluno : public Pessoa {
    public:
        Aluno(int numeroUSP, std::string nome, std::string email);
        Aluno(int id, int numeroUSP, std::string nome, std::string email);
        virtual ~Aluno();

        void imprimir() const;
    protected:

    private:
};

#endif // ALUNO_H
