/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones
 */

#ifndef MWFTRIE_HPP
#define MWFTRIE_HPP

#include <set>
#include <vector>
#include <array>
#include <string>
#include <cctype>
#include "MNode.cpp"
#include "constants.hpp"

using std::vector;
using std::set;
using std::string;
using std::pair;
using std::array;


/**
 *  The class for a multiway frequency trie, to form lexicon object
 *
 */
class MWFTrie
{
public:

  MWFTrie();
  vector<string> predictCompletions(string prefix, unsigned int num_completions);

  ~MWFTrie();
  const static char * dictionary[];
};

#endif // MWFTRIE_HPP
