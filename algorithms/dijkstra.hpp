#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define ll long long
#define ull unsigned ll

namespace graph {
// dijkstra
void unweighted_shortest_path(const vector<vector<ull>> &graph, int source,
                              vector<ull> &dist, vector<ull> &prev) {
  for (auto &v : dist)
    v = -1;

  dist[source] = -1;
  queue<ull> q;
  q.push(source);

  while (!q.empty()) {
    ull value = q.front();
    q.pop();

    for (auto &v : graph[value]) {
      if (dist[v] == -1) {
        dist[v] = dist[value] + 1;
        prev[v] = prev[value] + 1;
        q.push(v);
      }
    }
  }
}

// dijkstra weighted

void weighted_shortest_path(vector<vector<std::pair<ull, ull>>> &graph,
                            int source, vector<ull> &dist, vector<ull> &prev) {
  priority_queue<pair<ull, ull>, vector<pair<ull, ull>>,
                 greater<pair<ull, ull>>>
      pq;

  pq.push(make_pair(source, 0));
  dist[source] = 0;

  while (!pq.empty()) {
    int u = pq.top().first;
    pq.pop();

    for (auto &[v, weight] : graph[u]) {

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        prev[v] = u;
        pq.push(make_pair(v, dist[v]));
      }
    }
  }
}
}; // namespace graph
