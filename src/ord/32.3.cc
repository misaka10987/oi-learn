#include <bits/stdc++.h>

using namespace std;

int N, M;

int COST[100][100];

int GRID[100][100];

void init() {
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        cin >> COST[i][j];
}

bool valid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

void walk(int x = 0, int y = 0, int cost = 0) {
    if (!valid(x, y)) return;
    int c = cost + COST[x][y];
    if (GRID[x][y] > 0 && GRID[x][y] < c) return;
    GRID[x][y] = c;
    walk(x + 1, y, c);
    walk(x - 1, y, c);
    walk(x, y + 1, c);
    walk(x, y - 1, c);
}

int main() {
    cin >> N >> M;
    init();
    walk();
    cout << GRID[N - 1][M - 1] << endl;
}
