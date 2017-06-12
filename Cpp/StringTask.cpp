/*По введенному символу определите, является ли он цифрой.*/
#include <iostream>  
using namespace std;

int main() {
	char c;
	cin >> c;
	if (c >= '0' && c <= '9')
		cout << "yes";
	else
		cout << "no";
	cin >> c;
	return 0;
}

/*Переведите символ в верхний регистр.*/
#include <iostream>  
using namespace std;

int main() {
	char c;
	cin >> c;
	int a_num;
	if (c >= 'a' && c <= 'z') {
		a_num = c - 'a';
		c = 'A' + a_num;
	}
	cout << c;
	cin >> c;
	return 0;
}

/*Вводится один символ, измените его регистр. То есть, если была введена строчная буква - сделайте ее заглавной и наоборот. Символы, не являющиеся латинской буквой, нужно выводить без изменений.*/
#include <iostream>  
using namespace std;

int main() {
	char c;
	cin >> c;
	int a_num;
	if (c >= 'a' && c <= 'z') {
		a_num = c - 'a';
		c = 'A' + a_num;
	} else if(c >= 'A' && c <= 'Z') {
		a_num = c - 'A';
		c = 'a' + a_num;
	}
	cout << c;
	cin >> c;
	return 0;
}

/*Дана строка, содержащая пробелы. Найдите, сколько в ней слов (слово – это последовательность непробельных символов, слова разделены одним пробелом, первый и последний символ строки – не пробел).

*/
#include <iostream>  
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int z=0,i=0;
	while (z != -1) {
		z = s.find(" ", z+1);
		i++;
	}
	cout << i;
	cin >> s;
	return 0;
}

/*По данной строке определите, является ли она палиндромом (то есть, читается одинаково как слева-направо, так и справа-налево).*/
#include <iostream>  
#include <string>
using namespace std;

int main() {
	string s, s2;
	getline(cin, s);
	s2 = s;
	int m = s.size() - 1;
	for (int i = 0;i <m + 1;i++) {
		if (s[i] != s2[m - i]) {
			cout << "no";
			m = -3;
			break;
		}
	}
	if(m!=-3)
	cout << "yes";
	cin >> s;
	return 0;
}

/*Найдите в данной строке самое длинное слово и выведите его.*/
#include <iostream>  
#include <string>
using namespace std;

int main() {
	string s, s2,s3;
	int z = 0, m = 0, fi = 0,sz;
	getline(cin, s);
	sz = s.size();
	while (z != -1) {
		z = s.find(" ", z + 1);
		if (z == -1)
			z = sz;
		if (sz == 1)
			z = 1;
		if (m < z - fi) {
			m = z - fi;
			s2 = s.substr(fi,m);
			if (s2[0] == ' ') {
				s3 = s2.substr(fi + 1, z - fi);
				s2 = s3;
			}
		}

		fi = z+1;
		if (z==sz)
			break;
	}
	cout << s2;
	cin >> s;
	return 0;
}

/*В сети интернет каждому компьютеру присваивается четырехбайтовый код, который принято записывать в виде четырех чисел, каждое из которых может принимать значения от 0 до 255, разделенных точками. Вот примеры правильных IP-адресов:
127.0.0.0
192.168.0.1
255.0.255.255
Напишите программу, которая определяет, является ли заданная строка правильным IP-адресом.*/
#include <iostream>  
#include <string>
using namespace std;
int prof(string s) {
	if (s[0] <= '2' && s[0]>'0')
		if (s[0] == '2') {
			if (s[1] > '5' || s[2] > '5' || s[1] < '0' || s[2] < '0')
				return 0;
		}
		else if (s[1] >= '0' && s[2] >= '0' && s[1] <= '9' && s[2] <= '9')
			return 1;
		else 
			return 0;
	return 1;
}
int main() {
	string s, s1[6];
	int z = 0, m = 0, fi = 0,sz,j=0;
	getline(cin, s);

	for (int i = 0;i < 5;i++) {
		z = s.find(".", z + 1);
		if (z == -1)
		z = s.size();
		s1[i] = s.substr(fi, z - fi);
		fi = z + 1;
		j++;
		if (z == s.size())
			break;
	}
	if (j > 4) {
		cout << "NO";
		return 0;
	}
	for (int i = 0;i < 4;i++) {
		if (s1[i].size() > 3 || s1[i].size() == 0) {
			cout << "NO";
			return 0;
		}
		for (auto c : s1[i]) {
			if (s1[i].size() == 3) {
				if (prof(s1[i]) == 0) {
					cout << "NO";
					return 0;
				}
			}
			else if (c<'0' || c>'9') {
				cout << "NO";
				return 0;
			}
		}
	}
	cout <<"YES";
	cin >> s;
	return 0;
}
