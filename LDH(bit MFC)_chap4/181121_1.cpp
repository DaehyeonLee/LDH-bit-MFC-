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
	CStr(const CStr& C) { //���������
		str = new char[strlen(C.Get()) + 1];
		strcpy(str, C.Get());
		printf("copy structor\n");
	}
	char *Get()const { return str; } //const�Լ�, ��������ڿ��� ��ü��const�̹Ƿ� const��� �Լ��� �;����� �˷��ش�.
	~CStr() {
		delete[] str;
		printf("destroy structor\n");
	}
	void print() { printf("%s\n", str); }
};

void f(CStr s) {
	s.print();
}

//void f(CStr& s) { //reference �̿�, reference�� �̿��ϸ� ��ü�� �������� �ʴ´�.
//	s.print();
//}

//void f(CStr* s) { //������ �̿�
//	s->print();
//}

void main() {
	CStr s("hello");
	f(s);

	//f(&s); //������ �̿�

	//f�Լ��� ȣ���ϸ� s�� �Ȱ��� ī�ǵǾ� f�Լ� �ȿ��� ���÷� ��������µ� �װͶ��� ���� ���ڿ��� ����Ű�� �ǹǷ� shalow copy�߻�
	//pointer, reference, ��������� 3���� ������� �ذᰡ��

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
	CStr(const CStr& C) { //���������
		str = new char[strlen(C.Get()) + 1];
		strcpy(str, C.Get());
		printf("copy structor\n");
	}
	~CStr() {
		delete[] str;
		printf("destructor\n");
	}
	CStr& operator=(CStr &s) { //operator overloading ���� deep copy.
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
	CStr u = s; //��ü�� ���𹮿� ���� ������ ��������� ȣ��
	f(u); //�Լ��� �Ķ���ͷ� ���޵� ��ü�� ��������� ȣ��
	s = t; //��ü�� ���Կ����� ��������ڰ� ȣ����� �ʴ´�. bit������ ī�ǵȴ�.(bitwise copy), ������ �����ε��� �ʿ��ϴ�.
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
//Print�Լ� overriding
void main() {
	A* ap;
	B b;
	C c;
	ap = &b; //B�ӿ� A���ֱ⶧���� ����,B�ȿ��ִ� A�� access����
	ap->Print();
	ap = &c; //C�ӿ� A�� �ֱ⶧���� ����,C�ȿ��ִ� A�� access����
	ap->Print();
	//ap���� C�� �����Ϸ��� virtual�Լ��� ����Ѵ�.
	//���ε�: �Լ��� ȣ���ϴ� �κа� �Լ��� �������ִ°�.
	//apŸ�������� �������ֱ� =>���� ���ε�
	//ap�� ����Ű�� ���� Ÿ���� �����ֱ� => ���� ���ε�
}
#endif

#if 0
#include <stdio.h>

class CBase {
public:
	void Print() {
		printf("pre virtual\n");
		OverrideMe(); //�������ε��ӿ� �������ε�
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
	virtual ~A() { //����Ҹ���, ����������� �Ҹ��ڴ� �������� ȣ���϶�.
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
	virtual ~B() { //����Ҹ���, ����������� �Ҹ��ڴ� �������� ȣ���϶�.
		delete[] b;
		printf("Destructor of class B\n");
	}// ���� �Ҹ��ڸ� ó���ϰ� �ڵ����� �θ��� �Ҹ��ڷ� ����.
	//�θ𿡼��� �ڽĿ��� �����ü� ����
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

//CŬ������ test������ ������غ��� A���� ����� �Ǵµ� �������� C�� �����ڰ� ȣ���̵ǰ��� �Լ����θ� �����ϱ�����
//�θ��� �����ڷ� �̵��Ѵ�. B�� �̵��ϸ� �����ڰ� ȣ��ǰ� �ٽ� A�� �̵��Ѵ�. �׷��� �����ڴ� A,B,C ��
//�Ҹ��ڴ� �� �Ҹ��ڵ带 ���� ������ �Ŀ� �θ��� �Ҹ��ڷ� �̵��Ѵ�. �׷���virtual�� �ʿ��ϴ�. C,B,A ��
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
	p = new B; //�� ���δ� �����ϼ� ������ �����δ� ������.
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
	//�����ڿ� �Ҹ��ڿ����� �����Լ��� ȣ�������ʴ´�.(virtual�� �������ʴ´�)
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
//���α׷��� ���������� type�� �˷��ִ°�.
//��ü�� ����Ű�� �����ϳ��������� ��Ʈ���ϰ�; ����Ű��� �������� Ÿ���� �˾ƾ���.
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
	static char lpszClassName[];//CMyclass�θ��� ��ü���� ��� �����Ҽ� �ֵ��� static���� ����.
	virtual char* GetClassName() const {
		return lpszClassName;
	}
};
char CMyClass::lpszClassName[] = "CMyClass";
//Ŭ����Ÿ��(�̸�) �� ��ü���� �����ϰԲ��Ѵ�.
//���� Ÿ���� �̸��� ���̶����� �̸��� 1���� �������ָ� �Ǳ� ������, static���� ����

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
//���α׷��� ���������� type�� �˷��ִ°�.
//��ü�� ����Ű�� �����ϳ��������� ��Ʈ���ϰ�; ����Ű��� �������� Ÿ���� �˾ƾ���.
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
	//static char lpszClassName[];//CMyclass�θ��� ��ü���� ��� �����Ҽ� �ֵ��� static���� ����.
	DECLARE_CLASSNAME(CMyClass);
	virtual char* GetClassName() const {
		return lpszClassName;
	}
};
//char CMyClass::lpszClassName[] = "CMyClass";
IMPLEMENT_CLASSNAME(CMyClass);
//Ŭ����Ÿ��(�̸�) �� ��ü���� �����ϰԲ��Ѵ�.
//���� Ÿ���� �̸��� ���̶����� �̸��� 1���� �������ָ� �Ǳ� ������, static���� ����

void main() {
	CObject *p;
	p = new CMyClass;
	cout << p->GetClassName() << endl;

	delete p;
	return;
}
#endif

#if 0
//3.��ũ�� ������ RTTI
#include <iostream>
using namespace std;
#define DECLARE_CLASSNAME(s) static char lpszClassName[]
#define IMPLEMENT_CLASSNAME(s) char s##::lpszClassName[] = (#s)

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

class CObject; //class CObject ������ ����

struct CRuntimeClass { //���� ������ ���� ����ü ����
	char m_lpszClassName[21]; //1.Ŭ�����̸�
	int m_nObjectSize; //2.��ü�� ũ�⿡ ���� �����ͻ�����
	CObject * (*pfnCreateObject)(); //3.�Լ�������

	CObject * CreateObject(); //4.����Լ�
};

CObject* CRuntimeClass::CreateObject() { //CreateObjct �Լ�����
	return (*pfnCreateObject)(); //return ���� �Լ� ȣ��
}

class CObject { //CObject Ŭ���� ����
public:
	virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
	static CRuntimeClass classCObject; //static ���� �������� CObjectŬ������ ��� ��ü�� ��������
	virtual ~CObject() {} //�Ҹ���
protected:
	CObject() { printf("CObject constructor\n"); } //������, protected�̹Ƿ� ��ӹ޾ƾ߸� ������ ȣ���
};

CRuntimeClass CObject::classCObject = { //static ������ ������� ����
	"CObject",sizeof(CObject),NULL
};
class CAlpha : public CObject { // CAlpha�� CObject Ŭ���� ���
public:
	virtual CRuntimeClass* GetRuntimeClass() const { 
		return &classCAlpha;
	}
	static CRuntimeClass classCAlpha; //static ������������ CAlpha Ŭ���� ��� ��ü ��������
	static CObject* CreateObject();
protected:
	CAlpha() {
		printf("CAlpha constructor\n");
	}
};
CRuntimeClass CAlpha::classCAlpha = { //classAlpha�� ��� ���� ����
	"CAlpha",sizeof(CAlpha),CAlpha::CreateObject 
};
CObject* CAlpha::CreateObject() { //CreateObject �Լ� ����
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
//4.��ũ�� ����� RTTI
#include <iostream>
using namespace std;

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name;
//���� ����

#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass class_name::class##class_name = { (#class_name), sizeof(class_name), class_name::CreateObject};
//���� �ʱ�ȭ

#define DECLARE_DYNCREATE(class_name) static CObject* CreateObject();
//�Լ� ����

#define IMPLEMENT_DYNCREATE(class_name) CObject* class_name::CreateObject(){ return new class_name;}
//�Լ� ����

class CObject;

struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nObjectSize;
	CObject* (*pfnCreateObject)();

	CObject* CreateObject();
	//CObject�� ��ӹ��� ũ������ ��� ��ü�� ������ �� �ֵ��� ������ ������ ����.
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

// ���� RTTI - ��ũ�� ���
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
	   struct RuntimeClass�� CreateObject()�� ȣ�������, IMPLEMENT_DYNCREATE ��ũ�ο� ���� CAlpha�� &OnCreate()�� ���� �Ǿ� �����Ƿ�,
	   �ᱹ�� CAplha�� OnCreate()�� ȣ��Ǿ� �������� ��ü�� �����ϰ� �ȴ�.
	   ������ Ǫ�� ����� �ٷ� '�Լ� ������'��.
	*/
	printf("CAlpha class = %s\n", pObj1->GetRuntimeClass()->m_lpszClassName);

	
	delete pObj1;
}
#endif

