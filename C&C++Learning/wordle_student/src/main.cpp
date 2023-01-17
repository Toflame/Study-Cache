#include <iostream>
#include <string>
#include "state.h"
using namespace std;

int main(int argc, char* argv[]) {
    bool random_mode = false;
    // bool random_mode = true;
    bool difficult_mode = false;
    // bool difficult_mode = true;
    bool stats_mode = false;
    // bool stats_mode = true;
    bool word_mode = false;
    // bool word_mode = true;

    string word = "";
    for(size_t i = 1; i < argc; ++i) {
        if(string(argv[i]) == "-r" || string(argv[i]) == "--rand") {
            random_mode = true;
            continue;
        }
        if(string(argv[i]) == "-D" || string(argv[i]) == "--difficult") {
            difficult_mode = true;
            continue;
        }
        if(string(argv[i]) == "-t" || string(argv[i]) == "-stats") {
            stats_mode = true;
            continue;
        }
        if(string(argv[i]) == "-w" || string(argv[i]) == "--word") {
            word_mode = true;
            assert((i + 1) < argc);
            word = string(argv[i+1]);//在此处赋值
            continue;
        }
    }

    assert(!(word_mode && random_mode));

    GameState* gs = new GameState(word_mode, word, random_mode, difficult_mode, stats_mode);
    gs->run();

    return 0;
}