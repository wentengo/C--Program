#include<iostream>
using namespace std;
class Hungry
{
public:
	static Hungry* GetInstance()
	{
		return &_instance;
	}
private:
	Hungry(){}
	Hungry(const Hungry&){}
	static Hungry _instance;
};
Hungry Hungry::_instance;
int main()
{
	return 0;
}