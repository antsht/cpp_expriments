#include <iostream>
#include <stack>

int main() {
  std::stack<char> skobki{};
  std::string input{};

  std::cin >> input;
  for (const auto& c : input) {
    if (c == '(' || c == '{' || c == '[') {
      skobki.push(c);
    } else {
      if (skobki.empty()) {
        std::cout << "NO";
        return 0;
      }
      if (c == ')' && skobki.top() == '(') {
        skobki.pop();
      } else if (c == '}' && skobki.top() == '{') {
        skobki.pop();
      } else if (c == ']' && skobki.top() == '[') {
        skobki.pop();
      } else {
        std::cout << "NO";
        return 0;
      }
    }
  }
  if (skobki.empty()) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}