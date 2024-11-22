#include <bits/stdc++.h>

using namespace std;

int N;

char PPL[30];

int CNT = 0;

void distr(int curr = 0) {
    if (curr >= N) {
        CNT++;
        for (int i = 0; i < N; i++) cout << PPL[i];
        cout << endl;
        return;
    }
    PPL[curr] = '0';
    distr(curr + 1);
    if (curr != 0 && PPL[curr - 1] == '1') return;
    PPL[curr] = '1';
    distr(curr + 1);
}

int main() {
    cin >> N;
    distr();
    cout << CNT << endl;
}
