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

//九章算法解答： 
int lengthOfLongestSubstring(char *s){
        // 题意为求不包含重复字符的最长子串
        // left用以记录合法的最远左边界位置，last记录字符上一次出现的位置
        int ans = 0, left = 0, len = strlen(s),i;//s.length();
        int last[255];
        memset(last, -1, sizeof(last));
        //void *memset(void *s, int ch, size_t n);
        //函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
		//memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
		
        for ( i = 0; i < len; i++) {
            // 上次出现位置在当前记录边界之后，即该子串中出现了重复字符，需调整left使得子串合法
            if (last[s[i]] >= left) left = last[s[i]] + 1;
            last[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }

int max(int i, int j){
	if(i >=j){
		return i;
	}
	else {
		return j;
	}	
}    
    
int main(int argc, char *argv[]) {	
	int maxlen = 0;
	char *s = "abcabcbb";	
	int ans = 3;
	
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s, the right answer is %d,  I got %d,   %d\n",s,ans,maxlen,ans==maxlen);
	
	s = "wobgrovw";	
	ans = 6;	
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s, the right answer is %d,  I got %d,   %d\n",s,ans,maxlen,ans==maxlen);
	
	
	s = "dvdf";//"abcabcbb";
	ans = 3;		
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s, the right answer is %d,  I got %d,   %d\n",s,ans,maxlen,ans==maxlen);
	
	s = "bbbbb";
	ans = 1;		
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s, the right answer is %d,  I got %d,   %d\n",s,ans,maxlen,ans==maxlen);
	
	s = "pwwkew";
	ans = 3;		
    maxlen = lengthOfLongestSubstring(s);	
	printf("%s, the right answer is %d,  I got %d,   %d\n",s,ans,maxlen,ans==maxlen);
	
	return 0;
}
