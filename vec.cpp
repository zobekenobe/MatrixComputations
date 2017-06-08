#include "vec.h"
#include<iomanip>

template<typename T>
vec<T>::vec():_size{0}, elem{NULL}{}

template<typename T>
vec<T>::vec(int n):_size{n}, elem{new T[n]}
{
	for(int i=0;i<n;i++)
		elem[i] = 0;
}

template<typename T>
vec<T>::vec(const vec<T>& V):_size{V._size}, elem{new T[V._size]}
{
	for(int i=0;i<V._size;i++)
		elem[i] = V.elem[i];
}

template<typename T>
vec<T>::vec(vec<T>&& V):_size{V._size}, elem{new T[V._size]}
{
	for(int i=0;i<V._size;i++)
		elem[i] = std::move(V.elem[i]);
	V._size = 0;
}

template<typename T>
vec<T>::~vec()
{
	_size = 0;
	delete [] elem;
}

//===========================================================OVERLOADING OPERATOR==========================================================

//==============================================================Accessors==================================================================
template<typename T>
T& vec<T>::operator()(int i)
		{
			try
			{
				if(i>=_size)
					throw i;
			}
			catch(int i)
			{
				std::cout<<"index ("<< i<<") is out of bound"<<std::endl;
				exit(1);
			}
			return elem[i];
		}

template<typename T>
const T& vec<T>::operator[](int i) const 
{
	try
	{
		if(i>=_size)
			throw i;
	}
	catch(int i)
	{
		std::cout<<"index ["<< i<<"] is out of bound"<<std::endl;
		exit(1);
	}
	return elem[i];
}

/*template<typename T>
const vec<T> vec<T>::operator[](const vec<int>& v)
{
	vec<T> temp(v.size());
	for(int i=0;i<v.size();i++)
		temp(i) = v[i];
	return temp;
}*/

template<typename T>
void vec<T>::operator++(int)
{
	for(int i=0;i<_size;i++)
		elem[i]++;
}

template<typename T>
void vec<T>::operator++()
{
	for(int i=0;i<_size;i++)
		++elem[i];
}

template<typename T>
void vec<T>::operator--(int)
{
	for(int i=0;i<_size;i++)
		elem[i]--;
}

template<typename T>
void vec<T>::operator--()
{
	for(int i=0;i<_size;i++)
		--elem[i];
}

template<typename T>
const vec<T>& vec<T>::operator=(const vec<T>& rhs)
{
	_size = rhs._size;
	for(int i=0;i<rhs._size;i++)
		elem[i] = rhs.elem[i];
	return *this;
}

template<typename T>
const vec<T>& vec<T>::operator=(vec<T>&& rhs)
{
	_size = std::move(rhs._size);
	for(int i=0;i<rhs._size;i++)
		elem[i] = std::move(rhs.elem[i]);
	return *this;
}

//================================================= Overloading Operator: Friend Functions ================================================
//================================================= Vector -- Vector Operations ===========================================================

template<typename T>
vec<T> operator+(const vec<T>& v1, const vec<T>& v2)
{
	vec<T> v(v1._size);
	for(int i=0;i<v1._size;i++)
		v.elem[i] = v1.elem[i] + v2.elem[i];
	return v; 
}

template<typename T>
vec<T> operator-(const vec<T>& v1, const vec<T>& v2)
{
	vec<T> v(v1._size);
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] - v2[i];
	return v;
}

template<typename T>
vec<T> operator*(const vec<T>& v1, const vec<T>& v2)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i]*v2[i];
	return v;
}

template<typename T>
vec<T> operator/(const vec<T>& v1, const vec<T>& v2)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i]/v2[i];
	return v;
}

//================================================= Vector -- Constant Operations ==========================================================

template<typename T>
vec<T> operator+(const vec<T>& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + constant;
	return v;
}

template<typename T>
vec<T> operator-(const vec<T>& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] - constant;
	return v;
}

template<typename T>
vec<T> operator*(const vec<T>& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v[i]*constant;
	return v;
}

template<typename T>
vec<T> operator/(const vec<T> v1, const T& constant)
{
	if (constant == 0)
	{
		std::cout<<"Divison by zero"<<std::endl;
		return 0;
	}
	else
	{
		vec<T> v(v1.size());
		for(int i=0;i<v1.size();i++)
			v(i) = v1(i)/constant;
		return v;
	}
	
}

template<typename T>
vec<T> operator+(const T& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + constant;
	return v;
}

template<typename T>
vec<T> operator-(const T& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant - v1[i];
	return v;
}

template<typename T>
vec<T> operator*(const T& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] * constant;
	return v;
}

template<typename T>
vec<T> operator /(const T& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
	{
		try
		{
			if(v1.elem[i] != 0)
				v(i) = constant/v1[i];
			else 
				throw(0);
		}
		catch(int)
		{
			std::cout<<"Division by zero element"<<std::endl;
			return 0;
		}
	}
	return v;
}

//================================================= Vector -- Constant Operations: Move Semantics ===========================================

template<typename T>
vec<T> operator+(T&& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant + v1[i];
	return v;
}

template<typename T>
vec<T> operator-(T&& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant - v1[i];
	return v;
}

template<typename T>
vec<T> operator*(T&& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant * v1[i];
	return v1;
}

template<typename T>
vec<T> operator/( T&& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	try{
			for(int i=0;i<v1.size();i++)
			{
				if(v.elem[i] != 0)
					v(i) = constant/v1[i];
				else
					throw(1);
			}
		}
	catch(int)
		{
			std::cout<<"Division by zero element"<<std::endl;
			return 0;
		}
			
	return v;
}

template<typename T>
vec<T> operator+(const vec<T>& v1, T&& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v.size();i++)
		v(i) = constant + v1[i];
	return v;
}

//==================================================== Move Semantics for vectors=========================================================

template<typename T>
vec<T>& operator+(vec<T>&& v1, vec<T>&& v2)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + v2[i];
	return v;
}

template<typename T>
vec<T> operator-(vec<T>&& v1, vec<T>&& v2)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + v2[i];
	return v;
}

template<typename T>
vec<T> operator*(vec<T>&& v1, vec<T>&& v2)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i]*v2[i];
	return v;
}

template<typename T>
vec<T> operator/(vec<T>&& v1, vec<T>&& v2)
{
	vec<T> v(v1.size());
	try
	{
		for(int i=0;i<v1.size();i++)
		{
			if(v2.elem[i] != 0)
				v(i) = v1[i]/v2[i];
			else
				throw(1);
		}
	}
	catch(int)
	{
		std::cout<<"Division by zero when using the / operator between two rvalues"<<std::endl;
		return 0;
	}
	return v;
}

// ----------------------------------------------- Constant and Move Semantics --------------------------------------------------------

template<typename T>
vec<T> operator+(vec<T>&& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + constant;
	return v;
}

template<typename T>
vec<T> operator-(vec<T>&& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] - constant;
	return v;
}

template<typename T>
vec<T> operator*(vec<T>&& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] * constant;
	return v;
}

template<typename T>
vec<T> operator/(vec<T>&& v1, const T& constant)
{
	vec<T> v(v1.size());
	try
	{
		if(constant == 0)
			throw(0);
		else 
			for(int i=0;i<v1.size();i++)
				v(i) = v1[i]/constant;
	}
	catch(int)
	{
		std::cout<<"Division by zero, rvalue / constant faultered"<<std::endl;
		return 0;
	}
	return v;
}

template<typename T>
vec<T> operator+(const T& constant, vec<T>&& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + constant;
	return v;
}

template<typename T>
vec<T> operator-(const T& constant, vec<T>&& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant - v1[i];
	return v;
}

template<typename T>
vec<T> operator*(const T& constant, vec<T>&& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i=v1.size();i++)
		v(i) = v1[i] * constant;
	return v;
}

template<typename T>
vec<T> operator/(const T& constant, vec<T>&& v1)
{
	vec<T> v(v1.size());
	try
	{
		for(int i=0;i<v1.size();i++)
		{
			if(v1.elem[i]!=0)
				v(i) = constant/v1[i];
			else 
				throw(0);
		}
	}
	catch(int)
	{
		std::cout<<"Division by zero, between constant and rvalue vector"<<std::endl;
		return 0;
	}
	return 0;
}

// ------------------------------------------- move semantics for vector and constant -----------------------------------------------------
template<typename T>
vec<T> operator+(vec<T>&& v1, T&& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + constant;
	return v;
}

template<typename T>
vec<T> operator-(vec<T>&& v1, T&& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i]-constant;
	return v; 
}

template<typename T>
vec<T> operator*(vec<T>&& v1, T&& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] * constant;
	return v;
}

template<typename T>
vec<T> operator/(vec<T>&& v1, T&& constant)
{
	vec<T> v(v1.size());
	try
	{
		if(constant == 0)
			throw(0);
		else
			for(int i=0;i<v1.size();i++)
				v(i) = v1[i]/constant;
	}
	catch(int)
	{
		std::cout<<"Division by zero, rvalue vector / rvalue constant"<<std::endl;
		return 0;
	}
	return v;
}

template<typename T>
vec<T> operator+(T&& constant, vec<T>&& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + constant;
	return v;
}

template<typename T>
vec<T> operator-(T&& constant, vec<T>&& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant - v1[i];
	return v;
}

template<typename T>
vec<T> operator*(T&& constant, vec<T>&& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] * constant;
	return v;
}

template<typename T>
	vec<T> operator/(T&& constant, vec<T>&& v1)
{
	vec<T> v(v1.size());
	try
	{
		for(int i=0;i<v1.size();i++)
		{
			if(v1.elem[i] == 0)
				throw(0);
			else
				v(i) = constant/v1[i];
		}
	}
	catch(int)
	{
		std::cout<<"Division by zero, rvalue constant / rvalue vector"<<std::endl;
		return 0;
	}
	return v;
}

//==================================================== Overloading Input and Output Operators ============================================
template<typename T>
std::ostream& operator<< (std::ostream& out, const vec<T>& v)
{
	for(int i=0;i<v._size;i++)
		out<<std::setprecision(7)<<std::setw(4)<<v.elem[i]<<" "	;
	out<<std::endl;
	return out;
}

template<typename T>
std::istream& operator >>(std::istream& in, vec<T>& v)
{
	for(int i=0;i<v._size;i++)
		in>>v.elem[i];
	return in;
}

//========================================================= Useful functions ===============================================================

template<typename T>
void vec<T>::linspace(T&& start, T&& end, int n)
{
	// Create a range of numbers between the start point and end point divided in n parts and hence n+1 points
	_size = n+1;
	elem = new T[n+1];
	T dx = (end - start)/double(n);
	elem[0] = start;
	for(int i=1;i<_size;i++)
		elem[i] = elem[i-1] + dx;
}

template<typename T>
void vec<T>::linspace(T&& start, T&& end, T&& dx)
{
	// Create a range of numbers between the start point and end point divided in n parts and hence n+1 points
	_size = int((end - start)/(dx)) + 1;
	elem = new T[_size];
	elem[0] = start;
	for(int i=1;i<_size;i++)
		elem[i] = elem[i-1] + dx;
}

template<typename T>
vec<T> vec<T>::resize(int start, int end)
{
	try
	{
		if((end - start)<0)
		{
			vec<T> v(end - start);
			for(int i=start; i<=end;i++)
				v(i) = elem[i];
			return v;
		}
		else
			throw(0);
	}	
	catch(int)
	{
		std::cout<<"Incorrect Negative Indices error in the resize function"<<std::endl;
		return 0;
	}
}