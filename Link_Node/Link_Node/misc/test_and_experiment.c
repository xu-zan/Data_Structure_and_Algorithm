/***********************************************************************************
 * File name		: test_and_experiment.c
 * Description		: Do some experiments here to verify / test  some programming issue.
 * Creator			: XU ZAN
 * Creation date	: Wed.	Oct. 29, 2014
 * Copyright(C)		2014	All rights reserved.
 ***********************************************************************************/

#include "test_and_experiment.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reference_Output_Double_Array(int n, double **dArray)
{
	float k = 0.618, b = 3.14159, fTemp = 0.00f;
	int i = 0;

	double *dValue = (double *)malloc(sizeof(double)*n);
	// dArray = (double *)malloc(sizeof(double)*n);
	double *dArray2 = (double *)calloc(n, sizeof(double));
	*dArray = dArray2;

	for (i=1; i<=n; i++)
	{
		fTemp = k*i + b;
		dValue[i-1] = fTemp;
		memcpy(dArray2+i-1, dValue+i-1, sizeof(double));
	}
	free(dValue);
	dValue = NULL;
	// free(dArray2);
	// dArray2 = NULL;
	return;
}

void Test_ReferenceOutputDoubleArray(void)
{
	double *dMyArray = NULL;
	int i = 0, n;

	printf("Please enter the number : n = ");
	scanf("%d", &n);
	Reference_Output_Double_Array(n, &dMyArray);

	for (i=0; i<n; i++)
	{
		printf("MyArray[%d] = %.04f\n", i, *(dMyArray+i));
	}
	free(dMyArray);
	dMyArray = NULL;
	return;
}


/*


 ANSI C说明了三个用于存储空间动态分配的函数
(1) malloc   分配指定字节数的存储区。此存储区中的初始值不确定
(2) calloc   为指定长度的对象，分配能容纳其指定个数的存储空间。该空间中的每一位(bit)都初始化为0
(3) realloc  更改以前分配区的长度(增加或减少)。当增加长度时，可能需将以前分配区的内容移到另一个足够大的区域，而新增区域内的初始值则不确定
 
.分配函数时再分配 realloc()    
    使我们可以增、减以前分配区的长度(最常见的用法是增加该区)。
 
    如果先分配一个可容纳长度为512的数组的空间，并在运行时填充它，但又发现空间不够，则可调用realloc扩充该存储空间。
 
    如果在该存储区后有足够的空间可供扩充，则可在原存储区位置上向高地址方向扩充，并返回传送给它的同样的指针值。
 
    如果在原存储区后没有足够的空间，则realloc分配另一个足够大的存储区，将现存的5 1 2个元素数组的内容复制到新分配的存储区。
 
    因为这种存储区可能会移动位置，所以不应当使用任何指针指在该区中。
 
    注意，realloc的最后一个参数是存储区的newsize(新长度)，不是新、旧长度之差。作为一个特例，若ptr是一个空指针，则realloc的
	
	功能与malloc相同，用于分配一个指定长度newsize的存储区。
 
    这些分配例程通常通过sbrk(2)系统调用实现。该系统调用扩充(或缩小)进程的堆。虽然sbrk可以扩充或缩小一个进程的存储空间，但是
	
	大多数 malloc和free的实现都不减小进程的存储空间。释放的空间可供以后再分配，但将它们保持在malloc池中而不返回给内核。
 
    应当注意的是，大多数实现所分配的存储空间比所要求的要稍大一些，额外的空间用来记录管理信息——分配块的长度，指向下一个分配块的指针
	
	等等。这就意味着 如果写过一个已分配区的尾端，则会改写后一块的管理信息。这种类型的错误是灾难性的，但是因为这种错误不会很快就暴露出来，所以也就很难发现。
 
    将指向分配块的指针向后移动也可能会改写本块的管理信息。其他可能产生的致命性的错误是：释放一个已经释放了的块；调用free时所用的指针不
	
	是三个 alloc函数的返回值等。因为存储器分配出错很难跟踪，所以某些系统提供了这些函数的另一种实现方法。每次调用这三个分配函数中的任意一个或free时 都进行
	
	附加的出错检验。在调用连接编辑程序时指定一个专用库，则在程序中就可使用这种版本的函数。	此外还有公共可用的资源（例如由4.3+BSD所提供 的），在对其
	
	进行编译时使用一个特殊标志就会使附加的运行时间检查生效。
 
    因为存储空间分配程序的操作对某些应用程序的运行时间性能非常重要，所以某些系统提供了附加能力。例如，SVR4提供了名为mallopt的函数，它使
	
	进程可以设置一些变量，并用它们来控制存储空间分配程序的操作。还可使用另一个名为mallinfo的函数，以对存储空间分配程序
	
	的操作进行统计。请查看所 使用系统的malloc(3)手册页，弄清楚这些功能是否可用。
 
.alloca函数
   还有一个函数也值得一提，这就是alloca。其调用序列与malloc相同，但是它是在当前函数的栈帧上分配存储空间，而不是
   
   在堆中。其优点是：当 函数返回时，自动释放它所使用的栈帧，所以不必再为释放空间而费心。其缺点是：某些系统在函数已被调用后不
   
   能增加栈帧长度，于是也就不能支持alloca 函数。尽管如此，很多软件包还是使用alloca函数，也有很多系统支持它。


 */


void Test_Self_Increment_Decrement(void)
{
	int iAdd = 0, iDeduct = 10;

	printf("The original add number : iAdd = %d\n", iAdd);
	iAdd++;
	printf("After self-increment : iAdd++ = %d\n", iAdd);
	iAdd = 0;
	printf("Restore to origianl add number : iAdd = %d\n", iAdd);
	++iAdd;
	printf("After self-increment : ++iAdd = %d\n", iAdd);

	printf("\n\n\n");

	printf("The original deduct number : iDeduct = %d\n", iDeduct);
	// iDeduct_Result = iDeduct--;
	printf("After self-decrement : iDeduct-- = %d\n", iDeduct--);
	iDeduct = 10;
	printf("Restore to original deduct number : iDeduct = %d\n", iDeduct);
	// iDeduct_Result = --iDeduct;
	printf("After self-decrement : --iDeduct = %d\n", --iDeduct);

	printf("\n\n\n");
	return;

}
