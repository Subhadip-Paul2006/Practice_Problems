// Write an API that generates fancy sequences using the append, addAll, and multAll operations.
// Implement the Fancy class:
// Fancy() Initializes the object with an empty sequence.
// void append(val) Appends an integer val to the end of the sequence.
// void addAll(inc) Increments all existing values in the sequence by an integer inc.
// void multAll(m) Multiplies all existing values in the sequence by an integer m.
// int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.
// Example 1:
// Input
// ["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
// [[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
// Output
// [null, null, null, null, null, 10, null, null, null, 26, 34, 20]


#include <iostream>
#include <vector>
using namespace std;
class Fancy {
public:
    const long long MOD = 1e9 + 7;

    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    long long modInverse(long long x){
        long long power = MOD-2;
        long long result = 1;

        while(power){
            if(power&1) result = (result*x)%MOD;
            x = (x*x)%MOD;
            power >>= 1;
        }

        return result;
    }

    Fancy() {}

    void append(int val) {

        long long x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;

        seq.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {

        if(idx >= seq.size())
            return -1;

        return (seq[idx] * mul + add) % MOD;
    }
};

int main() {
    Fancy fancy;
    fancy.append(2);
    fancy.addAll(3);
    fancy.append(7);
    fancy.multAll(2);
    cout << fancy.getIndex(0) << endl; // Output: 10
    fancy.addAll(3);
    fancy.append(10);
    fancy.multAll(2);
    cout << fancy.getIndex(0) << endl; // Output: 26
    cout << fancy.getIndex(1) << endl; // Output: 34
    cout << fancy.getIndex(2) << endl; // Output: 20
    return 0;
}
    