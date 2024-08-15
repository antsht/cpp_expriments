#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <vector>

/**
 * Evaluates a reverse Polish notation (RPN) expression.
 *
 * This function takes an iterator range of strings representing an RPN expression,
 * evaluates the expression, and returns the result as a double.
 *
 * @tparam IT The iterator type for the input expression.
 * @param it The beginning of the iterator range for the input expression.
 * @param end The end of the iterator range for the input expression.
 * @return The result of evaluating the RPN expression.
 * @throws std::invalid_argument If an invalid operator is encountered in the expression.
 */
template <typename IT> double evaluate_rpn(IT it, IT end) {
  std::stack<double> val_stack;

  auto pop_stack([&]() {
    auto r(val_stack.top());
    val_stack.pop();
    return r;
  });

  std::map<std::string, double (*)(double, double)> ops{
      {"+", [](double a, double b) { return a + b; }},
      {"-", [](double a, double b) { return a - b; }},
      {"*", [](double a, double b) { return a * b; }},
      {"/", [](double a, double b) { return a / b; }},
      {"^", [](double a, double b) { return pow(a, b); }},
      {"%", [](double a, double b) { return fmod(a, b); }},
  };

  for (; it != end; it++) {
    std::stringstream ss{*it};
    if (double val; ss >> val) {
      val_stack.push(val);
    } else {
      const auto r{pop_stack()};
      const auto l{pop_stack()};

      try {
        const auto &op(ops.at(*it));
        const double result{op(l, r)};
        val_stack.push(result);
      } catch (const std::out_of_range &) {
        throw std::invalid_argument(*it);
      }
    }
  }
  return val_stack.top();
}

/**
 * Evaluates a reverse Polish notation (RPN) expression entered by the user.
 *
 * This function reads RPN expressions from standard input, evaluates them, and
 * prints the result to standard output. If an invalid operator is encountered,
 * an error message is printed to standard output.
 */
int main() {
  try {
    std::cout << evaluate_rpn(std::istream_iterator<std::string>{std::cin}, {})
              << std::endl;
  } catch (const std::invalid_argument &e) {
    std::cout << "Invalid operator:" << e.what() << std::endl;
  }
}
