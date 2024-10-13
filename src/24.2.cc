#include <iostream>
#include <format>
#include <vector>

auto my_cmp(std::string const& a, std::string const& b) -> bool {
    return a + b > b + a;
}

int main() {
    int n;
    std::cin >> n;
    auto v = std::vector<std::string>(n);
    for (auto& i : v) std::cin >> i;
    std::sort(v.begin(), v.end(), my_cmp);
    for (auto i : v) std::cout << i;
    std::cout << std::endl;
}
