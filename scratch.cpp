#include <iostream>

using namespace std;

struct Par {
	virtual void operator()() {
		cout << "par" << endl;
	}
};

struct Chi : public Par {
	void operator()() override;
};

void Chi::operator()() {
	cout << "chi" << endl;
}

void outer(Par* inner) {
	(*inner)();
}

int main() {
	Par p;
	Chi c;
	outer(&p);
	outer(&c);
	return 0;
}
