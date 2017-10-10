#include <iostream>

using namespace std;

bool isPrime(int number) {
    if (number < 2 ) return false;
    else {
        for (int i = 2; i <= number/2; i++) {
            if(number  % i == 0) return false;
        }
        return true;
    }
}

int main()
{

    int desiredIndex, pCounter = 0, iterator = 2;

    int* primes;

    bool found = false;

    cout << "which prime number is desired?" << endl;
    cin >> desiredIndex;

    primes = new int[desiredIndex];

	// loop over the primes we found 1 ... desiredIndex
    while(pCounter < desiredIndex)
    {
		// finding next prime - we divede the candidate number - iterator, by all primes we already found
        for(int i=0; i < pCounter; i++){
            if(!(iterator % primes[i])){
                found = true;
                break;
            }
        }
		// if a new prime is found, store it, insrease the prime numbers counter
        if(!found){
            primes[pCounter++] = iterator;
        }
        iterator++;
        found = false;
    }

	// output prime indexed desiredIndex
    cout << endl << primes[desiredIndex-1] << endl;

	char x;
	cin >> x;
    return 0;
}
