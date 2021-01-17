#include<iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }

	//복사생성자 선언 및 정의
	CMyData(const CMyData& rhs)
	{
		this->m_nData = rhs.m_nData;
		cout << "CMyData(const CMyData &)" << endl;
	}

	int GetData(void) const
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

private:
	int m_nData = 0;
};

int main()
{
	CMyData a;
	a.SetData(10);

	//복사생성자 호출
	CMyData b(a);

	cout << b.GetData() << endl;

	return 0;
}