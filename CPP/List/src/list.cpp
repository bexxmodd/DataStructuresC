#include <cassert>
#include <iostream>

template <typename T> struct Node {
  T data;
  Node<T> *next;
};

template <class T> class LinkedList {

private:
  int length;

public:
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;

  LinkedList<T>() : length(0) {}

  int size() { return length; }

  void add(T data) {
    if (!head) {
      head = new Node<T>;
      head->data = data;
      head->next = nullptr;
      tail = head;
    } else {
      if (tail == head) {
        tail = new Node<T>;
        tail->data = data;
        tail->next = nullptr;
        head->next = tail;
      } else {
        auto *newData = new Node<T>;
        newData->data = data;
        newData->next = nullptr;
        tail->next = newData;
        tail = newData;
      }
    }
    length++;
  }

  void remove(T data) {
    if (head->data == data)
      remove_first();
    else if (tail->data == data)
      remove_last();

    else {
      Node<T> *cur = head;
      for (; cur->next != nullptr; cur = cur->next) {
        if (cur->next->data == data) {
          cur->next = cur->next->next;
          length--;
          return;
        }
      }
    }
  }

  void remove_first() {
    if (head != nullptr)
      head = head->next;
    else
      return;

    if (head == nullptr)
      tail = nullptr;
    else
      length--;
  }

  void remove_last() {
    if (head == nullptr)
      return;
    else if (head == tail) {
      head = nullptr;
      tail = nullptr;
    } else {
      Node<T> *cur = head;
      for (; cur->next != tail; cur = cur->next)
        ;
      tail = cur;
      cur->next = nullptr;
    }
    length--;
  }

  void remove_at(unsigned int index) {
    assert(index < length);

    if (index == 0)
      remove_first();
    else if (index == length - 1)
      remove_last();
    else {
      Node<T> *cur = head;
      for (int i = 0; i < index - 1; i++, cur = cur->next)
        ;
      cur->next = cur->next->next;
      length--;
    }
  }

  T get(unsigned int index) {
    assert(index < length);

    if (index == 0)
      return head->data;
    else if (index == length - 1)
      return tail->data;

    Node<T> *cur = head;
    for (int i = 0; i < index; i++, cur = cur->next)
      ;
    return cur->data;
  }

  void print() {
    Node<T> *cur = head;
    for (; cur != nullptr; cur = cur->next)
      std::cout << cur->data << " -> ";
    std::cout << "NULL \n";
    delete cur;
  }

  friend std::ostream &operator<<(std::ostream &os, LinkedList<T> &list) {
    Node<T> *cur = list.head;
    for (; cur != nullptr; cur = cur->next)
      os << cur->data << " -> ";
    os << "NULL \n";
    return os;
  }
};

int main() {
  LinkedList<int> list;
  std::cout << "Length : " << list.size() << std::endl;

  list.add(4);
  list.add(7);
  list.add(8);
  list.add(6);
  std::cout << "Length : " << list.size() << std::endl;
  std::cout << list;

  list.remove_last();
  std::cout << "Length : " << list.size() << std::endl;
  list.print();

  list.add(99);
  list.add(87);
  std::cout << list;
  int a = list.get(2);
  std::cout << "val at index: 2 is " << a << std::endl;

  list.remove_at(4);
  std::cout << list;
  return 0;
}
