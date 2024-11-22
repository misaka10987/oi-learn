#include <bits/stdc++.h>

using namespace std;

int* NUMBER = nullptr;
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
    for (int i = 0; i < N; i++) {
        NUMBER[idx] = i + 1;
        dfs(idx + 1);
    }
}

int main() {
    cin >> N;
    NUMBER = new int[N];
    dfs(0);
}
