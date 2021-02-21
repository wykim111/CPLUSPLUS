#include <iostream>
using namespace std;

class SinivelCap    // 콧물 처치용 캡슐
{
public:
	void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap    // 재채기 처치용 캡슐
{
public:
	void Take() const { cout << "재채기가 멎습니다." << endl; }
};

class SnuffleCap   // 코막힘 처치용 캡슐
{
public:
	void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};
//class를 파라미터로 받아서 해당 클래스의 기능을 사용한다.
class ColdPatient
{
public: 
	void TakeSinivelCap(const SinivelCap &cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap &cap) const { cap.Take(); }
	void TakeSnuffleCap(const SnuffleCap &cap) const { cap.Take(); }
};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}
