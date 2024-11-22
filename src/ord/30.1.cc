/// 30.1

#include "lib.cc"
#include <bits/stdc++.h>

using namespace std;

int main() {
    using ll::Grid;
    int n, m;
    cin >> n >> m;
    Grid::set(m, n);
    Grid::init(cin);
    Grid start = Grid::next('2');
    start.tile() = '0';
    cout << start.conn_area() << endl;
}
