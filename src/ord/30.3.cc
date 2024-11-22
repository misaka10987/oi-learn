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
        return valid() && MAP[x][y] != '#';
    }
    char depth() {
        return MAP[x][y];
    }
    int walk(char depth) {
        if (!walkable()) return 0;
        if (this->depth() != depth) return 0;
        MAP[x][y] = '#';
        return 1
            + Pt(x + 1, y).walk(depth)
            + Pt(x - 1, y).walk(depth)
            + Pt(x, y + 1).walk(depth)
            + Pt(x, y - 1).walk(depth);
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
            if (MAP[i_x][i_y] != '#') return Pt(i_x, i_y);
        }
    }
    return Pt(-1, -1);
}

int main() {
    init();
    int ma = 0;
    for (;;) {
        Pt p = fd();
        if (!p.valid()) break;
        int area = p.walk(p.depth());
        ma = max(ma, area);
    }
    cout << ma << endl;
}
