#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H

#include <string>

class RedeSocial;

namespace PersistenciaDaRede{
    void salvar(std::string arquivo, RedeSocial* r);
    RedeSocial* carregar(std::string arquivo);
} //namespace PersistenciaDaRede


#endif