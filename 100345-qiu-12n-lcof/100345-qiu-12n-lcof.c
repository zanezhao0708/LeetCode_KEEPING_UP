int mechanicalAccumulator(int target) {
    if(target == 1) return 1;
    return target +mechanicalAccumulator(target - 1);
}