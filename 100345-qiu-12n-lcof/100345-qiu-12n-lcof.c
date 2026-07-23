int mechanicalAccumulator(int target) {
    int sum = 0;
    target && (sum = target + mechanicalAccumulator(target - 1));//利用短路，有0元素后结果为0
    return sum;
}