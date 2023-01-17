#pragma once

#include <set>
#include <string>
#include <optional>
#include <iostream>
#include <cassert>
#include <iomanip> 
#include "words.h"
#include "game.h"
using namespace std;

class GameState {
public:
    GameState(bool word_mode, string word_str, bool random_mode, bool difficult_mode, bool stats_mode) {
        this->word_mode = word_mode;
        this->word = word_str;
        this->random_mode = random_mode;
        this->difficult_mode = difficult_mode;
        this->stats_mode = stats_mode;
    }

    void run() {
        do {
            string answer;

            //TODO: task2
            //如果为 word_mode ，则从 word 中获取答案
            //如果为 reandom_mode ，则从 ws.get_random_answer() 中获取答案
            
             // 从标准输入获取答案
            if (word_mode) {
                assert(random_mode == false);  //difficult是否为0？
                answer = word;
            } else {
                getline(cin, answer);
            }
            
            if (random_mode) {
                WordSet generate_word;
                answer = (generate_word.get_random_answer());
            }

            new_round(answer);
            do {
                string guess;
                getline(cin, guess);
                if(check_word(guess)) {
                    print_round_info();
                    if(stats_mode) {
                        print_game_record();
                    }
                    break;
                }
            } while(true);

            if(word_mode) {
                break;
            }
            cout << "Next game?" << endl;
            string next;
            getline(cin, next);
            if(next == "Y") {
                continue;
            }
            else {
                assert(next == "N");
                break;
            }
        } while(true);
    }

    void new_round(string answer) {
        assert(ws.final_set.find(answer) != ws.final_set.end());
        games.push_back(Game(answer));
    }

    bool check_word(string guess) {
        if(ws.acceptable_set.find(guess) == ws.acceptable_set.end()) {
            cout << "INVALID" << endl;
            return false;
        }
        if(difficult_mode) {
            if(!games.rbegin()->hard_mode_constraints(guess)) {
                cout << "INVALID" << endl;
                return false;
            }
        }
        bool gameover = games.rbegin()->cmp_guess_with_answer(guess);
        return gameover;
    }

    void print_round_info() {
        games.rbegin()->print_result();
    }

    void print_game_record() {
        //TODO: task4
        // 输出游戏统计信息
        //hint: 游戏历史保存在 games 中，每一局游戏的猜测次数可通过 Game 类的 guess_count 获得
        //      假设 double pi = 3.1415
        //      可以使用 cout << fixed << setprecision(2) << pi << endl 输出保留两位小数的结果
        size_t total_tries_count_successed = 0;//所有成功局中的尝试次数之和
        double average_tries_count = 0;//成功局中平均尝试次数

        size_t success_count = 0;//成功总局数
        size_t fail_count = 0;//失败总局数
        size_t total_results_count = 0;//总局数
        bool havesuccess = false;
        //统计全部局数以及胜利局数
        total_results_count = games.size();
        
        for (int i = 0; i < total_results_count; ++i){
            if (games[i].win()){
                havesuccess = true;
                success_count++;
                total_tries_count_successed += games[i].guess_count();
            }

        }

        if (havesuccess) {
            average_tries_count =total_tries_count_successed/success_count;
        }else{
            average_tries_count =0;
        }

        fail_count = total_results_count - success_count;
        
        cout << fixed << setprecision(2) << success_count 
        << " " << fail_count << " " << average_tries_count << endl;
    }

private:
    WordSet ws;
    vector<Game> games;
    bool word_mode, random_mode, difficult_mode, stats_mode;
    string word;
};