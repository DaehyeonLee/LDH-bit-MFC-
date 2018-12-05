#include "KDocument.h"

KDocument::KDocument() { m_pView = NULL; }
KDocument::~KDocument() { m_kListBox.Clear(); }
void KDocument::Insert(int iData) { m_kListBox.Insert(iData); }

void KDocument::SetView(KView* pView) { m_pView = pView; }

KView* KDocument::GetView() {
	return m_pView;
}

KListBox<int>* KDocument::GetListBox() { return &m_kListBox; }