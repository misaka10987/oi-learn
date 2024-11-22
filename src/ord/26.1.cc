#include <bits/stdc++.h>

using namespace std;

void h(char src, char dst, char buf, int cnt) {
    if (cnt == 0) return;
    h(src, buf, dst, cnt - 1);
    cout << src << " -> " << dst << endl;
    h(buf, dst, src, cnt - 1);
}

int main() {
    h('A', 'C', 'B', 3);
}
