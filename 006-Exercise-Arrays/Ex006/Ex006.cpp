#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> array(n);

  for (int &num : array) {
    std::cin >> num;
  }

  std::sort(array.begin(), array.end());

  std::adjacent_difference(array.begin(), array.end(), array.begin());
  const int min_diff = *std::min_element(array.begin() + 1, array.end());

  std::cout << min_diff;

  return 0;
}
