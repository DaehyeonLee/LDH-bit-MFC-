#pragma once
class KDocument;
class KView {
private:
	KDocument* m_pDocument; //��ť��Ʈ����
	
	//display�� ������ ����
	int m_iStart;
	int m_iDisplayStart;
	int m_iSelected;

public:
	KView(KDocument* pDoc);
	virtual ~KView();

	void SetDocument(KDocument* pDoc); //��ť��Ʈ �ּҸ� �޾Ƽ� ����
	KDocument* GetDocument(); //��ť��Ʈ �θ���
	void SetDisplayStart(int iStart); //display�� ������ ����
	void SetSelected(int iSelected); //������ ����
	virtual void Draw();
};