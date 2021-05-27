#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
    int count = 0;
    /* 1 - 1000 */
    char const *str1[] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    char const *str2[] = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };
    char const *str3[] = {"hundred", "thousand"};
    char const *str_and = "and";

    for(int i = 1; i <= 1000; i++) {

        int thousand = i / 1000;
        int hundred = (i % 1000) / 100;
        int ten = (i % 100) / 10;
        int num = (i % 10);
        int temp;

        if(thousand) {
            count += strlen(str1[1]) + strlen(str3[1]);
            cout << str1[1] << " " << str3[1] << " ";
            if(hundred) {
                count += strlen(str_and) + strlen(str1[hundred]) + strlen(str3[0]);
                cout << str_and << " " << str1[hundred] << " " << str3[0] << " ";
            }
            temp = i % 100;
            if(temp) {
                count += strlen(str_and);
                cout << str_and << " ";
                if(temp < 20) {
                    count += strlen(str1[temp]);
                    cout << str1[temp] << " ";
                } else {
                    if(ten) {
                        count += strlen(str2[ten]);
                        cout << str2[ten] << " ";
                    }
                    if(num) {
                        count += strlen(str1[num]);
                        cout << str1[num] << " ";
                    }
                }
            }
        } else {
            if(hundred) {
                count += strlen(str1[hundred]) + strlen(str3[0]);
                cout << str1[hundred] << " " << str3[0] << " ";
                temp = i % 100;
                if(temp) {
                    count += strlen(str_and);
                    cout << str_and << " ";
                    if(temp < 20) {
                        count += strlen(str1[temp]);
                        cout << str1[temp] << " ";
                    } else {
                        if(ten) {
                            count += strlen(str2[ten]);
                            cout << str2[ten] << " ";
                        }
                        if(num) {
                            count += strlen(str1[num]);
                            cout << str1[num] << " ";
                        }
                    }
                }
            } else {
                temp = i % 100;
                if(temp) {
                    if(temp < 20) {
                        count += strlen(str1[temp]);
                        cout << str1[temp] << " ";
                    } else {
                        if(ten) {
                            count += strlen(str2[ten]);
                            cout << str2[ten] << " ";
                        }
                        if(num) {
                            count += strlen(str1[num]);
                            cout << str1[num] << " ";
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    cout << count << endl;

    return 0;
}
