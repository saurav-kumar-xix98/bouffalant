package com.bouffalant.leetcode;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class LC0843GuessTheWordTest {
    @Test
    void testcase1() {
        String secret = "acckzz";
        String[] words = {"acckzz","ccbazz","eiowzz","abcczz"};
        int allowedGuesses = 10;
        LC0843GuessTheWord.Master master = new LC0843GuessTheWord.Master(secret, words, allowedGuesses);
        LC0843GuessTheWord.findSecretWord(words, master);
        assertTrue(master.isGuessed());
    }

    @Test
    void testcase2() {
        String secret = "hamada";
        String[] words = {"hamada","khaled"};
        int allowedGuesses = 10;
        LC0843GuessTheWord.Master master = new LC0843GuessTheWord.Master(secret, words, allowedGuesses);
        LC0843GuessTheWord.findSecretWord(words, master);
        assertTrue(master.isGuessed());
    }
}
