#include <iostream>

using namespace std;

const int N = 1000010;
int lf[N]; // Lowest prime factor
int e[N]; // puissance


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

    for(int i=0; i<N; i++) e[i]=1;
    int k=0;
    while(n > 1) {
      if( lf[n] == lf[ n/lf[n] ] )
        e[k]++;
      else k++;
      n /= lf[n];
    }
    int p = 1;
    for(int i=0; i<k; i++) {
      p *= ( e[i] + 1 );
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
