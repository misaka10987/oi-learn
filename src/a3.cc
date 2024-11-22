#include <bits/stdc++.h>

using namespace std;

int solve(string&& num, int k) {
    for (int i = k; i < num.size(); i++) {
        for (int j = 0; j < k; j++) {
            if (num[j] < num[i]) swap(num[i], num[j]);
        }
    }
    return stoi(num.substr(k));
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        string buf; cin >> buf;
        int k; cin >> k;
        cout << solve(move(buf), k) << endl;
    }
}
