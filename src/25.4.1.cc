#include <bits/stdc++.h>

using namespace std;

bool try_append(unordered_set<string>& set) {
    unordered_set<string> del;
    for (string i : set) {
        int first = i[0] - '0';
        for (char j = '1'; j <= '0' + first / 2; j++) {
            string res = j + i;
            if (!set.contains(res)) del.insert(res);
        }
    }
    if (del.size() == 0) return false;
    set.merge(del);
    return true;
}

int main() {
    string n;
    cin >> n;
    unordered_set<string> set;
    set.insert(n);
    while (try_append(set)) {}
    cout << set.size() << endl;
}
