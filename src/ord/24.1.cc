#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;
    for (;;) {
        string max = n, min = n;
        sort(max.begin(), max.end(), [](char a, char b) {return a >= b; });
        sort(min.begin(), min.end());
        int n_max = stoi(max), n_min = stoi(min);
        int diff = n_max - n_min;
        cout << n_max << " - " << n_min << " = " << diff << endl;
        if (diff == 6174) break;
        n = format("{}", diff);
    }
}
