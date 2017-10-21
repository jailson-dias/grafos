#include <bits/stdc++.h>

#include "gerar_grafo.h"

using namespace std;

#define f(in,fi) for(int i = in; i<fi; i++)
// /*
vector<int> greedy(pair<vector<int>, vector<pair<int, int> > > G) {
    vector<int> Sol;
    vector<pair<int, int> > E = G.second;
    
    map<int, int> Vaux;
    int t = 0;
    // cout << E.size() << "    e" << endl;
    do {
        f(0,G.first.size()) {
            Vaux[i] = 0;
        }
        vector<pair<int, int> > V;
        f(0,E.size()) {
            // cout << "teste " << i << endl;
            Vaux[E[i].first] += 1;
            Vaux[E[i].second] += 1;
        }
        // cout << E[0].first << endl;
        // f(0, Vaux.size()) {
        //     V.push_back(make_pair(Vaux[i], i));
        // }
        // sort(V.begin(), V.end());
        int max = -1, v = -1;
        for (map<int,int>::iterator it=Vaux.begin(); it!=Vaux.end(); it++) {
            // cout << it->second << " " << it->first << "  map" << endl;
            if(it->second > max) {
                v = it->first;
                max = it->second;
            }
        }
        // cout << v << endl;
        // int v = V[V.size() - 1].second;
        // V.pop();
        // cout << v << " v" << endl;
        Sol.push_back(v);
        // cout << E.size() << "  E" << endl;
        for (int i = E.size() - 1;i>=0;i--) {
            int v1 = E[i].first;
            int v2 = E[i].second;
            // cout << v1 << "  " << v2 << endl;
            if (v1 == v || v2 == v) {
                E.erase(E.begin() + i);
            }
        }
    } while(!E.empty());
    // } while(t++ < 2);
    return Sol;
}
// */
int main() {
    vector<int> g = greedy(grafo(5,8));
    f(0,g.size()) {
        cout << g[i] << ", ";
    }
    cout << endl;
    // vector<pair<int, int> > a;
    // a.push_back(make_pair(5,2));
    // a.push_back(make_pair(7,3));
    // a.push_back(make_pair(5,3));
    // a.push_back(make_pair(9,2));
    // sort(a.begin(), a.end());
    // reverse(a.begin(),a.end());
    // f(0,a.size()) {
    //     cout << a[i].first << " " << a[i].second << endl;
    // }
}