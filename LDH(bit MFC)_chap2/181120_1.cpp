#include <iostream>
using namespace std;
#if 0
#include<stdio.h>
int Sum(int a, int b) {
	return a + b;
}
void main() {
	int(*fp)(int, int);
	int i;

	fp = Sum; //Sum()함수의 시작주소를 가지는 포인터변수 fp
	i = fp(2, 3); 
	printf("%d\n", i);
}
#endif

#if 0
//static 사용X
#include<stdio.h>
class CStateManager {
private:
	//0: idle state
	//1: attack state
	//2: game over state
	int m_iState;

	void State_Idle();
	void State_Attack();
	void State_GameOver();

public:
	CStateManager();
	void SetState(int state);
	void DoIt();
};
void CStateManager::State_Idle() {
	printf("idle\n");
}
void CStateManager::State_Attack() {
	printf("attack\n");
}
void CStateManager::State_GameOver() {
	printf("game over\n");
}
CStateManager::CStateManager() { //생성자
	m_iState = 0;
}
void CStateManager::SetState(int state) {
	if (state < 0) {
		printf("잘못된 값\n");
		return;
	}
	this->m_iState = state;
}

//DoIt 함수를 이용하여 private속의 함수에 접근한다.
void CStateManager::DoIt() {
	switch (m_iState) {
	case 0:
		State_Idle();
		break;
	case 1:
		State_Attack();
		break;
	case 2:
		State_GameOver();
		break;
	}
}
void main() {
	void(CStateManager::*fp)(int);
	fp = &CStateManager::SetState;

	CStateManager sman;
	(sman.*fp)(1); // == sman.SetState(1);

	sman.DoIt();
}
#endif 

#if 0
//static 사용
#include<stdio.h>
class CStateManager {
private:
	//0: idle state
	//1: attack state
	//2: game over state
	static int m_iState;

	void State_Idle();
	void State_Attack();
	void State_GameOver();

public:
	CStateManager();
	static void SetState(int state);
	void DoIt();
};
void CStateManager::State_Idle() {
	printf("idle\n");
}
void CStateManager::State_Attack() {
	printf("attack\n");
}
void CStateManager::State_GameOver() {
	printf("game over\n");
}
CStateManager::CStateManager() {
	m_iState = 0;
}
void CStateManager::SetState(int state) {
	if (state < 0) {
		printf("잘못된 값\n");
		return;
	}
	m_iState = state;
	//로컬변수는 static이아니어도 상관이없지만, 멤버변수는 문제가 될수 있어 static이 되어야함.
}

//DoIt 함수를 이용하여 private속의 함수에 접근한다.
void CStateManager::DoIt() {
	switch (m_iState) {
	case 0:
		State_Idle();
		break;
	case 1:
		State_Attack();
		break;
	case 2:
		State_GameOver();
		break;
	}
}
int CStateManager::m_iState = 0;
void main() {
	//void(CStateManager::*fp)(int);
//	fp = &CStateManager::SetState;
	
	void(*fp)(int);
	fp = CStateManager::SetState;

	CStateManager sman;
	sman.SetState(1);
	//(CStateManager::*fp)(1);
	//(sman.*fp)(1);
}
#endif 

#if 0
//DoIt() 수정
#include<stdio.h>
class CStateManager {
private:
	//0: idle state
	//1: attack state
	//2: game over state
	int m_iState;

	void State_Idle();
	void State_Attack();
	void State_GameOver();

public:
	CStateManager();
	void SetState(int state);
	void DoIt();
};
void CStateManager::State_Idle() {
	printf("idle\n");
}
void CStateManager::State_Attack() {
	printf("attack\n");
}
void CStateManager::State_GameOver() {
	printf("game over\n");
}
CStateManager::CStateManager() { //생성자
	m_iState = 0;
}
void CStateManager::SetState(int state) {
	if (state < 0) {
		printf("잘못된 값\n");
		return;
	}
	this->m_iState = state;
}

//DoIt 함수를 이용하여 private속의 함수에 접근한다.
/*void CStateManager::DoIt() {
	switch (m_iState) {
	case 0:
		State_Idle();
		break;
	case 1:
		State_Attack();
		break;
	case 2:
		State_GameOver();
		break;
	}
}
*/
void CStateManager::DoIt() {
	//int a[3] = { 1,2,3 };
	void (CStateManager::*fp[3])() =
	{
		&CStateManager::State_Idle,
		&CStateManager::State_Attack,
		&CStateManager::State_GameOver,
	};
	(this->*fp[m_iState])();
}
int main() {
	void(CStateManager::*fp)(int);
	fp = &CStateManager::SetState;

	CStateManager sman;
	(sman.*fp)(1); // == sman.SetState(1);

	sman.DoIt();
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
//#define charit(x) #@x //이연산자 #@는 각자가 사용하는 컴파일러의 도움말
#define stringit(x) #x
#define tokencat(x,y) x##y

void main() {
	int i = 1, j = 2, ij = 3;
	cout << stringit(hello) << '\n';
	cout << tokencat(i, j) << '\n';
}
#endif

#if 0
#include <stdio.h>
typedef unsigned int HANDLE;

class CHandle {
private:
	HANDLE m_handle;
	int m_data;
public:
	CHandle(){ //생성자
		m_handle = 0;
		m_data = 1;
	}
	HANDLE GetHandle() const {
		printf("GetHandle()\n");
		return m_handle;
	}
	int Getint() const {
		printf("Getdata()\n");
		return m_data;
	}
	operator HANDLE() const { //변환연산자 오버로딩
		return m_handle;
	}
	operator int() const {
		return m_data;
	}
	//호출한 객체가 변하지 않게 하기위해 const 사용
	//함수내부가 const가 되는것이 아니라 함수를 호출하는 객체가 const가 된다는것.

	void FromHandle(HANDLE handle) {
		m_handle = handle;
	}
};
void Test(HANDLE handle) {
	printf("handle = %i\n", handle);
}
void test(int i) {
	printf("i : %d\n", i);
}
void main() {
	CHandle handleObject;
	HANDLE handle;

	handle = 2;
	handleObject.FromHandle(handle);
	Test(handleObject.GetHandle());
	Test(handleObject); //변환연산자 오버로딩후 호출
	test(handleObject.Getint());
	test(handleObject);
}
#endif 
