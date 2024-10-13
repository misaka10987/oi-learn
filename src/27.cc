#include <bits/stdc++.h>

using namespace std;

int N;
int R;

int NUMBER[1000] = { 0 };

void dfs(int idx) {
    if (idx > R) {
        for (int i = 1; i <= R; i++) cout << NUMBER[i] << " ";
        cout << endl;
        return;
    }
    int min = NUMBER[idx - 1];
    for (int i = min + 1; i <= N; i++) {
        NUMBER[idx] = i;
        dfs(idx + 1);
    }
}

int main() {
    cin >> N >> R;
    dfs(1);
}
