#include <iostream>
#include <queue>
#include <string>
#include <tuple>

int main() {
  using item_type = std::pair<int, std::string>;

  std::priority_queue<item_type> q;

  std::initializer_list<item_type> il{
      {1, "C++ course"},   {0, "Youtube watch"},
      {2, "Linux course"}, {3, "Konstantin Vladimirov videos"},
      {1, "SQL bootcamp"},
  };

  for (const auto& p : il) {
    q.push(p);
  }

  while (!q.empty()) {
    std::cout << q.top().first << ": " << q.top().second << '\n';
    q.pop();
  }
}