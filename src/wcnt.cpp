#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

/**
 * Filters a string by removing any leading or trailing punctuation characters.
 *
 * @param s The input string to filter.
 * @return A new string with leading and trailing punctuation removed.
 */
std::string filter_punctuation(const std::string &s) {
  const char *forbidden{".,:; "};
  const auto idx_start(s.find_first_not_of(forbidden));
  const auto idx_end(s.find_last_not_of(forbidden));
  return s.substr(idx_start, idx_end - idx_start + 1);
}

/**
 * Reads words from standard input, counts their occurrences, and prints a sorted
 * list of the words and their counts, with the most frequent words first.
 * 
 * The program first reads words from standard input, filtering out any leading
 * or trailing punctuation characters using the `filter_punctuation` function.
 * It then counts the occurrences of each unique word and stores the counts in a
 * `std::map`. The program then sorts the words by their counts in descending
 * order and prints the sorted list, with the word length right-justified to
 * align the counts.
 */
int main() {
  std::map<std::string, size_t> words;
  int max_word_len{0};
  std::string s;
  while (std::cin >> s) {
    auto filtered(filter_punctuation(s));
    max_word_len = std::max<int>(max_word_len, filtered.length());
    ++words[filtered];
  }

  std::vector<std::pair<std::string, size_t>> word_counts;
  word_counts.reserve(words.size());
  std::move(std::begin(words), std::end(words),
            std::back_inserter(word_counts));
  std::sort(std::begin(word_counts), std::end(word_counts),
            [](const auto &a, const auto &b) { return a.second > b.second; });

  std::cout << "# " << std::setw(max_word_len) << "<WORD>"
            << " #<COUNT>\n";
  for (const auto &[word, count] : word_counts) {
    std::cout << std::setw(max_word_len + 2) << word << " #" << count << '\n';
  }
}