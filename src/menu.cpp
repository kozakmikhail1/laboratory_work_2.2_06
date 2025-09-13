#include "menu.h"


void Print_Menu_Constructor()
{
    std::cout << "You must select a constructor to create the array: "<< std::endl;
    std::cout << "1.Basic Constructor."<< std::endl;
    std::cout << "2.Constructor with input of array length."<< std::endl;

}

void Print_Menu()
{
    std::cout << "\tMenu"<< std::endl;
    std::cout << "1.Entering values for an array "<< std::endl;
    std::cout << "2.Displaying an array on the screen"<< std::endl;
    std::cout << "3.Using an overloaded operation '!' for array"<< std::endl;
    std::cout << "4.Exit"<< std::endl;
}

void Menu::Choose_Operation()
{
    while(true)
    {
        Print_Menu();
        int choose = Input_Int("Enter number of operation ");
        switch (choose)
        {
        case 1:
            Enter(arr_1);
            break;
        case 2:
            Show(arr_1,"\nArray ");
            std::cout <<" " << std::endl;
            break;
        case 3:
            arr_1 = !arr_1;
            break;
        case 4:
            return;
        default:
            std::cout <<C_RED <<"You make mistake"<<C_WHITE<<std::endl;
            break;
        }
    }
}
void Menu::Choose_Constructor()
{
    int choose = 0;
    Print_Menu_Constructor();

    while(true)
    {
        choose = Input_Int("Enter number of operation ");
        switch (choose)
        {
            case 1:
            {
                Array temp_arr;
                arr_1 = temp_arr;
                Choose_Operation();
                return;
            }
            case 2:
            {
                Array temp_arr_(Input_Int("Enter size of array "));
                arr_1 = temp_arr_;
                Choose_Operation();
                return;
            }
            default:
                std::cout << C_RED << "You make mistake"<< C_WHITE <<std::endl;
                break;
        }
    }
}


void Menu::Start()
{
    system("clear");
    Choose_Constructor();
}