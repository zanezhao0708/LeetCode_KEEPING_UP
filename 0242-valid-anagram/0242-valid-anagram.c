void sort(char *s,int left,int right){
    if(left >= right)return;

    char pviot = s[left];
    int i = left;
    int j = right;
    while(i < j){
        while(i < j && pviot <= s[j])j--;
        while(i < j && pviot >= s[i])i++;
        if(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }

    }
    s[left] = s[i];
    s[i] = pviot;

    sort(s,left,i-1);
    sort(s,i+1,right);
}

bool isAnagram(char* s, char* t) {
    int sl = strlen(s);//求长度
    int tl = strlen(t);
    if(sl != tl)return 0;
    sort(s,0,sl-1);
    sort(t,0,tl-1);
    for(int i = 0;i<sl;i++){
        if(s[i] != t[i])return 0;
    }
    return 1;
}