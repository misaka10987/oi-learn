#include <cmath>
#include <iostream>

auto dig_cnt(int num, int dig) -> int {
    auto n = (int) std::log10(num) + 1;
    auto ans = 0;
    for (auto i = 0; i < n; i++) {
        auto d = (int) (num / std::pow(10, i));
        if (d % 10 == dig) ans++;
    }
    return ans;
}

int main() {
    int n, d;
    std::cin >> n >> d;
    auto ans = 0;
    for (auto i = 0; i < n + 1; i++) ans += dig_cnt(i, d);
    std::cout << ans << std::endl;
}
