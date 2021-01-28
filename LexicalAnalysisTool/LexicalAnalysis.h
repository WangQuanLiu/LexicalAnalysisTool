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
#define ALPHABET_MAX 50 //�ַ��ĸ���
#define	NFA_ROW_MAX	408	//NFA����
#define NFA_COL_MAX	51	//NFA����
#define START_STATUS_MAX 41//��ʼ״̬�ĸ���
#define END_STATUS_MAX 97	//����״̬�ĸ���


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
/*�ַ�����*/
enum ENUM_EndStatus {
	logcial_symbo1 = 1,//�߼�����,
	keyword,//�ؼ���
	number,//����
	real,//������
	id,//�Զ���id
	add_sub_symbol,//�Ӽ��������
	mul_symbol,//�˷������
	div_symbol,//���������
	compare_symbol,//�Ƚ���
	assignment_symbol,//��ֵ����
	character,//�ַ���
	characterMatch,//�ַ���ƥ��
	l_bracket,//������
	r_bracket,//������
	underline,//�»���
	comma,//����
};
using namespace std;
struct ConverTable {//ӳ��� mapping table
private:
	vector<vector<int>>status;
	map<int, int>mapStatus;

public:

	ConverTable() = default;
	//���ӳ�䣬��sta��ch���ַ����±��е�ֵΪval   add mapping,
	void add_map(int sta, char ch, int val);
	inline	int get_values(int sta, char ch);//��ȡӳ���ֵ  get the mapping value
	vector<vector<int>>getStatus();
	map<int, int>getMapStatus();

};
struct StatusSet { //save status set class ����״̬����
private:
	vector<int>status;
public:
	StatusSet() = default;
	//��ʼ��status
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
	const static char  alphabet[ALPHABET_MAX];//�ַ�����
	void run();
private:
	vector<StatusSet>LexicalAnalysis::status;
	ConverTable LexicalAnalysis::conver;
	void ini_data(void);
	vector<int> edge(int s, char c);
	vector<int>dfa_edge(vector<int>&vec, char ch);
	std::vector<int> closure(int s);
	inline void init_endStatus_map_category();
	const static int startStatus[START_STATUS_MAX];//��ʼ״̬��
	const static int endStatus[END_STATUS_MAX];//����״̬��
	map<int, string>endStatus_map_category;//��̬ӳ�����
	const static int   nfa[NFA_ROW_MAX][NFA_COL_MAX];//nfa�Զ���
	void nfa_conversion_to_dfa();
	bool save_status();
	bool save_conver();
	bool save();
	map<char, int>	   alphabetMapIndex;//���ַ�ӳ�䵽�������е��±� 
};
inline int  character_conversion_to_index(const char alphabet[], size_t size, char ch);
#endif