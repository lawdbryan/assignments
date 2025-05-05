1. The base case in the function is when low > high

2. The following would print out: 10*8*6*4*2 = 3840. But there is no base case within the program, resulting in a stack overflow error.

3. def sum(low, high)
	return low if (low==high)
   else:
	return high + sum(low, high-1)

end

4).
```c++
#include <iostream>
#include <vector>
#include <variant>

using namespace std;

using NestedArray = variant<int, vector<NestedArray>>;

void printNumbers(const NestedArray& element) {
    if (holds_alternative<int>(element)) {
        cout << get<int>(element) << endl;
    } else {
        const vector<NestedArray>& subArray = get<vector<NestedArray>>(element);
        for (const auto& item : subArray) {
            printNumbers(item);
        }
    }
}
```

youtube video: https://youtu.be/BP_E2Jp7Y1Y
