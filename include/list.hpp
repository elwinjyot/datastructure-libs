#pragma once
#include <iostream>

template <typename T>
struct Node
{
  T data;
  int index;
  Node<T> *next;
  Node<T> *prev;
};

template <typename T>
class List
{
public:
  Node<T> *head;
  Node<T> *tail;
  int length = 0;

  List();
  ~List();

  // Basic actions
  Node<T> *push(T);
  void pop();
  T getAt(int);
  void reverse();
  void display();

  // Operators
  List<T> operator+(const List<T> &) const;
  T operator[](int);
};

template <typename T>
List<T>::List()
{
  this->head = nullptr;
  this->tail = nullptr;
}

template <typename T>
List<T>::~List()
{
  if (this->head == nullptr)
  {
    exit(EXIT_FAILURE);
  }

  Node<T> *curr = this->tail;
  while (curr != nullptr)
  {
    Node<T> *prev = curr->prev;
    delete curr;
    this->tail = prev;
    curr = this->tail;
  }
}

template <typename T>
Node<T> *List<T>::push(T data)
{
  Node<T> *newNode = new Node<T>;
  newNode->data = data;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  this->length++;

  if (this->head == nullptr || this->tail == nullptr)
  {
    newNode->index = 0;
    this->head = newNode;
    this->tail = newNode;
    return newNode;
  }

  this->tail->next = newNode;
  newNode->index = this->tail->index + 1;
  newNode->prev = this->tail;
  this->tail = newNode;
  return newNode;
}

template <typename T>
void List<T>::pop()
{
  this->tail->prev->next = nullptr;
  this->tail = this->tail->prev;
  this->length--;
}

template <typename T>
T List<T>::getAt(int index)
{
  if (index >= this->length)
  {
    return -1;
  }

  Node<T> *curr = this->head;
  while (curr != nullptr)
  {
    if (curr->index == index)
    {
      return curr->data;
    }

    curr = curr->next;
  }

  return -1;
}

template <typename T>
void List<T>::reverse()
{
  Node<T> *curr = this->tail;
  this->head = curr;
  while (curr != nullptr)
  {
    curr->index = (this->length - 1) - curr->index;
    curr->next = curr->prev;
    curr = curr->next;
  }

  this->tail = curr;
}

template <typename T>
void List<T>::display()
{
  Node<T> *head = this->head;
  std::cout << "[";
  while (head != nullptr)
  {
    std::cout << "{" << head->index << ": " << head->data << "}";
    head = head->next;
    if (head != nullptr)
    {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

template <typename T>
List<T> List<T>::operator+(const List<T> &other) const
{
  List<T> newList;

  Node<T> *curr = this->head;
  while (curr != nullptr)
  {
    newList.push(curr->data);
    curr = curr->next;
  }

  curr = other.head;
  while (curr != nullptr)
  {
    newList.push(curr->data);
    curr = curr->next;
  }

  return newList;
}

template <typename T>
T List<T>::operator[](int index)
{
  return this->getAt(index);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list)
{
  Node<T> *curr = list.head;
  while (curr != nullptr)
  {
    os << curr->data;
    curr = curr->next;
    if (curr != nullptr)
    {
      os << " -> ";
    }
  }

  return os;
}