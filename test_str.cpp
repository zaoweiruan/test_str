#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

	class UpperCaseStreamBuf : public std::streambuf {
	protected:
	    virtual int_type overflow(int_type c) {
	        if (c != EOF) {
	            //转大写
	            c = std::toupper(c);
	            //输出
	            if (putchar(c) == EOF) {
	                return EOF;
	            }
	        }

	        return c;
	    }
	};//UpperCaseStreamBuf

	int preNUm(unsigned char byte) {
	    unsigned char mask = 0x80;
	    int num = 0;
	    for (int i = 0; i < 8; i++) {
	        if ((byte & mask) == mask) {
	            mask = mask >> 1;
	            num++;
	        } else {
	            break;
	        }
	    }
	    return num;
	}


	bool isUtf8(unsigned char* data, int len) {
	    int num = 0;
	    int i = 0;
	    while (i < len) {
	        if ((data[i] & 0x80) == 0x00) {
	            // 0XXX_XXXX
	            i++;
	            continue;
	        }
	        else if ((num = preNUm(data[i])) > 2) {
	        // 110X_XXXX 10XX_XXXX
	        // 1110_XXXX 10XX_XXXX 10XX_XXXX
	        // 1111_0XXX 10XX_XXXX 10XX_XXXX 10XX_XXXX
	        // 1111_10XX 10XX_XXXX 10XX_XXXX 10XX_XXXX 10XX_XXXX
	        // 1111_110X 10XX_XXXX 10XX_XXXX 10XX_XXXX 10XX_XXXX 10XX_XXXX
	        // preNUm() 返回首个字节8个bits中首�?0bit前面1bit的个数，该数量也是该字符所使用的字节数
	        i++;
	        for(int j = 0; j < num - 1; j++) {
	            //判断后面num - 1 个字节是不是都是10开
	            if ((data[i] & 0xc0) != 0x80) {
	                    return false;
	                }
	                i++;
	        }
	    } else {
	        //其他情况说明不是utf-8
	        return false;
	    }
	    }
	    return true;
	}

	int main(int argc, char* argv[]){
		int test[]={1,2,3,4};
		int *p=test;
		cout<<"*p++="<<*p++<<endl;
		cout<<"now *p is "<<*p<<endl;
		cout<<"*++p"<<*++p<<endl;
		cout<<"now *p is "<<*p<<endl;
		vector<string> v;
		ifstream in("test_str.cpp");
		string line;
		while(getline(in,line))
		v.push_back(line);
		//Add the line to the end//Add line numbers:
		for(int i=0;i<v.size();i++)
			cout << i<<":"<< v[i]<< endl;
//	    UpperCaseStreamBuf upper_case_stream_buf;
//	    //使用我们新定义的streambuf
//	    std::ostream out(&upper_case_stream_buf);
//	    //31 HEXADECIMAL:1F
//	    out << "31 hexadecimal:" << std::hex << 31 << std::endl;
//		string str="31 hexadecimal:";
//		cout<<isUtf8((unsigned char *)str.c_str(),sizeof(str))<<endl;
//	    return 0;

//	string str1;
//	while((cin>>str1) && strcmp(str1.c_str(),"quit"))
//	{
//		cout<<"x=  "<<str1<<endl;
//	}
//	return 0;
//	string ip_addr(argv[1]),port;
//	string::size_type pos=ip_addr.find(':');
//
//		if (pos!=ip_addr.npos)
//			{
//				string str="hello";
//				cout<<str<<endl;
//				port=ip_addr.substr(pos+1,sizeof(ip_addr));
//				ip_addr=ip_addr.substr(0,pos);
//				cout<<"ip_addr : "<<ip_addr<<" port "<<port<<endl;
//			}
//			else
//			{
//				cout<<"ip_addr : "<<ip_addr<<endl;
//			}
			//cout<<str<<endl;
}

