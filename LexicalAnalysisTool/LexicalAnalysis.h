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
#define	NFA_ROW_MAX	404	//NFA����
#define NFA_COL_MAX	51	//NFA����
#define START_STATUS_MAX 38//��ʼ״̬�ĸ���
#define END_STATUS_MAX 90	//����״̬�ĸ���

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
	vector<int>get_set();
	StatusSet&operator=(vector<int>&obj);
	StatusSet&operator=(StatusSet&obj);
	bool operator==(StatusSet&obj)const;

};
class LexicalAnalysis {
public :
	const static char  alphabet[ALPHABET_MAX];//�ַ�����
private:
	void ini_data(void);
	vector<int> edge(int s, char c);
	vector<int>dfa_edge(vector<int>&vec, char ch);
	std::vector<int> closure(int s);
	const static int startStatus[START_STATUS_MAX];//��ʼ״̬��
	const static int endStatus[END_STATUS_MAX];//����״̬��
	
	const static int   nfa[NFA_ROW_MAX][NFA_COL_MAX];//nfa�Զ���

	map<char, int>	   alphabetMapIndex;//���ַ�ӳ�䵽�������е��±� 
};
inline int  character_conversion_to_index(const char alphabet[], size_t size, char ch);
#endif