#include "MWFTrie.hpp"

vector<string> MWFTrie::predictCompletions(string prefix, unsigned int num_completions) {
    std::vector<std::string> temp;
    for(int i = 0 ; i < DICT_SIZE ; i++) {
       if(string(dictionary[i]).find(prefix) == 0) {
           temp.push_back(string(dictionary[i]));
           if(temp.size() >= num_completions) {
               break;
           }
       }
    }
    return temp;

}

const char * MWFTrie::dictionary[] = DICTIONARY;
