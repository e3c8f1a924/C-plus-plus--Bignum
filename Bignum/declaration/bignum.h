#ifndef DEC_BIGNUM_HEADER
#define DEC_BIGNUM_HEADER

#include <iostream>
#include <sstream>
#include <string>
#include <vector> 

namespace std{
	class _BIGNUM{
		private:
			vector<short> NUM;
			bool MINUS;
			
			inline void clear();
			inline void deleteLeaderZero();
		
		public:
			_BIGNUM();
			~_BIGNUM();
			
			inline _BIGNUM& operator = (_BIGNUM);
			inline _BIGNUM& operator = (bool);
			inline _BIGNUM& operator = (char);
			inline _BIGNUM& operator = (short);
			inline _BIGNUM& operator = (unsigned short);
			inline _BIGNUM& operator = (int);
			inline _BIGNUM& operator = (unsigned int);
			inline _BIGNUM& operator = (long);
			inline _BIGNUM& operator = (unsigned long);
			inline _BIGNUM& operator = (long long);
			inline _BIGNUM& operator = (unsigned long long);
			
			inline const _BIGNUM& operator + ();
			inline const _BIGNUM operator - ();
			
			friend ostream& operator << (ostream&,const _BIGNUM&);
			friend istream& operator >> (istream&,_BIGNUM&);
	};
}

#endif
