int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0;
    }
    int min_p[pricesSize];
    int max_p[pricesSize];
    int minn = INT_MAX;
    int maxx = -1;
    for(int i = 0;i<pricesSize;i++) {
        if(minn > prices[i])minn = prices[i];
        min_p[i] = minn;
        if(maxx < prices[pricesSize-i-1])maxx = prices[pricesSize-i-1];
        max_p[pricesSize-i-1] = maxx;
    }
    int earn = 0;
    for(int i = 0;i<pricesSize;i++) {
        if (max_p[i] - min_p[i] > earn)earn = max_p[i]-min_p[i];
    }
    if(earn>0)return earn;
    return 0;

}