//题目一：一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶，求该青蛙跳上一个n级台阶共有多少种跳法？ 
int jumpFloorI(int n)
{
    if (n <= 0)
        return -1;

    if (1 == n)
        return 1;
    else if (2 == n)
        return 2;
    else
    {
        return jumpFloorI(n - 1) + jumpFloorI(n - 2);
    }
}

//题目二：一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶，还可以跳上3级台阶，求该青蛙跳上一个n级台阶共有多少种跳法？
int jumpFloorII(int number) {
        if (number <= 0)
            return -1;
        if (number == 1)
            return 1;
        return 2 * jumpFloorII(number - 1);
    }