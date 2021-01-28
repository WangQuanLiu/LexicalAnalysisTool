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
#include<map>
#include"myException.h"
#include<Windows.h>
#include<direct.h>
#define ALPHABET_MAX 50 //字符的个数
#define	NFA_ROW_MAX	408	//NFA的行
#define NFA_COL_MAX	51	//NFA的列
#define START_STATUS_MAX 41//开始状态的个数
#define END_STATUS_MAX 97	//结束状态的个数


#define KEYWORD "keyword"
#define NUM "num"
#define REAL "real"
#define ID "id"
#define ADD_SUB_SYMBOL "add_sub_symbol"
#define MUL_SYMBOL "mul_symbol"
#define DIV_SYMBOL "div_symbol"
#define LOGCIAL_SYMBOL "logical_symbol"
#define COMPARE_SYMBOL "compare_symbol"
#define CHARACTER "character"
#define CHARACTERMATCH "characterMatch"
#define L_BRACKET "l_bracket"
#define R_BRACKET "r_bracket"
#define COMMA "comma"
#define ASSIGNMENT_SYMBOL "assignment_symbol"
#define BLANK "blank"
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
using namespace std;
struct ConverTable {//映射表 mapping table
private:
	vector<vector<int>>status;
	map<int, int>mapStatus;

public:

	ConverTable() = default;
	//添加映射，即sta行ch在字符表下标中的值为val   add mapping,
	void add_map(int sta, char ch, int val);
	inline	int get_values(int sta, char ch);//获取映射的值  get the mapping value
	vector<vector<int>>getStatus();
	map<int, int>getMapStatus();

};
struct StatusSet { //save status set class 保存状态集类
private:
	vector<int>status;
public:
	StatusSet() = default;
	//初始化status
	StatusSet(initializer_list<int>list);
	StatusSet(vector<int>&vec);
	StatusSet& operator=(initializer_list<int>list);
	int operator[](const int index);
	vector<int>get_set();
	size_t size();
	StatusSet&operator=(vector<int>&obj);
	StatusSet&operator=(StatusSet&obj);
	bool operator==(StatusSet&obj)const;

};
class LexicalAnalysis {
public :
	const static char  alphabet[ALPHABET_MAX];//字符数组
	void run();
private:
	vector<StatusSet>LexicalAnalysis::status;
	ConverTable LexicalAnalysis::conver;
	void ini_data(void);
	vector<int> edge(int s, char c);
	vector<int>dfa_edge(vector<int>&vec, char ch);
	std::vector<int> closure(int s);
	inline void init_endStatus_map_category();
	const static int startStatus[START_STATUS_MAX];//开始状态集
	const static int endStatus[END_STATUS_MAX];//结束状态集
	map<int, string>endStatus_map_category;//终态映射类别
	const static int   nfa[NFA_ROW_MAX][NFA_COL_MAX];//nfa自动机
	void nfa_conversion_to_dfa();
	bool save_status();
	bool save_conver();
	bool save();
	map<char, int>	   alphabetMapIndex;//把字符映射到在数组中的下标 
};
inline int  character_conversion_to_index(const char alphabet[], size_t size, char ch);
#endif