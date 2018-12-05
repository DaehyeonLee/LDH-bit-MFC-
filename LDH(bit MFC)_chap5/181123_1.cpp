//#include <iostream>
//#include "KListBox.h"
//
//using std::cout;
//using std::endl;
//void main() {
//	KListBox<int> kListBox;
//
//	for (int i = 0; i < 20; i++) { kListBox.Insert(i); }
//
//	int iStart = kListBox.SetDisplayStart(15);
//	kListBox.SetSelected(17);
//	for (kListBox<int>::VITOR itor = kListBox.BeginDisplay(); itor !=
//		kListBox.EndDisplay(); ++itor) {
//		if (kListBox.m_iSelectedItem(iStart)) cout << "* ";
//		else cout << " ";
//		cout << "element value = " << (*itor) << endl;
//		++iStart;
//	}
//}
#if 0
#include <iostream>
#include "KListBox.h"

using std::cout;
using std::endl;
int main() {
	KListBox<int> kListBox;
	for (int i = 1; i <= 20; i++) {
		kListBox.Insert(i);
	}
	int iStart = kListBox.SetDisplayStart(15);
	kListBox.SetSelected(17);
	for (KListBox<int>::VITOR itor = kListBox.BeginDisplay(); itor != kListBox.EndDisplay(); ++itor) {
		if (kListBox.IsSelected(iStart))cout << "* ";
		else cout << "  ";
		cout << "element value = " << (*itor) << endl;
		++iStart;
	}

	kListBox.Reverse();

	for(KListBox<int>::VITOR itor =kListBox.Begin();
		itor != kListBox.End(); itor++) {
		cout << "element value = " << (*itor) << endl;
	}
	cout << "kListBox[3] = " << kListBox[3] << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	vector<int>::iterator iter;

	for (int i = 0; i< 10; ++i) {
		v.push_back(i + 1);
	}
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " ";
	}
}
#endif

#if 0
#include <iostream>
#include <assert.h>
#include <conio.h>
#include "KDocument.h"
#include "KView.h"

//m_pDoc�� �����͸� ����ְ�, display�� m_pView���� �Ѵ�.
class CWinApp {
private:
	KDocument* m_pDoc; 
	KView* m_pView;
public:
	CWinApp() {
		m_pDoc = new KDocument();
		m_pView = new KView(m_pDoc);
		m_pDoc->SetView(m_pView);
	}

	CWinApp(const CWinApp& right) {
		assert(!"fall");
	}
	~CWinApp() {
		delete m_pDoc;
		delete m_pView;
	}
	void InitInstance() {
		for (int i = 0; i < 20; i++) { m_pDoc->Insert(i); }
	}
	void OnDraw() {
		m_pView->SetDisplayStart(15);
		m_pView->SetSelected(17);
		m_pView->Draw();
	}
};

CWinApp theApp; //������ȣ���ϸ鼭 cocument�� view����

void main() {
	theApp.InitInstance();//������ֱ�
	theApp.OnDraw(); //view
}
#endif

#if 0
//������Ʈ ���� -> ��Ȳ������ �ٸ���
#include<iostream>
#include<conio.h>
#include<Windows.h>

#define KEY_ESC 27

using std::cout;
using std::endl;

class CAccount{
public:
	enum{ STATE_IDLE, STATE_INPUT, STATE_WAIT_ACK, STATE_MAX};
public:
	int m_iState;

	CAccount();
	void OnIdle();
	void OnInput();
	void OnWaitAck();

	void SetState(int iState);
	void Render();
};

CAccount::CAccount() { m_iState = STATE_IDLE; }

void CAccount::OnIdle() { cout << "OnIdle()" << endl; }

void CAccount::OnInput() { cout << "OnInput()" << endl; }

void CAccount::OnWaitAck() { cout << "OnWaitAck()" << endl; }

void CAccount::SetState(int iState) { m_iState = iState; }

void CAccount::Render() {
	static void(CAccount::*mfp[]) () = {
		&CAccount::OnIdle,
		&CAccount::OnInput,
		&CAccount::OnWaitAck
	};

	if (m_iState >= 0 && m_iState < STATE_MAX) { (this->*mfp[m_iState])(); }

}
int main() {
	CAccount account;
	int ch = 0;

	while(ch != KEY_ESC) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == '1')
				account.SetState(CAccount::STATE_IDLE);
			if (ch == '2')
				account.SetState(CAccount::STATE_INPUT);
			if (ch == '3')
				account.SetState(CAccount::STATE_WAIT_ACK);
		}
		Sleep(500);
		account.Render();
	}
}
#endif

#if 0
//�̱���
#include <stdio.h>
#include <assert.h>
#define AfxGetApp() KSingleton<CWinApp>::GetSingleton()

template<typename T>
class KSingleton {
private:
	static T* ms_pSingleton;
public:
	KSingleton() {
		assert(NULL == KSingleton<T>::ms_pSingleton);
		//������ �������������� return ;
		KSingleton<T>::ms_pSingleton = (T*)this;
	}
	~KSingleton() {
		KSingleton<T>::ms_pSingleton = NULL;
	}
	static T* GetSingleton() {
		return ms_pSingleton;
	}
};

template<typename T> T* KSingleton<T>::ms_pSingleton = NULL;

class CWinApp : public KSingleton<CWinApp> {
public:
	void Print() {
		printf("hello\n");
	}
};

//CWinApp theApp;

int main() {
	//CWinApp theApp;
	//�̱����� ��ü�� �ϳ��� �����̰���.
	AfxGetApp()->Print();
}
#endif

#if 0
//�̱��� ����
#include <iostream>
using namespace std;
class SingleTon {
private:
	int n;
	int m;
	SingleTon() { } //�����ڰ� private�̶� ��ü�� �׳� �����Ҽ��� ����.
	static SingleTon instance;
	//��ü�� �����Ǿ� ��������� ������ �Ǵµ� �ܺο��� ��ü�� �����ϰԵǸ� �����ڰ� private�̹Ƿ�
	//�ܺο��� ��ü�� �����Ҽ� ���ԵǹǷ� ��ü�� �ϳ��� �����Ҽ� ���� �ǹǷ� static���� ���� �� �ۿ� ����.
	//static���� ������ ����� main�������� ��ü�� �����ǰ� �����ڰ� ���� ����Լ� �̹Ƿ� ��ü ��������

public:
	static SingleTon* GetInstance() { return &instance; }
	//static������ �����Ϸ��� ����Լ��� static���� ����.
	void SetData(int a, int b) { n = a; m = b; }
	void Print() { cout << "m: " << m << " n: " << n << endl; }
};
SingleTon SingleTon::instance;

int main() {
	//SingleTon obj; ��ü���� �Ұ���
	SingleTon* pInstance = SingleTon::GetInstance();
	pInstance->SetData(10, 20);
	pInstance->Print();
}
#endif