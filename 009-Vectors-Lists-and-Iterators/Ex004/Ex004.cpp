#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string line;
  std::getline(std::cin, line);
  std::istringstream first_line(line);
  std::vector<int> first_sequence{std::istream_iterator<int>(first_line),
                                  std::istream_iterator<int>()};
  std::getline(std::cin, line);
  std::istringstream second_line(line);
  std::vector<int> second_sequence{std::istream_iterator<int>(second_line),
                                   std::istream_iterator<int>()};

  std::vector<int> merged_sequence;
  std::merge(first_sequence.begin(), first_sequence.end(),
             second_sequence.begin(), second_sequence.end(),
             std::back_inserter(merged_sequence));

  std::copy(merged_sequence.begin(), merged_sequence.end(),
            std::ostream_iterator<int>(std::cout, " "));

  return 0;
}
