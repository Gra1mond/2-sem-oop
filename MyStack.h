#pragma once

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
