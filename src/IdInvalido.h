#ifndef IDINVALIDO_H
#define IDINVALIDO_H

#include <stdexcept>


class IdInvalido : public std::logic_error
{
    public:
        IdInvalido();
        virtual ~IdInvalido() noexcept;
};

#endif // IDINVALIDO_H
