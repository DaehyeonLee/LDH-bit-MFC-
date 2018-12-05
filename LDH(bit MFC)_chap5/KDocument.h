#pragma once
#include "KListBox.h"
#include "KView.h"
class KDocument {
public:
	typedef KListBox<int>::VITOR KDITOR; 
private:
	KListBox<int> m_kListBox; //vector 가져오기
	KView* m_pView; //view 참조
public:
	KDocument();
	virtual ~KDocument();

	void Insert(int iData);//데이터 집어넣기
	void SetView(KView* pView); //view의 주소값을 세팅
	KView* GetView(); //view 부르기
	KListBox<int>* GetListBox(); //데이터 저장,처리
};