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

class BearFair {
 public:
  string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
    vector<int> up_to_quantity(b + 1, -1);
    for (int i = 0; i < upTo.size(); ++i) {
      int element = upTo[i];
      // c1.
      if (up_to_quantity[element] != -1 &&
          up_to_quantity[element] != quantity[i]) {
        return "unfair";
      }
      up_to_quantity[element] = quantity[i];
    }

    // c2.
    if (up_to_quantity[b] != -1 && up_to_quantity[b] != n) {
      return "unfair";
    }
    up_to_quantity[b] = n;

    int even_count = 0;
    int odd_count = 0;

    up_to_quantity[0] = 0;
    for (int begin = 1, end = 1; begin <= b; begin = end + 1) {
      end = begin;
      while (end <= b && up_to_quantity[end] == -1) {
        ++end;
      }
      int pre_quantity = up_to_quantity[begin - 1];
      int cur_quantity = up_to_quantity[end];
      // c3.
      if (pre_quantity > cur_quantity) {
        return "unfair";
      }
      if (cur_quantity > pre_quantity) {
        int slice_size = end - begin + 1;
        int element_size = cur_quantity - pre_quantity;

        // c4.
        if (element_size > slice_size) {
          return "unfair";
        }

        int odd_slice = slice_size / 2;
        if (slice_size % 2 != 0 && begin % 2 != 0) {
          ++odd_slice;
        }

        int even_slice = slice_size / 2;
        if (slice_size % 2 != 0 && begin % 2 == 0) {
          ++even_slice;
        }

        int odd_base = max(element_size - even_slice, 0);
        int even_base = max(element_size - odd_slice, 0);
        
        // update counts.
        odd_count += odd_base;
        even_count += even_base;
      }
    }

    int half = n / 2;
    // c5.
    if (odd_count > half || even_count > half) {
      return "unfair";
    }
    return "fair";
  }
};
