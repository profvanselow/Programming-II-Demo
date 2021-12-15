#include <fstream>
#include <functional>
#include <iostream>
#include <string>

#include "Accumulator.h"
#include "Car.h"
#include "Cat.h"
#include "Date.h"
#include "Dog.h"
#include "meal_functions.h"
void DemoIPO();
void functionsFun();
void demonstratePassByValue(int num1, int num2);
void write_file_demo();
void read_file_demo();
void stack_procedural_demo();
void stack_object_oriented_demo();
auto pop() -> int;
void push(int value);
void DisplayMenu();
void DemoDate();
void AccumulatorDemo();
void InheritanceDemo();
void ExceptionsDemo();

int stack[100];
int sp = 0;

int invoke(int x, int y, std::function<int(int, int)> func) {
  return func(x, y);
}

class my_exception : public std::exception {
  using std::exception::exception;
};

class Stack {
 private:
  int stackstore[100];
  int sp;

 public:
  // Constructor
  // often used to initialize variables
  // often overloaded
  // is a function (a function in a class is a method)
  // same name as the class
  // must be public
  // no return type
  // if one isn't written the compiler makes one for you
  // called automatically when an instance of the class is created
  // another name for an instance of a class is an object
  Stack(void) { sp = 0; }
  Stack(int p) { sp = p; }
  void push(int value);
  auto pop() -> int { return stackstore[--sp]; }
};

void Stack::push(int value) { stackstore[sp++] = value; }

int main() { DisplayMenu(); }

void DisplayMenu() {
  int choice{};
  int const QUIT = 9;
  while (choice != QUIT) {
    std::cout << "Enter the number for what to see: \n";
    std::cout << "1. Total Meal Price Calculator \n";
    std::cout << "2. Functions fun\n";
    std::cout << "3. Write to a file\n";
    std::cout << "4. Read from a file \n";
    std::cout << "5. Procedural stack \n";
    std::cout << "6. Object oriented stack \n";
    std::cout << "7. Date object \n";
    std::cout << "8. Accumulator \n";
    std::cout << "9. Inheritance \n";
    std::cout << "10. Exceptions \n";
    std::cout << "11. Quit \n";
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
      case 7:
        DemoDate();
        break;
      case 8:
        AccumulatorDemo();
        break;
      case 9:
        InheritanceDemo();
        break;
      case 10:
        ExceptionsDemo();
        break;
      case 11:
        break;
      default:
        std::cout << "Invalid choice \n";
        break;
    }
  }
}

void ExceptionsDemo() {
  // what is an exception?
  // 1) an error
  // 2) a response to an exceptional circumstance that arises
  // while a program is running
  // 3) an event, which occurs during the execution of a program,
  // that disrupts the normal flow of the program's instructions
  // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-errors

  int num0 = 0;

  try {
    if (num0 == 0) {
      // throw std::runtime_error("Math error: Attempted to divide by Zero\n");
      // throw 1;
      throw my_exception("My message");
      // return 1;
    }
    int result = 5 / num0;
  } catch (int a) {
    std::cout << "Exception occurred. Value " << a << std::endl;
  } catch (std::runtime_error &e) {
    // prints that exception has occurred
    // calls the what function
    // using runtime_error object
    std::cout << "Exception occurred" << std::endl << e.what();
  } catch (my_exception &e) {
    // prints that exception has occurred
    // calls the what function
    // using runtime_error object
    std::cout << "Exception occurred" << std::endl << e.what();
  }
}

void InheritanceDemo() {
  Cat whiskers;
  std::cout << whiskers.makeSound() << std::endl;
  whiskers.set_height(11);
  std::cout << whiskers.get_height() << std::endl;
  whiskers.set_name("Whiskers");
  std::cout << whiskers.get_name() << std::endl;
  Dog fido;
  std::cout << fido.makeSound() << std::endl;
  Cat blanch("Blanch");
  std::cout << blanch.get_name() << std::endl;
  Dog molly("Molly");
  std::cout << molly.get_name() << std::endl;

  Pet *dale = new Dog("Dale");
  std::cout << dale->get_name() << std::endl;
  std::cout << dale->makeSound() << std::endl;
  std::cout << static_cast<Dog *>(dale)->makeSound() << std::endl;
}

void AccumulatorDemo() {
  Accumulator acc;
  acc.add(5);  // add 5 to the accumulator
  reset(acc);  // reset the accumulator to 0
  std::cout << "Friends!" << std::endl;
}

void DemoDate() {
  Date my_date(2011, 10, 12);  // makes an object
  std::cout << my_date.getYear() << std::endl;
}

/**
 * @brief
 */
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

void push(int value) { stack[sp++] = value; }

auto pop(void) -> int { return stack[--sp]; }

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
