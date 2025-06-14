// Object.hpp
#ifndef Object_hpp
#define Object_hpp

#include "Model.hpp"
#include <memory>
#include <string>
#include "Ply.hpp"
#include "Obj.hpp"

template <class T>
class Object : public T {  // Hereda directamente de T
    static_assert(std::is_base_of<Model, T>::value, "T must be derived from Model");

public:
    Object() : T() {} // Llama al constructor vacío de T
    Object(const std::string& filename) : T(filename) {} // Llama al constructor de T que toma un filename

    // Los métodos públicos de T estarán accesibles automáticamente
};

#endif /* Object_hpp */
