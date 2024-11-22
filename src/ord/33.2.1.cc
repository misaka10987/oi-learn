#include <bits/stdc++.h>

using namespace std;

int N;
int NUM[50];

int best(int nth = 0) {
    return nth >= N ? 0 : max(best(nth + 1), NUM[nth] + best(nth + 2));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> NUM[i];
    cout << best() << endl;
}
