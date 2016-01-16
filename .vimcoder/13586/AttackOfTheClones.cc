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

// O(n^2) solution, passed all testcases.
// class AttackOfTheClones {
//  public:
//   int count(vector <int> firstWeek, vector <int> lastWeek) {
//     const int N = firstWeek.size();
// 
//     // promise: begins[i] is the minimum index of the ith t-shirt.
//     vector<int> begins(N + 1);
//     for (int i = 0; i < N; ++i) {
//       begins[firstWeek[i]] = i;
//     }
// 
//     int weeks = 1;
//     while (true) {
//       // test stop condition.
//       bool stop = true;
//       for (int i = 0; i < N; ++i) {
//         int shirt_num = lastWeek[i];
//         if (begins[shirt_num] > i) {
//           stop = false;
//           break;
//         }
//       }
//       if (stop) {
//         break;
//       }
// 
//       // update begins.
//       for (int i = 1; i <= N; ++i) {
//         begins[i] = max(0, begins[i] - 1);
//       }
//       ++weeks;
//     }
//     return weeks;
//   }
// };


// O(n) solution.
class AttackOfTheClones {
 public:
  int count(vector <int> firstWeek, vector <int> lastWeek) {
    const int N = firstWeek.size();
    vector<int> first_mapping(N + 1);
    vector<int> last_mapping(N + 1);
    for (int i = 0; i < N; ++i) {
      first_mapping[firstWeek[i]] = i;
      last_mapping[lastWeek[i]] = i;
    }

    int weeks = 1;
    for (int shirt = 1; shirt <= N; ++shirt) {
      if (first_mapping[shirt] <= last_mapping[shirt]) {
        continue;
      }
      weeks = max(weeks, first_mapping[shirt] - last_mapping[shirt] + 1);
    }
    return weeks;
  }
};
