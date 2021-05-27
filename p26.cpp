#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int getReciprocalCycles(int div)
{
    unordered_map<int, int> m;
    queue<int> q;
    int num = 1;

    while(num) {
        q.push(num/div);
        if(num > div) {
            if(m.find(num) != m.end()) {
                break;
            }
            m.insert({num, num/div});
            num %= div;
        }
        num *= 10;
    }
    if(num == 0) {
        return 0;
    }
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        if(front == num/div) {
            break;
        }
    }
    return q.size();
}

int main(int argc, char **argv)
{
    int ans = -1, curr = -1;

    for(int i = 1; i < 1000; i++) {
        int temp = getReciprocalCycles(i);
        if(temp > curr) {
            curr = temp;
            ans = i;
        }
        // cout << i << ": " << temp << endl;
    }
    cout << ans << endl;

    return 0;
}
