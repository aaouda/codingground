#include <iostream>

using namespace std;

const int N = 1000010;
int lf[N]; // Lowest prime factor


/*
----------------------------------------
   pre_processing lowest prime factor
----------------------------------------
*/

void sieve( void ) {
    for(int i = 2; i < N; i += 2)
        lf[i] = 2;

    for(int i = 3; i < N; i += 2)
        if(lf[i] == 0) {
            lf[i] = i;
            for(int j = i + i; j < N; j += i) {
                if(lf[j] == 0)
                    lf[j] = i;
            }
        }
}



/*
------------------------------------------
  arithmetique fct: nbre of divisor of n
------------------------------------------
*/
void fct( int n ) {

    int e = 1, p = 1;
    while(n > 1) {
      if( lf[n] == lf[ n/lf[n] ] )
        e++;
      else{
         p *= (e + 1);
         e = 1;
      }
      n /= lf[n];
    }
    cout << p << endl;
}

int main( void ) {
    int x;
    cin >> x;
    sieve();
    fct(x);
    return 0;
}
