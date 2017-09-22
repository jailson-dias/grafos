#include <bits/stdc++.h>

using namespace std;

int *ant, *cost, *adj, *to, *from, z, *cut;

void init(int v, int e) {
    ant = (int*)malloc(e*sizeof(int));
    cost = (int*)malloc(e*sizeof(int));
    to = (int*)malloc(e*sizeof(int));
    from = (int*)malloc(e*sizeof(int));
    cut = (int*)malloc(e*sizeof(int));
    adj = (int*)malloc(v*sizeof(int));
    for (int i = 0; i< v; i++) {
        adj[i] = -1;
    }
    for (int i = 0; i< e; i++) {
        cut[i] = -1;
    }
    z = 0;
}

void insert(int v, int w, int c) {
    ant[z] = adj[v];
    to[z] = w;
    from[z] = v;
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
    queue<pair<int, pair<int, int> > > q; // fila com os nós sendo visitados
    q.push(make_pair(s, make_pair(0, INT_MAX)));
    int max_flow = 0, i_cut = 0;
    while(!q.empty()) {
        int a = q.front().first;
        int d = q.front().second.second;
        int aresta = q.front().second.first;
        q.pop();
        if (a == t) {
            // se já chegou em t retorna a capacidade mínima do caminho de s para t
            max_flow += d;
            cut[i_cut++] = aresta;
        }
        // cout << "arestas" << endl;
        for (int i = adj[a]; i != -1; i=ant[i]) {
            // cout << i << ", ";
            cout << "(" << from[i] << ", " << to[i] << ") " << cost[i] << "  " << i<< endl;
            if(cost[i] > 0) {
                if (cost[i] > d){
                    q.push(make_pair(to[i], make_pair(aresta, d)));
                    cost[i] -= d;
                } else {
                    q.push(make_pair(to[i], make_pair(i, cost[i])));
                    cost[i] = 0;
                }
            }
        }
        // cout << endl;
    }
    return max_flow;

}

int *st(int v) {
    // cout << "ini"  << endl;
    int *a, *sai, *chega;
    a = (int*)malloc(2*sizeof(int));
    sai = (int*)malloc(v*sizeof(int));
    chega = (int*)malloc(v*sizeof(int));
    for (int i = 0;i<v;i++) {
        sai[i] = 0;
        chega[i] = 0;
    }
    for (int i = 0;i<z;i++) {
        sai[from[i]] += 1;
        chega[to[i]] += 1;
        // cout << from[i] << "  " << to[i] << endl;
    }
    for (int i = 0;i<v;i++) {
        if(chega[i] == 0) {
            // cout << i << " i"<< endl;
            a[0] = i;
        } else if(sai[i] == 0) {
            // cout << i << " i2"<< endl;
            a[1] = i;
        }
    }
    // cout << a[0] << " " << a[1] << endl;
    // cout << "fim"  << endl;
    return a;
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
        int *a = st(n);
        // cout << a[0] << "  " << a[1] << endl;
        cout << bfs(a[0], a[1]) << " max flow" << endl;

        for (int i = 0; cut[i] != -1;i++) {
            cout << "(" << from[cut[i]] << ", " << to[cut[i]] << ")" << endl;
        }
        // printg(n);

    }
    return 0;
}