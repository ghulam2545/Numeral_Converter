              ////////////////////////////////////////////////////////////////
              //            	   NUMERAL CONVERSION						//
              //															//
              //	decimal		to 		decimal - binary - octal - hexa		//
              //															//	
              //	binary		to 		decimal - binary - octal - hexa		//
              //															//
			  //	octal		to 		decimal - binary - octal - hexa 	//
              //															//
              //	hexa		to 		decimal - binary - octal - hexa		//
              //															//
              ////////////////////////////////////////////////////////////////
              


#include <iostream>
#include <cmath>
#include <cstring>
#include <deque>

char _point = '.';

////////////////////////////////////////////////////////
// Validation check methods
bool _isWhole(std::string& input_data);

bool valid_long(std::string& input_data,char leftOp, char rightOp);
bool valid_double(std::string& input_data,char leftOp, char rightOp);

bool valid_hexa_long(std::string& input_data);
bool valid_hexa_double(std::string& input_data);
////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
// Conversion methods

std::string deci_base_long(std::string& input_data, int base);
std::string deci_base_double(std::string& input_data, int base, int fracDigits);
std::string deci_base_hexa_long(std::string& input_data);
std::string deci_base_hexa_double(std::string& input_data);


std::string binary_base_long(std::string& input_data, int base);
std::string binary_base_double(std::string& input_data, int base, int fracDigits);
std::string binary_base_hexa_long(std::string& input_data);
std::string binary_base_hexa_double(std::string& input_data);


std::string octal_base_long(std::string& input_data, int base);
std::string octal_base_double(std::string& input_data, int base, int fracDigits);
std::string octal_base_hexa_long(std::string& input_data);
std::string octal_base_hexa_double(std::string& input_data);


std::string hexa_base_long(std::string& input_data, int base);
std::string hexa_base_double(std::string& input_data, int base, int fracDigits);
std::string hexa_base_hexa_long(std::string& input_data);
std::string hexa_base_hexa_double(std::string& input_data);
////////////////////////////////////////////////////////


int main() {
//	std::string num = "-23.2";
//	char left = '0', right = '9';
//	if(_isWhole(num)) {
//		if(valid_long(num, left, right)) {
//			int base = 2;
//			std::cout<<deci_base_long(num, base);
//		}
//		else std::cout<<"jhjfgjd";
//	}  
//	else {
//		if(valid_double(num, left, right)) {
//			int base = 10;
//			int fg = 8;
//			std::cout<<deci_base_double(num, base, fg);
//		}
//		else std::cout<<"jhjfgjd";
//	};
	
	return 0;
}

bool _isWhole(std::string& input_data) {
	bool Whole = true;
	for(int i=0; i<input_data.size(); i++) {
		if(input_data[i] == '.') Whole = false;
	}
	return Whole;
}
bool valid_long(std::string& input_data,char leftOp, char rightOp) {
	bool ans = true;
	int i = 0;
	if(input_data[0] == '-') i = 1;
	for(i; i<input_data.size(); i++) {
		if(!(input_data[i] >= leftOp && input_data[i] <= rightOp)) ans = false;
	}
	return ans;
}
bool valid_double(std::string& input_data,char leftOp, char rightOp) {
	bool ans = true;
	int point = 0;
	int i = 0;
	if(input_data[0] == '-') i = 1;
	for(i; i<input_data.size(); i++) {
		if(!(input_data[i] >= leftOp && input_data[i] <= rightOp && point <= 1)) {
			if(input_data[i] == '.') point++;
			else ans = false;
		}	
	}
	return ans;
}
bool valid_hexa_long(std::string& input_data) {
	bool ans = true;
	int i = 0;
	if(input_data[0] == '-') i = 1;
	for(i; i<input_data.size(); i++) {
		if(!((input_data[i] >= '0' && input_data[i] <= '9') || (toupper(input_data[i]) >= 'A' && toupper(input_data[i]) <= 'F'))) ans = false;
	}
	return ans;
}
bool valid_hexa_double(std::string& input_data) {
	bool ans = true;
	int point = 0;
	int i = 0;
	if(input_data[0] == '-') i = 1;
	for(i; i<input_data.size(); i++) {
		if(!((input_data[i] >= '0' && input_data[i] <= '9' && point <= 1) || (toupper(input_data[i]) >= 'A' && toupper(input_data[i]) <= 'F' && point <= 1))) {
			if(input_data[i] == '.') point++;
			else ans = false;
		}	
	}
	return ans;
}
std::string deci_base_long(std::string& input_data, int _base) {
	long long _input_data = stoll(input_data);
	bool positive = true;
	if(_input_data < 0) positive = false;
	std::deque<int> _ans;
	std::string ans = "";
	if(abs(_input_data) == 0) return "0";
	while((abs(_input_data))) {
		_ans.push_front(abs(_input_data) % _base);
		_input_data /= _base;
	}
	for(int i=0; i<_ans.size(); i++) {
		ans += std::to_string(_ans[i]);
	}
	if (positive) return ans;
	else  return ("-"+ans);
}
std::string deci_base_double(std::string& input_data, int base, int fracDigits) {
	long double x = stold(input_data);
	std::string result;
	bool neg = ( x < 0 );   if ( neg ) x = -x;
	x += pow(base, -fracDigits) / 2.0;
	long long whole = x;
    long double fraction = x - whole;
    if ( whole == 0 ) result = "0";
    while ( whole ) {
       result = (char)( whole % base + '0' ) + result;
       whole /= base;
    } 
    result += _point;
    long double value = 1.0;
   	for (long long int i = 1; i <= fracDigits; i++ ) {
       value /= base;
       long long num = fraction / value;
       result += (char)( num + '0' );
       fraction -= num * value;
    }
    if ( neg ) result = '-' + result;
   	return result;
}

// Complete.........
std::string deci_base_hexa_long(std::string& input_data) {
	
}
std::string deci_base_hexa_double(std::string& input_data) {
	
}


// .............
