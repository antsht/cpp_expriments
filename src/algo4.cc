#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  int k;
  std::cin >> k;

  std::vector<int> v1;
  v1.reserve(n);
  for (int i = 0, tmp = 0; i < n; ++i) {
    std::cin >> tmp;
    v1.push_back(tmp);
  }

  std::vector<int> v2;
  v2.reserve(k);
  for (int i = 0, tmp = 0; i < k; ++i) {
    std::cin >> tmp;
    v2.push_back(tmp);
  }

  if (!std::is_sorted(v1.begin(), v1.end())) {
    std::sort(v1.begin(), v1.end());
  }

  for (const auto& val : v2) {
    auto it = std::lower_bound(v1.begin(), v1.end(), val);
    auto it2 = std::upper_bound(v1.begin(), v1.end(), val);
    if (it != v1.end() && it2 != v1.begin()) {
      if (std::abs(*it - val) < std::abs(*(--it2) - val)) {
        std::cout << *it << '\n';
      } else {
        std::cout << *it2 << '\n';
      }
    } else if (it != v1.end()) {
      std::cout << *it << '\n';
    } else {
      std::cout << *(--it2) << '\n';
    }
  }
}