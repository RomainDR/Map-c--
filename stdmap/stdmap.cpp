#include <iostream>
#include <string>
#include "Map.h"

int main()
{
    Map<int, std::string> map = Map<int, std::string>();
    map.Insert(1, std::to_string(15));
    map.Insert(4, "Hello");
    map.Display();
    std::cout << "=====================" << std::endl;
    map.At(1) = "He";
    std::cout << "Map1 => " << map[1] << std::endl;
    map.Display(); 
    std::cout << "=====================" << std::endl;
    map.Clear();
    map.Display();
}