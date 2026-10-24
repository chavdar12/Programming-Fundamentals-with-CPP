#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

std::string title_case(const std::string &text) {
  std::string result = text;
  bool new_word = true;

  std::for_each(result.begin(), result.end(), [&](char &c) {
    if (new_word && std::isalpha(c)) {
      c = std::toupper(c);
    }
    new_word = !std::isalpha(c);
  });

  return result;
}

int main() {
  std::string text;
  std::getline(std::cin, text);

  std::cout << title_case(text) << '\n';

  return 0;
}
