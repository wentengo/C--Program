#include<iostream>
#include<mutex>
using namespace std;
class Lazy
{
public:
	static Lazy* Getinstance(){
		if (nullptr == _instance){
			_mtx.lock();
			if (nullptr == _instance){
				_instance = new Lazy();
			}
			_mtx.unlock();
		}
		return _instance;
	}
	class Clean{
	public:
		~Clean(){
			if (Lazy::_instance)
				delete Lazy::_instance;
		}
	};
	static Clean Getclean;
private:
	Lazy(){};
	Lazy(const Lazy&);
	static Lazy* _instance;
	static mutex _mtx;
};
Lazy* Lazy::_instance = nullptr;
Lazy::Clean GetClean;
mutex Lazy::_mtx;
int main()
{
	return 0;
}