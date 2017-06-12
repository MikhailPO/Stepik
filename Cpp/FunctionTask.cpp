/*Напишите функцию min(a, b), вычисляющую минимум двух чисел. Затем напишите функцию min4(a, b, c, d), вычисляющую минимум 4 чисел с помощью функции min. Считайте четыре целых числа и выведите их минимум.*/
#include <iostream> 

using namespace std;
int min(int a, int b) {
	int m;
	if (a < b)
		m = a;
	else
		m = b;
	return m;
}
int min4(int a, int b, int c, int d) {
	return min(min(a, b), min(c, d));
}
int main() {
	int a, b,c,d;
	
	cin >>a>>b>>c>>d;
	cout << min4(a, b, c, d);
	cin >> a;
	return 0;
}

/*Даны четыре действительных числа: x1, y1, x2, y2. Напишите функцию distance(x1, y1, x2, y2), вычисляющую расстояние между точкой (x1. y1) и (x2, y2). Считайте четыре действительных числа и выведите результат работы этой функции.*/
#include <iostream> 
#include <cmath> 
using namespace std;
double distance(double a, double b, double c, double d) {
	return sqrt((c-a)*(c-a)+ (d - b)*(d - b));
}
int main() {
	double a, b,c,d;
	
	cin >>a>>b>>c>>d;
	cout << distance(a, b, c, d);
	cin >> a;
	return 0;
}

/*Даны два действительных числа x и y. Проверьте, принадлежит ли точка с координатами (x, y) заштрихованному квадрату (включая его границу). Если точка принадлежит квадрату, выведите слово YES, иначе выведите слово NO. На рисунке сетка проведена с шагом 1.Решение должно содержать функцию IsPointInSquare(x, y), возвращающую true, если точка принадлежит квадрату и false, если не принадлежит. Основная программа должна считать координаты точки, вызвать функцию IsPointInSquare и в зависимости от возвращенного значения вывести на экран необходимое сообщение.
Функция IsPointInSquare не должна содержать инструкцию if.
*/
#include <iostream> 

using namespace std;
int betweenY(double a, double b, double c) {
	if (a <= b && b <= c)
		cout << "YES";
	else
		cout << "NO";
	return 1;
}
int betweenX(double a,double b,double c,double y) {
	if (a <= b && b <= c)
		betweenY(-1, y, 1);
	else
		cout << "NO";
	return 1;
}

bool IsPointInSquare(double x, double y) {
	betweenX(-1, x, 1,y);
	return 1;
}

int main() {
	double a, b;
	
	cin >>a>>b;
	IsPointInSquare(a, b);
	cin >> a;
	return 0;
}

/*Даны пять действительных чисел: x, y, xc, yc, r. Проверьте, принадлежит ли точка (x, y) кругу с центром (xc, yc) и радиусом r. Если точка принадлежит кругу, выведите слово YES, иначе выведите слово NO.
Решение должно содержать функцию IsPointInCircle(x, y, xc, yc, r), возвращающую True, если точка принадлежит кругу и False, если не принадлежит. Основная программа должна считать координаты точки, вызвать функцию IsPointInCircle и в зависимости от возвращенного значения вывести на экран необходимое сообщение.
Функция IsPointInCircle не должна содержать инструкцию if.*/
#include <iostream> 
using namespace std;

int betweenX(double x,double y, double x0, double y0, double r){
		if ((x-x0)*(x-x0)+(y - y0)*(y - y0) <= r*r)
			cout << "YES";
		else
			cout << "NO";
	return 1;
}

bool IsPointInSquare(double x, double y, double x0, double y0, double r) {
	betweenX(x,y,x0,y0,r);
	return 1;
}

int main() {
	double a,b,c,d,e;
	
	cin >>a>>b>>c>>d>>e;
	IsPointInSquare(a,b,c,d,e);
	cin >> a;
	return 0;
}

/*Проверьте, принадлежит ли точка данной закрашенной области:*/
#include <iostream> 
using namespace std;

int cir(double x,double y, double x0, double y0, double r){
	if ((x - x0)*(x - x0) + (y - y0)*(y - y0) < r*r)
		return 1;
	else
		if ((x - x0)*(x - x0) + (y - y0)*(y - y0) == r*r)
			return 2;
	else
			return 0;
}
void dir(double x, double y) {
	if (y >= 0 && (cir(x, y, -1, 1, 2) == 1 || cir(x, y, -1, 1, 2) == 2))
		if ((y + x >= 0) && (y - 2 * x - 2 >= 0))
			cout << "YES";
		else
			cout << "NO";
	else
		if (y < 0 && (cir(x, y, -1, 1, 2) == 0 || cir(x, y, -1, 1, 2) == 2))
			if ((y + x <= 0) && (y - 2 * x - 2 <= 0))
				cout << "YES";
			else
				cout << "NO";
		else
			cout << "NO";
}

bool IsPointInSquare(double x, double y) {
	dir(x,y);
	return 1;
}

int main() {
	double a,b;
	cin >>a>>b;
	IsPointInSquare(a,b);
	cin >> a;
	return 0;
}

/*Дано действительное положительное число a и целоe число n.
Вычислите an. Решение оформите в виде рекурсивной функции power(a, n).
*/
#include <iostream> 
using namespace std;

double power(double a, int n) {
	if (n >0 )
			return a*(power(a, n - 1));
	else
		if (n <0)
			return 1/a*(power(a, n + 1));
		else
		return 1;
}

int main() {
	double a;
	int n;
	cin >>a>>n;
	cout<< power(a,n);
	cin >> a;
	return 0;
}

/*Дано натуральное число n > 1. Выведите его наименьший делитель, отличный от 1.
Решение оформите в виде функции MinDivisor(n). Количество операций в программе должно быть пропорционально корню из n.
Указание. Если у числа n нет делителя, меньшего n , то число n — простое и ответом будет само число n.*/
#include <iostream> 
#include <cmath> 
using namespace std;

int MinDivisor(int n) {
	int h=1, m=1;
	while (h < sqrt(n)) {
		h++;
		if (n % h == 0)
			return h;
	}
	return n;
}

int main() {
	int n;
	cin >>n;
	cout<< MinDivisor(n);
	cin >> n;
	return 0;
}

/*Дано натуральное число n > 1. Проверьте, является ли оно простым. Программа должна вывести слово YES, если число простое и NO, если число составное.
Решение оформите в виде функции IsPrime(n), которая возвращает True для простых чисел и False для составных чисел. Количество операций в программе должно быть пропорционально корню из n.*/
#include <iostream> 
#include <cmath> 
using namespace std;


int MinDivisor(int n) {
	int h=1, m=1;
	while (h < sqrt(n)) {
		h++;
		if (n % h == 0)
			return h;
	}
	return n;
}
bool IsPrime(int n) {
	if (MinDivisor(n) != n)
		return 1;
	else
		return 0;
}
int main() {
	int n;
	cin >>n;
	if (IsPrime(n) == 1)
		cout << "NO";
	else
		cout << "YES";
	cin >> n;
	return 0;
}

/*Возводить в степень можно гораздо быстрее, чем за n умножений! Для этого нужно воспользоваться следующими рекуррентными соотношениями:
an = (a2)n/2  при четном n,
an = a × an−1 при нечетном n.
Реализуйте алгоритм быстрого возведения в степень с помощью рекурсивной функции.
*/
#include <iostream> 
#include <cmath> 
using namespace std;

double power(double a, int n) {
	if (n == 2)
		return a*a;
	if (n % 2 == 0) {
		if (n > 0)
			return power(power(a, 2), n / 2);
		else
			if (n < 0)
				return 1 / a*(power(a, n + 1));
			else
				return 1;
	}
	else
		return a*power(a, n - 1);
}

int main() {
	double a;
	int n;
	cin >>a>>n;
	cout << power(a, n);
	cin >> n;
	return 0;
}

/*Дана последовательность чисел, завершающаяся числом 0. Найдите сумму всех этих чисел, не используя цикл.*/
#include <iostream> 
#include <cmath> 
using namespace std;


int Sum() {
	int n, k = 0;
	cin >> n;
	if (n != 0) {
		return n+Sum();
	}
	return 0;
}
int main() {
	int n;
	cout << Sum();
	cin >> n;
	return 0;
}

/*Напишите функцию fib(n), которая по данному целому положительному n возвращает n-e число Фибоначчи. В этой задаче нельзя использовать циклы - используйте рекурсию.
Первое и второе числа Фибоначчи равны 1, а каждое следующее равно сумме двух предыдущих.

*/
#include <iostream> 
#include <cmath> 
using namespace std;

int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else
		return fib(n - 1) + fib(n - 2);
}
int main() {
	int n;
	cin >> n;
	cout << fib(n);
	cin >> n;
	return 0;
}

/*В небоскребе n этажей. Известно, что если уронить стеклянный шарик с этажа номер p, и шарик разобьется, то если уронить шарик с этажа номер p+1, то он тоже разобьется. Также известно, что при броске с последнего этажа шарик всегда разбивается.Вы хотите определить минимальный номер этажа, при падении с которого шарик разбивается. Для проведения экспериментов у вас есть два шарика. Вы можете разбить их все, но в результате вы должны абсолютно точно определить этот номер.
Определите, какого числа бросков достаточно, чтобы заведомо решить эту задачу.*/
#include <iostream> 
#include <cmath> 
using namespace std;

int f(int n) {
	int k = 2, s = 1;
	while (n>k) {
		s++;
		k += s;
	}
	return s;
}
int main() {
	int n;
	cin >> n;
	cout << f(n);
	cin >> n;
	return 0;
}

/*Дано число N. Определите, сколькими способами можно расставить на доске N×N N ферзей, не бьющих друг друга.

*/
#include <iostream>  
using namespace std;


void stolb(int n, int m[11], int now,int &s) {
	int a[11];
	for (int i = 1;i <= n;i++) {
		a[i] = 0;
	}
	for (int i = 1; i < now;i++) {
		a[m[i]] = 1;
		if (m[i] - (now - i) >= 1)
			a[m[i] - (now - i)] = 1;
		if (m[i] + (now - i) <=n)
			a[m[i] + (now - i)] = 1;
	}
	for (int i = 1;i <= n;i++) {
		if (a[i] == 0) {
			if (now == n) {
				s++;
				break;
			}
			m[now] = i;
			stolb(n, m, now + 1, s);
		}
	}
}
int main() {
	int n,s=0;
	int m[11];
	cin >> n;
	for (int i = 0;i <= n;i++)
		m[i] = 0;
	stolb(n, m,1, s);
	cout << s;
	cin >> n;
	return 0;
}
