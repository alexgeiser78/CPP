#ifndef ITER_HPP
#define ITER_HPP

# include<iostream>

template<typename T_array, typename T_function> //function template that can work with two types: T_array and T_function
                                                //T_array is a placeholder for the type of the array
                                                //T_function is a placeholder for the type of the function
void iter(T_array *array, size_t length, T_function function)
{
    size_t i = 0;

    while(i < length)
    {
        function(array[i]);
        i++;
    }
}

#endif