#include <bits/stdc++.h>

int f(int n) {
    return n == 1 ? 1 : 1 + f(n - f(f(n - 1)));
}

int main() {
    using namespace std;
    int x; cin >> x;
    cout << f(x) << endl;
}
