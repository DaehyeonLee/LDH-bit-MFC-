#if 0
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <conio.h>

class CStr {
	char *str;
public:
	CStr(const char *s = "") {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		printf("new structor\n");
	}
	CStr(const CStr& C) { //복사생성자
		str = new char[strlen(C.Get()) + 1];
		strcpy(str, C.Get());
		printf("copy structor\n");
	}
	char *Get()const { return str; } //const함수, 복사생성자에서 객체가const이므로 const멤버 함수가 와야함을 알려준다.
	~CStr() {
		delete[] str;
		printf("destroy structor\n");
	}
	void print() { printf("%s\n", str); }
};

void f(CStr s) {
	s.print();
}

//void f(CStr& s) { //reference 이용, reference를 이용하면 객체가 생성되지 않는다.
//	s.print();
//}

//void f(CStr* s) { //포인터 이용
//	s->print();
//}

void main() {
	CStr s("hello");
	f(s);

	//f(&s); //포인터 이용

	//f함수를 호출하면 s가 똑같이 카피되어 f함수 안에서 로컬로 만들어지는데 그것또한 같은 문자열을 가리키게 되므로 shalow copy발생
	//pointer, reference, 복사생성자 3가지 방법으로 해결가능

}
#endif

#if 0
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
class CStr {
	char *str;
public:
	CStr(const char *s = "") {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		printf("normal constructor\n");
	}
	CStr(const CStr& C) { //복사생성자
		str = new char[strlen(C.Get()) + 1];
		strcpy(str, C.Get());
		printf("copy structor\n");
	}
	~CStr() {
		delete[] str;
		printf("destructor\n");
	}
	CStr& operator=(CStr &s) { //operator overloading 으로 deep copy.
		delete[] str;
		str = new char[strlen(s.Get()) + 1];
		strcpy(str, s.Get());
		printf("= operator\n");
		return *this;
	}
	char *Get() const { return str; }
	void Print() { printf("%s\n", str); }
};

void f(CStr s) {
	s.Print();
}

void main() {
	CStr s("hello"), t("world");
	CStr u = s; //객체의 선언문에 사용된 대입은 복사생성자 호출
	f(u); //함수의 파라미터로 전달된 객체는 복사생성자 호출
	s = t; //객체간 대입연산은 복사생성자가 호출되지 않는다. bit단위로 카피된다.(bitwise copy), 연산자 오버로딩이 필요하다.
	s.Print();

}
#endif

#if 0
#include <stdio.h>
#include <iostream>
using namespace std;

class A {
	int i;
public:
	A() {
		i = 0;
	}
	virtual void Print() { cout << i << endl; }
};
class B :public A {
	int i;
public:
	B() {
		i = 1;
	}
	virtual void Print() { cout << i << endl; }
};
class C : public B {
	int i;
public:
	C() {
		i = 2;
	}
	virtual void Print() { cout << i << endl; }
};
//Print함수 overriding
void main() {
	A* ap;
	B b;
	C c;
	ap = &b; //B속에 A가있기때문에 가능,B안에있는 A만 access가능
	ap->Print();
	ap = &c; //C속에 A가 있기때문에 가능,C안에있는 A만 access가능
	ap->Print();
	//ap에서 C에 접근하려고 virtual함수를 사용한다.
	//바인딩: 함수를 호출하는 부분과 함수를 연결해주는것.
	//ap타입을보고 연결해주기 =>정적 바인딩
	//ap가 가리키는 놈의 타입을 맞춰주기 => 동적 바인딩
}
#endif

#if 0
#include <stdio.h>

class CBase {
public:
	void Print() {
		printf("pre virtual\n");
		OverrideMe(); //정적바인딩속에 동적바인딩
		printf("post virtual\n");
	}

	virtual void OverrideMe() {
		printf("CBase\n");
	}
};
class CDerive : public CBase {
public:
	void Draw() {
		printf("draw\n");
	}

	virtual void OverrideMe() {
		CBase::OverrideMe();
		printf("CDerive\n");
	}
};

void main() {
	CDerive d;
	d.Print();
}
#endif

#if 0
#include <iostream>
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

class A {
	char *a;
public:
	A(const char* s) {
		a = new char[strlen(s) + 1];
		strcpy(a, s);
	}
	virtual ~A() { //가상소멸자, 상속을받으면 소멸자는 가상으로 호출하라.
		delete[] a;
		printf("Destructor of class A\n");
	}
	virtual void Print() {
		printf("%s\n", a);
	}
};

class B : public A {
	char *b;
public:
	B(const char* s, const char* t) : A(t) {
		b = new char[strlen(s) + 1];
		strcpy(b, s);
	}
	virtual ~B() { //가상소멸자, 상속을받으면 소멸자는 가상으로 호출하라.
		delete[] b;
		printf("Destructor of class B\n");
	}// 나의 소멸자를 처리하고 자동으로 부모의 소멸자로 간다.
	//부모에서는 자식에게 내려올수 없다
	virtual void Print() {
		A::Print();
		printf("%s\n", b);
	}
};

void main() {
	A* pA;
	pA = new B("hello", "world");
	pA->Print();
	delete pA;
}
#endif

#if 0

#include<stdio.h>

class A
{
	int a;
public:
	A(int _a = 1) :a(_a)
	{
		printf("A : constructor\n");
	}
	virtual ~A() {
		printf("A : destructor\n");
	}
};

class B : public A
{
	int b;
public:
	B(int _b = 2) :b(_b)
	{
		printf("B : constructor\n");
	}
	virtual ~B() {
		printf("B : destructor\n");
	}
};

class C : public B
{
	int c;
public:
	C(int _c = 3) : c(_c)
	{
		printf("C : constructor\n");
	}
	virtual ~C() {
		printf("C : destructor\n");
	}
};

//C클래스의 test이지만 출력을해보면 A부터 출력이 되는데 그이유는 C의 생성자가 호출이되고나서 함수내부를 실행하기전에
//부모의 생성자로 이동한다. B로 이동하면 생성자가 호출되고 다시 A로 이동한다. 그래서 생성자는 A,B,C 순
//소멸자는 내 소멸코드를 전부 실행한 후에 부모의 소멸자로 이동한다. 그래서virtual이 필요하다. C,B,A 순
int main()
{
	//C test;
	C *cp;
	B *p;
	A *ap;
	printf("-----------------------\n");
	cp = new C;
	delete cp;
	printf("-----------------------\n");
	p = new B; //내 위로는 움직일수 있지만 밑으로는 못간다.
	delete p;
	printf("-----------------------\n");
	ap = new A;
	delete ap;
	return 0;
}
#endif
#if 0
#include <stdio.h>

class CBase {
public:
	//생성자와 소멸자에서는 가상함수를 호출하지않는다.(virtual이 통하지않는다)
	CBase() {
		DoVirtual();
	}
	virtual ~CBase() {
		DoVirtual();
	}
	void DoIt() {
		DoVirtual();
	}
	virtual void DoVirtual() {
		printf("CBase\n");
	}
};

class CDerive :public CBase {
public:
	virtual void DoVirtual() {
		printf("CDerive\n");
	}
};
void main() {
	CDerive b;
	b.DoIt();
}
#endif

#if 0
//1
//RTTI(run-time type information)
//프로그램이 돌고있을때 type을 알려주는것.
//객체를 가리키는 변수하나만가지고 컨트롤하고싶어서 가리키기고 싶은놈의 타입을 알아야함.
#include <iostream>
using namespace std;

class CObject {
public:
	virtual char* GetClassName() const {
		return NULL;
	}
};
class CMyClass : public CObject {
public:
	static char lpszClassName[];//CMyclass로만든 객체들이 모두 공유할수 있도록 static으로 선언.
	virtual char* GetClassName() const {
		return lpszClassName;
	}
};
char CMyClass::lpszClassName[] = "CMyClass";
//클래스타입(이름) 을 객체들이 공유하게끔한다.
//같은 타입의 이름은 같이때문에 이름은 1개만 선언해주면 되기 때문에, static으로 선언

void main() {
	CObject *p;
	p = new CMyClass;
	cout << p->GetClassName() << endl;

	delete p;
	return;
}
#endif

#if 0
//2
//RTTI(run-time type information)
//프로그램이 돌고있을때 type을 알려주는것.
//객체를 가리키는 변수하나만가지고 컨트롤하고싶어서 가리키기고 싶은놈의 타입을 알아야함.
#include <iostream>
using namespace std;
#define DECLARE_CLASSNAME(s) static char lpszClassName[]
#define IMPLEMENT_CLASSNAME(s) char s##::lpszClassName[] = (#s)

class CObject {
public:
	virtual char* GetClassName() const {
		return NULL;
	}
};
class CMyClass : public CObject {
public:
	//static char lpszClassName[];//CMyclass로만든 객체들이 모두 공유할수 있도록 static으로 선언.
	DECLARE_CLASSNAME(CMyClass);
	virtual char* GetClassName() const {
		return lpszClassName;
	}
};
//char CMyClass::lpszClassName[] = "CMyClass";
IMPLEMENT_CLASSNAME(CMyClass);
//클래스타입(이름) 을 객체들이 공유하게끔한다.
//같은 타입의 이름은 같이때문에 이름은 1개만 선언해주면 되기 때문에, static으로 선언

void main() {
	CObject *p;
	p = new CMyClass;
	cout << p->GetClassName() << endl;

	delete p;
	return;
}
#endif

#if 0
//3.매크로 사용안한 RTTI
#include <iostream>
using namespace std;
#define DECLARE_CLASSNAME(s) static char lpszClassName[]
#define IMPLEMENT_CLASSNAME(s) char s##::lpszClassName[] = (#s)

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

class CObject; //class CObject 전방위 선언

struct CRuntimeClass { //동적 생성을 위한 구조체 선언
	char m_lpszClassName[21]; //1.클래스이름
	int m_nObjectSize; //2.객체의 크기에 대한 데이터사이즈
	CObject * (*pfnCreateObject)(); //3.함수포인터

	CObject * CreateObject(); //4.멤버함수
};

CObject* CRuntimeClass::CreateObject() { //CreateObjct 함수정의
	return (*pfnCreateObject)(); //return 값이 함수 호출
}

class CObject { //CObject 클래스 정의
public:
	virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
	static CRuntimeClass classCObject; //static 변수 선언으로 CObject클래스의 모든 객체가 정보공유
	virtual ~CObject() {} //소멸자
protected:
	CObject() { printf("CObject constructor\n"); } //생성자, protected이므로 상속받아야만 생성자 호출됨
};

CRuntimeClass CObject::classCObject = { //static 변수의 멤버변수 정의
	"CObject",sizeof(CObject),NULL
};
class CAlpha : public CObject { // CAlpha는 CObject 클래스 상속
public:
	virtual CRuntimeClass* GetRuntimeClass() const { 
		return &classCAlpha;
	}
	static CRuntimeClass classCAlpha; //static 변수선언으로 CAlpha 클래스 모든 객체 정보공유
	static CObject* CreateObject();
protected:
	CAlpha() {
		printf("CAlpha constructor\n");
	}
};
CRuntimeClass CAlpha::classCAlpha = { //classAlpha의 멤버 변수 정의
	"CAlpha",sizeof(CAlpha),CAlpha::CreateObject 
};
CObject* CAlpha::CreateObject() { //CreateObject 함수 정의
	return new CAlpha;
}
class CBeta : public CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCBeta;
	}
	static CRuntimeClass classCBeta;
	static CObject* CreateObject();
protected:
	CBeta() {
		printf("CBeata constructor\n");
	}
};

CRuntimeClass CBeta::classCBeta = {
	"CBeta",sizeof(CBeta),CBeta::CreateObject
};
CObject* CBeta::CreateObject() { return new CBeta; }

int main() {
	CRuntimeClass* pRTCAlpha = RUNTIME_CLASS(CAlpha);
	CObject* pObj1;

	pObj1 = (*pRTCAlpha).CreateObject();
	printf("CAlpha class= %s\n", pObj1->GetRuntimeClass()->m_lpszClassName);

	CRuntimeClass* pRTCBeta = RUNTIME_CLASS(CBeta);
	CObject* pObj2;

	pObj2 = pRTCBeta->CreateObject();
	printf("CBeta class = %s\n", pObj2->GetRuntimeClass()->m_lpszClassName);

	delete pObj1;
	delete pObj2;

}
#endif

#if 0
//4.매크로 사용한 RTTI
#include <iostream>
using namespace std;

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name;
//변수 선언

#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass class_name::class##class_name = { (#class_name), sizeof(class_name), class_name::CreateObject};
//변수 초기화

#define DECLARE_DYNCREATE(class_name) static CObject* CreateObject();
//함수 선언

#define IMPLEMENT_DYNCREATE(class_name) CObject* class_name::CreateObject(){ return new class_name;}
//함수 정의

class CObject;

struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nObjectSize;
	CObject* (*pfnCreateObject)();

	CObject* CreateObject();
	//CObject를 상속받은 크래스의 모든 객체에 접근할 수 있도록 포인터 변수로 선언.
};

CObject* CRuntimeClass::CreateObject() {
	return (*pfnCreateObject)();
}

class CObject {
public:
	virtual CRuntimeClass* GetRuntimaClass() const { return NULL; }
	DECLARE_DYNAMIC(CObject)
	virtual ~CObject() {}
protected:
	CObject() { printf("CObject constructor\n"); }
};

CRuntimeClass CObject::classCObject = { "CObject",sizeof(CObject),NULL };

class CAlpha: public CObject{
public:
	virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCAlpha;
	}
	DECLARE_DYNAMIC(CAlpha)
	DECLARE_DYNCREATE(CAlpha)
protected:
	CAlpha() { printf("CAlpha constructor\n"); }
};
IMPLEMENT_DYNAMIC(CAlpha)
IMPLEMENT_DYNCREATE(CAlpha)

class CBeta : public CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCBeta;
	}
	DECLARE_DYNAMIC(CBeta)
	DECLARE_DYNCREATE(CBeta)
protected:
	CBeta() { printf("CBeta constructor\n"); }
};
IMPLEMENT_DYNAMIC(CBeta)
IMPLEMENT_DYNCREATE(CBeta)

void main() {
	CRuntimeClass* pRTCAlpha = RUNTIME_CLASS(CAlpha);
	CObject* pObj1;

	pObj1 = pRTCAlpha->CreateObject();
	printf("CAlpha class = %s\n", pObj1->GetRuntimaClass()->m_lpszClassName);

	CRuntimeClass* pRTCBeta = RUNTIME_CLASS(CBeta);
	CObject* pObj2;

	pObj2 = pRTCBeta->CreateObject();
	printf("CBeta class = %s\n", pObj2->GetRuntimaClass()->m_lpszClassName);

	delete pObj1;
	delete pObj2;
}
#endif

// 동적 RTTI - 매크로 사용
#if 1
#include <afx.h>

#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name) }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }


#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
		class_name::CreateObject, NULL)

#define DECLARE_DYNAMIC(class_name) \
public: \
	static const CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define DECLARE_DYNCREATE(class_name) \
	DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();



class CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
	static CRuntimeClass classCObject;
	//DECLARE_DYNAMIC(CObject)
	virtual ~CObject() {}

protected:
	CObject() { printf("CObject constructor\n"); }
};

//IMPLEMENT_DYNAMIC(CObject)
CRuntimeClass CObject::classCObject = {
	"CObject",sizeof(CObject),NULL
};




class CAlpha : public CObject
{
public:
	static const CRuntimeClass classCAlpha;
	virtual CRuntimeClass* GetRuntimeClass() const;
	static CObject* CreateObject();
protected:
	CAlpha() { printf("CAlpha constructor\n"); }
};

CObject* PASCAL CAlpha::CreateObject()
{
	return new CAlpha;
};

AFX_COMDAT const CRuntimeClass CAlpha::classCAlpha = {
	 "CAlpha", 32, 0xFFFF, CAlpha::CreateObject,
	 (CRuntimeClass*)(&CObject::classCObject)
};

CRuntimeClass* CAlpha::GetRuntimeClass() const
{
	return(CRuntimeClass*)(&CAlpha::classCAlpha);
}
struct CRuntimeClass
{
	const char * m_lpszClassName;
	int m_nObjectSize;
	unsigned int m_wSchema;
	CObject* (*m_pfnCreateObject)();
	CRuntimeClass * m_pBaseClass;
	CObject* CreateObject();
};

//int main()
//{
//	CRuntimeClass* pRTCAlpha = (CRuntimeClass*)(&CAlpha::classCAlpha);
//}

class CAlpha :public CObject {
public:
	DECLARE_DYNCREATE(CAlpha)
protected:
	CAlpha() { printf("CAlpha constructor\n"); }
};
IMPLEMENT_DYNCREATE(CAlpha,CObject)

int main() {
	//Create CAlpha
	CRuntimeClass *pRTCAlpha = RUNTIME_CLASS(CAlpha);
	CObject *pObj1;

	pObj1 = pRTCAlpha->CreateObject();
	/*
	   struct RuntimeClass의 CreateObject()가 호출되지만, IMPLEMENT_DYNCREATE 매크로에 의해 CAlpha의 &OnCreate()가 대입 되어 있으므로,
	   결국은 CAplha의 OnCreate()가 호출되어 동적으로 객체를 생성하게 된다.
	   문제를 푸는 열쇠는 바로 '함수 포인터'다.
	*/
	printf("CAlpha class = %s\n", pObj1->GetRuntimeClass()->m_lpszClassName);

	
	delete pObj1;
}
#endif

