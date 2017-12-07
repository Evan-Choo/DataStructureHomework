#include <iostream>

using namespace std;

class Lifecycle
{
private:
	string name;
public:
	Lifecycle(string name);
	~Lifecycle();
};

Lifecycle::Lifecycle(string name)
{
	this->name = name;
	cout << name << " created." << endl;
}

Lifecycle::~Lifecycle()
{
	cout << name << " destructed." << endl;
}

Lifecycle l1("l1");
Lifecycle l2("l2");

int main()
{
	Lifecycle l3("l3");
	Lifecycle l4("l4");

	return 0;
}