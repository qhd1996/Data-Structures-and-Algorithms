/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date:2018-08-15，本来想08-14做完的，没来得及，唉 
Description: leetcode上Word Ladder解答
**************************************************/  
/**
* 这题非常符合BFS的结构，能想到用BFS做就不难，剩下的就是考察对STL的掌握程度了。
* 做法是从beginword开始，访问它的邻居（只修改一个字母的单词），再访问它的邻居的邻居（当然必须是还没有被访问的），直到到达endword。为了方便，可以将endword加入到dict中，同时在申明一个变量dist，用来记录每次BFS之后的距离。
* leetcode网站提供的函数签名最后一个参数是vector类型的，处理起来非常不方便，所以我做的时候和leetcode上其他人一样使用set来做。
* 注意这题可以作为set用法的一个练习。
* 最后想说一句一定把STL常用数据结构熟练掌握吧。
**/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordSet(wordList.begin(), wordList.end());
		return ladderLength_1(beginWord, endWord, wordSet);
	}
private:
	int ladderLength_1(string beginWord, string endWord, unordered_set<string>& wordSet) {
		//endWord不在字典里，直接凉凉
		if (wordSet.find(endWord)==wordSet.end()) return 0;
		queue<string> toVisit;
		addNextWords(beginWord, wordSet, toVisit);
		int dist = 2;
		while (!toVisit.empty()) {
			int num = toVisit.size();
			for (int i = 0; i<num; i++) {
				string word = toVisit.front();
				toVisit.pop();
				if (word == endWord)
					return dist;
				else
					addNextWords(word,wordSet, toVisit);
			}
			dist++;
		}
        //这是endWord在wordList里面但是却永远无法由beginWord转变而来的情况
        return 0;
	}
	//构造辅助函数，计算即将要访问的word
	void addNextWords(string word, unordered_set<string>& wordSet, queue<string>& toVisit) {
		wordSet.erase(word);
		for (int i = 0; i<word.length(); i++) {
			//保存即将被修改的那一位，以后还要恢复的
			char letter = word[i];
			for (int k = 0; k<26; k++) {
				word[i] = 'a' + k;
				if (wordSet.find(word) != wordSet.end()) {
					toVisit.push(word);
					wordSet.erase(word);
				}
			}
			//恢复word
			word[i] = letter;
		}
	}
};
