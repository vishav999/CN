#include <iostream>
using namespace std;
string onesComp(string data) {
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '0') {
			data[i] = '1';
		}
		else {
			data[i] = '0';
		}
	}
	return data;
}
string checkSum(string data) {
	int n = data.length();
	if (n % 8 != 0) {
		int zeroAppend = 8 - (n % 8);
		for (int i = 0; i < zeroAppend; i++) {
			data = '0' + data;
		}
	}
	string result = "";
	for (int i = 0; i < 8; i++ ) {
		result = data[i];
	}
	for (int i = 8; i < n; i += 8) {
		string nextGroup = "";
		for (int j = i; j < i + 8; j++) {
			nextGroup += data[j];
		}
		string additions = "";
		int sum = 0, carry = 0;
		
		for (int k = 7;  k >= 0; k--) {
			sum += (nextGroup[k] - '0') + (result[k] - '0');
			carry = sum/2;
			if (sum == 0) {
				additions = '0' + additions;
			}
			else if (sum == 1) {
				additions = '1' + additions;
			}
			else if (sum == 2) {
				additions = '0' + additions;
				sum = 1;
			}
			else {
				additions = '1' + additions;
				sum = carry;
			}
		}
		string final = "";
		if (carry == 1) {
			for (int l = 7; l >= 0; l--) {
				if (carry == 0) {
					final = additions[l] + final;
				}
				else if (((additions[l] - '0') + carry) % 2 == 0) {
					final = '0' + final;
					carry = 1;
				}
				else {
					final = "1" + final;
					carry = 0;
				}
			}
			result = final;
		}
		else {
			result = additions;
		}
	}
	return result;
	//return onesComp(result);
	
}

int main() {
	cout << "Enter dataword: ";
	string d;
	cin >> d;
	cout << "Dataword: " << d << endl;
	string cS = checkSum(d);
	cout << "CheckSum = " << cS << endl;
	d = d + cS;
	cout << "Codeword: " << d;
	return 0;
}