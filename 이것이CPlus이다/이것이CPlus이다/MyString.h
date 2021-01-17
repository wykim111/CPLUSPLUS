#include <iostream>
using namespace std;

#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
	//���������
	CMyString(const CMyString& rhs);

private:
	// ���ڿ��� ����� ���� �Ҵ��� �޸𸮸� ����Ű�� ���� ������.
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();

	CMyString& operator=(const CMyString& rhs);
};

