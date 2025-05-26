#include "DualList.h"

int main() 
{
    system("chcp 1251");

    List list;

    list.remove(0);
    
    for (int i = 0; i <= 1000000; i++) list.add(i);
    //for (int i = 0; i <= 500; i++) list.add(i);

    list.remove(49).remove(999999); 

    //std::cout << list;

    list.clear();
    
    list.remove(0);

    return 0;
}