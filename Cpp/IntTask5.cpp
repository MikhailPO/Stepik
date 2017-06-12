#include <iostream>
using namespace std;
int main() {
    int N,K;
    cin >> N;
    K=(N-(N/100)*100)/10 + N/100 +(N-(N/10)*10);
    cout << K;
  return 0;
}
