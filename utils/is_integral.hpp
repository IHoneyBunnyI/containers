#ifndef IS_INEGRAL_HPP
#define IS_INEGRAL_HPP

#include "remove_const.hpp"

namespace ft
{

template<class T> struct is_integral_const { static const bool value = false; };

template<> struct is_integral_const<char> { static const bool value = true; };
template<> struct is_integral_const<unsigned char> { static const bool value = true; };
template<> struct is_integral_const<signed char> { static const bool value = true; };

template<> struct is_integral_const<int> { static const bool value = true; };
template<> struct is_integral_const<unsigned int> { static const bool value = true; };

template<> struct is_integral_const<bool> { static const bool value = true; };

template<> struct is_integral_const<long> { static const bool value = true; };
template<> struct is_integral_const<unsigned long> { static const bool value = true; };

template<> struct is_integral_const<long long> { static const bool value = true; };
template<> struct is_integral_const<unsigned long long> { static const bool value = true; };

template<> struct is_integral_const<short int> { static const bool value = true; };
template<> struct is_integral_const<unsigned short int> { static const bool value = true; };

template<class T>
struct is_integral
{
	static const bool value = is_integral_const<typename ft::remove_const<T>::type>::value;
};

}

#endif
