#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int count = 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int date = (1 + 365) % 7;

    /* 1 Jan 1900 was a Monday, search range 1 Jan 1901 to 31 Dec 2000 */
    if(date == 0) {
        count++;
    }
    for(int i = 1901; i < 2001; i++) {
        for(int j = 0; j < 12; j++) {
            date = (date + days[j]) % 7;
            if(j == 1 && i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
                date = (date + 1) % 7;
            }
            if(date == 0) {
                count++;
            }
        }   
    }
    cout << count << endl;

    return 0;
}
