#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"
#include <ctime> //time
#include <cstdlib> //srand


int main(void)
{
    time_t seed = time(NULL);
    srand(seed); //necessary to have a full random number
    //std::cout << "Seed: " << seed << std::endl; //to check

    Base *ptr = generate();
    Base &ref = *ptr;

    identify(ptr);
    identify(ref);

    delete ptr;
    return 0;
}

//srand(time(NULL)); is used to seed the random number generator