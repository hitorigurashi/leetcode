Given an integer n, return the number of trailing zeroes in n!.

Example 1:
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
    
Example 2:
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.

#统计 n！该数字的尾部有多少个0
/*
这一题肯定是解决大数问题，统计大数后面的0的个数，如果做的太耿直了，就无法计算了
但是即便是我优化了一点点，还是无法计算
优化思路，每次

计算n！
    判断该数%10是否==0
        cnt++
        while（该数%10==0）
            cnt++
    除于不等于0
        只保留这个数字的最后一位进行计算（优化步骤，防止大数越界）


即便是这样计算，在1000！的时候还是出错了
*/
    
/*
下面这种思路是：
0的产生是 2*5=10
统计n以内 2*5的对数就可以计算出0的个数
在n以内，2的个数远多于5（2*2=4、2*3=6）
所以只用统计5的个数即可

例如20！尾部有多少0？
20/5=4
答案：4个0

25！尾部有多少个0？
25/5=5
答案：5个0
错误！
因为25 = 5 * 5
所以5的个数为 25/5 + 25/5/5 = 6
*/
    
#递归
class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5)
            return 0;
        return n/5 + trailingZeroes(n/5);
    }
};

#循环
class Solution{
public:
    int trailingZeroes(int n){
        int res = 0;
        while(n != 0)
        {
            res += n/5;
            n /= 5;
        }
        return res;
    }
}
