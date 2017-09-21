#include <bits/stdc++.h>

using namespace std;

int *ant, *cost, *adj, *to, z;

void init(int v, int e) {
    ant = (int*)malloc(e*sizeof(int));
    cost = (int*)malloc(e*sizeof(int));
    to = (int*)malloc(e*sizeof(int));
    adj = (int*)malloc(v*sizeof(int));
    for (int i = 0; i< v; i++) {
        adj[i] = -1;
    }
}

void insert(int v, int w, int c) {
    ant[z] = adj[v];
    to[z] = w;
    cost[z] = c;
    adj[v] = z++;
}

void printg(int v) {
    for (int i = 0; i< v;i++) {
        cout << i << ". ";
        for (int j = adj[i]; j != -1; j=ant[j]) {
            cout << j << ", ";
        }
        cout << endl;
    }
}


int main() {
    int k; // numero de instâncias
    cin >> k;
    while (k--) {
        int m, n; // m = numero de arestas e n = numero de vertices
        init(n,m);
        cin >> m >> n;
        cout << m << "  " << n << endl;
        for (int i = 0; i< m; i++) {
            int v, w, c; // vertices v e w, e c a capacidade da aresta (v,w)
            cin >> v >> w >> c;
            cout << v << "  " << w << "  " << c << endl;
            insert(v - 1,w - 1,c); // inserindo a aresta (v,w) com custo c no grafo
        }

        // printg(n);

    }
    return 0;
}