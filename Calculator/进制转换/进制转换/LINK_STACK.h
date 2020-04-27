// LINK_STACK.h: interface for the LINK_STACK class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINK_STACK_H__9116166E_A584_4DB0_8227_B3613CD849E5__INCLUDED_)
#define AFX_LINK_STACK_H__9116166E_A584_4DB0_8227_B3613CD849E5__INCLUDED_

#include "my.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class LINK_STACK  
{
public:
	void Change(CString &pobj,int val,int obj_redix);
	bool Pop(ELEMTYPE *pe);
	void Push(ELEMTYPE *pe);
	void Init();
	LINK_STACK();
	virtual ~LINK_STACK();

private:
	void IntToStringPush(int n,int redix);
	bool Empty();
	NODE h;
};

#endif // !defined(AFX_LINK_STACK_H__9116166E_A584_4DB0_8227_B3613CD849E5__INCLUDED_)
