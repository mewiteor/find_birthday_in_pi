/*
 * MIT License
 * 
 * Copyright (c) 2021 mewiteor
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _PI_H_
#define _PI_H_

/*
 * 从0001-01-01到9999-12-31每个日期在pi小数点后的首次出现的位置
 * 位置从1开始计数，比如14159265对应的位置为1
 * 这里假设每一年都为闰年，即每一年都是366天
 * 所以数组大小为: 9999*366
 *
 * 无效日期的位置设为0
 */
extern const unsigned int indexes_in_pi[];

// 每个月的日期数，其中2月按29天计算
extern const unsigned int days_of_month[];

// 前n个月的日期数，其中2月按29天计算
extern const unsigned int all_days_of_month[];

#endif // _PI_H_
