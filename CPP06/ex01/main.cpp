#include "Serializer.hpp"

int main(void)
{
    Data *data = new Data(); //Create a new Data object and assign values to its members.
    data->name = "Max";
    data->age = 25;
    data->height = 1.80f;

    uintptr_t raw = Serializer::serialize(data);//The data pointer is serialized to an uintptr_t integer. This means the memory address of the data object is stored in raw.
    Data* deserialized = Serializer::deserialize(raw);//The uintptr_t integer raw is deserialized back to a Data* pointer. The deserialized pointer should now point to the same Data object as data.

    std::cout << std::endl;
    if (deserialized == data) {
        std::cout << "Pointers match. Serialization and deserialization are correct." << std::endl;
    } else {
        std::cout << "Pointers do not match. There is an error in serialization/deserialization." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Data:" << std::endl;
    std::cout << "Name: " << data->name << std::endl;
    std::cout << "Age: " << data->age << std::endl;
    std::cout << "Height: " << data->height << std::endl;
    std::cout << std::endl;

    std::cout << "Deserialized:" << std::endl; 
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Height: " << deserialized->height << std::endl;

    delete data;
    return 0;
}