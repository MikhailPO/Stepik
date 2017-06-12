//следующие четное число
#include <iostream>
using namespace std;
int main() {
 int K,N;
    cin >> N;
    K= (N-(N/2)*2);
    cout << N +2 - K;
  return 0;
}

//Парты
#include <iostream>
using namespace std;
int main() {
    int F,S,T;
    cin >> F >> S >>T;
    cout << (F+2-1)/2+(S+2-1)/2+(T+2-1)/2;
  return 0;
}

//Покупка пирожков
#include <iostream>
using namespace std;
int main() {
    int R,C,N;
    cin >> R >> C >> N;
    R=R*N;
    C=C*N;
    R=R+C/100;
    C=C-(C/100)*100;
    cout << R << " " <<C;
  return 0;
}

//Электронные часы
#include <iostream>
using namespace std;
int main() {
    int N,h,m,m1,s,s1;
    cin >> N;
    h=(N/3600);
    h=h-h/24*24;
    m=(N-(N/3600)*3600-(N-(N/60)*60))/60;
    m1=m/10;
    m=m-(m/10)*10;
    s=N-(N/60)*60;
    s1=s/10;
    s=s-(s/10)*10;
    cout << h << ":" << m1 <<m<<":"<<s1<<s;
  return 0;
}


//Разность времен
#include <iostream>
using namespace std;
int main() {
    int h,m,s,h1,s1,m1,sec,sec1;
    cin >> h>>m>>s>>h1>>m1>>s1;
    sec=h*3600+m*60+s;
    sec1=h1*3600+m1*60+s1;
    cout<<sec1-sec;
  return 0;
}

//МКАД
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int V,T,d,da,e;
    cin >> V >>T;
    d=V*T;
    da=fabs(d);
    da=da-(da/109)*109;
    e=V/fabs(V);
    d=da*e+109;
   d=d-(d/109)*109;
        cout << d;
  
  return 0;
}

//Симметричное число
#include <iostream>
using namespace std;
int main() {
    int N,s,d,t,e;
    cin >> N;
    t=N/1000;
    s=(N-(N/1000)*1000)/100;
    d=(N-(N/100)*100)/10;
    e=N-(N/10)*10;
    if(t==e){
        if(s==d){cout <<1;
                }else cout <<0;}
   else cout <<0;
    return 0;
}

//Улитка
#include <iostream>
using namespace std;
int main() {
    int H,A,B,day,way;
    cin >> H >> A >>B;
    way=B;
    for(day=0;H>way;day++){
    way-=B;
    way+=A;
    }
    cout << day;
  return 0;
}
