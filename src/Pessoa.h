#ifndef PESSOA_H
#define PESSOA_H

#include "Perfil.h"


class Pessoa : public Perfil
{
    public:
        Pessoa(int numeroUSP, std::string nome, std::string email);
        Pessoa(int id, int numeroUSP, std::string nome, std::string email);
        virtual ~Pessoa();

        virtual int getNumeroUSP() const;
        virtual std::string getEmail() const;
    protected:

    private:
        int nusp;
		std::string email;

};

#endif // PESSOA_H
