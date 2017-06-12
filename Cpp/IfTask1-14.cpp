//Max
#include <iostream>
using namespace std;
int main() {
    int F,S;
    cin >> F >> S;
    if(F>S){cout <<F;
           }else{
    cout<<S;}
     return 0;
}

//Сравнить
#include <iostream>
using namespace std;
int main() {
    int F,S;
    cin >> F >> S;
    if(F>S){cout <<1;
           }else if(S>F){
    cout<<2;}else cout<<0;
     return 0;
}

//Max
#include <iostream>
using namespace std;
int main() {
    int F,S,T;
    cin >> F >> S >>T;
    if(F>=S && F>=T){cout<<F;}else if(S>=F && S>=T){
    cout<<S;
    }else cout<<T;
  return 0;
}

//Треугольник
#include <iostream>
using namespace std;
int main() {
    int F,S,T;
    cin >> F >> S >>T;
    if(F+S>T && T+S>F && F+T>S){cout<<"YES";}
    else cout<<"NO";
  return 0;
}

//Совпадение
#include <iostream>
using namespace std;
int main() {
    int F,S,T,i=0;
    cin >> F >> S >>T;
    if(F==S){i++;}
    if(F==T){i++;}
    if(T==S){i++;}
    if(i==1){i++;}
    cout<<i;
  return 0;
}

//Шахматная ладья
#include <iostream>
using namespace std;
int main() {
    int F,S,F1,S1;
    cin >> F >> S >>F1>>S1;
    if(F==F1||S==S1){cout<<"YES";}else{
    cout<<"NO";
    }
  return 0;
}

//Шахматный король
#include <iostream>
using namespace std;
int main() {
    int F,S,F1,S1;
    cin >> F >> S >>F1>>S1;
    if(F==F1 && ((S1==S+1) || (S1==S-1))){
        cout<<"YES";
    }else if(S==S1 && (F1==F+1 || F1==F-1)){
        cout<<"YES";} else if( ((S1==S+1) || (S1==S-1))&& (F1==F+1 || F1==F-1)){
       cout<<"YES";
    }else cout<<"NO";
  return 0;
}

//Шахматный слон
#include <iostream>
using namespace std;
int main() {
    int F,S,F1,S1;
    cin >> F >> S >>F1>>S1;
    if((F-F1)*(F-F1)==(S-S1)*(S-S1) ||(F1==F && S1==S) ){cout<<"YES";}else cout<<"NO";
  return 0;
}

//Ферзь
#include <iostream>
using namespace std;
int main() {
    int F,S,F1,S1;
    cin >> F >> S >>F1>>S1;
    if((F-F1)*(F-F1)==(S-S1)*(S-S1) ||(F1==F && S1==S) ){cout<<"YES";}else if(F==F1 || S==S1){cout<<"YES";}else cout<<"NO";
  return 0;
}

//Конь
#include <iostream>
using namespace std;
int main() {
    int F,S,F1,S1;
    bool One,To;
    cin >> F >> S >>F1>>S1;
     One=((F-F1)*(F-F1)==1 && (S-S1)*(S-S1)==4);
    To=((F-F1)*(F-F1)==4 && (S-S1)*(S-S1)==1);
    if(One || To){
        cout<<"YES";
    }else cout<<"NO";
  return 0;
}

//Шоколадка
#include <iostream>
using namespace std;
int main() {
    int M,N,K;
    cin >> M >> N >>K;
    bool ONE,TOO;
    ONE=K-K/M*M == 0;
    TOO=K-K/N*N == 0;
    if(ONE||TOO){
        if(K/M<N||K/N<M){cout<<"YES";}
        else cout<<"NO";
    } else  cout<<"NO";
  return 0;
}

//Бассейн
#include <iostream>
using namespace std;
int main() {
    int m,n,x,y,Short,Long;
    cin >> n >> m >>y>>x;
    if(m>=n){
        Long=m;
        Short=n;
    } 
    else {
        Long=n;
        Short=m;
    } 
    if(x>y){if(y<Long-x){if(y<Short-y){cout<<y;}else cout<<Short-y;}
            else if(Long-x<Short-y){cout<<Long-x;}else cout<<Short-y;
    
           }else if(x<Short-y){ if(x<Long-x){cout<<x;}else cout<<Long-x;}
    else if(Short-y<Long-x){cout<<Short-y;}else cout<<Long-x;
    
  return 0;
}

//Неубывания
#include <iostream>
using namespace std;
int main() {
    int a[3];
    cin >> a[0] >> a[1] >>a[2];
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(a[i]>a[j]){
                a[3]=a[i];
                a[i]=a[j];
                a[j]=a[3];
            }
        }
    }
    cout<<a[0]<<" "<<a[1]<<" "<<a[2];
  return 0;
}

//Коропки
#include <iostream>
using namespace std;
int main() {
	int a[3], b[3];
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	int V[2];
	V[0] = a[0] * a[1] * a[2];
	V[1] = b[0] * b[1] * b[2];
	for (int i = 0;i < 3;i++) {
		for (int j = i + 1;j < 3;j++) {
			if (a[i] > a[j]) {
				a[3] = a[i];
				a[i] = a[j];
				a[j] = a[3];
			}
		}
	}
	for (int i = 0;i < 3;i++) {
		for (int j = i + 1;j < 3;j++) {
			if (b[i] > b[j]) {
				b[3] = b[i];
				b[i] = b[j];
				b[j] = b[3];
			}
		}
	}

			if (V[0] == V[1]) { cout << "Boxes are equal"; }
			else if (V[0]>V[1]) {
				if (a[2]>=b[2] && a[1]>=b[1] && a[0] >= b[0]) { cout << "The first box is larger than the second one"; }
				else { cout << "Boxes are incomparable"; }
			}
			else if (V[0] < V[1]) {
				if (a[2] <= b[2] && a[1] <= b[1] && a[0] <= b[0]) { cout << "The first box is smaller than the second one"; }
				else { cout << "Boxes are incomparable"; }
			}


				return 0;
			}
