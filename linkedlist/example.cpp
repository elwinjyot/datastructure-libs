#include <list.hpp>
#include <iostream>

int main()
{
  // Initialize a linked list which stores int values
  List<int> numbers;

  // Push a float value to the list
  numbers.push(1);
  numbers.push(2);
  numbers.push(3);
  numbers.push(4);
  numbers.push(5);

  // Join two lists together, returns a new list object
  List<int> otherNums;
  otherNums.push(7);
  otherNums.push(8);
  std::cout << numbers + otherNums << std::endl;

  // Display the contents of the list or use List<T>::display() function
  std::cout
      << "Initial list: " << numbers << std::endl;

  // Remove last element from the list
  numbers.pop();
  std::cout << "Last element dropped: " << numbers << std::endl;

  // Reverse the ordering of the list
  numbers.reverse();
  std::cout << "Reversed list: " << numbers << std::endl;

  // Index with array-like style or use List<T>::getAt(int) function.
  std::cout << "Element at index 2: " << numbers[2] << std::endl;
  std::cout << "Length of list: " << numbers.length << std::endl;
  return 0;
}