
// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

// }}}

class FarmvilleDiv2
{
public:
	int minTime(vector<int> time, vector<int> cost, int budget) {
    const int n = time.size();
    vector<pair<int, int>> cost_time_pairs;
    for (int i = 0; i < n; ++i) {
      cost_time_pairs.push_back(make_pair(cost[i], time[i]));
    }
    sort(cost_time_pairs.begin(), cost_time_pairs.end());

    for (auto &ct_pair : cost_time_pairs) {
      while (ct_pair.second > 0 && budget >= ct_pair.first) {
        budget -= ct_pair.first;
        --ct_pair.second;
      }
    }
    int min_time = 0;
    for (const auto &ct_pair : cost_time_pairs) {
      min_time += ct_pair.second;
    }
    return min_time;
	}
};

