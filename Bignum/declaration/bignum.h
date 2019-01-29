#ifndef DEC_BIGNUM_HEADER
#define DEC_BIGNUM_HEADER 1

#include <iostream>
#include <sstream>
#include <string>
#include <vector> 

namespace std{
	class _BIGNUM{
		private:
			vector<short> NUM;
			bool MINUS;
		
		public:
			_BIGNUM();
			~_BIGNUM();
			
			inline void clear();
			
			inline _BIGNUM operator = (_BIGNUM);
			inline _BIGNUM operator = (char);
			inline _BIGNUM operator = (int);
			inline _BIGNUM operator = (long);
			inline _BIGNUM operator = (long long);
			
			friend ostream& operator << (ostream&,const _BIGNUM&);
			friend istream& operator >> (istream&,_BIGNUM&);
	};
}

#endif
