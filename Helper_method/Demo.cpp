#include <iostream>


bool valid_decimal_double(std::string& input_data) {
	bool ans = true;
	bool point = true;
	int i = 0;
	if(input_data[0] == '-') i = 1;
	for(i; i<input_data.size(); i++) {
		if(input_data[i] >= '0' && input_data[i] <= '9' || point == true) {
			if(input_data[i] == '.') point = false;
		} 	
		else ans = false;
	}
	return ans;
}

int main() {
	std::string num = "-.858422323";
	bool _isWhole = true;
	for(int i=0; i<num.size(); i++) {
		if(num[i] == '.') _isWhole = false;
	}
	
	
	
	std::cout<<valid_decimal_double(num);
	return 0;
}
