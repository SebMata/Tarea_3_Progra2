#ifndef ExcepcionProductoNoExiste_H
#define ExcepcionProductoNoExiste_H

#include <exception>

class ExcepcionProductoNoExiste : public std::exception
{
    public:
    ExcepcionProductoNoExiste() noexcept = default;
    ~ExcepcionProductoNoExiste() = default;

    virtual const char* what() const noexcept {
        return "El producto indicado no existe.";
    }

};

#endif