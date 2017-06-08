#ifndef MAT_H
#define MAT_H

template<typename T> class mat;

template<typename T> std::ostream& operator<<(std::ostream&, const mat<T>&);
template<typename T> std::istream& operator>>(std::istream&, mat<T>&);

template<typename T> mat<T> operator+(const mat<T>&, const mat<T>&);
template<typename T> mat<T> operator-(const mat<T>&, const mat<T>&);
template<typename T> mat<T> operator*(const mat<T>&, const mat<T>&);

template<typename T> mat<T> operator+(const mat<T>&, const T& constant);
template<typename T> mat<T> operator-(const mat<T>&, const T& constant);
template<typename T> mat<T> operator*(const mat<T>&, const T& constant);
template<typename T> mat<T> operator/(const mat<T>&, const T& constant);
template<typename T> mat<T> operator^(const mat<T>&, const int&&);

template<typename T> mat<T> operator+(const T& constant, const mat<T>&);
template<typename T> mat<T> operator-(const T& constant, const mat<T>&);
template<typename T> mat<T> operator*(const T& constant, const mat<T>&);

template<typename T> mat<T> operator+(const mat<T>&,  T&& constant);
template<typename T> mat<T> operator-(const mat<T>&,  T&& constant);
template<typename T> mat<T> operator*(const mat<T>&,  T&& constant);
template<typename T> mat<T> operator/(const mat<T>&,  T&& constant);

template<typename T> mat<T> operator+( T&& constant, const mat<T>&);
template<typename T> mat<T> operator-( T&& constant, const mat<T>&);
template<typename T> mat<T> operator*( T&& constant, const mat<T>&);

template<typename T> mat<T> operator+( mat<T>&&,  T&& constant);
template<typename T> mat<T> operator-( mat<T>&&,  T&& constant);
template<typename T> mat<T> operator*( mat<T>&&,  T&& constant);
template<typename T> mat<T> operator/( mat<T>&&,  T&& constant);

template<typename T> mat<T> operator+( T&& constant,  mat<T>&&);
template<typename T> mat<T> operator-( T&& constant,  mat<T>&&);
template<typename T> mat<T> operator*( T&& constant,  mat<T>&&);


template<typename T> mat<T> ones (int, int);
template<typename T> mat<T> zeros(int, int);
template<typename T> mat<T> eyes (int);
template<typename T> mat<T> randMat(int , int);


template<typename T>
class mat
{
	friend class vec<T>;

	private:	
		int rows, cols;
		vec<T>* data;
		

	public:
		mat();
		mat(int r = 3);
		mat(int r = 3, int c = 3);
		~mat();
		mat(const mat&);
		mat(mat&&);

		const mat& operator=(const mat&);
		const mat& operator=(mat&&);

		//vec<T> operator()(int r);
		T& operator()(int r, int c);
		const vec<T> operator[](int i)  const;

		const mat<T> resize(int r, int c);



 friend std::ostream& operator<< <T>(std::ostream&, const mat<T>&);
 friend std::istream& operator>> <T>(std::istream&, mat<T>&);

 friend mat<T> operator+ <T>(const mat<T>&, const mat<T>&);
 friend mat<T> operator- <T>(const mat<T>&, const mat<T>&);
 friend mat<T> operator* <T>(const mat<T>&, const mat<T>&);

 friend mat<T> operator+ <T>(const mat<T>&, const T& constant);
 friend mat<T> operator- <T>(const mat<T>&, const T& constant);
 friend mat<T> operator* <T>(const mat<T>&, const T& constant);
 friend mat<T> operator/ <T>(const mat<T>&, const T& constant);
 friend mat<T> operator^ <T>(const mat<T>&, int&&);

 friend mat<T> operator+ <T>(const T& constant, const mat<T>&);
 friend mat<T> operator- <T>(const T& constant, const mat<T>&);
 friend mat<T> operator* <T>(const T& constant, const mat<T>&);

 friend mat<T> operator+ <T>(const mat<T>&, T&& constant);
 friend mat<T> operator- <T>(const mat<T>&, T&& constant);
 friend mat<T> operator* <T>(const mat<T>&, T&& constant);
 friend mat<T> operator/ <T>(const mat<T>&, T&& constant);

 friend mat<T> operator+ <T>(T&& constant, const mat<T>&);
 friend mat<T> operator- <T>(T&& constant, const mat<T>&);
 friend mat<T> operator* <T>(T&& constant, const mat<T>&);

 friend mat<T> operator+ <T>( mat<T>&&, T&& constant);
 friend mat<T> operator- <T>( mat<T>&&, T&& constant);
 friend mat<T> operator* <T>( mat<T>&&, T&& constant);
 friend mat<T> operator/ <T>( mat<T>&&, T&& constant); 
 
 friend mat<T> operator+ <T>( T&& constant, mat<T>&&);
 friend mat<T> operator- <T>( T&& constant, mat<T>&&);
 friend mat<T> operator* <T>( T&& constant, mat<T>&&);


 friend mat<T> randMat(int, int);

};




#endif 