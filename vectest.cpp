#include "vec.cpp"
#include "mat.cpp"


template<typename T>
void vec_swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T, template<typename> typename CONT>
void bubbleSort(CONT<T>& v)
{
	for(int i=0;i<v.size()-1;i++)
		for(int j=0;j<v.size()-1;j++)
			if(v[j]<v[j+1])
				vec_swap(v(j), v(j+1));
}

template<typename T, template<typename> typename CONT>
void selectionSort(CONT<T>& v)
{

}

int main()
{
	vec<double> v(20);
	double D = 2.0;
	for(int i=0;i<v.size();i++)
		v(i) = i;
	std::cout<<(v+1.0);
	v++;
	v = v+2.0;
	std::cout<<v;
	vec<int> a(4);
	//bubbleSort(v);
	std::cout<<v<<std::endl;

	v.linspace(0., 1., 0.1);
	std::cout<<v<<std::endl;

	mat<double> m(2,3);	
	std::cout<<m + 5.0<<std::endl;
	mat<double> n(m);
	std::cout<<n;
	m(0,1) = 10;
	std::cout<<n<<std::endl;
	n = m.resize(6,1);

	//std::cout<<"this is summation "<<std::endl<<m*m<<std::endl;
	std::cout<<n;
}