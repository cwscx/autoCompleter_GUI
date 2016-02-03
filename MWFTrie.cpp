#include "MWFTrie.hpp"
#include <iostream>
#include <fstream>
#include <string>

MWFTrie::MWFTrie() {
   std::ifstream dict;
   dict.open("freq_dict.txt");
   int num;
   string str;
   dictSize = 0;
   while (dict.good()) {
      dict >> num;
      getline(dict, str);
      str = str.substr(1);
      dictionary.push_back(str);
      dictSize++;
   }
}

vector<string> MWFTrie::predictCompletions(string prefix, unsigned int num_completions) {
    std::vector<std::string> temp;
    for(int i = 0 ; i < dictSize; i++) {
       if(string(dictionary[i]).find(prefix) == 0) {
           temp.push_back(string(dictionary[i]));
           if(temp.size() >= num_completions) {
               break;
           }
       }
    }
    return temp;

}

