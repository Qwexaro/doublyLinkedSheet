#include "List.h"

int main()
{
    system("chcp 1251");
    
    List<int> int_list;
    List<std::string> str_list;
    List<double> double_list;

    int_list.add(1).add(2).add(3).add(4).add(5).add(6).add(7);
    
    int_list.remove(0).remove(3);

    str_list.add("Каждый").add("охотник").add("желает").add("знать").add("где").add("сидит").add("Фёдор");

    str_list.remove(2).remove(2).remove(2).remove(2);

    double_list.add(12.3).add(19.9).add(11.6).add(2.5).add(4.7).add(5).add(9.9).add(12.5);
   
    double_list.remove(3);

    std::cout << int_list << str_list << double_list;

    int_list.clear();
    str_list.clear();
    double_list.clear();

    return 0;
}