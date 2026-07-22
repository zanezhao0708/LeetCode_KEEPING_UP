char* removeDuplicates(char* s) {
    int n = strlen(s);//获取字符串长度
    if(n == 0)return "";
    if(n == 1)return s;

    int top = 0;//此时top永远指向下一个入栈道的位置（是空的）
    //由于这种设置比较时利用top-1进行比较
    
    char* stack =(char*)malloc(sizeof(char) * (n+1));//给'\0'留空间
    for (int i = 0; i < n; i++) {
        if (top != 0 && s[i] == stack[top-1]) { // 当前遍历到的元素与刚刚入栈元素相同进行删除
        
            top--;
            }
        else{
                stack[top++] = s[i];
            }
        }
    
    stack[top]='\0';//字符串结束符
    return stack;
}