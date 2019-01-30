#ifndef DEF_BIGNUM_HEADER
#define DEF_BIGNUM_HEADER 1

namespace std{
	_BIGNUM::_BIGNUM(){
		this->NUM.push_back(0);
		this->MINUS=0;
	}
	_BIGNUM::~_BIGNUM(){
		
	}
	 
	void _BIGNUM::deleteLeaderZero(){
		for(vector<short>::iterator i=this->NUM.end()-1;i!=this->NUM.begin();i--){
			if(*i==0){
				vector<short>::iterator() = this->NUM.erase(i);
			}else{
				break;
			}
		}
	}
	
	void _BIGNUM::clear(){
		vector<short>().swap(this->NUM);
		this->MINUS=0;
	}
	//Operator =
	inline _BIGNUM& _BIGNUM::operator = (_BIGNUM __n){
		this->MINUS = __n.MINUS;
		vector<short> __n_T(__n.NUM);
		this->NUM.swap(__n_T);
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (bool __n){
		this->operator = ((int)__n);
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (char __n){
		this->operator = ((int)__n);
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (short __n){
		short __n_T=__n;
		this->clear();
		if(__n_T<0){
			this->MINUS=1;
			__n_T=-__n_T;
		}
		if(__n_T==0){
			this->NUM.push_back(0);
		}
		while(__n_T>0){
			this->NUM.push_back(__n_T%10);
			__n_T/=10;
		}
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (unsigned short __n){
		unsigned short __n_T=__n;
		this->clear();
		if(__n_T==0){
			this->NUM.push_back(0);
		}
		while(__n_T>0){
			this->NUM.push_back(__n_T%10);
			__n_T/=10;
		}
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (int __n){
		int __n_T=__n;
		this->clear();
		if(__n_T<0){
			this->MINUS=1;
			__n_T=-__n_T;
		}
		if(__n_T==0){
			this->NUM.push_back(0);
		}
		while(__n_T>0){
			this->NUM.push_back(__n_T%10);
			__n_T/=10;
		}
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (unsigned int __n){
		unsigned int __n_T=__n;
		this->clear();
		if(__n_T==0){
			this->NUM.push_back(0);
		}
		while(__n_T>0){
			this->NUM.push_back(__n_T%10);
			__n_T/=10;
		}
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (long __n){
		long __n_T=__n;
		this->clear();
		if(__n_T<0){
			this->MINUS=1;
			__n_T=-__n_T;
		}
		if(__n_T==0){
			this->NUM.push_back(0);
		}
		while(__n_T>0){
			this->NUM.push_back(__n_T%10);
			__n_T/=10;
		}
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (unsigned long __n){
		unsigned long __n_T=__n;
		this->clear();
		if(__n_T==0){
			this->NUM.push_back(0);
		}
		while(__n_T>0){
			this->NUM.push_back(__n_T%10);
			__n_T/=10;
		}
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (long long __n){
		long long __n_T=__n;
		this->clear();
		if(__n_T<0){
			this->MINUS=1;
			__n_T=-__n_T;
		}
		if(__n_T==0){
			this->NUM.push_back(0);
		}
		while(__n_T>0){
			this->NUM.push_back(__n_T%10);
			__n_T/=10;
		}
		return *this;
	}
	
	inline _BIGNUM& _BIGNUM::operator = (unsigned long long __n){
		unsigned long long __n_T=__n;
		this->clear();
		if(__n_T==0){
			this->NUM.push_back(0);
		}
		while(__n_T>0){
			this->NUM.push_back(__n_T%10);
			__n_T/=10;
		}
		return *this;
	}
	//Operator +
	inline const _BIGNUM& _BIGNUM::operator + (){
		return *this;
	}
	//Operator -
	inline const _BIGNUM _BIGNUM::operator - (){
		_BIGNUM __n_T=(*this);
		__n_T.MINUS=!__n_T.MINUS;
		return __n_T;
	}
	//Standard Input/Output
	ostream& operator << (ostream& OS,const _BIGNUM& __n){
		ostringstream OSS;
		string NUM_STR="";
		if(__n.MINUS==1)OS<<'-';
		for(vector<short>::const_iterator i=__n.NUM.begin();i!=__n.NUM.end();i++){
			OSS<<*i;
		}
		NUM_STR=OSS.str();
		for(int i=NUM_STR.length()-1;i>=0;i--){
			OS<<NUM_STR[i];
		}
		return OS;
	}
	istream& operator >> (istream& IS,_BIGNUM& __n){
		__n.clear();
		char NUM_C;
		string NUM_STR;
		IS.get(NUM_C);
		while(NUM_C<'0'||NUM_C>'9'){
			if(NUM_C=='-')__n.MINUS=!__n.MINUS;
			IS.get(NUM_C);
		}
		while(NUM_C>='0'&&NUM_C<='9'){
			NUM_STR.push_back(((char)NUM_C-'0'));
			IS.get(NUM_C);
		}
		for(int i=NUM_STR.length()-1;i>=0;i--){
			__n.NUM.push_back((char)NUM_STR[i]);
		}
		__n.deleteLeaderZero();
		return IS;
	}
}

#endif
