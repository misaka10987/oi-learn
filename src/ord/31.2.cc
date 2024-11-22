/// 31.2

#include <bits/stdc++.h>

using namespace std;

char GRID[5][5];

void init() {
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
        cin >> GRID[i][j];
}

bool valid(int x, int y) {
    return 0 <= x && x < 5 && 0 <= y && y < 5;
}

unordered_set<int> ans;

void jump(int x, int y, int step = 0) {
    static char num[7] = "";
    if (!valid(x, y)) return;
    if (step > 5) {
        ans.insert(stoi(num));
        return;
    }
    num[step] = GRID[x][y];
    jump(x + 1, y, step + 1);
    jump(x - 1, y, step + 1);
    jump(x, y + 1, step + 1);
    jump(x, y - 1, step + 1);
}

int main() {
    init();
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
        jump(i, j);
    cout << ans.size() << endl;
}
