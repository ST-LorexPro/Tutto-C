#include <iostream>
#include <list>
#include <cassert>
using namespace std;

template<typename T>
class Stack{
private:
    list<T> S;
public:
    void push(T el){S.push_back(el);}
    void pop(){assert(!S.empty());
    S.pop_back(); }
    bool empty(){return S.empty();}
    size_t size(){return S.size();}
    T top () {return S.back(); }
};
template<typename T>
class Queue{
private:
    list<T> S;
public:
    void enqueue(T el){S.push_back(el);}
    void dequeue(){assert(!S.empty()); S.pop_front();}
    bool empty(){return S.empty();}
    size_t size(){return S.size();}
    T front () {return S.front(); }
};

//classe coda ereditando la lista

template <typename T>
class QueueINH:private list<T>{
public:
    void enqueue(T el){push_back(el);}
    void dequeue(){assert(!empty()); pop_front();}
    //bool empty(){return empty();}
    using list<T>::empty;
    size_t size(){return size();}
    T front () {return front(); }
};

int main(){
    Stack<int> H;
    if (!H.empty())
        H.pop();
    QueueINH<int> Q;
    Q.enqueue(3);
    
    if (Q.empty())
        cout<<"coda vuota"<<endl;

}