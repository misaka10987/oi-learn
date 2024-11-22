#include <bits/stdc++.h>

using namespace std;

struct Pack {
    int area = 36;
    bool used[6][6];
    bool check(int x, int y, int len) {
        if (x + len > 6 || y + len > 6) return false;
        for (int i = x; i < x + len; i++) for (int j = y; j < y + len; j++)
            if (this->used[i][j]) return false;
        return true;
    }
    bool try_place(int len) {
        if (this->area < len * len) return false;
        for (int x = 0; x < 6; x++) for (int y = 0; y < 6; y++) {
            if (!check(x, y, len)) continue;
            for (int i = x; i < x + len; i++) for (int j = y; j < y + len; j++) this->used[i][j] = true;
            this->area -= len * len;
            return true;
        }
        return false;
    }
};

int main_1() {
    int order[7];
    for (int i = 1; i <= 6; i++) cin >> order[i];
    vector<Pack> pack = vector<Pack>();
    for (int i = 6; i >= 1; i--) {
        while (order[i] > 0) {
            bool placed = false;
            for (Pack p : pack) {
                if (p.try_place(i)) {
                    placed = true;
                    break;
                }
            }
            if (!placed) pack.push_back(Pack());
            pack.back().try_place(i);
            order[i]--;
        }
    }
    cout << pack.size() << endl;
}

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans = f + e + d + (c + 3) / 4;
    int insert_2 = 5 * d;
    if (c % 4 == 1) insert_2 += 5;
    else if (c % 4 == 2) insert_2 += 3;
    else if (c % 4 == 3) insert_2 += 1;
    if (b > insert_2) ans += (b - insert_2 + 8) / 9;
    int remain_area = 36 * ans - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
    if (remain_area < a) ans += (a - remain_area + 35) / 36;
    cout << ans << endl;
}
