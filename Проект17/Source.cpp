#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string &tolowerString(string &s)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}


class lessZeroFive {
public:
	bool operator()(double v) {
		return(sin(v) < 0.5);
	}
};

void less05(double v)
{
	if (sin(v) < 0.5)
		cout << v << endl;
}

void print(double d) {
	cout << d << endl;
}

int main() {
	short a;
	cout << "which task?";
	cin >> a;

	switch (a) {
	case 1:
	{
		ifstream in_file;

		string file_name;
		string word;
		deque<string> words;
		set<string> orderedWords;

		cout << "enter file name" << endl;
		cin >> file_name;

		in_file.open(file_name);
		if (!in_file)
		{
			cerr << "error\n";
		}
		else
		{
			while (!in_file.eof()) {
				in_file >> word;
				words.push_back(word);
			}
		}


		for (auto it = words.begin(); it != words.end(); it++)
		{
			orderedWords.insert(tolowerString(*it));
		}

		for (auto it = words.begin(); it != words.end(); it++)
		{
			cout << *it << endl;
		}
	}break;

	case 4:
	{
		vector <double> v;
		v.push_back(60);
		v.push_back(45);
		v.push_back(90);
		for_each(v.begin(), v.end(), less05);
	}break;

	case 5:
	{
		vector <double> v;
		v.push_back(60);
		v.push_back(45);
		v.push_back(90);

		auto itr = v.erase(remove_if(v.begin(), v.end(), lessZeroFive()), v.end());
		for_each(v.begin(), v.end(), print);
	}
	}
	system("pause");
	return 0;
}