#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 100005;

struct Graph{
    int numNodes;
    set<int> adj[MAX_NODES];
    void clear(){
        numNodes = 0;
        for(int i=0;i<MAX_NODES;i++)
            adj[i].clear();
    }
    void add_edge(int u,int v){
        adj[u].insert(v);
    }
};

int po[MAX_NODES],comp[MAX_NODES];

void DFS(int v,const Graph& G,Graph& G_scc,int& C, stack<int>& P,stack<int>& S){
    po[v] = C++;
  
    S.push(v);  P.push(v);
    for(auto w : G.adj[v]) {
        if(po[w] == -1){
            DFS(w,G,G_scc,C,P,S);
        } else if(comp[w] == -1){
            while(!P.empty() && (po[P.top()] > po[w]))
	            P.pop();
        }
    }
    if(!P.empty() && P.top() == v){
        while(!S.empty()){
            int t = S.top();
            S.pop();
            comp[t] = G_scc.numNodes;
            if(t == v)
	            break;
        }
        G_scc.numNodes++;
        P.pop();
    }
}

int SCC(const Graph& G,Graph& G_scc){
    G_scc.clear();
    int C=1;
    stack<int> P,S;
    fill(po,po+G.numNodes,-1);
    fill(comp,comp+G.numNodes,-1);
    for(int i=0;i<G.numNodes;i++)
        if(po[i] == -1)
            DFS(i,G,G_scc,C,P,S);
  
    // You do not need this if you are only interested in the number of
    //    strongly connected components.
    for(int i=0;i<G.numNodes;i++){
        for(auto w : G.adj[i]) {
            if(comp[i] != comp[w])
	            G_scc.add_edge(comp[i],comp[w]);
        }
    }
  
    return G_scc.numNodes;
}

Graph G,G_scc;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    set<string> langs;

    int index = 0;
    map<string, int> i_lang;
    map<int, int> person_speaks;

    vector<vector<int>> langs_hears; // list of languages and who hears them

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        string name, speaks, hears;
        ss >> name >> speaks;
        if (langs.count(speaks) == 0) {
            langs.insert(speaks);
            i_lang[speaks] = index;
            langs_hears.push_back(vector<int>());
            index++;
        }
        // they can speak their default lang
        person_speaks[i] = i_lang[speaks];
        // they can hear their default lang
        langs_hears[i_lang[speaks]].push_back(i);

        while (ss >> hears) {
            if (langs.count(hears) == 0) {
                langs.insert(hears);
                i_lang[hears] = index;
                langs_hears.push_back(vector<int>());
                index++;
            }

            langs_hears[i_lang[hears]].push_back(i);
        }
    }

    G.numNodes = n;

    for (int u = 0; u < n; u++) {
        for (auto v: langs_hears[person_speaks[u]]) {
            G.add_edge(u, v);
        }
    }
    int n_scc = SCC(G,G_scc);

    vector<int> scc_sizes(n_scc, 0);
    for (int i = 0; i < n; i++) {
        scc_sizes[comp[i]]++;
    }

    int largest = 0;
    for (int i = 0; i < n_scc; i++) {
        largest = max(largest, scc_sizes[i]);
    }

    cout << n-largest << endl;

    return 0;
}