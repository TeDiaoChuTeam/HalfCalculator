// SEQUENCE_QUEUE.h: interface for the SEQUENCE_QUEUE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCE_QUEUE_H__6DD8A2C7_2D89_4504_A8F4_D754934BC888__INCLUDED_)
#define AFX_SEQUENCE_QUEUE_H__6DD8A2C7_2D89_4504_A8F4_D754934BC888__INCLUDED_

#include "my.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SEQUENCE_QUEUE  
{
public:
	void Change(CString &pobj, double v,int obj_redix);
	void Init();
	SEQUENCE_QUEUE();
	virtual ~SEQUENCE_QUEUE();

private:
	void OutQueue(ELEMTYPE *pe);
	void InQueue(ELEMTYPE *pe);
	bool TestEmpty();
	bool TestFull();
	ELEMTYPE queue[MAXSIZE];		//队缓存
	int	front,rear;					//队首、队尾指针
};

#endif // !defined(AFX_SEQUENCE_QUEUE_H__6DD8A2C7_2D89_4504_A8F4_D754934BC888__INCLUDED_)
