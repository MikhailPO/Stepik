/*Выведите все элементы массива с четными индексами (то есть A[0], A[2], A[4], ...).*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a(n);
 //in array
    for (int i=0;i<=n;i++) {
        cin >> a[i];
}
	//out array
   int i=-1;
    int temp=1;
    for (auto now : a) {
        if(temp>0){
        cout << now << " ";
        }else{}
        temp*=i;
}
	
	return 0;
}

/*Выведите все четные элементы массива.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a;
 //in array
    int temp;
    for (int i=0;i<n;i++) {
        cin >> temp;
        if(temp-temp/2*2==0)
         a.push_back(temp);
}
	//out array
    for (auto now : a) {
        cout << now << " ";       
}
	
	return 0;
}

/*Найдите количество положительных элементов в данном массиве.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a;
 //in array
    int temp;
    for (int i=0;i<n;i++) {
        cin >> temp;
        if(temp>0)
         a.push_back(temp);
}
	//out array
cout <<a.size();
	
	return 0;
}

/*Дан массив чисел. Выведите все элементы массива, которые больше предыдущего элемента .*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a;
 //in array
    int temp;
    int last;
    cin>>last;
    for (int i=0;i<n-1;i++) {
        cin >> temp;
        if(last<temp)
         a.push_back(temp);
        last=temp;
}
	//out array
    for (auto now : a) {
        cout << now << " ";       
}
	
	return 0;
}

/*Дан массив целых чисел. Если в нем есть два соседних элемента одного знака, выведите эти числа. Если соседних элементов одного знака нет - не выводите ничего. Если таких пар соседей несколько - выведите первую пару.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a;
 //in array
    int temp;
    int last;
    cin>>last;
    for (int i=0;i<n-1;i++) {
        cin >> temp;
        if(last*temp>0){
         a.push_back(last);
         a.push_back(temp);
            break;
        }
        last=temp;
}
	//out array
    for (auto now : a) {
        cout << now << " ";       
}
	
	return 0;
}

/*Выведите значение наименьшего из всех положительных элементов в массиве. Известно, что в массиве есть хотя бы один положительный элемент.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a;
 //in array
    int temp;
    for (int i=0;i<n;i++) {
        cin >> temp;
        if(temp>0){
         a.push_back(temp);
        }
}
    int min=a[0];
 for (int i=1;i<a.size();i++) {
     if(a[i]<min){
     min=a[i];
         a[0]=min;
     }
                 
}   
	//out array
        cout << min;       

	
	return 0;
}

/*Выведите значение наименьшего нечетного элемента списка, а если в списке нет нечетных элементов - выведите число 0.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a;
 //in array
    int temp;
    for (int i=0;i<n;i++) {
        cin >> temp;
        if((temp-temp/2*2)!=0){
         a.push_back(temp);
        }
}
    if(a.size()==0)
        cout <<0;
    else{
    int min=a[0];
 for (int i=1;i<a.size();i++) {
     if(a[i]<min){
     min=a[i];
       a[0]=min;
     }
                 
}   
	//out array
        cout << min;       
    }
	
	return 0;
}

/*Дан список, упорядоченный по неубыванию элементов в нем. Определите, сколько в нем различных элементов.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a;
 //in array
    int temp;
     cin >> temp;
       a.push_back(temp);
    int j=0;
    for (int i=0;i<n-1;i++) {
        cin >> temp;
        if(a[j]!=temp){
         a.push_back(temp);
            j++;
        }
}
    
  
	//out array
        cout << a.size();       
	
	return 0;
}

/* Переставьте соседние элементы массива (A[0] c A[1], A[2] c A[3] и т.д.). Если элементов нечетное число, то последний элемент остается на своем месте.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a;
 //in array
    int temp;
    int j=1;
    for (int i=0;i<n;i++) {
        cin >> temp;
         a.push_back(temp);
}
    if(n-n/2*2!=0)
    n--;
    else{}
     for (int i=0;i<n;i+=2) {
        temp=a[i];
         a[i]=a[j];
         a[j]=temp;
         j+=2;
}
  
	//out array
      for (auto now:a) {
     cout << now <<" ";
}     
	
	return 0;
}

/*Циклически сдвиньте элементы списка вправо (A[0] переходит на место A[1], A[1] на место A[2], ..., последний элемент переходит на место A[0]).*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a(n);
 //in array
    for (int i=1;i<n;i++) {
        cin >> a[i];
}
    cin >> a[0];
  
	//out array
      for (auto now:a) {
     cout << now <<" ";
}     
	
	return 0;
}

/*Дан массив чисел. Посчитайте, сколько в нем пар элементов, равных друг другу. Считается, что любые два элемента, равные друг другу образуют одну пару, которую необходимо посчитать.

*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
     vector <int> a(n);
 //in array
    for (int i=0;i<n;i++) {
        cin >> a[i];
}
int Sum=0;
    for (int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j])
                Sum++;
        }
        
}  
	//out array
   
     cout << Sum;
     
	
	return 0;
}

/*Дан массив. Выведите те его элементы, которые встречаются в массиве только один раз. Элементы нужно выводить в том порядке, в котором они встречаются в списке.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	int n, g = 0;
	cin >> n;
	vector <int> a(n);
	vector <int> c(n);
	vector <int> b;
	//in array
	for (int i = 0;i<n;i++) {
		cin >> a[i];
		c[i] = a[i];
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i] == c[j]) {
				g++;
			}
		}
		if (g == 1)
			b.push_back(a[i]);
		else {}
		g = 0;
	}


	//out array
	for (auto now : b) {
		cout << now << " ";
	}


	return 0;
}
/*Известно, что на доске 8×8 можно расставить 8 ферзей так, чтобы они не били друг друга. Вам дана расстановка 8 ферзей на доске, определите, есть ли среди них пара бьющих друг друга.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int diag(vector <int> a, vector <int> b) {
	vector <int> c(8);
	for (int i = 0;i < 8;i++) {
		c[i] = a[i] - b[i];

	}
	int Sum = 0;
	for (int i = 0;i < 8;i++) {
		for (int j = i + 1;j < 8;j++) {
			if (c[i] == c[j])
				Sum++;

		}
	}
		return Sum;
}
int diag2(vector <int> a, vector <int> b) {
	for (int i = 0;i < 8;i++) {
		for (int j = 0; j < 8;j++) {
			if (a[i] == b[j]) {
				if (b[i] == a[j])
					return 0;
			}
		}
		return 1;
	}
}
int Rev18(int a) {
	switch (a)
	{
	case 1: return 8;
	case 2: return 7;
	case 3: return 6;
	case 4: return 5;
	case 5: return 4;
	case 6: return 3;
	case 7: return 2;
	case 8: return 1;
	}
}

int main() {
	vector <int> a(8);
	vector <int> b(8);
	vector <int> r(8);
    vector <int> r2(8);
	//in array
	for (int i = 0;i<8;i++) {
		cin >> a[i];
		cin >> b[i];
		r[i] = Rev18(a[i]);
        r2[i] = Rev18(b[i]);
	}
	int Sum = 0;
	int Sum2 = 0;
	for (int i = 0;i<8;i++) {
		for (int j = i + 1;j<8;j++) {
			if (a[i] == a[j])
				Sum++;
			if (b[i] == b[j])
				Sum2++;
		}

	}
	//out array

	if (Sum+Sum2 == 0 && diag(a, b) == 0 && diag2(a, b) != 0 && diag(r, b) == 0  ) {
		cout << "NO";
	}
	else cout << "YES";

	
	return 0;
}

/*N кеглей выставили в один ряд, занумеровав их слева направо числами от 1 до N. Затем по этому ряду бросили K шаров, при этом i-й шар сбил все кегли с номерами от li до ri включительно. Определите, какие кегли остались стоять на месте.*/
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector <int> a(k);
	vector <int> b(k);
	vector <string> kek(n);
	set <int> c;
	//in array
	for (int i = 0;i < k;i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0;i < k;i++) {
		for (int j = a[i];j <= b[i];j++) {
			c.emplace(j);
		}
	}

	for (int i = 0; i <n;i++) {
	kek[i] = "I";
	}
	for (auto now:c) {
	kek[now-1] = ".";
	}
	for (auto now : kek) {
	std::cout << now;
	}
	cin >> a[0];
	return 0;
}




