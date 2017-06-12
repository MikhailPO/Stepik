/*Дано положительное действительное число X. Выведите его дробную часть.*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double N;
	cin >> N;
		cout << N- trunc(N);


	return 0;
}

/*Дано положительное действительное число X. Выведите его первую цифру после десятичной точки.*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double N,X;
	cin >> N;
	X=N- trunc(N);
    X*=10;
    cout <<trunc(X) ;


	return 0;
}

/*Даны длины сторон треугольника. Вычислите площадь треугольника.*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a,b,c,p;
	cin >> a >> b >>c;
    p=(a+b+c)/2;
    cout << sqrt(p*(p-a)*(p-b)*(p-c));


	return 0;
}

/*Процентная ставка по вкладу составляет P процентов годовых, которые прибавляются к сумме вклада в конце года. Вклад составляет X рублей Y копеек. Определите размер вклада через год.*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double x, y, c, p, b;
	cin >> p >> x >> y;
	p = p / 100;
	x *= 100;
	x += y;
	x += x*p+0.0001;
	b = x / 100;
	y = b - trunc(b);
	y *= 100;
	
	x -= y;
	x /= 100;
	cout << floor(x) << " " << floor(y);

	
	return 0;
}

/*Процентная ставка по вкладу составляет P процентов годовых, которые прибавляются к сумме вклада через год. Вклад составляет X рублей Y копеек. Определите размер вклада через K лет.*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long x, y, c, b;
    double p;
    int k;
	cin >> p >> x >> y>>k;
    c=x*100 +y;
    int i=0;
    b=c;
    while(i<k){
    b+=(p/100)*b;
        i++;
    }
	
    x=b/100;
    y= b-b/100*100;
	cout << x << " " << y;

	
	return 0;
}

/*Определите среднее значение всех элементов последовательности, завершающейся числом 0.*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int N=1,Sum=0,i=0; 
    double middle;
    while(N!=0){
        cin >> N;
    Sum+=N;
        i++;
    }
    i--;
    middle=(double)Sum/i;
    cout << setprecision(11) << fixed << middle;
       
   
				return 0;
			}

/*Дана последовательность натуральных чисел. Определите стандартное отклонение для данной последовательности натуральных чисел, завершающейся числом 0.*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	int N[1000],Sum=0,i=0; 
    double middle,result=0;
   cin >> N[i];
	Sum += N[i];
	while (N[i] != 0) {
		i++;
		cin >> N[i];
		Sum += N[i];
		
	}
    middle=(double)Sum/i;
    for(int j=0;j<i;j++){
    result+=(N[j]-middle)*(N[j]-middle);
    }
    result/=(i-1);
    result=sqrt(result);
    cout << setprecision(11) << fixed << result;
       
   
				return 0;
			}

/*Дан многочлен P(x)=anxn + an−1xn−1+ … + a1x + a0 и число x. Вычислите значение этого многочлена, воспользовавшись схемой Горнера:*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	int n,Sum,i=0; 
   cin >> n;
    double arr[n+1],x,result=0;
	 cin >>x;
    if(n!=0){
     cin >>arr[0];
    result=arr[0]*x;
    for (i=1;i<n;i++){
        cin >>arr[i];
        result+=arr[i];
        result*=x;
    }}else{}
     cin >>arr[n+1];
    result+=arr[n+1];
    cout << result;
       
   
				return 0;
			}

/*Даны действительные коэффициенты a, b, c, при этом a ≠ 0 . Решите квадратное уравнение ax2 + bx + c = 0 и выведите все его корни.*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double a,b,c,D;
     cin >> a >> b >> c;
    if(b*b-4*a*c>0){
    D=sqrt(b*b-4*a*c);
        if((-b-D)/(2*a)<(-b+D)/(2*a))
        cout <<(-b-D)/(2*a)<<" "<<(-b+D)/(2*a);
        else
            cout <<(-b+D)/(2*a)<<" "<<(-b-D)/(2*a);
    }else if(b*b-4*a*c==0){
    
        cout <<(-b)/(2*a);
    }
	 
   
				return 0;
			}

/*Даны действительные коэффициенты a, b, c. Решите уравнение ax2 + bx + c = 0 и выведите все его корни.*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double a,b,c,D;
     cin >> a >> b >> c;
    if(a!=0){
    if(b*b-4*a*c>0){
    D=sqrt(b*b-4*a*c);
        if((-b-D)/(2*a)<(-b+D)/(2*a))
        cout <<2<<" "<<(-b-D)/(2*a)<<" "<<(-b+D)/(2*a);
        else
            cout <<2<<" "<<(-b+D)/(2*a)<<" "<<(-b-D)/(2*a);
    }else if(b*b-4*a*c==0){
    
        cout <<1<<" "<<(-b)/(2*a);
    }else cout <<0;
    }else
    { if(b==c && c==0)
    cout <<3;
     if(b!=0)
    cout <<1<<" "<<(-c)/(b);
     else if(b==0 && c!=0)
          cout <<0;
    }
    
	 
   
				return 0;
			}

/*
Даны вещественные числа a, b, c, d, e, f. Известно, что система линейных уравнений

имеет ровно одно решение. Выведите два числа x и y, являющиеся решением этой системы.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double a,b,c,d,e,f;
     cin >> a >> b >> c >> d >>e >>f;
    cout <<((d*e-b*f)/(a*d-c*b))<<" "<<((a*f-c*e)/(a*d-c*b));
   return 0;
    }
