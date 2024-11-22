#include <bits/stdc++.h>

int f(int x) {
    if (x == 1) return 1;
    if (x % 2 == 1) return f(x - 1);
    return f(x - 1) + f(x / 2);
}

int main() {
    using namespace std;
    int x;
    cin >> x;
    cout << f(x) << endl;
}
