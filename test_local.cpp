#include <iostream>
 
int main()
{
	using namespace std;
 std::locale::global(std::locale("zh_CN"));
	locale lc_defalut;
	cout << lc_defalut.name() << "\n";
 
	system("pause");
	return 0;
}