package com.bouffalant.codeforces;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class CF1552FTelepantingTest {
    @Test
    void testcase1() {
        List<Integer> src = List.of(3, 6, 7, 8);
        List<Integer> des = List.of( 2, 5, 4, 1 );
        List<Boolean> state = List.of( false, true, false, true );
        assertEquals(23, CF1552FTelepanting.telepanting(src, des, state));
    }

    @Test
    void testcase2() {
        List<Integer> src = List.of(454971987);
        List<Integer> des = List.of( 406874902 );
        List<Boolean> state = List.of( true );
        assertEquals(503069073, CF1552FTelepanting.telepanting(src, des, state));
    }

    @Test
    void testcase3() {
        List<Integer> src = List.of(243385510, 644426565, 708622105, 786625660, 899754846);
        List<Integer> des = List.of( 42245605, 574769163, 208990040, 616437691, 382774619 );
        List<Boolean> state = List.of( false, false, false, false, false );
        assertEquals(899754847, CF1552FTelepanting.telepanting(src, des, state));
    }

    @Test
    void testcase4() {
        List<Integer> src = List.of(200000000, 600000000, 800000000, 900000000, 1000000000);
        List<Integer> des = List.of( 100000000, 400000000, 300000000, 700000000, 500000000 );
        List<Boolean> state = List.of( true, false, false, true, false );
        assertEquals(3511295, CF1552FTelepanting.telepanting(src, des, state));
    }
}
