/*
	문제 1

	- 모든 클래스에 생성자 정의
*/

/*
#include<iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;

	
public:
	Point(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	void ShowPointInfo() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};

class Circle
{
private:
	int rad;
	Point center;

public:
	Circle(int x, int y, int r)
	:center(x, y)
	{
		rad = r;

	}
	void ShowCircleInfo() const
	{
		cout << "radius : " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inCircle;
	Circle outCircle;
public:
	Ring(int inx, int iny, int inR, int outx, int outy, int outR)
		:inCircle(inx, iny, inR), outCircle(outx, outy, outR)
	{
	

	}

	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		inCircle.ShowCircleInfo();


		cout << "Out Circle Info..." << endl;
		outCircle.ShowCircleInfo();
	}
};

int main()
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}
*/

/*
	문제 2
	
	"인수목록이 일치하는 생성자 인스턴스가 없습니다"라는 에러
	 출력 시 char* 앞에 const를 추가한다.
*/

#include<iostream>
#include<string>

using namespace std;

namespace COMP_POS
{
	enum { CLERK = 0, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;


		}
	}
}

class NameCard
{
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(const char* _name,const char* _company,const char* _phone, int pos)
		:position(pos)
	{
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];

		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(phone, _phone);

	}

	void ShowNameCardInfo()
	{
		cout << "이름 :" << name << endl;
		cout << "회사 :" << company << endl;
		cout << "전화번호 :" << phone << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(position);
	}

	~NameCard()
	{
		delete []name;
		delete []company;
		delete []phone;
	}

};

int main()
{
	NameCard manClerk ("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manASSIST("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manASSIST.ShowNameCardInfo();

	return 0;
}
