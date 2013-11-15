/********************************************************************************************
 * File name	: Abstract_Data_Type.h
 * Description	: To describe the ADT, expression approach.
 * Creator		: XU ZAN
 * Creation date: Fri.	Nov. 15, 2013
 * Copyright(C)		2013	All rights reserved.
 *
 ********************************************************************************************/

#ifndef ABSTRACT_DATA_TYPE_H
#define ABSTRACT_DATA_TYPE_H

	#define ADT struct

	/*
	 * 抽象數據類型的表示 :
	 * 
	 *	ADT 抽象數據類型名
	 *	{
			數據對象 : <數據對象的定義>
			數據關係 : <數據關係的定義>
			基本操作 : <基本操作的定義>
	 *	} ADT 抽象數據類型名
	 *	基本操作名(參數表)
	 *		初始條件:<初始條件描述>
	 *		操作結果:<操作結果描述>
	 */

	/*
	typedef ADT Triplet
	{
		数据对象:D={e1, e2, e3(定义了关系运算的某个集合)}
		數據關係:R1={<e1, e2>, <e2, e3>}
		基本操作:
			InitTriplet(&T, v1, v2, v3);
			操作結果：構造了一個三元組T,元素e1, e2, e3分別被賦以參數v1, v2, v3的值.
			
			DestroyTriplet(&T);
			操作結果:三元組T被銷毀.
			
			Get(T, i, &e);
			初始條件:三元組T已存在,1<=i<=3
			操作結果:用e返回T的第i元的值
			
			Put(&T, i, e);
			初始條件:三元組T已存在,1<=i<=3
			操作結果:改變T的第i元的值為e

			IsAscending(T);
			初始條件:三元組T已存在
			操作結果:如果T的3個元素按照升序排列,則返回1, 否則返回0

			IsDescending(T);
			Max(T, &e);
			Min(T, &e);
	}
	Triplet;
	 */

#endif	/*  ABSTRACT_DATA_TYPE_H  */