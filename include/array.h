#pragma once
#include <iostream>
#include "functions.h"

class Array
{
    int *data;
    int size;
 
    public :

    Array();
    explicit Array(int size);
    Array(const Array &other_arr);
    Array(Array &&) noexcept;
    ~Array();

    Array & operator !(); 
    Array & operator = (Array &&other) noexcept;

    friend void Show (const Array& arr, std::string message);
    friend void Enter(Array& arr);

    int Get_Size() const;
    bool Is_Empty();

};