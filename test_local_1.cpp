#include <iostream>
 
void PrintWchar()
{
	std::wcout << L"output English\n";
	std::wcout << L"输出一句中文\n";
	std::cout << "now-wcout: " << std::wcout.getloc().name() << std::endl;
 
	std::locale lc_global;
	std::cout << "now-global: " << lc_global.name() << std::endl;
}
 
int main()
{
	using namespace std;
	
	std::cout << "before: "<< std::wcout.getloc().name() << std::endl;
	locale lc_old = locale::global(locale("zh_cn"));  //设置全局locale为中文，并记录返回值，即原来的全局locale
	PrintWchar();
	locale::global(lc_old);  //设回原来的全局locale
	std::cout << "after: " << std::wcout.getloc().name() << std::endl;
 
	system("pause");
	return 0;
}