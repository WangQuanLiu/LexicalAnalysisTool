#pragma once
#ifndef _LEXICAL_ANALYSIS_
#define _CRT_SECURE_NO_WARNINGS
#define _LEXICAL_ANALYSISL_
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<list>
#include<string>
#include<set>
#include<Windows.h>
#include<direct.h>
#define ALPHABET_MAX 50 //字符的个数
#define	NFA_ROW_MAX	404	//NFA的行
#define NFA_COL_MAX	51	//NFA的列
#define START_STATUS_MAX 39//开始状态的个数
#define END_STATUS_MAX 92	//结束状态的个数
#endif
/*字符类型*/
enum ENUM_EndStatus {
	logcial_symbo1 = 1,//逻辑符号,
	keyword,//关键字
	number,//数字
	real,//浮点数
	id,//自定义id
	add_sub_symbol,//加减运算符号
	mul_symbol,//乘法运算符
	div_symbol,//除法运算符
	compare_symbol,//比较类
	assignment_symbol,//赋值符号
	character,//字符串
	characterMatch,//字符串匹配
	l_bracket,//左括号
	r_bracket,//右括号
	underline,//下划线
	comma,//逗号
};

class LexicalAnalysis {
	std::vector<int> closure(int s);
	const static char  alphabet[ALPHABET_MAX];//字符数组
	const static int  nfa[NFA_ROW_MAX][NFA_COL_MAX];//nfa自动机

};