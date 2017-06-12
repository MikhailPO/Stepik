/*Дан список целых чисел, который может содержать до 100000 чисел. Определите, сколько в нем встречается различных чисел.*/
#include <iostream>
#include <set>

using namespace std;

int main() {
	set <int> s;
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}
	cout << s.size();
	return 0;
}

/*Во входной строке записана последовательность чисел через пробел. Для каждого числа выведите слово YES (в отдельной строке), если это число ранее встречалось в последовательности или NO, если не встречалось.

*/
#include <iostream>
#include <set>
using namespace std;

int main() {
	set <int> s;
	int n,x,f=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		 s.insert(x);
		 if (f == s.size())
			 cout << "YES\n";
		 else
			 cout << "NO\n";
		 f = s.size();
	}
	cin >> n;
	return 0;
}

/*Даны два списка чисел, которые могут содержать до 100000 чисел каждый. Посчитайте, сколько чисел содержится одновременно как в первом списке, так и во втором.*/
#include <iostream>
#include <set>
using namespace std;

int main() {
	set <int> s;
	int n,x,f;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		 s.insert(x);
		
	}
	cin >> f;
	for (int i = 0; i < f; i++) {
		cin >> x;
		s.insert(x);

	}
	cout << n+f-s.size();
	cin >> n;
	return 0;
}
/*Даны два списка чисел, которые могут содержать до 100000 чисел каждый.  Выведите все числа, которые входят как в первый, так и во второй список в порядке возрастания.

*/
#include <iostream>
#include <set>

using namespace std;

int main() {
	set <int> s,d;
	int n,x,f,sz;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		 s.insert(x);
		
	}
	cin >> f;
	sz = n;
	for (int i = 0; i < f; i++) {
		cin >> x;
		s.insert(x);
		if (sz == s.size())
			d.insert(x);
		sz = s.size();
		
	}
	for (auto c : d) {
		cout << c<<" ";
	}	
	cin >> n;
	return 0;
}

/*Вам дан словарь, состоящий из пар слов. Каждое слово является синонимом к парному ему слову. Все слова в словаре различны. Для одного данного слова определите его синоним.
*/
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main() {
	map <string, string> s;
	int n,r;
	string s1, s2;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> s1>>s2;
	
		s[s1] = s2;
	}
	cin >> s1;
	for (auto now : s) {
		if(now.first==s1)
		cout <<now.second;
		if (now.second == s1)
			cout << now.first;
	}
	cin >> n;
	return 0;
}

/*Однажды, разбирая старые книги на чердаке, школьник Вася нашёл англо-латинский словарь. Английский он к тому времени знал в совершенстве, и его мечтой было изучить латынь. Поэтому попавшийся словарь был как раз кстати.

К сожалению, для полноценного изучения языка недостаточно только одного словаря: кроме англо-латинского необходим латинско-английский. За неимением лучшего он решил сделать второй словарь из первого.

Как известно, словарь состоит из переводимых слов, к каждому из которых приводится несколько слов-переводов. Для каждого латинского слова, встречающегося где-либо в словаре, Вася предлагает найти все его переводы (то есть все английские слова, для которых наше латинское встречалось в его списке переводов), и считать их и только их переводами этого латинского слова.

Помогите Васе выполнить работу по созданию латинско-английского словаря из англо-латинского.*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
	map <string, string> s, s1;
	string x, a;
	set <string> word;
	int n;
	cin >> n;
	getline(cin, a);
	for (int i = 0;i < n;i++) {
		int	z = 0, fi = 0, m = 0;
		set <string> d, t;
		getline(cin, a);
		z = a.find("-", z + 1);
		x = a.substr(fi, z - fi - 1);
		fi = z + 2;
		for (auto c : a) {
			if (c == ',')
				m++;
		}
		m++;
		for (int j = 0;j < m;j++) {
			z = a.find(",", z + 1);
			if (z == -1)
				z = a.size();
			d.insert(a.substr(fi, z - fi));
			fi = z + 2;
		}
		for (auto f : d) {
			s[f] += x + ", ";
		}
	}
	cout << s.size()<<"\n";
	for (auto c : s) {
		int now;
		now = c.second.size();
		string h;
		h = c.second.substr(0, now - 2);
		cout << c.first << " - " << h;
		cout << "\n";
	}
	cin >> n;
	return 0;
}

