package com.bouffalant;

import java.util.List;

public class Util {
    public static int modulus(long val, int divisor) {
        val %= divisor;
        if (val < 0) {
            val += divisor;
        }
        return (int)val;
    }

    public static int lowerBound(List<Integer> arr, int firstIndex, int lastIndex, int value) {
        while (firstIndex < lastIndex) {
            int midIndex = (firstIndex + lastIndex) / 2;
            if (arr.get(midIndex) < value) {
                firstIndex = midIndex + 1;
            } else {
                lastIndex = midIndex;
            }
        }
        return firstIndex;
    }
}
