#include <fstream>
#include <iostream>
#include <string>

#include "meal_functions.h"
void DemoIPO();
void functionsFun();
void demonstratePassByValue(int, int);
void write_file_demo();
void read_file_demo();
void stack_procedural_demo();
void stack_object_oriented_demo();
int pop(void);
int push(void);
void DisplayMenu();

int stack[100];
int SP = 0;

class Stack {
 private:
  int stackstore[100];
  int SP;

 public:
  // Constructor
  // often used to initialize variables
  // often overloaded
  // is a function (a function in a class is a method)
  // same name as the class
  // must be public
  // no return type
  // if one isn't written the compiler makes one for you
  // called automatically when create an instance of the class
  // another name for an instance of a class is an object
  Stack(void) { SP = 0; }
  Stack(int p) { SP = p; }
  void push(int value);
  int pop(void) { return stackstore[--SP]; }
};

void Stack::push(int value) { stackstore[SP++] = value; }

int main() { DisplayMenu(); }

void DisplayMenu() {
  int choice{};
  while (choice != 7) {
    std::cout << "Enter the number for what to see: \n";
    std::cout << "1. Total Meal Price Calculator \n";
    std::cout << "2. Functions fun\n";
    std::cout << "3. Write to a file\n";
    std::cout << "4. Read from a file \n";
    std::cout << "5. Procedural stack \n";
    std::cout << "6. Object oriented stack \n";
    std::cout << "7. Quit \n";
    std::cin >> choice;
    switch (choice) {
      case 1:
        DemoIPO();
        break;
      case 2:
        functionsFun();
        break;
      case 3:
        write_file_demo();
        break;
      case 4:
        read_file_demo();
        break;
      case 5:
        stack_procedural_demo();
        break;
      case 6:
        stack_object_oriented_demo();
        break;
      default:
        std::cout << "Invalid choice \n";
        break;
    }
  }
}

void DemoIPO() {
  // input
  std::cout << "Enter the price of the meal: \n";  // ask user for a number
  double meal_price{};  // define variable meal_price to hold user input (and
  // zero-initialize it)
  std::cin >> meal_price;  // get number from keyboard and
  // store it in variable

  double total_price = calculate_total_price(meal_price);

  // output
  std::cout << "The total cost is " << calculate_total_price(meal_price)
            << '\n';
}

void functionsFun() {
  // pass by value
  // the value of the argument is copied into a new parameter variable
  int num1 = 1;
  int num2 = 2;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;
  demonstratePassByValue(num1, num2);
  std::cout << "back in functionsFun " << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  // pass by reference

  // pass by address
}

void demonstratePassByValue(int num1, int num2) {
  std::cout << "In demonstratePassByValue" << num1 << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  num1 = 3;
  num2 = 4;

  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;
}

void write_file_demo() {
  // Writing operations
  std::ofstream myfile("example.txt");
  if (myfile.is_open()) {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  } else
    std::cout << "Unable to open file";
}

void read_file_demo() {
  // Reading from a file

  std::string line;
  std::ifstream my_read_file("example.txt");
  std::cout << "in read" << '\n';
  if (my_read_file.is_open()) {
    std::cout << "in if" << '\n';
    while (std::getline(my_read_file, line)) {
      std::cout << line << '\n';
      std::cout << "in while" << '\n';
    }
    my_read_file.close();
  }

  else
    std::cout << "Unable to open file";
}

void push(int value) { stack[SP++] = value; }

int pop(void) { return stack[--SP]; }

void stack_procedural_demo() {
  push(3);
  push(2);
  push(1);
  std::cout << pop() << std::endl;
  std::cout << pop() << std::endl;
  std::cout << pop() << std::endl;
}

void stack_object_oriented_demo() {
  Stack little_stack;
  Stack another_stack;
  Stack funny_stack;

  little_stack.push(1);
  another_stack.push(little_stack.pop() + 1);
  funny_stack.push(another_stack.pop() + 2);
  std::cout << funny_stack.pop() << std::endl;
}
