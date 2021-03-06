/*
1031 查验身份证 （15 分）
一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：

Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2
现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

输入格式：
输入第一行给出正整数N（≤100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

输出格式：
按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出All passed。

输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：
All passed
*/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {
	int n, err_num = 0, flag_dig17 = 1, temp;
	char z[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < 17; j++) {
			if (!isdigit(s[j])) {
				flag_dig17 = 0;
				err_num++;
				cout << s << endl;
				break;
			}
		}
		if (flag_dig17) {
			temp = ((s[0] - '0') * 7 + (s[1] - '0') * 9 + (s[2] - '0') * 10 + (s[3] - '0') * 5 + (s[4] - '0') * 8 + (s[5] - '0') * 4 + (s[6] - '0') * 2 + (s[7] - '0') * 1 + (s[8] - '0') * 6 + (s[9] - '0') * 3 + (s[10] - '0') * 7 + (s[11] - '0') * 9 + (s[12] - '0') * 10 + (s[13] - '0') * 5 + (s[14] - '0') * 8 + (s[15] - '0') * 4 + (s[16] - '0') * 2) % 11;
			if (z[temp] != s[17]) {
				cout << s << endl;
				err_num++;
			}
		}
		flag_dig17 = 1;
	}
	if (!err_num)
		cout << "All passed";
	return 0;
}