#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"
# include <stdint.h> //uintptr_t (unsigned integer type that is capable of storing a data pointer)

class Serializer
{
    private:
        Serializer(void);
        Serializer(Serializer const &obj);
        Serializer &operator=(Serializer const &obj);
        ~Serializer(void);
    public:
        static uintptr_t serialize(Data *ptr); //Converts a Data* pointer to an uintptr_t integer using reinterpret_cast.
        static Data* deserialize(uintptr_t raw);//Converts an uintptr_t integer back to a Data* pointer using reinterpret_cast.
};

#endif

//Serialization is the process of converting an object into a stream 
//of bytes to store the object or transmit it to memory, a database, 
//or a file. Its main purpose is to save the state of an object 
//in order to be able to recreate it when needed. The reverse process 
//is called deserialization.