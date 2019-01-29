#ifndef DEF_BIGNUM_HEADER
#define DEF_BIGNUM_HEADER 1

namespace std{
	_BIGNUM::_BIGNUM(){
		this->NUM.push_back(0);
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
	}
	
	ostream& operator << (ostream& OS,const _BIGNUM& __n){
		ostringstream oss;
		string NUM_STR="";
		for(vector<short>::const_iterator i = __n.NUM.begin();i!=__n.NUM.end();i++){
			oss<<*i;
		}
		NUM_STR=oss.str();
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
		return IS;
	}
}

#endif
