/// 30.5

#include <bits/stdc++.h>

using namespace std;

int N, M;

int BOARD[100][100];

bool valid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

void jump(int x, int y, int step = 0) {
    if (!valid(x, y)) return;
    if (BOARD[x][y] > 0 && BOARD[x][y] <= step) return;
    BOARD[x][y] = step;
    jump(x + 1, y + 2, step + 1);
    jump(x - 1, y + 2, step + 1);
    jump(x + 1, y - 2, step + 1);
    jump(x - 1, y - 2, step + 1);
    jump(x + 2, y + 1, step + 1);
    jump(x - 2, y + 1, step + 1);
    jump(x + 2, y - 1, step + 1);
    jump(x - 2, y - 1, step + 1);
}

int main() {
    int x, y, s, t;
    cin >> N >> M >> x >> y >> s >> t;
    jump(x - 1, y - 1);
    cout << BOARD[s - 1][t - 1] << endl;
}
