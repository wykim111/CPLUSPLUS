// StringCtrlSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "MyString.h"

int main(int argc, char* argv[])
{
	CMyString strData,strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	//���� ����
	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	//�ܼ� ���� ������ ȣ��
	strNewData = strTest;
	cout << strNewData.GetString() << endl;
	return 0;
}
