#include <iostream>
#include <unordered_map>

using namespace std;

int getLength(long num, unordered_map<int, int>& m)
{
    int result;

    if(num == 1) {
        return 1;
    }
    if(m.find(num) != m.end()) {
        return m[num];
    }
    if(num % 2 == 0) {
        result = 1 + getLength(num / 2, m);
    } else {
        result = 1 + getLength(3 * num + 1, m);
    }
    m.insert({num, result});
    
    return result;
}

int main(int argc, char **argv)
{
    int maximum = 0;
    int ans = -1;
    unordered_map<int, int> m;
    for(int i = 1; i <= 1000000; i++) {
        int length = getLength(i, m);
        if(length > maximum) {
            maximum = length;
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
