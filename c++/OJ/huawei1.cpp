#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;


struct PBUF{
	int offset;
	int len;
};


int move_into(PBUF& p,int ex_len,int max){
	int ans;
	ans = p.len + ex_len - max;
	if(ans > 0){
		p.offset = 0;
		p.len = max;
		return ans;
	}
	else{
		if(p.offset >= ex_len){
			p.offset -= ex_len;
			p.len += ex_len;
		}
		else{
			p.offset = 0;
			p.len += ex_len;
		}
		return 0;
	}
}


void insert_ex(int ex_len,vector<PBUF>& massage,int payload_len){
	if(massage[0].offset >= ex_len){	//数据可以插入到第一个PBUF
		massage[0].offset -= ex_len;
		massage[0].len += ex_len;
	}
	else if( massage.size()<16 ){	//数据不可以插入到第一个PBUF中 且 可以创建新的PBUF
		PBUF new_one;
		new_one.offset = 0;
		new_one.len = ex_len;
		massage.insert(massage.begin(),new_one);
	}
	else{	//不能创建新的PBUF，只能搬移
		for(int i=0;i<massage.size();i++){
			ex_len = move_into(massage[i],ex_len,payload_len);
			if(ex_len == 0) break;
		}
	}
}


int main(){
	int payload_len;	//PBUF长度
	int ex_len;			//要插入报头的数据长度
	vector<PBUF> massage;	//报文的PBUF链
	cin>>payload_len>>ex_len;
	string str;
	while(cin>>str && str!="end"){
		for(int i=0;i<str.size();i++)if(str[i] == ',') str[i] = ' ';
		stringstream ss(str);
		PBUF now;
		ss>>now.offset>>now.len;
		massage.push_back(now);
	}
	//输入数据处理完毕
	if(ex_len > payload_len){	//如果插入的数据大于PBUF长度
		int x = ex_len / payload_len;
		ex_len = ex_len % payload_len;
		insert_ex(ex_len,massage,payload_len);
		while(massage.size()<16 && x>0){
			PBUF tmp;
			tmp.offset = 0;
			tmp.len = payload_len;
			massage.insert(massage.begin(),tmp);
			x--;
		}
		if(x > 0){
			int exx_len = x*payload_len;
			for(int i=0;i<massage.size();i++){
				exx_len = move_into(massage[i],exx_len,payload_len);
				if(exx_len == 0) break;
			}
		}
	}
	else if(ex_len < payload_len){	//如果插入的数据小于PBUF长度
		insert_ex(ex_len,massage,payload_len);
	}
	for(int i=0;i<massage.size();i++){
		cout<<massage[i].offset<<","<<massage[i].len<<endl;
	}
	return 0;
}