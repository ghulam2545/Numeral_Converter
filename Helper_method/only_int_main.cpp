#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <deque>

////////////////////////////////////////////////////////
// Validation check methods
bool is_valid(std::string& input_data,char leftOp, char rightOp);
bool is_hexa_valid(std::string& input_data);

// Conversion methods
std::string deci_to_base(std::string& input_data, int _base);
std::string binary_to_base(std::string& input_data, int _base);
std::string octal_to_base(std::string& input_data, int _base);
std::string hexa_to_base(std::string& input_data, int _base);
////////////////////////////////////////////////////////


int main() {
	
	
	return 0;
}

bool is_valid(std::string& input_data,char leftOp, char rightOp) {
	bool ans = true;
	int i = 0;
	if(input_data[0] == '-') i = 1;
	for(i; i<input_data.size(); i++) {
		if(!(input_data[i] >= leftOp && input_data[i] <= rightOp)) ans = false;
	}
	return ans;
}
bool is_hexa_valid(std::string& input_data) {
	bool ans = true;
	int i = 0;
	if(input_data[0] == '-') i = 1;
	for(i; i<input_data.size(); i++) {
		if(!((input_data[i] >= '0' && input_data[i] <= '9') || (toupper(input_data[i]) >= 'A' && toupper(input_data[i]) <= 'F'))) ans = false;
	}
	return ans;
}
std::string deci_to_base(std::string& input_data, int _base) {
	long long _input_data = stoll(input_data);
	bool positive = true;
	if(_input_data < 0) positive = false;
	std::deque<int> _ans;
	std::string ans = "";
	if(abs(_input_data) == 0) return "0";
	if(_base == 16) {
		while((abs(_input_data))) {
			int remainder = _input_data % _base;
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
			_ans.push_front(_input_data % _base);
			_input_data /= _base;
		}
	}
	for(int i=0; i<_ans.size(); i++) {
		if(_ans[i] >= 10) {
			char value = _ans[i];
			ans += value;	
		}
		else {
			if(abs(_ans[i]) >= 10) {
				if(abs(_ans[i]) == 10) ans += 'A';
				else if(abs(_ans[i]) == 11) ans += 'B';
				else if(abs(_ans[i]) == 12) ans += 'C';
				else if(abs(_ans[i]) == 13) ans += 'D';
				else if(abs(_ans[i]) == 14) ans += 'E';
				else if(abs(_ans[i]) == 15) ans += 'F';
			}
			else ans += std::to_string(abs(_ans[i]));
		}	
	}
	if (positive) return ans;
	else  return ("-"+ans);
}
std::string binary_to_base(std::string& input_data, int _base) {
	long long _ans = stoll(input_data, 0, 2);
	std::string ans = std::to_string(_ans);
	if(_base == 10) return ans; 
	else if(_base == 2) return input_data;
	else if(_base == 8) return deci_to_base(ans, 8);
	else return deci_to_base(ans, 16);
}
std::string octal_to_base(std::string& input_data, int _base) {
	long long _input;
	std::istringstream(input_data) >> std::oct >> _input;
	std::string ans = std::to_string(_input);
	if(_base == 10) return ans;
	else if(_base == 2) return  deci_to_base(ans, 2);
	else if(_base == 8) return  deci_to_base(ans, 8);
	else if(_base == 16) return  deci_to_base(ans, 16);
}
std::string hexa_to_base(std::string& input_data, int _base) {
	long long _input;
	std::istringstream(input_data) >> std::hex >> _input;
	std::string ans = std::to_string(_input);
	if(_base == 10) return ans;
	else if(_base == 2) return  deci_to_base(ans, 2);
	else if(_base == 8) return  deci_to_base(ans, 8);
	else if(_base == 16) return  deci_to_base(ans, 16);
	
}
