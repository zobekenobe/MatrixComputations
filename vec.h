#ifndef _vec_h
#define _vec_h

#include<iostream>

template<typename> class vec;

template<typename T>  vec<T> operator+(const vec<T>& , const vec<T>&);
template<typename T>  vec<T> operator-(const vec<T>& , const vec<T>&);
template<typename T>  vec<T> operator*(const vec<T>& , const vec<T>&);

template<typename T>  vec<T> operator+(const vec<T>&, const T&);
template<typename T>  vec<T> operator-(const vec<T>&, const T&);
template<typename T>  vec<T> operator*(const vec<T>&, const T&);
template<typename T>  vec<T> operator/(const vec<T>&, const T&);

template<typename T>  vec<T> operator+(const T&, const vec<T>&);
template<typename T>  vec<T> operator-(const T&, const vec<T>&);
template<typename T>  vec<T> operator*(const T&, const vec<T>&);
template<typename T>  vec<T> operator/(const T&, const vec<T>&);

template<typename T>  vec<T> operator+(const vec<T>&, T&&);
template<typename T>  vec<T> operator-(const vec<T>&, T&&);
template<typename T>  vec<T> operator*(const vec<T>&, T&&);
template<typename T>  vec<T> operator/(const vec<T>&, T&&);

template<typename T>  vec<T> operator+(T&&, const vec<T>&);
template<typename T>  vec<T> operator-(T&&, const vec<T>&);
template<typename T>  vec<T> operator*(T&&, const vec<T>&);
template<typename T>  vec<T> operator/(T&&, const vec<T>&);

template<typename T>  vec<T> operator+(vec<T>&&, vec<T>&&);
template<typename T>  vec<T> operator-(vec<T>&&, vec<T>&&);
template<typename T>  vec<T> operator*(vec<T>&&, vec<T>&&);
template<typename T>  vec<T> operator/(vec<T>&&, vec<T>&&);

template<typename T>  vec<T> operator+(vec<T>&&, const T&);
template<typename T>  vec<T> operator-(vec<T>&&, const T&);
template<typename T>  vec<T> operator*(vec<T>&&, const T&);
template<typename T>  vec<T> operator/(vec<T>&&, const T&);

template<typename T>  vec<T> operator+(const T&, vec<T>&&);
template<typename T>  vec<T> operator-(const T&, vec<T>&&);
template<typename T>  vec<T> operator*(const T&, vec<T>&&);
template<typename T>  vec<T> operator/(const T&, vec<T>&&);

template<typename T>  vec<T> operator+(vec<T>&&, T&&);
template<typename T>  vec<T> operator-(vec<T>&&, T&&);
template<typename T>  vec<T> operator*(vec<T>&&, T&&);
template<typename T>  vec<T> operator/(vec<T>&&, T&&);

template<typename T>  vec<T> operator+(T&&, vec<T>&&);
template<typename T>  vec<T> operator-(T&&, vec<T>&&);
template<typename T>  vec<T> operator*(T&&, vec<T>&&);
template<typename T>  vec<T> operator/(T&&, vec<T>&&);


template<typename T> std::ostream& operator<<(std::ostream&, const vec<T>&);
template<typename T> std::istream& operator>>(std::istream&, const vec<T>&);


template<typename T>
class vec
{
	private:
		int _size;
		T* elem;

	public:
		vec();
		vec(int n);
		vec(const vec<T>& );
		vec(vec<T>&&);
		~vec();

		// Overloading the operators
		const int size()const {return _size;}
		T& operator()(int i);
		const T& operator[](int i) const;
		//const vec<T> operator[](const vec<int>&);	

		const vec<T>& operator=(const vec<T>&);
		const vec<T>& operator=(vec<T>&&);

		void operator++(int);
		void operator++();

		void operator--(int);
		void operator--();

		// Friend Overloaded operators
		friend vec<T> operator+ <T>(const vec<T>&, const vec<T>& );
		friend vec<T> operator- <T>(const vec<T>&, const vec<T>& );
		friend vec<T> operator* <T>(const vec<T>&, const vec<T>& );

		friend vec<T> operator+ <T>(const vec<T>&, const T&);
		friend vec<T> operator- <T>(const vec<T>&, const T&);
		friend vec<T> operator* <T>(const vec<T>&, const T&);
		friend vec<T> operator/ <T>(const vec<T>&, const T&);

		friend vec<T> operator+ <T>(const T&, const vec<T>&);
		friend vec<T> operator- <T>(const T&, const vec<T>&);
		friend vec<T> operator* <T>(const T&, const vec<T>&);
		friend vec<T> operator/ <T>(const T&, const vec<T>&);

		friend vec<T> operator+ <T>(const vec<T>&, T&&);
		friend vec<T> operator- <T>(const vec<T>&, T&&);
		friend vec<T> operator* <T>(const vec<T>&, T&&);
		friend vec<T> operator/ <T>(const vec<T>&, T&&);

		friend vec<T> operator+ <T>(T&&, const vec<T>&);
		friend vec<T> operator- <T>(T&&, const vec<T>&);
		friend vec<T> operator* <T>(T&&, const vec<T>&);
		friend vec<T> operator/ <T>(T&&, const vec<T>&);

		friend vec<T> operator+ <T>(vec<T>&&, const T&);
		friend vec<T> operator- <T>(vec<T>&&, const T&);
		friend vec<T> operator* <T>(vec<T>&&, const T&);
		friend vec<T> operator/ <T>(vec<T>&&, const T&);

		friend vec<T> operator+ <T>(const T&, vec<T>&&);
		friend vec<T> operator- <T>(const T&, vec<T>&&);
		friend vec<T> operator* <T>(const T&, vec<T>&&);
		friend vec<T> operator/ <T>(const T&, vec<T>&&);

		friend vec<T> operator+ <T>(vec<T>&&, T&&);
		friend vec<T> operator- <T>(vec<T>&&, T&&);
		friend vec<T> operator* <T>(vec<T>&&, T&&);
		friend vec<T> operator/ <T>(vec<T>&&, T&&);

		friend vec<T> operator+ <T>(T&&, vec<T>&&);
		friend vec<T> operator- <T>(T&&, vec<T>&&);
		friend vec<T> operator* <T>(T&&, vec<T>&&);
		friend vec<T> operator/ <T>(T&&, vec<T>&&);



		friend std::ostream& operator<< <T>(std::ostream&, const vec<T>&);
		friend std::istream& operator>> <T>(std::istream&, const vec<T>&);

		// useful functions 
		void linspace(T&& start, T&& end, int n = 100);
		void linspace(T&& start, T&& end, T&& dx);
		vec resize(int startindex, int endindex);

};




#endif