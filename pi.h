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
 * ��0001-01-01��9999-12-31ÿ��������piС�������״γ��ֵ�λ��
 * λ�ô�1��ʼ����������14159265��Ӧ��λ��Ϊ1
 * �������ÿһ�궼Ϊ���꣬��ÿһ�궼��366��
 * ���������СΪ: 9999*366
 *
 * ��Ч���ڵ�λ����Ϊ0
 */
extern const unsigned int indexes_in_pi[];

// ÿ���µ�������������2�°�29�����
extern const unsigned int days_of_month[];

// ǰn���µ�������������2�°�29�����
extern const unsigned int all_days_of_month[];

#endif // _PI_H_
