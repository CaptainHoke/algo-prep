#include <bits/stdc++.h>

// LC841
bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    std::vector<int> visited(rooms.size());
    std::queue<int> nextRooms;
    for (int e : rooms[0])
    {
        nextRooms.push(e);
    }
    visited[0] = true;

    while (!nextRooms.empty())
    {
        const int curr = nextRooms.front();
        nextRooms.pop();

        if (visited[curr])
        {
            continue;
        }

        visited[curr] = true;
        for (int e : rooms[curr])
        {
            nextRooms.push(e);
        }
    }

    return std::ranges::all_of(visited, std::identity{});
}

// LC547
int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
    int provinces = 0;

    std::vector<int> visited(isConnected.size());
    int nVisited = 0;

    while (nVisited != isConnected.size())
    {
        provinces++;

        const auto vIter = std::ranges::find_if_not(visited, std::identity{});
        int nextVertex = static_cast<int>(std::distance(visited.begin(), vIter));

        if (nextVertex == isConnected.size())
        {
            break;
        }

        std::queue<int> q;
        q.push(nextVertex);

        while (!q.empty())
        {
            const int curr = q.front();
            q.pop();

            if (visited[curr])
            {
                continue;
            }

            visited[curr] = true;
            nVisited++;
            for (int i = 0; i < isConnected[curr].size(); ++i)
            {
                if (i != curr && isConnected[curr][i] && !visited[i])
                {
                    q.push(i);
                }
            }
        }
    }

    return provinces;
}

// LC2149
std::vector<int> rearrangeArray(std::vector<int>& nums) {
    std::vector<int> result(nums.size());
    int posPtr = 0;
    int negPtr = 1;

    for (auto n : nums)
    {
        if (n > 0)
        {
            result[posPtr] = n;
            posPtr += 2;
        }
        else
        {
            result[negPtr] = n;
            negPtr += 2;
        }
    }

    return result;
}

int main()
{
    // std::cout << findCircleNum(std::vector<std::vector<int>>{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});
    return 0;
}
