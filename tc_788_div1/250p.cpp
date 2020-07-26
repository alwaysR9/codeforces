#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class RailwayMaster {
	public:
	int maxProfit(int N, int M, int K, vector <int> a, vector <int> b, vector <int> v) {
	    int n_rm = std::min(K, M-(N-1));
        if (n_rm <= 0)
            return 0;

        struct Edge{
            int a, b, v;
            Edge() {}
            Edge(int a, int b, int v) {
                this->a = a;
                this->b = b;
                this->v = v;
            }
        };

        vector<Edge> edges;
        for (int i = 0; i < a.size(); ++ i) {
            Edge e(a[i], b[i], v[i]);
            edges.push_back(e);
        }
        std::sort(edges.begin(), edges.end(), [](const Edge & e1, const Edge & e2){
            return e1.v > e2.v;
        });

        int G[105][105] = {0};
        for (int i = 0; i < edges.size(); ++ i) {
            Edge e = edges[i];
            G[e.a][e.b] += 1;
            G[e.b][e.a] += 1;
        }
        int k = 0;
        long long res = 0;
        while (n_rm > 0) {
            Edge e = edges[k];
            G[e.a][e.b] -= 1;
            G[e.b][e.a] -= 1;
            if (is_connected(G, N)) {
                res += (long long)e.v; 
                -- n_rm;
            } else {
                G[e.a][e.b] += 1;
                G[e.b][e.a] += 1;
            }
            ++ k;
        }
        return res;
	}

    private:
    bool is_connected(int G[105][105], int N) {
        bool visit[105] = {0};
        dfs(G, N, 0, visit);
        bool succ = true;
        for (int i = 0; i < N; ++ i)
            succ = succ && visit[i];
        return succ;
    }

    void dfs(int G[105][105], int N, int id, bool visit[]) {
        if (visit[id]) return;

        visit[id] = 1;
        for (int i = 0; i < N; ++ i) {
            if (G[id][i] && !visit[i])
                dfs(G, N, i, visit);
        }
    }
};
