#include <bits/stdc++.h>

using namespace std;

int V;
int N;
int OBJ[31];

int best(int v, int nth) {
    if (nth >= N) return v;
    if (OBJ[nth] > v) return best(v, nth + 1);
    int in = best(v - OBJ[nth], nth + 1);
    int out = best(v, nth + 1);
    return min(in, out);
}

int main() {
    cin >> V >> N;
    for (int i = 0; i < N; i++) cin >> OBJ[i];
    cout << best(V, 0) << endl;
}
