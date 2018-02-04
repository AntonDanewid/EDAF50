//
// Created by Anton on 2/3/2018.
//


#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n);
int main() {

    char c = 'P';
    string marked;
    for(unsigned int i = 0; i < 201; ++i ) {
        marked += c;
    }
    marked.at(0) = 'C';
    marked.at(1) = 'C';
    int length = 200;
    for(int i = 2; i < length; i++) {
        if(isPrime(i)) {
            for(int j = 2; j < length/i ; j++) {
                if(j*i < marked.size()) {
                    marked.at(j*i) = 'C';
                } else {
                    break;
                }
            }
        }
        }

    cout << marked;

    int last = 0;
    for(int i = 2; i < 100000; i++) {
        if(isPrime(i)) {
            if(i > last) {
                last = i;
            }
        }
    }
    cout << endl;
    cout << "largest prime is " << last;



}
bool isPrime(int n) {

    if(n < 2) {
        return false;
    }

    if(n % 2 == 0) {
        return n ==2;
    }
    int root = sqrt(n);
    for (int i = 3; i <= root; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

