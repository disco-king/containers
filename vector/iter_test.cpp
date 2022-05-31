#include <vector>
#include "vector.hpp"
#include <iostream>
   
class B {
public:
    char *l;
    int i;
    B():l(0), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = 0;
    };
};

class A : public B {
public:
    A():B(){}
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = 0;
    }

};

class Test
{
public:
    Test(): ap(0){}

	template <typename T, typename InputIt>
    void secondary(T *arr, InputIt ex)
	{
        alloc.construct(arr, *ex);
	}

    template <typename InputIt>
    void insert(int size, InputIt ex)
    {
        A*ptr = alloc.allocate(size);
		secondary(ptr, ex);
		ap = ptr;
    }

    A *ap;
    std::allocator<A> alloc;
};

int main()
{
    B* k2(new B(3));
    B* k3(new B(4));
    B* k4(new B(-1));
    std::vector<B*> v1;
	v1.push_back(k2);
	v1.push_back(k3);
	v1.push_back(k4);

	ft::vector<A> vec;
	try
	{
		// ft::vector<A> vec(v1.begin(), v1.end());
		vec.assign(v1.begin(), v1.end());
	}
	catch(...)
	{
		std::cerr << "caught" << '\n';
		std::cout << "size " << vec.size()
		<< " capacity " << vec.capacity() << '\n';
	}
	
} 

