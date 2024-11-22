#include <bits/stdc++.h>

using namespace std;

int N, M;

char MAZE[100][100];

void init() {
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        cin >> MAZE[i][j];
}

bool valid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

bool walkable(int x, int y) {
    return MAZE[x][y] == '0';
}

struct Pt {
    int x;
    int y;
    Pt(int x, int y) :x(x), y(y) {}
    friend ostream& operator<<(ostream& out, Pt pt) {
        return out << "(" << pt.x + 1 << "," << pt.y + 1 << ")";
    }
};

void walk(int x = 0, int y = 0) {
    static vector<Pt> path = vector<Pt>();
    if (!valid(x, y)) return;
    if (!walkable(x, y)) return;
    if (x == N - 1 && y == M - 1) {
        for (Pt p : path) cout << p << " ";
        cout << Pt(x, y) << endl;
        return;
    }
    path.push_back(Pt(x, y));
    MAZE[x][y] = '1';
    walk(x + 1, y);
    walk(x - 1, y);
    walk(x, y + 1);
    walk(x, y - 1);
    MAZE[x][y] = '0';
    path.pop_back();
}

int main() {
    cin >> N >> M;
    init();
    walk();
}
