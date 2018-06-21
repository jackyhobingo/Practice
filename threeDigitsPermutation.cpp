// Description:
// Using 1,2,3,...,9 to combinate 3 three-digit number abc, def, ghi.
// Each number (1,2,3,...,9) only appears once.
// abc:def:ghi = 1:2:3 
// Print all solution.

#include<iostream>

using namespace std;

void record(int threeDigits, int numbers[10]) 
{
    numbers[threeDigits % 10] ++;
    numbers[threeDigits / 10 % 10] ++;
    numbers[threeDigits / 100 % 10] ++;
}

int main()
{
    int abc, def, ghi;
    
    abc = 123; // The minimal and not repeating number.
    
    while (abc <= 333) { // if abc > 333 then ghi > 1000
        def = abc * 2;
        ghi = abc * 3;
        int usedNumbers[10] = {0};
        record(abc, usedNumbers);
        record(def, usedNumbers);
        record(ghi, usedNumbers);
        int legal = 1;
        for (int i = 1; i < 10; i++) {
            legal &= usedNumbers[i];
        }
        if (legal) {
            cout << abc << ":";
            cout << def << ":";
            cout << ghi << endl;
        }
        abc ++;
    }



}

