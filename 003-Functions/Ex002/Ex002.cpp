#include <iostream>

void print_grade(const double grade) {
  if (grade < 2.00 || grade > 6.00) {
    return;
  }
  if (grade < 3.00) {
    std::cout << "Fail";
  } else if (grade < 3.50) {
    std::cout << "Poor";
  } else if (grade < 4.50) {
    std::cout << "Good";
  } else if (grade < 5.50) {
    std::cout << "Very good";
  } else {
    std::cout << "Excellent";
  }
}

int main() {
  double grade;
  std::cin >> grade;

  print_grade(grade);

  return 0;
}
