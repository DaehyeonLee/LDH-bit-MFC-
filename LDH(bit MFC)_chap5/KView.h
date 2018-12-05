#pragma once
class KDocument;
class KView {
private:
	KDocument* m_pDocument; //도큐먼트참조
	
	//display할 데이터 고르기
	int m_iStart;
	int m_iDisplayStart;
	int m_iSelected;

public:
	KView(KDocument* pDoc);
	virtual ~KView();

	void SetDocument(KDocument* pDoc); //도큐먼트 주소를 받아서 세팅
	KDocument* GetDocument(); //도큐먼트 부르기
	void SetDisplayStart(int iStart); //display할 데이터 세팅
	void SetSelected(int iSelected); //데이터 고르기
	virtual void Draw();
};