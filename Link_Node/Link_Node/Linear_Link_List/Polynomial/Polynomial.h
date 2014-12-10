/*************************************************************************************
 * File name		: Polynomial.h
 * Description		: 研究一元n次多项式的算法实现.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Dec. 09, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *************************************************************************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

	#include "../Link_Node.h"


	typedef struct		// 多项式的项的表示, 多项式的项多为LinkList的数据元素
	{
		float coef;		// 系数
		int expn;		// 指数
	}
	term,				// term用于本抽象数据类型ADT
	ElementType;		// ElementType为LinkList的数据对象名.

	typedef LinkList Polynomial;	// 用带表头结点的有序链表表示多项式.

	/* 基本操作的函数原型声明
	 */
	void CreatePolyn(Polynomial *P, int m);
	void DestroyPolyn(Polynomial *P);
	void PrintPolyn(Polynomial P);
	int PolynLength(Polynomial P);
	void AddPolyn(Polynomial *Pa, Polynomial *Pb);
	void SubstractPolyn(Polynomial *Pa, Polynomial *Pb);
	void MultiplyPolyn(Polynomial *Pa, Polynomial *Pb);


#endif	/*  POLYNOMIAL_H  */