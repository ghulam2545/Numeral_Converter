              ////////////////////////////////////////////////////////////////////////////////////
              //            	   NUMERAL CONVERSION						//
              //										//
              //	decimal		to 		decimal - binary - octal - hexa		//
              //										//	
              //	binary		to 		decimal - binary - octal - hexa		//
              //										//
	      //	octal		to 		decimal - binary - octal - hexa 	//
              //										//
              //	hexa		to 		decimal - binary - octal - hexa		//
              //										//
              ////////////////////////////////////////////////////////////////////////////////////
              


#include <iostream>
#include <cmath>
#include <cstring>
#include <deque>



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


std::string binary_base_long(std::string& input_data, int base);
std::string binary_base_double(std::string& input_data, int base);


std::string octal_base_long(std::string& input_data, int base);
std::string octal_base_double(std::string& input_data, int base, int fracDigits);


std::string hexa_base_long(std::string& input_data, int base);
std::string hexa_base_double(std::string& input_data, int base, int fracDigits);
////////////////////////////////////////////////////////


int main() {
	std::string num = "12.543212";
	if(_isWhole(num)) {
		if(valid_hexa_long(num)) {
			int base = 2;
			std::cout<<deci_base_long(num, base);
		}
		else std::cout<<"jhjfgjd";
	}  
	else {
		char left = '0', right = '9';
		if(valid_double(num, left, right)) {
			int base = 2;
			int fg = 8;
			std::cout<<deci_base_double(num, base, fg);
			std::cout<<"end";
		}
		else std::cout<<"jhjfgjd";
	};
	
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
	if(_base == 16) {
		while((abs(_input_data))) {
			int remainder = abs(_input_data) % _base;
			if(remainder == 10) _ans.push_front('A');
			else if(remainder == 11) _ans.push_front('B');
			else if(remainder == 12) _ans.push_front('C');
			else if(remainder == 13) _ans.push_front('D');
			else if(remainder == 14) _ans.push_front('E');
			else if(remainder == 15) _ans.push_front('F');
			else {
				_ans.push_front(remainder);
			}
			_input_data /= _base;
		}
	}
	else {
		while((abs(_input_data))) {
			_ans.push_front(abs(_input_data) % _base);
			_input_data /= _base;
		}
	}
	for(int i=0; i<_ans.size(); i++) {
		if(_ans[i] >= 10) {
			char value = _ans[i];
			ans += value;	
		}
		else {
			ans += std::to_string(_ans[i]);
		}	
	}
	if (positive) return ans;
	else  return ("-"+ans);
}
std::string deci_base_double(std::string& input_data, int base, int fracDigits) {
	long double _input_data = stold(input_data);
	std::cout<<"i am  "<<_input_data<<"\n\n\n";
	bool positive = true;
	if(_input_data < 0) positive = false;
	long long whole = abs(_input_data);
	std::string whole_ = std::to_string(whole);
	double fractional = 0.0;
	if(positive) fractional = _input_data - whole;
	else fractional = (-1 * _input_data) - whole;
	
	std::string ans1 = deci_base_long(whole_, base);
	std::string ans2 = "";
	while(fracDigits--) {
		if(base == 16) {
			fractional = fractional * base;
			if(fractional < 0) {
				ans2 += "0";
			}
			else {
				int temp = fractional;
				if(temp == 10) ans2 += 'A';
				else if(temp == 11) ans2 += 'B';
				else if(temp == 12) ans2 += 'C';
				else if(temp == 13) ans2 += 'D';
				else if(temp == 14) ans2 += 'E';
				else if(temp == 15) ans2 += 'F';
				else {
					ans2 += std::to_string(temp);
					fractional = fractional - temp;
				}	
			}
		}
		else {
			fractional = fractional * base;
			if(fractional < 0) {
				ans2 += "0";
			}
			else {
				int temp = fractional;
				ans2 += std::to_string(temp);
				fractional = fractional - temp;
			}
		}
	}
	if (positive) return ans1 + "." + ans2;
	else  return ("-"+ ans1 + "." + ans2);	
}

// Complete.........
std::string binary_base_long(std::string& input_data, int base) {
	long _ans = stol(input_data, 0, 2);
	std::string ans = std::to_string(_ans);
	if(base == 10) return ans; 
	else if(base == 2) return input_data;
	else if(base == 8) return deci_base_long(ans, 8);
	else return deci_base_long(ans, 16);
}
std::string binary_base_double(std::string& input_data, int base) {
	std::cout<<input_data<<"\n\n\n";
	double _input_data = stod(input_data);
	std::cout<<_input_data<<"\n\n\n";
	bool positive = true;
	if(_input_data < 0) positive = false;
	long long whole = abs(_input_data);
	std::string whole_ = std::to_string(whole);
	double fractional = 0.0;
	if(positive) fractional = _input_data - whole;
	else fractional = (-1 * _input_data) - whole;
	std::string fractional_ = std::to_string(fractional);
	std::cout<<"fjdjf         " <<fractional_<<"\n";
	
	return "abs";
}

// .............



// I discarted bcz it's hard to deal/convert floating point number for now. SEE YOU LATER
