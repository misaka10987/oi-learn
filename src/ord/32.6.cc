#include <bits/stdc++.h>

using namespace std;

int N, M;

char BOARD[5][5];

bool valid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

bool walkable(int x, int y) {
    if (!valid(x, y)) return false;
    return BOARD[x][y] == '0';
}

void init() {
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        cin >> BOARD[i][j];
}

int cnt() {
    int ans = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        if (BOARD[i][j] == '0') ans++;
    return ans;
}

int COUNT;

int jump(int x, int y, int step = 1) {
    if (!walkable(x, y)) return 0;
    if (step == COUNT) return 1;
    BOARD[x][y] = '#';
    int ans = jump(x + 1, y + 2, step + 1)
        + jump(x - 1, y + 2, step + 1)
        + jump(x + 1, y - 2, step + 1)
        + jump(x - 1, y - 2, step + 1)
        + jump(x + 2, y + 1, step + 1)
        + jump(x - 2, y + 1, step + 1)
        + jump(x + 2, y - 1, step + 1)
        + jump(x - 2, y - 1, step + 1);
    BOARD[x][y] = '0';
    return ans;
}

int main() {
    int x, y;
    cin >> N >> M >> x >> y;
    init();
    COUNT = cnt();
    cout << jump(x - 1, y - 1) << endl;
}
