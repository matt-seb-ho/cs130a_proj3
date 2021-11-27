#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s1 = "PA3_Large_";
string s2 = "PA3_Small_";
string inp = "_input.txt";
string out = "_output.txt";

int main() {
	string num;
	for (int i = 1; i < 4; i++) {
		num = to_string(i);
		rename((s1 + num + inp).c_str(), ("l" + num + "i.txt").c_str());
		rename((s1 + num + out).c_str(), ("l" + num + "o.txt").c_str());
	}
	for (int i = 1; i < 5; i++) {
		num = to_string(i);
		rename((s2 + num + inp).c_str(), ("s" + num + "i.txt").c_str());
		rename((s2 + num + out).c_str(), ("s" + num + "o.txt").c_str());
	}
	return 0;
}
