#include <bits/stdc++.h>

using namespace std;

#define f(in,fi) for(int i = in; i<fi; i++)

pair<vector<int>, vector<pair<int, int> > > grafo(int n, int m) {
    vector<int> V, R;
    /* V = conjunto de vertices alcançaveis
       R = conjunto de vertices não alcançaveis
    */
    int ini = rand()%n; // vertice inicial
    V.push_back(ini);

    // vertices não alcançaveis
    f(0,n) {
        if(i!=ini) {
            R.push_back(i);
        }
    }

    // arestas de G
    vector<pair<int, int> > E;

    // utilizado para garantir que G vai ser conexo
    while (!R.empty()) {
        int v1 = V[rand()%V.size()];
        int indexv2 = rand()%R.size();
        V.push_back(R[indexv2]);
        E.push_back(make_pair(v1,R[indexv2]));
        R.erase(R.begin() + indexv2);
        m--;
    }
    // utilizado para garantir que a quantidade de aresta de G é m
    while(m--) {
        int v1 = 0, v2 = 0;
        do {
            v1 = V[rand()%V.size()];
            v2 = V[rand()%V.size()];
            // utilizado para garantir que v1 é diferente de v2
            while (v1 == v2) {
                v2 = V[rand()%V.size()];
            }
        } while (find(E.begin(), E.end(), make_pair(v1,v2)) != E.end() || 
                find(E.begin(), E.end(), make_pair(v2,v1)) != E.end());
        E.push_back(make_pair(v1,v2));
    }
    return make_pair(V,E);
}

// int main() {
    /*
    pair<vector<int>, vector<pair<int, int> > > G = grafo(5,10);
    vector<int> V = G.first;
    vector<pair<int, int> > E = G.second;
    cout << "Vértices" << endl;
    f(0, V.size()) {
        cout << i << " - " << V[i] << endl;
    }

    cout << "Arestas" << endl;
    f(0, E.size()) {
        cout << i << " - (" << E[i].first << ", " << E[i].second << ")" << endl;
    }

    cout << "fim" << endl;
    // */
// }