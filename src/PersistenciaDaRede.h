#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include "RedeSocial.h"

class PersistenciaDaRede{
    public:
        PersistenciaDaRede();  //default constructor is good enough
        virtual ~PersistenciaDaRede();

        void salvar(std::string arquivo, RedeSocial* r);
        RedeSocial* carregar(std::string arquivo);
        
    private:
        template <typename T>
        void leDoArquivo(std::ifstream& arquivoStream, T* destino);

        template <typename T>
        void salvaPerfisDoTipo(std::ofstream& arquivoStream, RedeSocial* r);

        void salvaPerfilIndividual(std::ofstream& arquivoStream, Aluno* perfil);
        void salvaPerfilIndividual(std::ofstream& arquivoStream, Professor* perfil);
        void salvaPerfilIndividual(std::ofstream& arquivoStream, Disciplina* perfil);
};



#endif