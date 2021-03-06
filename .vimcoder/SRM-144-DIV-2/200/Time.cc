
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

class Time
{
public:
	string whatTime(int seconds)
	{
    int h = seconds / 3600;
    seconds %= 3600;
    int m = seconds / 60;
    seconds %= 60;
    return to_string(h) + ":" + to_string(m) + ":" + to_string(seconds);
	}
};

