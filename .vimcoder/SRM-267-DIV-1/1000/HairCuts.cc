// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// }}}

class HairCuts {
 public:

  bool CanSchedule(const vector<int> enter, const int lastExit,
                   const double max_cut) {
    double begin = -1;
    double end = -1;
    for (const int t : enter) {
      if (t < begin) {
        begin += 5;
        end += max_cut;
      } else if (t <= end) {
        begin = t + 5;
        end += max_cut;
      } else {
        begin = t + 5;
        end = t + max_cut;
      }
    }
    return begin <= lastExit && lastExit <= end;
  }

  int ToIntTime(const string &time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));

    int ret = 0;
    // hour.
    if (h >= 9) {
      ret += (h - 9) * 60;
    } else {
      ret += 180 + h * 60;
    }
    // minute.
    ret += m;

    return ret;
  }

  double maxCut(vector <string> enter, string lastExit) {
    vector<int> ienter;
    for (const string &t : enter) {
      ienter.push_back(ToIntTime(t));
    }
    sort(ienter.begin(), ienter.end());
    int ilastExit = ToIntTime(lastExit);

    if (!CanSchedule(ienter, ilastExit, 600)) {
      return -1;
    }

    double lo = 5;
    double hi = 600;
    for (int i = 0; i < 100; ++i) {
      double mid = lo + (hi - lo) / 2;
      if (CanSchedule(ienter, ilastExit, mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }

    return lo;
  }
};
