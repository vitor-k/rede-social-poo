#include "IdInvalido.h"

IdInvalido::IdInvalido() : std::logic_error("Id invalido")
{
    //ctor
}
IdInvalido::~IdInvalido() noexcept{}
