#include <bits/stdc++.h>

using namespace std;

int width, height;

char MAP[100][100];

struct Pt {
    int x;
    int y;
    Pt(int x, int y) :x(x), y(y) {}
    bool valid() {
        return 0 <= x && x < width && 0 <= y && y < height;
    }
    bool walkable() {
        return valid() && MAP[x][y] == 'W';
    }
    void walk() {
        if (!walkable()) return;
        MAP[x][y] = '#';
        Pt(x + 1, y).walk();
        Pt(x - 1, y).walk();
        Pt(x, y + 1).walk();
        Pt(x, y - 1).walk();
    }
};

void init() {
    cin >> height >> width;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) cin >> MAP[j][i];
}

Pt fd() {
    for (int i_x = 0; i_x < width; i_x++) {
        for (int i_y = 0; i_y < height; i_y++) {
            if (MAP[i_x][i_y] == 'W') return Pt(i_x, i_y);
        }
    }
    return Pt(-1, -1);
}

int main() {
    init();
    int ans = 0;
    for (;;) {
        Pt p = fd();
        if (!p.valid()) break;
        p.walk();
        ans++;
    }
    cout << ans << endl;
}
