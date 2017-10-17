/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int lengthOfLongestSubstring(char* s) {
    //char *s = "abcabcbb";
	int slen = strlen(s);
	int totlelen = 0;
	int nextStart=0;
	int maxlen = 0;

	while(1){
		int len = lengthOfOneSubstring(s,&nextStart);
		if(len > maxlen){
			maxlen = len;
		}
		s+=1;//nextStart;
		totlelen += len;		
		if(totlelen>=slen)
		{
			break;
		}
	}
	return maxlen;
}

int lengthOfOneSubstring(char *s,int *nextStart){//其实不用nextStart，代码还可以简化 
	int i,j; 
	int len = 0;
	int stop = 0;
	int slen = strlen(s);
	
	//下面用到2重循环 
	for(i=0;i<slen;i++){		
		for(j=0;j<i;j++){//检查有没有重复的字符 
			if(s[i] == s[j]){
				stop = 1;
				break;
			}
		}
		if(stop){
			break;
		}
		else{
			len++;
		}
	} 
	*nextStart = i;
	return len;
}


int main(int argc, char *argv[]) {	
	int maxlen = 0;
	char *s = "abcabcbb";	
	
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s,%d\n",s,maxlen);
	
	s = "dvdf";//"abcabcbb";		
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s,%d\n",s,maxlen);
	
	s = "bbbbb";		
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s,%d\n",s,maxlen);
	
	s = "pwwkew";		
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s,%d\n",s,maxlen);
	
	return 0;
}
