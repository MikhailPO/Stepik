/*Отсортируйте массив.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	//reverse(a.begin(), a.end());
	for (auto now : a) {

		cout << now << " ";
	}
	return 0;
}

/*В обувном магазине продается обувь разного размера. Известно, что одну пару обуви можно надеть на другую, если она хотя бы на три размера больше. В магазин пришел покупатель. Требуется определить, какое наибольшее количество пар обуви сможет предложить ему продавец так, чтобы он смог надеть их все одновременно.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,m;
	cin >> m>>n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int s=0;
	for (auto now : a) {
		if (now >= m) {
			s++;
			m =now+3;
		}
		
	}
	cout << s;
	return 0;
}

/*Во время проведения олимпиады каждый из участников получил свой идентификационный номер – натуральное число. Необходимо отсортировать список участников олимпиады по количеству набранных ими баллов.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct olymp {
	int number;
	int point;
};
bool cmd(olymp a,olymp b) {
	if (a.point == b.point) {
		return a.number > b.number;
	}
	return a.point < b.point;
}
int main() {
	int n;
	cin >> n;
	vector <olymp> a(n);
	for (int i = 0; i < n; i++) {
		int temp_n, temp_p;
		cin >> temp_n >> temp_p;
		a[i] = { temp_n,temp_p };
	}
	sort(a.begin(), a.end(),cmd);
	reverse(a.begin(), a.end());
	for (auto now : a) {	
		cout << now.number <<" "<< now.point;
		cout << "\n";
		
		
	}
	return 0;
}

/*Выведите все исходные точки в порядке возрастания их расстояний от начала координат. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
struct olymp {
	int number;
	int point;
};
bool cmd(olymp a,olymp b) {
	float r1, r2;
	r1 = sqrt(a.number*a.number + a.point*a.point);
	r2 = sqrt(b.number*b.number + b.point*b.point);
	return r1 < r2;
}
int main() {
	int n;
	cin >> n;
	vector <olymp> a(n);
	for (int i = 0; i < n; i++) {
		int temp_n, temp_p;
		cin >> temp_n >> temp_p;
		a[i] = { temp_n,temp_p };
	}
	sort(a.begin(), a.end(),cmd);
	//reverse(a.begin(), a.end());
	for (auto now : a) {	
		cout << now.number <<" "<< now.point;
		cout << "\n";
		
		
	}
	return 0;
}

/*Выведите фамилии и имена учащихся в порядке убывания их среднего балла.*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
struct stud {
	string fnam;
	string snam;
	int a, b, c;
};
int IntStr(string f) {
	if ( f[0] == '1') {
		return 1;
	}else if(f[0] == '2') {
		return 2;
	}
	else if(f[0] == '3') {
		return 3;
	}
	else if(f[0] == '4') {
		return 4;
	}
	else if (f[0] == '5') {
		return 5;
	}
		return 3;
}
bool cmd(stud a,stud b) {
	int r1, r2;
	r1 = (a.a + a.b + a.c) ;
	r2 = (b.a + b.b + b.c) ;
	
	return r1 > r2;
}
int main() {
	int n;
	string hh;
	cin >> n;
	getline(cin, hh);
	vector <stud> a(n);
	for (int i = 0; i < n; i++) {
		getline(cin, hh);
		int z = 0,x=0,m=0,fi=0;
		string dd[5];
		for (auto c : hh) {
			if (c == ' ')
				m++;
		}
		m++;
		for (int j = 0;j < m;j++) {
			z = hh.find(" ", z + 1);
			if (z == -1)
				z = hh.size();
			dd[x]=hh.substr(fi, z - fi);
			x++;
			fi = z + 1;
		}
		stud temp_str;
		temp_str.fnam = dd[0];
		temp_str.snam = dd[1];
		temp_str.a = IntStr(dd[2]);
		temp_str.b = IntStr(dd[3]);
		temp_str.c = IntStr(dd[4]);
		a[i] = temp_str;
	}
	stable_sort(a.begin(), a.end(),cmd);
	//reverse(a.begin(), a.end());
	//cout << "\n\n\n\n";
	for (auto now : a) {	

		cout << now.fnam << " " << now.snam ;
        //<<"  "<<now.a << now.b << now.c;
		cout << "\n";
		
	}
	cin >> n;
	return 0;
}	
