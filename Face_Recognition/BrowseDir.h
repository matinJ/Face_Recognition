#pragma once
#include "direct.h"
#include "string.h"
#include "io.h"
#include "stdio.h" 
#include <vector>
#include <iostream>
using namespace std;
class CBrowseDir
{
protected:
	char m_szInitDir[_MAX_PATH]; //��ų�ʼľľ�ľ���·������\����β

public:
	CBrowseDir();
	bool SetInitDir(const char *dir); //���ó�ʼĿ¼Ϊdir���������false,��ʾĿ¼��ͬ
	bool BeginBrowse(const char *filespec);
	//��ʼ������ʼĿ¼������Ŀ¼����filespecָ�����͵��ļ�  
    //filespec����ʹ��ͨ��� * ?�����ܰ���·����  
    //�������false����ʾ�������̱��û���ֹ 

	vector<char*> BeginBrowseFilenames(const char *filespec); //����Ŀ¼�������ļ���

protected:
	//����Ŀ¼dir����filespecָ�����ļ�  
	//������Ŀ¼,���õ����ķ���  
	//�������false,��ʾ��ֹ�����ļ�  
	bool BrowseDir(const char *dir,const char *filespec);
	vector<char*> GetDirFilenames(const char *dir,const char *filespec);

	//����BrowseDirÿ�ҵ�һ���ļ�,�͵���ProcessFile  
	//�����ļ�����Ϊ�������ݹ�ȥ  
	//�������false,��ʾ��ֹ�����ļ�  
	//�û����Ը�д�ú���,�����Լ��Ĵ������  
	virtual bool ProcessFile(const char *filename);

	//����BrowseDirÿ����һ��Ŀ¼,�͵���ProcessDir  
	//�������ڴ����Ŀ¼������һ��Ŀ¼����Ϊ�������ݹ�ȥ  
	//������ڴ�����ǳ�ʼĿ¼,��parentdir=NULL  
	//�û����Ը�д�ú���,�����Լ��Ĵ������  
	//�����û�����������ͳ����Ŀ¼�ĸ���
	virtual void ProcessDir(const char *currentdir,const char *parentdir);
};