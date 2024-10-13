#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    auto v = std::vector<bool>(n, false);
    for (auto i = 1; i <= n; i++)
        for (auto j = i - 1; j < n; j += i)
            v[j] = !v[j];
    auto ans = 0;
    for (auto i : v) if (i) ans++;
    std::cout << ans << std::endl;
}
