#include "Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &obj)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = obj;
}

Serializer &Serializer::operator=(Serializer const &obj)
{
    std::cout << "Serializer assignation operator called" << std::endl;
    if (this != &obj)
	{
		*this = obj;
	}
    return *this;
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

//reinterpret_cast = converts any pointer type to any other pointer type, even of unrelated classes.
//It can also be used to cast a pointer to an integer type and vice versa.
//uintptr_t raw = Serializer::serialize(data); converts the Data* pointer to a uintptr_t integer. This is useful for storing or transmitting the pointer value as an integer.
//reinterpret_cast<Data*>(raw) converts the uintptr_t integer back to a Data* pointer. This restores the original pointer value so that it can be used to access the Data object again.