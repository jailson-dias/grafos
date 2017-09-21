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
            cout << to[j] << ", ";
        }
        cout << endl;
    }
}

int bfs(int s, int t) {
    /** s = nó inicial do grafo, t = nó final do grafo e max = capacidade minima das arestar no caminho 
    de s para t, iniciar max com INT_MAX*/
    queue<pair<int, int> > q; // fila com os nós sendo visitados
    q.push(make_pair(s, INT_MAX));
    int max_flow = 0;
    while(!q.empty()) {
        int a = q.front().first;
        int d = q.front().second;
        q.pop();
        if (a == t) {
            // se já chegou em t retorna a capacidade mínima do caminho de s para t
            max_flow += d;
        }
        for (int i = adj[a]; i != -1; i=ant[i]) {
            if(cost[i] > 0) {
                q.push(make_pair(to[i], min(cost[i], d)));
            }
        }
    }
    return max_flow;

}


int main() {
    int k; // numero de instâncias
    cin >> k;
    while (k--) {
        int m, n; // m = numero de arestas e n = numero de vertices
        cin >> m >> n;
        init(n,m);
        for (int i = 0; i< m; i++) {
            int v, w, c; // vertices v e w, e c a capacidade da aresta (v,w)
            cin >> v >> w >> c;
            insert(v - 1,w - 1,c); // inserindo a aresta (v,w) com custo c no grafo
        }
        cout << bfs(0,2) << " max flow" << endl;
        printg(n);

    }
    return 0;
}