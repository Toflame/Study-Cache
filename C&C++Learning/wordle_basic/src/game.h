#pragma once

#include <cctype>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define WORDLEN 5//使用宏定义一个单词长度5
#define MAXGUESSTIME 6//使用宏定义最大的猜测次数
char Captalize_ch(char ch){return toupper(ch);}
string Captalize_str(string s){
    transform(s.begin(),s.end(),s.begin(),Captalize_ch);
    return s;
}

enum class ChState : int {
    Unknown = 0,
    Wrong = 1,
    Misplaced = 2,
    Correct = 3
};

char ChState2Char(ChState c) {
    switch (c)
    {
    case ChState::Unknown :
        return 'X';
    case ChState::Wrong :
        return 'R';
    case ChState::Misplaced :
        return 'Y';
    case ChState::Correct :
        return 'G'; 
        break;
    }
}

class Game {
public:
    Game(string answer):answer(answer){
        for(auto& c : characters) {
            c = ChState::Unknown;
        }
    }

    bool cmp_guess_with_answer(string guess) {
        ChState cs[5] = {ChState::Unknown};

        //TODO: task1
        //hint: 如果 guess 中的第一个字符状态为 Misplaced，你可以使用以下语句赋值
        // cs[0] = ChState::Misplaced;
        string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        //把answer、和guess中的字符转为大写
        

        string cpy_answer(answer);
        string cpy_guess(guess);

        cpy_answer = Captalize_str(cpy_answer);

        cpy_guess = Captalize_str(cpy_guess);

        size_t ans_ch_pos;  //定义描述answer中对应字符位置的变量
        size_t start_find_pos = 0;  //定义开始找的位置的变量
        size_t count_guess = 0;  //已经进行到第几个guess中的字符

        for (auto& guess_char : cpy_guess){  //循环的应该是guess的字符这样才能指定character的status
            
            if (guess_char == cpy_answer[count_guess]){
                cs[count_guess] = ChState::Correct;
                characters[alphabet.find(guess_char,start_find_pos)] = ChState::Correct;
                cpy_answer[count_guess] = '*'+count_guess;
                cpy_guess[count_guess] = '*'+count_guess;
            }
            count_guess++;
        }
        count_guess = 0;
        for (auto& guess_char : cpy_guess){
            ans_ch_pos = cpy_answer.find(guess_char,start_find_pos);
            if (ans_ch_pos == count_guess){
                assert(cpy_answer[count_guess] == '*'+count_guess);
                count_guess++;
                continue;
            } else if (ans_ch_pos != count_guess && ans_ch_pos != string::npos){
                cs[count_guess] = ChState::Misplaced;
                if(characters[alphabet.find(guess_char,start_find_pos)]!=ChState::Correct){
                    characters[alphabet.find(guess_char,start_find_pos)] = ChState::Misplaced;
                    }
                cpy_answer[ans_ch_pos] = '#';
                cpy_guess[count_guess] = '#';
              
            } else {
                cs[count_guess] = ChState::Wrong;
                if(characters[alphabet.find(guess_char,start_find_pos)]!=ChState::Correct&&
                characters[alphabet.find(guess_char,start_find_pos)]!=ChState::Misplaced){
                characters[alphabet.find(guess_char,start_find_pos)] = ChState::Wrong;
                }
            }
            count_guess++;
        }

        for(size_t i = 0; i < WORDLEN; ++i)
            cout << ChState2Char(cs[i]);
        cout << ' ';
        for(size_t i = 0; i < 26; ++i)
            cout << ChState2Char(characters[i]);
        cout << endl;

        guesses.push_back(guess);

        //为自己定义的ches加入状态
        cses.push_back(&cs[0]);
        //自己定义的加入状态结束


        return (answer == guess || guesses.size() == 6);
    }

    bool hard_mode_constraints(string guess) {
        //TODO: task3
        // 判断当前猜测是否符合困难模式的要求，返回一个布尔值。
        // 你可以像普通变量一样地访问成员变量 answer, guesses 和 characters

         // 思路：此时应该还未cmp_guess_with_answer()所以guesses的最后一个就是上一次的答案，同时我的上次状态的存储应该也没有更新
        // 1. 先把guess的副本变成大写
        
        bool isValid = true;
        if(guesses.size() == 0) {return isValid;}

        string cpy_guess(guess);
        string cpy_answer(answer);
        cpy_guess = Captalize_str(cpy_guess);
        cpy_answer = Captalize_str(cpy_answer);
        // 2. green的位置必须不变，找到answer和上一次guess的相等的字符位置，然后使用本次和

        string guess_last_time;
        string a = *guesses.rbegin();

        guess_last_time.append(*guesses.rbegin());
        guess_last_time = Captalize_str(guess_last_time);
        for (int i = 0; i < WORDLEN; i++) {
            if (guess_last_time[i] == cpy_answer[i]) {
                if(guess_last_time[i] == cpy_guess[i]){
                    cpy_guess[i]= '*'+i;
                    continue;
                }else{
                    isValid = false;
                }
                // cpy_answer.erase(i,1);
                // cpy_answer.insert(i,1,'*');
                cpy_answer[i] = '*'+i;
                // guess_last_time.erase(i,1);
                // guess_last_time.insert(i,1,'*');
                guess_last_time[i] = '*'+i;
            }
            //如果上次猜测中有同答案相同但是位置不同的字母
            if (guess_last_time.find(cpy_answer[i])!= string::npos
            && guess_last_time.find(cpy_answer[i]) != i){
                if (cpy_guess.find(cpy_answer[i]) == string::npos){
                    isValid = false;
                }else{
                    cpy_answer[i] = '#';
                    guess_last_time[i] = '#';
                    continue;
                }
            }
        }
        // int misplaced_answer[WORDLEN];
        // ChState *cs_last_time = *cses.rbegin();
        // for (int i = 0; i < WORDLEN; i++) {
        
        // }    
        return isValid;
    }

    bool win() {
        return answer == *guesses.rbegin();
    }

    void print_result() {
        //TODO: task1
        //hint: 可以使用 guesses.size() 获取猜测次数
        //      可以使用 toupper() 函数将小写字母转化为大写字母(例如 char c = 'a'， toupper(c)的结果为'A' )
        string cpy_answer(answer);
        cpy_answer = Captalize_str(answer);

        if(win()) {
            //TODO
            cout << "CORRECT" <<" " <<guesses.size() << endl;
        }
        else {
            //TODO
            cout << "FAILED" <<" " <<cpy_answer << endl;
        }
    }

    size_t guess_count() {
        return guesses.size();
    }

private:
    string answer;
    vector<string> guesses;
    ChState characters[26];

    //以下是自定义部分
    vector<ChState*> cses;//定义这个部分是因为需要获得上一次输入的状态，并且把状态存储下来可以之后算法的时候使用
    //自定义部分结束
};