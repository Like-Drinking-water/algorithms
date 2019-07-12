# 字符串
## 目录简介
* [matchSubstring](https://github.com/Like-Drinking-water/algorithms/tree/master/string/matchSubstring) - 匹配子串
## KMP算法
通过i, j分别标记主串跟子串匹配的当前位置位置  
先通过子串来判断当某个位置失配时  
j 应该标记的子串的什么地方
``` c
//首先先获取 next , 即失配时 j 应移动的位置
i = 1; j = 0;
next[1] = 0;
//t[0] 保存字符串的长度
while (i < t[0]) {
	if (j == 0 || t[i] == t[j]) {
		i++;
		j++;
		//此时表示在 i 位置出失配了
		//则应该移动到 j 位置上
		//因为 1 ～ j - 1 位置和 i - j + 1 ～ i - 1 位置上的字符相同
		//无需重新匹配
		next[i] = j;
	}
	else {
		//不匹配则回到上一处进行匹配
		j = next[j];
	}
}
```
获取完 next 后则可以根据 next 来完成算法
``` c
//pos 表示开始匹配的位置
i = pos; j = 1;
while (i <= s[0] && j <= t[0]) {
	if (s[i] == t[j] || j == 0) {
		i++;
		j++;
	}
	else {
		j = next[j];
	}
}
//表示匹配成功
if (j > t[0]) {
	//返回开始匹配的位置
	return i - t[0];
}
else {
	return -1;
}
```
