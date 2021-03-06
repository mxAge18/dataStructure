#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * 递归的作用
 * 1）替代多重循环
 * 2）解决本来就是用递归形式定义的问题
 * 3）将问题分解为规模更小的子问题进行求解
 *
*/

/**
 *  汉诺塔问题(Hanoi)
 * 古代有一个梵塔，塔内有三个座A、B、C，A座上有64个盘子，盘子大小不等，
 * 大的在下，小的在上。
 * 有一个和尚想把这64个盘子从A座移到C座，但每次只能允许移动一个盘子，并且在移动过程中，
 * 3个座上的盘子始终保持大盘在下，小盘在上。在移动过程中可以利用B座，要求输出移动的步骤。
 * 1) 先把N - 1个盘子移动到B，然后再把第N个移动到C；
 * 2）把 N - 2 移动到 A , N - 1移动到C
 * ...
*/
void Hanoi();

/**
 * 输入一个正整数N，则程序输出N皇后问题的全部摆法。
 * 输出结果里的每一行都代表一种摆法。行里的第i个数字如 果是n，就代表第i行的皇后应该放在第n列。
 * 皇后的行、列编号都是从1开始算。
 * */
void NQueen();


/**
 * 前缀表达式求值
*/
double Exp();




/** 表达式求值
 * 输入一个表达式，对表达式进行求值
 * 分解：表达式分解为项和因子，表达式是由多个项进行加减得到，项是因子间乘除得到
 * so 需要写一个求项的值的函数
 *         一个求因子的值的函数
 *         一个求表达式的值的函数
 * 
 * 
 * */

void ExperessionVal();
int exp_val();

/**
 * 爬楼梯
*/
void Stairs();


/**
 * m个苹果放n个盘子里
*/
void SetApple();

/**
 * 计算24
*/

void Caculate24();