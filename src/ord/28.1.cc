#include <bits/stdc++.h>

using namespace std;

int f(int x) {
    if (x == 1) return 1;
    int ans = 1;
    for (int i = 1; i < sqrt(x); i++) ans += f(i);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
}
