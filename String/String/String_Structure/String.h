/*******************************************************************************
 * File name        : String.h
 * Description      : Define the string structure.
 * Creator          : XU ZAN
 * Creation date    : Thu.  Nov. 27, 2014
 * Copyright(C)     2014    All rights reserved.
 * 
 *******************************************************************************/

#ifndef STRING_H
#define	STRING_H

    #include "../general.h"

    #ifdef	__cplusplus
    extern "C" 
    {
    #endif
        /* 串的堆分配存儲表示
         */
        typedef struct HString
        {
            char *ch;       // 若串是非空串，則按串長分配存儲區, 否則ch為NULL.
            int length;     // 串長度
        }
        HString, *PtrHString;
        
        /* 基本操作的函數原型說明 
         */
        Status StrAssign(HString *T, char *chars);
        int StrLength(HString S);
        int StrCompare(HString S, HString T);
        Status ClearString(HString *S);
        Status Concat(HString *T, HString S1, HString S2);
        Status SubString(HString *sub, HString S, int pos, int len);
        Status StrInsert(HString *S, int pos, HString T);
        
        
    #ifdef	__cplusplus
    }
    #endif

#endif	/* STRING_H */

