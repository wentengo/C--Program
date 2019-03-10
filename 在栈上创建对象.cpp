#include <iostream>
using namespace std;
class StackOnly
{
public:
	StackOnly(){}
	~StackOnly(){}
private:
	void* operator new(size_t);
	void operator delete(void*);
};
int main()
{
	StackOnly obj1;
	return 0;
}