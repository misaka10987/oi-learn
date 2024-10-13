#include <bits/stdc++.h>

using namespace std;

int f(int x) {
    cout << x << " ";
    if (x == 1) return 1;
    return 1 + (x % 2 == 0 ? f(x / 2) : f(3 * x + 1));
}

int main() {
    int x;
    cin >> x;
    int stp = f(x);
    cout << endl << "STEP=" << stp << endl;
}
