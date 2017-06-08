#include "mat.h"

template<typename T>
mat<T>::mat():rows{0}, cols{0}, data{new vec<T>()}{}

template<typename T>
mat<T>::mat(int r, int c):rows{r}, cols{c}, data{new vec<T>(r*c)}{}

template<typename T>
mat<T>::mat(int r):rows{r}, cols{r}, data{new vec<T>(r*r)}{}

template<typename T>
mat<T>::~mat()
{
	delete data;
}

template<typename T>
mat<T>::mat(const mat& m):rows{m.rows}, cols{m.cols}, data{new vec<T>(m.rows*m.cols)}
{
	*data = *(m.data);
}

template<typename T>
mat<T>::mat(mat&& m):rows{std::move(m.rows)}, cols{std::move(m.cols)}, data{new vec<T>(m.rows*m.cols)}
{
	*data = std::move(*(m.data));
}

template<typename T>
const mat<T>& mat<T>::operator=(const mat<T>& m)
{
	rows = m.rows; cols = m.cols;
	*data = *(m.data);
	return *this;
}

// =============================================================== Operator Overloading: Accessing Operators==================================
template<typename T>
T& mat<T>::operator()(int r, int c)
{
	return data->operator()(r*cols + c);
}

template<typename T>
const vec<T> mat<T>::operator[](int r) const
{
	vec<T> v(cols);
	for(int i=0;i<cols;i++)
		v(i) = data->operator()(r*cols + i);
	return v;
}

template<typename T>
const mat<T> mat<T>::resize(int r, int c)
{
	mat<T> temp(*this);
	try
	{
		if(rows*cols != r*c)
			throw(0);
		else
			{temp.rows = r; temp.cols = c;return temp;}

	}
	catch(int)
	{
		std::cout<<"Index problem with the Resize function"<<std::endl;
		return temp;
	}
}

// ======================================================= Operator Overloading: Arithmetic Functions=========================================
template<typename T>
mat<T> operator+(const mat<T>& m1, const mat<T>& m2)
{
	mat<T> temp(m1.rows, m1.cols);
	*(temp.data) = *(m1.data) + *(m2.data);
	return temp;
}

template<typename T>
mat<T> operator-(const mat<T>& m1, const mat<T>& m2)
{
	mat<T> temp(m1.rows, m1.cols);
	*(temp.data) = *(m1.data)-*(m2.data);
	return temp;
}

template<typename T>
mat<T> operator*(const mat<T>& m1, const mat<T>& m2)
{
	mat<T> temp(m1.rows, m1.cols);
	*(temp.data) = (*(m1.data))*(*(m2.data));
	return temp;
}

// ======================================================= Operator Overloading: Matrix Object and constant===================================
template<typename T>
mat<T> operator+(const mat<T>& m, const T& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) + constant;
	return temp;
}

template<typename T>
mat<T> operator-(const mat<T>& m, const T& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) - constant;
	return temp;
}

template<typename T>
mat<T> operator*(const mat<T>& m, const T& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) * constant;
	return temp;
}

template<typename T>
mat<T> operator/(const mat<T>& m, const T& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data)/constant;
	return temp;
}

// ======================================================= Operator Overloading:Constant and Matrix Object ===================================
template<typename T>
mat<T> operator+(const T& constant, const mat<T>& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = constant + *(m.data);
	return temp;
}

template<typename T>
mat<T> operator-(const T& constant, const mat<T>& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = constant - *(m.data);
	return temp;
}

template<typename T>
mat<T> operator*(const T& constant, const mat<T>& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = constant * (*(m.data));
}

// ============================================== Operator Overloading:Constant and Matrix Object ============================================
template<typename T>
mat<T> operator+(const mat<T>& m, T&& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) + constant;
	return temp;
}

template<typename T>
mat<T> operator-(const mat<T>& m, T&& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) - constant;
	return temp;
}

template<typename T>
mat<T> operator*(const mat<T>& m, T&& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) * constant;
	return temp;
}

template<typename T>
mat<T> operator/(const mat<T>& m, T&& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data)/constant;
	return temp;
}


template<typename T>
mat<T> operator+(T&& constant, const mat<T>& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) + constant;
	return temp;
}

template<typename T>
mat<T> operator-(T&& constant, const mat<T>& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = constant - *(m.data);
	return temp; 
}

template<typename T>
mat<T> operator*(T&& constant, const mat<T>& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = constant * *(m.data);
	return temp;
}

template<typename T>
mat<T> operator+(mat<T>&& m, T&& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) + constant;
	return temp;
}

template<typename T>
mat<T> operator-(mat<T>&& m, T&& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) - constant;
	return temp;
}

template<typename T>
mat<T> operator*(mat<T>&& m, T&& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) * constant;
	return temp;
}

template<typename T>
mat<T> operator/(mat<T>&& m, T&& constant)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = *(m.data) / constant;
	return temp;
}

template<typename T>
mat<T> operator+(T&& constant, mat<T>&& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = constant + *(m.data);
	return temp;
}

template<typename T>
mat<T> operator-(T&& constant, mat<T>&& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = constant  - *(m.data);
	return temp; 
}

template<typename T>
mat<T> operator*(T&& constant, mat<T>&& m)
{
	mat<T> temp(m.rows, m.cols);
	*(temp.data) = constant * (*(m.data));
	return temp;
}

// ======================================================================= Input Output Operators ============================================
template<typename T>
std::ostream& operator<< (std::ostream& out, const mat<T>& m)
{
	for(int i=0;i<m.rows;i++)
	{	
		for(int j=0;j<m.cols;j++)
		{
			out<<m.data->operator[](i*m.cols + j)<<" ";
		}
		out<<std::endl;
	}
	out<<std::endl;
	return out;
}

template<typename T>
std::istream& operator>> (std::istream& in, mat<T>& m)
{
	for(int i=0;i<m.rows;i++)
		for(int j=0;j<m.cols;j++)
			in>>m.data->operator()(i*m.cols + j);
	return in;
}