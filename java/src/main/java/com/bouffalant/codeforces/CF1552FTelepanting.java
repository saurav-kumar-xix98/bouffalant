package com.bouffalant.codeforces;

import com.bouffalant.Util;

import java.util.ArrayList;
import java.util.List;

public class CF1552FTelepanting {
    public static int telepanting(List<Integer> src, List<Integer> des, List<Boolean> state) {
        final int divisor = 998244353;
        List<Long> prefixSum = new ArrayList<>();
        prefixSum.add(0L);
        long ans = Util.modulus(src.getLast() + 1, divisor);

        for (int i = 0; i < src.size(); ++i) {
            int index = Util.lowerBound(src, 0, i, des.get(i));

            long cost = Util.modulus(src.get(i) - des.get(i) + prefixSum.get(i) - prefixSum.get(index), divisor);
            prefixSum.add((long) Util.modulus(prefixSum.getLast() + cost, divisor));

            if (state.get(i)) {
                ans = Util.modulus(ans + cost, divisor);
            }
        }

        return (int)ans;
    }
}
