#include <iostream>
#include <string>

int character_multiplier(const std::string &str1, const std::string &str2) {
  int sum = 0;
  const std::string &shorter = str1.size() < str2.size() ? str1 : str2;
  const std::string &longer = str1.size() < str2.size() ? str2 : str1;

  for (size_t i = 0; i < longer.size(); ++i) {
    sum += i < shorter.size() ? shorter[i] * longer[i] : longer[i];
  }

  return sum;
}

int main() {
  std::string str1, str2;
  std::cin >> str1 >> str2;

  std::cout << character_multiplier(str1, str2) << '\n';

  return 0;
}
