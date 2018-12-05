#pragma once

//#if !defined(_KListBox_Defined_)
//#define _KListBox_Defined_
//
//#if _MSC_VER >1000
//#endif
//
//#include <vector>
//template<typename T>
//class KListBox {
//public:
//	typedef std::vector<T>	VTYPE;
//	typedef typename VTYPE::iterator	 VITOR;
//
//	VTYPE m_vector;
//	int m_iSelectedItem;
//	int m_iStartIndex;
//	int m_numItemToDisplay;
//
//public:
//	KListBox() {
//		m_iSelectedItem = 0;
//		m_iStartIndex = 0;
//		m_numItemToDisplay = 9;
//	}
//
//	virtual ~KListBox() { Clear(); }
//
//	VITOR Begin() { return m_vector.begin(); }
//	VITOR End() { return m_vector.end(); }
//
//	void Clear() {
//		PreClear();
//		m_vector.clear();
//		PostClear();
//	}
//
//	virtual void PreClear() {}
//	virtual void PostClear() {}
//
//	void Insert(T item) { m_vector.push_back(item); }
//
//	void Insert(VITOR itor, T item) { m_vector.insert(itor, item); }
//
//	T& At(int index) { return m_vector[index]; }
//
//	T& operator[](int index) { return m_vector[index]; }
//
//	VITOR RindByValue(T item) {
//		for (VITOR itor = m_vector.begin(); itor != m_vector.end(); ++itor) {
//			if (item == (*itor)) return itor;
//			return NULL;
//		}
//	}
//
//	bool EraseByValue(T item) {
//		VITOR itor = FindByValue(item);
//		if (itor) m_vector.erase(itor);
//		
//		return itor != NULL;
//	}
//
//	bool EraseByIndex(int iItem) {
//		int index = 0;
//		for (VITOR itor = m_vector.begin(); itor != m_vector.end(); ++itor) {
//			if (index == iItem) { Erase(itor); return true; }
//		}
//		return false;
//	}
//
//	void Erase(VITOR itor) {
//		m_vector.erase(itor);
//	}
//
//	void Erase(VITOR itorBegin, VITOR itorEnd) { m_vector.erase(itorBegin, itorEnd); }
//
//	bool IsEmpty() { return m_vector.empty(); }
//
//	int GetSize() { return m_vector.size(); }
//
//	void Reserve(int size) { m_vector.reserve(size); }
//
//public:
//
//	void SetSelected(int iItem) { m_iSelectedItem = iItem; }
//
//	int GetSeleted() { return m_iSelectedItem; }
//
//	bool IsSelected(int iSelected) { return m_iSelectedItem == iSelected; }
//
//	int SetDisplayStart(int iIndex) {
//		m_iStartIndex = iIndex;
//		retuern m_iStartIndex;
//	}
//
//	int GetDisplayStart() { return m_iStartIndex; }
//
//	void SetNumDisplay(int iSize) { m_numItemToDisplay = iSize + 1; }
//
//	int GetNumDisplay() { return m_numItemToDisplay - 1; }
//
//	VITOR BeginDisplay() {
//		if (m_iStartIndex >= Getsize()) return m_vector.end();
//		return m_vector.begin() + m_iStartIndex;
//	}
//
//	VITOR EndDisplay() {
//		int endIndex = m_iStartIndex + m_numItemToDisplay - 1;
//		if (endIndex >= GetSize()) return m_vector.end();
//		return m_vector.begin() + endIndex;
//	}
//};
//#endif

#if  !defined(_KListBox_Defiend)
#define _KListBox_Defined

#if _MSC_VER >1000
#pragma once
#endif // _MSC_VER>1000

#include <vector>
//KListBox가 vector class를 포함하고있는 형태이므로 have-a관계
//view역할을 하는것과 data는 별개의 것으로 본다.
template<class T>
class KListBox { //view 역할을 한다.
public:
	typedef std::vector<T>   VTYPE;
	typedef typename VTYPE::iterator VITOR;
	VTYPE m_vector; //have-a  aggregation
	int m_iSelectedItem;
	int m_iStartIndex;
	int m_numItemToDisplay;
public:
	KListBox() {
		m_iSelectedItem = 0;
		m_iStartIndex = 0;
		m_numItemToDisplay = 9;
	}
	virtual ~KListBox() { Clear(); }

	VITOR Begin() { return m_vector.begin(); }
	//VITOR RBegin() { return m_vector.rbegin(); }
	//VITOR REnd() { return m_vector.rend(); }
	VITOR End() { return m_vector.end(); }

	void Reverse() { std::reverse(m_vector.begin(), m_vector.end()); }

	void Clear() {
		PreClear();
		m_vector.clear();
		PostClear();
	}
	void PreClear() {}
	void PostClear() {}
	void Insert(T item) {
		m_vector.push_back(item);
	}
	void Insert(VITOR itor, T item) {
		m_vector.insert(itor, item);
	}

	T& At(int index) {
		return m_vector[index];
	}
	T& operator[](int index) {
		return  m_vector[index];
	}
	VITOR FindByteValue(T item) {
		for (VITOR itor = m_vector.begin(); itor != m_vector.end(); ++itor) {
			if (item == (*itor))return itor;
		}
	}
	bool EraseByValue(T item) {
		VITOR itor = FindByValue(item);
		if (itor) m_vector.erase(itor);
		return itor != NULL;
	}
	bool EreaseByIndex(int iItem) {
		int index = 0;
		for (VITOR itor = m_vector.begin(); itor != m_vector.end(); ++itor) {
			if (index == iItem) {
				Erase(itor);
				return true;
			}

		}
		return false;
	}
	void Erase(VITOR itor) {
		m_vector.erase(itor);
	}
	void Erase(VITOR itorBegin, VITOR itorEnd) {
		m_vector.erase(itorBegin, itorEnd);
	}
	bool IsEmpty() {
		return m_vector.empty();
	}

	int GetSize() {
		return m_vector.size();
	}
	void Reserve(int size) {
		m_vector.reserve(size);
	}
public:
	void SetSelected(int iItem) {
		m_iSelectedItem = iItem;
	}
	int GetSelected() {
		return m_iSelectedItem;
	}
	bool IsSelected(int iSelected) {
		return m_iSelectedItem == iSelected;
	}
	int SetDisplayStart(int iIndex) {
		m_iStartIndex = iIndex;
		return m_iStartIndex;
	}
	int GetDisplayStart() {
		return m_iStartIndex;
	}
	void SetNumDisplay(int iSize) {
		m_numItemToDisplay = iSize + 1;
	}
	int GetNumDisplay() {
		return m_numItemToDisplay - 1;
	}
	VITOR BeginDisplay() {
		if (m_iStartIndex >= GetSize()) return m_vector.end();
		return m_vector.begin() + m_iStartIndex;
	}
	VITOR EndDisplay() {
		int endIndex = m_iStartIndex + m_numItemToDisplay - 1;
		if (endIndex >= GetSize()) return  m_vector.end();
		return m_vector.begin() + endIndex;
	}
};
#endif
