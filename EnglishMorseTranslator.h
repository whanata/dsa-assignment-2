#ifndef ENGLISH_MORSE_TRANSLATOR_H_
#define ENGLISH_MORSE_TRANSLATOR_H_

#include <vector>

#include "bintree.h"
#include "EnglishMorseConversionTable.h"

using namespace std;

class EnglishMorseTranslator
{
   private:
      string text;
      string translatedText;
      vector<EnglishMorseConversionTable> englishToMorse;
      treespc::bintree<EnglishMorseConversionTable> morseToEnglish;

      void matchMorseToEnglish(const string morse);
      string trim(const string str) const;
      string loadFile(const string file) const;
      bool isMorse(const char character) const;

   public:
      static const string MORSE_CODE_FILE;

      void loadTranslationFile(const string file);
      void loadMorseCodeFile();
      void printFile(const string file) const;
      void convertEnglishToMorse();
      void convertMorseToEnglish();

      EnglishMorseTranslator()
      {
         text = "";
         translatedText = "";
      }
};

#endif