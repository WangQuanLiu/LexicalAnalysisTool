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
#define ALPHABET_MAX 50 //�ַ��ĸ���
#define	NFA_ROW_MAX	404	//NFA����
#define NFA_COL_MAX	51	//NFA����
#define START_STATUS_MAX 39//��ʼ״̬�ĸ���
#define END_STATUS_MAX 92	//����״̬�ĸ���
#endif
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

class LexicalAnalysis {
	std::vector<int> closure(int s);
	const static char  alphabet[ALPHABET_MAX];//�ַ�����
	const static int  nfa[NFA_ROW_MAX][NFA_COL_MAX];//nfa�Զ���

};