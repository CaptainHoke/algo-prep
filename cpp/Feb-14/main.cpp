#include <bits/stdc++.h>

// LC1466
int minReorder(int n, const std::vector<std::vector<int>>& connections) {
    int reorders = 0;

    std::vector<int> visited(n);
    int nVisited = 0;

    // Redundancy moment yuuu
    std::vector<std::vector<int>> adjList(n);
    std::vector<std::vector<int>> revAdjList(n);

    for (auto& c : connections) {
        adjList[c[0]].emplace_back(c[1]);
        revAdjList[c[1]].emplace_back(c[0]);
    }

    while (nVisited != n) {
        const auto vIter =
            std::ranges::find_if_not(visited, std::identity{});
        int nextVertex =
            static_cast<int>(std::distance(visited.begin(), vIter));

        if (nextVertex == n) {
            break;
        }

        std::queue<int> q;
        q.push(nextVertex);

        while (!q.empty()) {
            const int curr = q.front();
            q.pop();

            if (visited[curr]) {
                continue;
            }

            visited[curr] = true;
            nVisited++;

            for (int i = 0; i < adjList[curr].size(); ++i) {
                if (!visited[adjList[curr][i]]) {
                    reorders++;
                    q.push(adjList[curr][i]);
                }
            }

            for (int i = 0; i < revAdjList[curr].size(); ++i) {
                if (!visited[revAdjList[curr][i]]) {
                    q.push(revAdjList[curr][i]);
                }
            }
        }
    }

    return reorders;
}


int main() {

    return 0;
}
