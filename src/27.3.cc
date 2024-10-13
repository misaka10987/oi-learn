#include <bits/stdc++.h>

using namespace std;

int NUMBER[10];

int N = 0;

void dy() {
    for (int i = 0; i < N; i++) cout << NUMBER[i];
    cout << endl;
}

void dfs(int idx) {
    if (idx >= N) {
        dy();
        return;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < idx; j++) if (NUMBER[j] == i) goto LABEL;
        NUMBER[idx] = i;
        dfs(idx + 1);
    LABEL:;
    }
}

int main() {
    cin >> N;
    dfs(0);
}
