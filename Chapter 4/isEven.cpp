#include <iostream>

int getNum() {
  int x{};
  std::cout << "Enter an integer: ";
  std::cin >> x;
  return x;
}

int main() {
  int userInput{getNum()};

  if (userInput % 2 == 0)
    std::cout << userInput << " is even\n";
  else
    std::cout << userInput << " is odd\n";
  return 0;
}