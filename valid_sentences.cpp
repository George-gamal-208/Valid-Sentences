#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
vector<string>v;
void load() {
	string line = "";
	ifstream load_data;
	load_data.open("dictionary.txt");
	if (!load_data) {
		cout << "error";
	}
	else {
		while (!load_data.eof()) {
			getline(load_data, line);
			v.push_back(line);
		}
		load_data.close();
	}
}
bool isword(string s) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == s) {
			return true;
		}
	}
	return false;
}
void valid_sentence(string str, string word, string result) {
	string s = "";
	if (str.size() == 0) {
		if (isword(word)) {
			cout << result << endl;
			return;
		}
	}
	for (int i = 1; i <= str.size(); i++) {
		s += str[i - 1];
		if (isword(s)) {
			word = s;
			valid_sentence(str.substr(i, str.size() - i), word, result + word + " ");
		}
	}
}
int main() {
	vector<string>v1;
	string word = "";
	string res = "";
	string str = "IWearmyshoes";
	load();
	valid_sentence(str, word, res);
}