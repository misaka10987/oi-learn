#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> expr;

void f(int sum, int ma) {
    if (sum < 0) return;
    if (sum == 0) {
        cout << n << " = ";
        for (int i = 0; i < expr.size() - 1; i++) cout << expr[i] << " + ";
        cout << expr[expr.size() - 1] << endl;
    }
    for (int i = 1; i <= ma ; i++) {
        expr.push_back(i);
        f(sum - i, i);
        expr.pop_back();
    }
}

int main() {
    cin >> n;
    f(n, n);
}
