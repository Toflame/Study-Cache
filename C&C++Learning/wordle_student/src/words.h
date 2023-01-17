#pragma once

#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <random>       
#include <chrono>
using namespace std;
#define lenFINAL 2315
#define lenACC 12972


class WordSet {
public:

    WordSet() {
        ifstream FINAL_FILE; 
        FINAL_FILE.open("./src/FINAL.txt", ifstream::in);
        while(!FINAL_FILE.eof()) {
            string str;
            FINAL_FILE >> str;
            final_set.insert(str);
        } 
        
        ifstream ACCEPTABLE_FILE;
        ACCEPTABLE_FILE.open("./src/ACC.txt", ifstream::in);
        while(!ACCEPTABLE_FILE.eof()) {
            string str;
            ACCEPTABLE_FILE >> str;
            acceptable_set.insert(str);
        }

        for(auto word : final_set) {
            answers.push_back(word);
        }

        // seed = 9324;

        // TODO: task2
        // 在初始化时打乱 answers ，方便后续每轮生成一个答案。
        // hint 可以使用 shuffle 函数对 answers 进行随机重排
        // 可以参考：https://cplusplus.com/reference/algorithm/shuffle/

        /*The next two lines of code was adapted from the c++ documents here:
        https://cplusplus.com/reference/algorithm/shuffle/
         */
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle (answers.begin(), answers.end(), default_random_engine(seed));

    }

    string get_random_answer() {
        //TODO: task2
        //TODO: task2
        // 下方代码固定返回第一个单词作为答案，需要改为随机抽取。
        size_t num;
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        
        num = rand()%lenFINAL;//生成在范围内的随机数

        return answers[num];
        // return answers[0];
    }

    set<string> final_set;
    set<string> acceptable_set;
    vector<string> answers;
    unsigned seed;
};