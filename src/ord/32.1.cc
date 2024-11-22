#include <bits/stdc++.h>

using namespace std;

int fact(int x) {
    return x == 0 ? 1 : x * fact(x - 1);
}

int choose(int x, int y) {
    return fact(x) / fact(x - y) / fact(y);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << choose(x + y, x) << endl;
}
