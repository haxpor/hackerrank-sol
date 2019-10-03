#include <iostream>
#include <cmath>
#include <type_traits>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()
template <bool digit>
static int reversed_binary_value()
{
    return digit;
};

template <bool digit, bool...digits, typename std::enable_if<sizeof...(digits), int>::type = 0>
static int reversed_binary_value()
{
    return (reversed_binary_value<digits...>() << 1) + digit;
};

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
