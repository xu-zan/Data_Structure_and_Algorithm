/*******************************************************************************
 * File name        : String.c
 * Description      : Implement the algorithm of string structure.
 * Creator          : XU ZAN
 * Creation date    : Thu.  Nov. 27, 2014
 * Copyright(C)     2014    All rights reserved.
 * 
 *******************************************************************************/

#include "String.h"
#include "../general.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 基本操作的算法描述
 */

int SStrLength(SString S)
{
	int iLen = 0, n = 0;
	for (n=0; n<=MAXSTRLEN; n++)
	{
		if (S[n] == '\0')
		{
			break;
		}
		iLen++;
	}
	return iLen;
}

Status SStrConcat(SString *T, SString S1, SString S2)
/* 用T返回由S1和S2联结而成的新串。
* 若未截断，则返回True, 否则就返回False.
*/
{
	Status uncnt = TRUE;
	int iLen_S1 = SStrLength(S1), iLen_S2 = SStrLength(S2);
	
	SString sTarget = {0};
	
	if (iLen_S1+iLen_S2 <= MAXSTRLEN)
	{
		strcat(sTarget, S1);
		strcat(sTarget, S2);
		uncnt = TRUE;
	}
	else if ((iLen_S1<MAXSTRLEN) && (iLen_S1+iLen_S2>MAXSTRLEN))
	{
		strcat(sTarget, S1);
		strncat(sTarget, S2, MAXSTRLEN-iLen_S1);
		uncnt = FALSE;
	}
	else
	{
		strncat(sTarget, S1, MAXSTRLEN);
		uncnt = FALSE;
	}
	memcpy(T, sTarget, SStrLength(sTarget));
	return uncnt;
}

Status SubSString(SString *Sub, SString S, int pos, int len)
/* 用Sub返回串S的第pos个字符起长度为len的子串。
 * 其中：1<=pos<=SStrLength(S)
 *      且0<=len<=SStrLength(S)-pos+1
 */
{
	SString sTarget = {0};
	int iLen = SStrLength(S);
	if ( (pos<1) || (pos<iLen) ||
		 (len<0) || (len>iLen-pos+1) )
	{
		return ERROR;
	}
	strncpy(sTarget, S+pos, len);
	memcpy(Sub, sTarget, SStrLength(sTarget));
	return OK;
}

Status StrAssign(HString *T, char *chars)
/* 生成一個其值等於串常量chars的串T
 */
{
    unsigned int len = strlen(chars);
    if (T->ch)
        free(T->ch);    // 釋放T原有的空間
    T->ch = (char *)calloc(len+1, sizeof(char));
    if (NULL == T->ch)
    {
        printf("Heap memory is overflow.");
        return OVERFLOW;
    }
    strcpy(T->ch, chars);
    T->length = len;
    return OK;
}

/*=============================================================================*/
int StrLength(HString S)
/* 返回S的元素個數，稱為串的長度.
 */
{
    unsigned int iLen = 0;
    iLen = strlen(S.ch);
    if (iLen != S.length)
    {
        printf("The length of this string is wrong.");
    }    
    return iLen;
}

int StrCompare(HString S, HString T)
/* 比較兩個字符串， 若S>T，則返回值>0;
 * 若S=T，則返回值＝0； 若S<T，則返回值<0
 */
{
    int i = 0;
    for (i=0; ((i<S.length) && (i<T.length)); i++)
    {
        if (S.ch[i] != T.ch[i])
        {
            return (S.ch[i]-T.ch[i]);
        }
    }
    return (S.length-T.length);
}

Status ClearString(HString *S)
/* 將S清為空串
 */
{
    if (S->ch != NULL)
    {
        free(S->ch);
        S->ch = NULL;
    }
    S->length = 0;
    return OK;
}

Status Concat(HString *T, HString S1, HString S2)
/* 由T返回S1和S2聯接而成的新串
 */
{
    if (T->ch != NULL)
    {
        free(T->ch);        // 釋放原來舊的空間
        T->length = 0;
    }
    T->ch = (char *)calloc(S1.length+S2.length, sizeof(char));
    if (T->ch == NULL)
        return OVERFLOW;
	strcat(T->ch, S1.ch);
	strcat(T->ch, S2.ch);
	T->length = S1.length + S2.length;
    return OK;
}

Status SubString(HString *sub, HString S, int pos, int len)
/* 用sub返回串S的第pos個字符起，長度為len的子串。
 * 其中, 1<=pos<=StrLength(S)且0<=StrLength(S)-pos+1
 */
{
    if ( (pos<1) ||
         (pos>S.length) || 
         (len<0) ||
         (len>S.length-pos+1) )
    {
        return ERROR;
    }
    if (sub->ch)
    {
        free(sub->ch);      // 清空舊的空間
        sub->length = 0;
    }
    if (!len)   // 空子串
    {
        sub->ch = NULL;
        sub->length = 0;
    }
    else        // 完整子串
    {
        sub->ch = (char *)calloc(len+1, sizeof(char));
        if (sub->ch == NULL)
            return OVERFLOW;
        strncpy(sub->ch, S.ch+pos, len);
		sub->length = len;
    }
	return OK;
}

Status StrInsert(HString *S, int pos, HString T)
/* 在串S的第pos個字符之前插入串T
 * 1<=pos<=StrLength(S)+1
 */
{
    HString oldStr = *S;
	char *sTemp = NULL;
	
    int iLen = StrLength(oldStr), iTotalLen = 0;
    if ( (pos<1) || (pos>iLen+1) )	// pos不合法
    {
        return ERROR;
    }
	if (T.length)
	{
		iTotalLen = StrLength(oldStr)+StrLength(T)+1;
		sTemp = (char *)calloc(iTotalLen, sizeof(char));
		
		strncpy(sTemp, oldStr.ch, pos);
		strcat(sTemp, T.ch);
		strcat(sTemp, oldStr.ch+pos);
		
		S->ch = (char *)realloc(S->ch, iTotalLen);
		strcpy(S->ch, sTemp);
		S->length = iTotalLen-1;
		
		free(sTemp);
	}
    return OK;
}



/* 
 * END OF FILE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */

