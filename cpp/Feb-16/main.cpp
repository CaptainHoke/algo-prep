#include <bits/stdc++.h>

namespace LC
{
    using namespace std;

    // LC1481
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> occurences;
        for (auto e : arr)
        {
            ++occurences[e];
        }

        vector<pair<int, int>> elemFreq;
        for (const auto [e, freq] : occurences)
        {
            elemFreq.emplace_back(e, freq);
        }

        ranges::sort(elemFreq, [](pair<int, int> p1, pair<int, int> p2) {return p1.second < p2.second;});

        int uniqueElems = 0;
        for (const auto [_, freq] : elemFreq)
        {
            if (k >= freq)
            {
                k -= freq;
                continue;
            }
            uniqueElems++;
        }

        return uniqueElems;
    }
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
