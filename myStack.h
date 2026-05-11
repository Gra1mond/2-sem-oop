#pragma once 
#include"listNode.h"
#include<iostream>
template<typename T>
class MyStack{
private:
  ListNode<T>* top; //  указатель на вершину стека.

public:
  MyStack();                   // конструктор по умолчанию.
  ~MyStack();                  // деструктор (освобождает память).
  void push(const T& value);   // добавляет элемент на вершину.
  bool pop(T& value);          // удаляет элемент с вершины, возвращает его значение.
  bool peek(T& value) const;   // возвращает значение верхнего элемента без удаления.
  bool isEmpty() const;        // проверка на пустоту.
  int size() const;            // возвращает количество элементов.
  void clear();                // очищает стек.
  void print() const;          // выводит содержимое стека (от вершины ко дну).
};

template<typename T>
MyStack<T>::~MyStack(){
    clear();
}


template<typename T>
MyStack<T>::MyStack():top(nullptr){}


template<typename T>
void MyStack<T>::push(const T& value){
    ListNode<T>* node = new ListNode<T>(value);
    node->next=top;
    top = node;
}

template<typename T>
bool MyStack<T>::pop(T& value){
    if(isEmpty()){
        return false;
    }
    value = top->data;
    ListNode<T>* temp = top;
    top = top->next;
    delete temp;
    return true;
}

template<typename T>
bool MyStack<T>::peek(T& value) const{
    if(isEmpty()){
        return false;
    }
    value = top->data;
    return true;
}

template<typename T>
bool MyStack<T>::isEmpty()const{
    if(top==nullptr){
        return true;
    }
    return false;
}

template<typename T>
int MyStack<T>::size()const{
    int count = 0;
    ListNode<T>* temp = top;
    while(temp!=nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

template<typename T>
void MyStack<T>::clear(){
    T temp;
    while(!isEmpty()){
        pop(temp);
    }
}

template<typename T>
void MyStack<T>::print()const{
    if(isEmpty()){
        std::cout<<"Empty";
        return;
    }
    ListNode<T>* temp = top;
    while(temp!=nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}