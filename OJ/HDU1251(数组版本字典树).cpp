#define LOCAL
#include <iostream>
#include <stdio.h>
using namespace std;

int trie[1000010][26];    //数组形式定义字典树，值存储的是下一个字符的位置
int num[1000010]={0};    //附加值，以某一字符串为前缀的单词的数量
int pos = 1;

void Insert(char word[])    //在字典树中插入某个单词
{
    int i;
    int c = 0;
    for(i=0;word[i];i++){
        int n = word[i]-'a';
        if(trie[c][n]==0)    //如果对应字符还没有值
            trie[c][n] = pos++;
        c = trie[c][n];
        num[c]++;
    }
}
int Find(char word[])    //返回以某个字符串为前缀的单词的数量
{
    int i;
    int c = 0;
    for(i=0;word[i];i++){
        int n = word[i]-'a';
        if(trie[c][n]==0)
            return 0;
        c = trie[c][n];
    }
    return num[c];
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    char word[11];
    while(gets(word)){
        if(word[0]==NULL)    //空行。gets读入的回车符会自动转换为NULL。
            break;
        Insert(word);
    }
    while(gets(word))
        printf("%d\n",Find(word));
    return 0;
}