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
    for(unsigned int i = 0; i < 100000; ++i ) {
        marked += c;
    }
    marked.at(0) = 'C';
    marked.at(1) = 'C';
    cout << "running";

    int length = marked.size();
    for(int i = 2; i < length; i++) {
            for(int j = 2; j*i < length ; j++) {
                    marked.at(j*i) = 'C';

            }
        }

    cout << "running";
    cout << marked.rfind("P");
    /*int last = 0;
    for(int i = 2; i < 100000; i++) {
        if(isPrime(i)) {
            if(i > last) {
                last = i;
            }
        }
    }
     */
    cout << endl;



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

