#include <algorithm>
#include <vector>

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;

    auto filteredLast = std::copy_if(
        data.begin(),
        data.end(),
        std::back_inserter(filtered),
        [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end());
}