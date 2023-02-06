#include <iostream>
#include "queue.h"

int main()
{
    setlocale(LC_ALL, "rus");


    Queue queue;
    queue.pop(); // ничего удалятся не будет, так как стек пустой

    queue.push(6);
    queue.push(1);
    queue.push(80);
    queue.push(23);

    queue.print();


    std::cout << std::endl;
    queue.pop(); queue.pop(); // удалятся два первые добавленные узлы (6 и 1)

    queue.print();

    return 0;
}