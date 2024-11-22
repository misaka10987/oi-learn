#include <bits/stdc++.h>

using namespace std;

int32_t f91(int32_t n) {
    return n >= 101 ? n - 10 : f91(f91(n + 11));
}

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (n == 0) break;
        cout << "f91(" << n << ") = " << f91(n) << endl;
    }
}
