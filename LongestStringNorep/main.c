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

//�����㷨��� 
int lengthOfLongestSubstring(char *s){
        // ����Ϊ�󲻰����ظ��ַ�����Ӵ�
        // left���Լ�¼�Ϸ�����Զ��߽�λ�ã�last��¼�ַ���һ�γ��ֵ�λ��
        int ans = 0, left = 0, len = strlen(s),i;//s.length();
        int last[255];
        memset(last, -1, sizeof(last));
        //void *memset(void *s, int ch, size_t n);
        //�������ͣ���s�е�ǰλ�ú����n���ֽ� ��typedef unsigned int size_t ���� ch �滻������ s ��
		//memset����������һ���ڴ�������ĳ��������ֵ�����ǶԽϴ�Ľṹ�������������������һ����췽��
		
        for ( i = 0; i < len; i++) {
            // �ϴγ���λ���ڵ�ǰ��¼�߽�֮�󣬼����Ӵ��г������ظ��ַ��������leftʹ���Ӵ��Ϸ�
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
