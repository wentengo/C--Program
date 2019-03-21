#include <iostream>
using namespace std;

struct _true_type{}; //内置类型
struct _false_type{};//自定义类型

template <class T>
struct _type_traits{
	typedef _false_type is_POD_type;
};
template <>
struct _type_traits<int>{
	typedef _true_type is_POD_type;
};
template <>
struct _type_traits<unsigned int>{
	typedef _true_type is_POD_type;
};
template <>
struct _type_traits<char>{
	typedef _true_type is_POD_type;
};
template <>
struct _type_traits<signed char>{
	typedef _true_type is_POD_type;
};
template <>
struct _type_traits<unsigned char>{
	typedef _true_type is_POD_type;
};
template <>
struct _type_traits<float>{
	typedef _true_type is_POD_type;
};
template <>
struct _type_traits<double>{
	typedef _true_type is_POD_type;
};

template <class T>
void _copy(T* dst, T*src, size_t n, _true_type){
	memcpy(dst, src, n*sizeof(T));
}
template <class T>
void _copy(T* dst, T*src, size_t n, _false_type){
	for (size_t i = 0; i < n; ++i){
		dst[i] = src[i];
	}
}

template <class T>
void Copy(T* dst, T* src, size_t n){
	_copy(dst, src, n, _type_traits<T>::is_POD_type());
}

int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };   
	int a2[10];   
	Copy(a2, a1, 10);  

	string s1[] = { "1111", "2222", "3333", "4444" };  
	string s2[4]; 
	Copy(s2, s1, 4);
	return 0;
}