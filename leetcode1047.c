char *removeDuplicates(char *s) {
    int top = 0;                        /* 栈里几个元素，也是下一个写入位置 */
    for (int i = 0; s[i] != '\0'; i++) {   /*i遍历整个字符串*/ 
        if (top > 0 && s[top - 1] == s[i])/*比较top位和i位上*/ 
            top--;                      /* 和栈顶相同 → 弹栈 */
        else
            s[top++] = s[i];            /* 否则压栈 ,同时覆盖那个位置上的内容，不用的另外删除动作*/
    }
    s[top] = '\0';                      /* 栈内容就是答案，补结束符 */
    return s;
}

