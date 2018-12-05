#pragma once
#include "KListBox.h"
#include "KView.h"
class KDocument {
public:
	typedef KListBox<int>::VITOR KDITOR; 
private:
	KListBox<int> m_kListBox; //vector ��������
	KView* m_pView; //view ����
public:
	KDocument();
	virtual ~KDocument();

	void Insert(int iData);//������ ����ֱ�
	void SetView(KView* pView); //view�� �ּҰ��� ����
	KView* GetView(); //view �θ���
	KListBox<int>* GetListBox(); //������ ����,ó��
};