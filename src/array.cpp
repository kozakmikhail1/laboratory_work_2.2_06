#include "array.h"

Array::Array() : Array (3){}

Array::Array(int size): size(size), data(nullptr)
{
    auto * temp = new int[size]{};
    data = temp;
}

Array::Array(const Array& other_arr) : size(other_arr.size), data(new int[other_arr.size]) 
{
    for (size_t i = 0; i < size; ++i) {
        data[i] = other_arr.data[i];
    }
}

Array::Array(Array && other)noexcept : size(other.size), data(other.data)
{
    other.size = 0;
    other.data = nullptr;
}

Array::~Array()
{
    delete[] data;
    data = nullptr;
    size = 0;
}


Array &  Array :: operator !()
{
    auto * temp = new int[size * 2];
    for(int i = 0;i < size;i++)
    {
        temp[i] = data[i];
        temp[i + size] = data[i];
    }
    delete[] data;
    data = temp;
    size *= 2;

    return *this;
}

// Правильное перемещающее присваивание
Array& Array::operator=(Array&& other) noexcept 
{
    if (this != &other) {
        delete[] data;     // Освобождаем старые данные
        
        data = other.data; // Перехватываем ресурсы
        size = other.size;
        
        other.data = nullptr;  // Обнуляем исходный объект
        other.size = 0;
    }
    return *this;
}
int Array::Get_Size() const {  return size;  };

bool Array::Is_Empty()
{
    return data == nullptr;
}

void Show(const Array & arr, std::string message)
{
    if(arr.data != nullptr)
    {
        std::cout << message << std::endl;
        for(int i = 0;i < arr.size;i++)
        {
            std::cout << arr.data[i] << " ";
        }
        std::cout << "" << std::endl;
    }
}

void Enter(Array &arr)
{
    if(arr.size != 0)
    {
        for(int i = 0;i < arr.size;i++)
        {
            std::cout << "Enter one value for the array [" << i + 1 << "]"<<std::endl;
            arr.data[i] = Input_Int("");
        }
    }
}