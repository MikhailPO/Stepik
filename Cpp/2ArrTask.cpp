/*Найдите индексы первого вхождения максимального элемента.*/
#include <iostream>
using namespace std;

int main() {
	int a[100][100];
	int max[2][2];
	int n, m;
	//read array
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	// processing
	 max[1][0]=0;
	 max[0][1] = 0;
	 max[0][0] = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > max[0][0]) {
				max[1][0] = i;
				max[0][1] = j;
				max[0][0] = a[i][j];
			}
		}
	}
	cout << max[1][0]<<" "<< max[0][1];
	cin >> m;
	return 0;
}

/*Дано нечетное число n, не превосходящее 15. Создайте двумерный массив из n×n элементов, заполнив его символами "." (каждый элемент массива является строкой из одного символа). Затем заполните символами "*" среднюю строку массива, средний столбец массива, главную диагональ и побочную диагональ. В результате "*" в массиве должны образовывать изображение звездочки. Выведите полученный массив на экран, разделяя элементы массива пробелами.*/
#include <iostream>
//#include <iomanip>
//#include <cmath>

using namespace std;

int main() {
	char a[100][100];
	int n,midlle;
	//read array
	cin >> n;
	midlle = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == midlle || j == midlle)||(i == j)) {
				a[i][j] = '*';
			}else {
				a[i][j] = '.';
			}
		}
	}

	// processing
	int i = 0, j = n-1;
	while (i != n) {
		a[i][j] = '*';
		i++;
		j--;
	}
	// out
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
	//wait
	cin >> n;
	return 0;
}

/*Дано число n, не превышающее 100. Создайте массив размером n×n и заполните его по следующему правилу. На главной диагонали должны быть записаны числа 0. На двух диагоналях, прилегающих к главной, числа 1. На следующих двух диагоналях числа 2, и т.д. Выведите полученный массив на экран, разделяя элементы массива пробелами.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;
int abs(int f) {
	f *= f;
	return sqrt(f);
}
int main() {
	int a[100][100];
	int n,midlle;
	//read array
	cin >> n;
	midlle = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = abs(i - j);
			}
		}
	

	// processing

	// out
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
	//wait
	cin >> n;
	return 0;
}

/*Дан двумерный массив и два числа: i и j. Поменяйте в массиве столбцы с номерами i и j*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;
int abs(int f) {
	f *= f;
	return sqrt(f);
}
int main() {
	int a[100][100],b[100][100];
	int n,m;
	int x, y;
	//read array
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j];
			}
		}
	cin >> x>>y;

	// processing
	for (int i = 0;i < n;i++) {
		b[i][x] = a[i][y];
		b[i][y] = a[i][x];
	}
	// out
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << b[i][j]<<" ";
		}
		cout << endl;
	}
	//wait
	cin >> n;
	return 0;
}

/*Дано число n, не превосходящее 10, и массив размером n × n. Проверьте, является ли этот массив симметричным относительно главной диагонали. Выведите слово “YES”, если массив симметричный, и слово “NO” в противном случае.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;
int abs(int f) {
	f *= f;
	return sqrt(f);
}
int main() {
	int a[100][100];
	int n;
	int x=0, y;
	//read array
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			}
		}

	// processing
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((a[i][j] != a[j][i]) &&(i!=j)) {
				x = 1;
			}
		}
	}
	// out
	if (x == 0)
		cout << "YES";
else
cout << "NO";
	//wait
	cin >> n;
	return 0;
}

/*ан квадратный двумерный массив размером n × n и число k. Выведите элементы k-й по счету диагонали ниже главной диагонали (т.е. если k = 1, то нужно вывести элементы первой диагонали, лежащей ниже главной, если k = 2, то второй диагонали и т.д.).

Значение k может быть отрицательным, например, если k = −1, то нужно вывести значение первой диагонали лежащей выше главной. Если k = 0, то нужно вывести элементы главной диагонали.

Программа получает на вход число n, не превосходящие 10, затем массив размером n × n, затем число k.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;
int abs(int f) {
	f *= f;
	return sqrt(f);
}
int main() {
	int a[100][100];
	int n;
	int x=0, k;
	//read array
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			}
		}
	cin >> k;
	// processing
	if (k == 0) {
		for (int i=0;i < n;i++) {
			cout << a[i][i] <<" ";
		}
	}
	else if (k > 0) {
		int j = k;
		for (int i=0;j < n;i++) {
			cout << a[j][i] << " ";
			j++;
		}
		}
	else if (k < 0) {
		int j = abs(k);
		for (int i = 0;j < n;i++) {
			cout << a[i][j] << " ";
			j++;
		}
	}
	// out
	
	//wait
	cin >> n;
	return 0;
}

/*Дан двумерный массив размером n×m (n и m не превосходят 1000). Симметричный ему относительно главной диагонали массив называется транспонированным к данному. Он имеет размеры m×n: строки исходного массива становятся столбцами транспонированного, столбцы исходного массива становятся строками транспонированного.

Для данного массива постройте транспонированный массив и выведите его на экран.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;
int abs(int f) {
	f *= f;
	return sqrt(f);
}
int main() {
	int a[1000][1000];
	int b[1000][1000];
	int n,m;
	int x=0, k;
	//read array
	cin >> n >>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			b[j][i] = a[i][j];
			}
		}
	// processing
	
	// out
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
		cout <<	b[i][j]<< " ";
		}
		cout << endl;
	}
	//wait
	cin >> n;
	return 0;
}

/*В кинотеатре n рядов по m мест в каждом (n и m не превосходят 20). В двумерном массиве хранится информация о проданных билетах, число 1 означает, что билет на данное место уже продан, число 0 означает, что место свободно. Поступил запрос на продажу k билетов на соседние места в одном ряду. Определите, можно ли выполнить такой запрос.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;
int abs(int f) {
	f *= f;
	return sqrt(f);
}
int main() {
	int a[100][100];
	int n,m;
	int x=0, k,mem=-1,number=0;
	//read array
	cin >> n >>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			}
		}
	// processing
	cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				x++;
			}
			else
			{
				if (mem < x) {
					mem = x;
				}
				x = 0;}
			if (mem < x) {
				mem = x;
			}
			
		}
		if (mem >= k) {
			number = i+1;
			break;
		}
        mem=0;
        x=0;
	}
	// out

		cout << number;
	//wait
	cin >> n;
	return 0;
}

/*	Дан прямоугольный массив размером n×m. Поверните его на 90 градусов по часовой стрелке, записав результат в новый массив размером m×n.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;
int abs(int f) {
	f *= f;
	return sqrt(f);
}
int main() {
	int a[100][100];
	int b[100][100];
	int n,m;
	int x=0, k,mem=-1,number=0;
	//read array
	cin >> n >>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			b[i][j] = 0;
			}
		}
	// processing
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j]=a[n-j-1][i];
		}
	}
	// out
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << b[i][j]<<" ";
		}
		cout << endl;
	}

	//wait
	cin >> n;
	return 0;
}

/*По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m “змейкой”, как показано в примере.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;
int abs(int f) {
	f *= f;
	return sqrt(f);
}
int main() {
	int a[100][100];
	int b[4][4];
	int n,m;
	int x=0, k,mem=-1,number=0;
	//read array
	cin >> n >>m;
	for (int i = 0; i < n; i++) {
		if(i-i/2*2==0){
		for (int j = 0; j < m; j++) {
			x++;
			a[i][j]= x;
			}
		}
		else {
			for (int j = m-1; j >= 0; j--) {
				x++;
				a[i][j] = x;
			}
		}
		}
	// processing

	// out
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		cout << endl;
	}

	//wait
	cin >> n;
	return 0;
}

/*По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m “диагоналями”, как показано в примере.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;

int diagonal(int index, int curentN,int curentM, int array[100][100],int n){
	for (int i = curentM; i >= 0;i--) {
		array[curentN][i] = index;
		index++;
		curentN++;
	//	cout << curentN;
		if (curentN >=n)
			break;
	
	}
	return index;

}
int main() {
	int a[100][100];
	int n, m,index=1,curentM=0, curentN=0;
	//read array
	cin >> n >> m;
	for (int i = 0;i <m;i++) {
		index=diagonal(index, 0,i, a,n);
		
	}
	for (int i = 1;i <n;i++) {
	
		index = diagonal(index, i, m-1, a, n);
	}
	// out
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		cout << endl;
	}

	//wait
	cin >> n;
	return 0;
}

/*Даны числа n и m. Заполните массив размером n × m в шахматном порядке: клетки одного цвета заполнены нулями, а другого цвета - заполнены числами натурального ряда сверху вниз, слева направо. В левом верхнем углу записано число 1.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;

int diagonal(int index, int curentN,int curentM, int array[100][100],int n){
	for (int i = curentM; i >= 0;i--) {
		array[curentN][i] = index;
		index++;
		curentN++;
	//	cout << curentN;
		if (curentN >=n)
			break;
	
	}
	return index;

}
int main() {
	int a[100][100];
	int n, m,index=1,curentM=0, curentN=0;
	//read array
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				if (i == 2 * (i / 2)) {
					a[i][j] = index++;
					continue;
				}
				else {
					a[i][j] = 0;
					continue;
				}
			}
			else if (a[i][j - 1] == 0)
					a[i][j] = index++;
				else
					a[i][j] = 0;
		}
		
	}
	// out
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		cout << endl;
	}

	//wait
	cin >> n;
	return 0;
}

/*По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m по спирали, выходящей из левого верхнего угла и закрученной по часовой стрелке, как показано в примере.*/
#include <iostream>
//#include <iomanip>
#include <cmath>

using namespace std;

int Right(int a[100][100],int horizontal,int nowH, int nowV,int index) {
	for (int i = 0;i < horizontal;i++) {
		a[nowV][nowH] = index++;
		nowH++;
	}
	return index;
}
int Left(int a[100][100], int horizontal, int nowH, int nowV, int index) {
	for (int i = 0;i < horizontal;i++) {
		a[nowV][nowH] = index++;
		nowH--;
	}
	return index;
}
int Top(int a[100][100], int vertical, int nowH, int nowV, int index) {
	for (int i = 0;i < vertical;i++) {
		a[nowV][nowH] = index++;
		nowV--;
	}
	return index;
}
int Down(int a[100][100], int vertical, int nowH, int nowV, int index) {
	for (int i = 0;i < vertical;i++) {
		a[nowV][nowH] = index++;
		nowV++;
	}
	return index;
}
int main() {
	int a[100][100];
	int n, m,index=1,nowH=0, nowV=0,ver,hor;
	//read array
	cin >> n >> m;
	ver = n-1;
	hor = m;
	while (1) {
		if (hor == 0)
			break;
		index=Right(a,hor,nowH,nowV,index);
		hor--;
		nowH += hor;
		nowV++;
		if (ver == 0)
			break;
		index = Down(a, ver, nowH, nowV, index);
		ver--;
		nowV += ver;
		nowH--;
		if (hor == 0)
			break;
		index = Left(a, hor, nowH, nowV, index);
		hor--;
		nowH -= hor;
		nowV--;
		if (ver == 0)
			break;
		index = Top(a, ver, nowH, nowV, index);
		ver--;
		nowV -= ver;
		nowH++;
	}
	// out
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		cout << endl;
	}

	//wait
	cin >> n;
	return 0;
}
