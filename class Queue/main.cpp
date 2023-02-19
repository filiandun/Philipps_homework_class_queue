#include <iostream>
#include "queue.h"

int main()
{
    setlocale(LC_ALL, "rus");

// ТЕСТ МЕЛОЧИ
 
    //Queue queue;
    //std::cout << "ПОПЫТКА УДАЛИТЬ ЭЛЕМЕНТ У ПУСТОЙ ОЧЕРЕДИ: "; queue.pop(); // ничего не удалится, так как очередь пустая


    //// ФУНКЦИЯ PUSH
    //std::cout << std::endl << "ФУНКЦИЯ PUSH:" << std::endl;

    //queue.push(6); std::cout << "Добавлено 6 " << std::endl;
    //queue.push(1); std::cout << "Добавлено 1 " << std::endl;
    //queue.push(80); std::cout << "Добавлено 80 " << std::endl;
    //queue.push(23); std::cout << "Добавлено 23 " << std::endl;

    //std::cout << "QUEUE, В КОТОРЫЙ БЫЛИ ДОБАВЛЕНЫ ЭЛЕМЕНТЫ ВЫШЕ: "; queue.print(); std::cout << std::endl;


    //// ФУНКЦИЯ POP
    //std::cout << "ФУНКЦИЯ POP:" << std::endl;

    //queue.pop(); std::cout << "Удален первый добавленный элемент (6)" << std::endl; 
    //queue.pop(); std::cout << "Удален второй добавленный элемент (1)" << std::endl; // удалятся два первые добавленные узлы (6 и 1)

    //std::cout << "QUEUE, У КОТОРОГО БЫЛИ УДАЛЕНЫ ПЕРВЫЕ ДВА ДОБАВЛЕННЫЕ ЭЛЕМЕНТЫ: "; queue.print(); std::cout << std::endl << std::endl;



// ТЕСТ ГЛОБАЛЬНЕЕ

    Queue queue_1(6, 2, 0, 30, 654, 101, 44); // первое число - длина будущей очереди, а дальше числа, которые добавить нужно
    Queue queue_2(5, 101, 44, 12, 0, 988); 
    Queue queue_3(7, 344, 1, 112, 21, 48, 90, 1001);
    Queue queue_4(6, 1001, 1, 76, 564, 19, 21);



    // КОНСТРУКТОР КОПИРОВАНИЯ
    std::cout << "КОНСТРУКТОР КОПИРОВАНИЯ: " << std::endl;

    std::cout << "ПОПЫТКА СКОПИРОВАТЬ ПУСТУЮ ОЧЕРЕДЬ: "; 
    Queue queue_nullptr; Queue queue_2_construct_copy = queue_nullptr; // не даст скопировать, так как копируемая очередь пустая

    Queue queue_1_construct_copy = queue_1;

    std::cout << "QUEUE_1: "; queue_1.print();
    std::cout << "QUEUE_1_CONSTRUCT_COPY: "; queue_1_construct_copy.print(); std::cout << std::endl << std::endl;



    // КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ
    std::cout << "КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ: " << std::endl;

    std::cout << "QUEUE_1_COPY ДО: "; queue_1_construct_copy.print();

    Queue queue_1_construct_move = std::move(queue_1_construct_copy);

    std::cout << "QUEUE_1_COPY ПОСЛЕ: "; queue_1_construct_copy.print(); 
    std::cout << "QUEUE_1_CONSTRUCT_MOVE: "; queue_1_construct_move.print(); std::cout << std::endl << std::endl;



    // ФУНКЦИЯ COPY_IN
    std::cout << "ФУНКЦИЯ COPY_IN:" << std::endl;

    std::cout << "ПОПЫТКА СКОПИРОВАТЬ ПУСТУЮ ОЧЕРЕДЬ: ";
    Queue queue_2_func_copy; queue_2_func_copy.copy_in(queue_nullptr); // не даст скопировать, так как копируемая очередь пустая

    Queue queue_1_func_copy;

    std::cout << "QUEUE_1 ДО: "; queue_1.print();
    std::cout << "QUEUE_1_FUNC_COPY ДО: "; queue_1_func_copy.print(); std::cout << std::endl;

    std::cout << "АДРЕС СКОПИРОВАННОЙ ОЧЕРЕДИ: " << queue_1.copy_in(queue_1_func_copy) << std::endl;

    std::cout << "QUEUE_1 ПОСЛЕ: "; queue_1.print();
    std::cout << "QUEUE_1_FUNC_COPY ПОСЛЕ: "; queue_1_func_copy.print(); std::cout << std::endl << std::endl;



    // OPERATOR+
    std::cout << "OPERATOR+: " << std::endl;

    std::cout << "QUEUE_1: "; queue_1.print();
    std::cout << "QUEUE_2: "; queue_2.print(); std::cout << std::endl;

    std::cout << "АДРЕС ГОЛОВЫ НОВОЙ ОЧЕРЕДИ (QUEUE_1 + QUEUE_2): " << queue_1 + queue_2 << std::endl;

    Queue queue_sum = queue_1 + queue_2;
    std::cout << "QUEUE_SUM = QUEUE_1 + QUEUE_2: "; queue_sum.print(); std::cout << std::endl << std::endl;



    // OPERATOR*
    std::cout << "OPERATOR*: " << std::endl;

    std::cout << "QUEUE_3: "; queue_3.print();
    std::cout << "QUEUE_4: "; queue_4.print(); std::cout << std::endl;

    std::cout << "АДРЕС ГОЛОВЫ НОВОЙ ОЧЕРЕДИ (QUEUE_3 * QUEUE_4): " << queue_3 * queue_4 << std::endl;

    Queue queue_product = queue_3 * queue_4;
    std::cout << "QUEUE_PRODUCT = QUEUE_3 * QUEUE_4: "; queue_product.print();




    return 0;
}