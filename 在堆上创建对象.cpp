#include <iostream>
using namespace std;
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}
	HeapOnly(const HeapOnly&);
};
int main()
{
	HeapOnly* obj2 = HeapOnly::CreateObject();
	return 0;
}