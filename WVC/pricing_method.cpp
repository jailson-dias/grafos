#include <bits/stdc++.h>

using namespace std;

vector<int> wvc(pair<vector<pair<int, int> >, vector<pair<int, int> > > G) {
    vector<pair<int, int> > E = G.second;
    vector<int> pe(E.size(), 0);
    vector<int> vertexCover;
    for (int i = 0; i < E.size(); i++) {
        if (find(vertexCover.begin(), vertexCover.end(), E.first) == vertexCover.end() &&
            find(vertexCover.begin(), vertexCover.end(), E.second) == vertexCover.end()) {

            }
    }
}

int main() {

    return 0;
}