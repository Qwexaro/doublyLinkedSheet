#include "List.h"

template <typename T>
int main()
{
    List<T> list;
    system("chcp 1251");

    //for (int i = 0; i <= 1000000; i++) list.add(i);
    //for (int i = 0; i <= 500; i++) list.add(i);

    list.add("d").add(2).add(3).add(4).add(5).add(6).add(7);

    list.remove(0).remove(3);

    std::cout << list;

    list.clear();

    list.remove(0);

    return 0;
}