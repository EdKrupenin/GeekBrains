//
// Created by krupenin on 31.01.2022.
//

#ifndef UNTITLED_ITERATOR_H
#define UNTITLED_ITERATOR_H
#include <vector>

/*
 * Реализовать паттерн итератор, с помощью которого можно будет проитерироваться по контейнеру с объектами
 * (одного любого класса) в оба направления (возьмите контейнеры - список, массив, вектор, дек).
 * (Дополнительно) Попробуйте улучшить вашу реализацию,
 * чтобы не было четкой привязки к классу объектов, хранящихся в контейнерах.
 */

template <class Container, class Type>
class Iterator {
    Container& data;
    int curIndex;
    Type* ptr;
public:
    explicit Iterator(Container& ref) : data(ref), curIndex(-1), ptr(nullptr) {
        ++(*this);
    }
    void reset(){
        curIndex = -1;
        ptr = nullptr;
    }
    Iterator& operator++(){
        curIndex++;
        if(curIndex == -1)
            curIndex = 0;
        ptr = &data[curIndex];
        if (curIndex == data.size())
            reset();
        return *this;
    }
    Iterator& operator--(){
        if (curIndex == -1)
            curIndex = data.size() - 1;
        curIndex--;
        ptr = &data[curIndex];

        if (curIndex == -1)
            ptr = nullptr;
        return *this;
    }
    Iterator begin(){
        Iterator it(data);
        return it;
    }
    Iterator end() {
        Iterator it(data);
        it.reset();
        return it;
    }
    Type& operator*(){
        return data[curIndex];
    }
    bool operator==(Iterator it) // проверка на лог. равенство итераторов
    {
        if (curIndex == it.curIndex &&
            ptr == it.ptr &&
            data == it.data)
        {
            return true;
        }
        return false;
    }
    bool operator!=(Iterator it) // проверка на лог. неравенство
    {
        return *this != it;
    }
};


#endif //UNTITLED_ITERATOR_H
