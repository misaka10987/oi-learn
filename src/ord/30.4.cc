#include <bits/stdc++.h>

using namespace std;

int width, height;

int MAP[100][100];

struct Pt {
    int x;
    int y;
    Pt(int x, int y) :x(x), y(y) {}
    bool valid() {
        return 0 <= x && x < width && 0 <= y && y < height;
    }
    bool walkable() {
        return valid() && MAP[x][y] != -1;
    }
    void walk(int day) {
        if (!walkable()) return;
        if (MAP[x][y] == 0) MAP[x][y] = day;
        Pt(x + 1, y).walk(day + 1);
        Pt(x - 1, y).walk(day + 1);
        Pt(x, y + 1).walk(day + 1);
        Pt(x, y - 1).walk(day + 1);
    }
};

void init() {
    int n;
    cin >> n;
    width = n;
    height = n;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            char sym;
            cin >> sym;
            switch (sym) {
            case '@':
                MAP[j][i] = 1;
                break;
            case '.':
                MAP[j][i] = 0;
                break;
            default:
                MAP[j][i] = -1;
            }
        }
}

Pt fd(int day) {
    for (int i_x = 0; i_x < width; i_x++) {
        for (int i_y = 0; i_y < height; i_y++) {
            if (MAP[i_x][i_y] == day) return Pt(i_x, i_y);
        }
    }
    return Pt(-1, -1);
}

int stat(int day) {
    int ans = 0;
    for (int i_x = 0; i_x < width; i_x++) {
        for (int i_y = 0; i_y < height; i_y++) {
            cout << (int) MAP[i_x][i_y];
            if (MAP[i_x][i_y] > 0 && MAP[i_x][i_y] < day) ans++;
        }
        cout << endl;
    }
    return ans;
}

int main() {
    init();
    int ans = 0;
    for (;;) {
        Pt p = fd(1);
        if (!p.valid()) break;
        p.walk(1);
    }
    int day;
    cin >> day;
    cout << stat(day) << endl;
}
