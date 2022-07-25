#include"List.h"
#include <iostream>

//S. M. Mahedi Hasan
//2112370642
//Rjp Sir
//CSE225

using namespace std;

int main()
{
     List list;
     std::cout << "List before filling: ";
     list.print();
     std::cout << ", isEmpty: " << list.isEmpty() << ", length: " << list.length();
     for (int i = 0; i < 10; ++i) {
     list.addAsTail(i % 5 + 1);
  }
  std::cout << "\nList after filling: ";
  list.print();
  std::cout << ", isEmpty: " << list.isEmpty() << ", length: " << list.length();
  list.addAsHead(11);
  std::cout << "\nAfter adding 11 as head: ";
  list.print();
  list.reverse();
  std::cout << "\nReversed list: ";
  list.print();
  int head = list.popHead();
  std::cout << "\nRemoved from head value: " << head << '\n';
  std::cout << "List: ";
  list.print();
  list.removeFirst(3);
  std::cout << "\nAfter removing 3: ";
  list.print();
  list.removeAll(2);
  std::cout << "\nAfter removing all 2's: ";
  list.print();
  List list2;
  for (int i = 0; i < 5; ++i) {
    list2.addAsHead(i);
  }
  std::cout << "\nSecond list: ";
  list2.print();
  list.addAll(list2);
  std::cout << "\nConcatenated lists: ";
  list.print();
  Node* node = list.find(3);
  std::cout << "\nFound node with value of 3: address = " << node << ", {value: " << node->value << ", next: " << node->next << "}\n";
  return 0;
}
