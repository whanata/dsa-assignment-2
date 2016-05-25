#ifndef ENGLISH_MORSE_TRANSLATOR_H_
#define ENGLISH_MORSE_TRANSLATOR_H_

#include <vector>

#include "bintree.h"

using namespace std;

struct EnglishMorseConversionTable {
   string character;
   string morse;

   bool operator == (const EnglishMorseConversionTable &EMCT) const 
   {
      return ((EMCT.character == character) || (EMCT.morse == morse));
   }

   bool operator < (const EnglishMorseConversionTable &EMCT) const
   {
      return (EMCT.morse < morse);
   }

   bool operator > (const EnglishMorseConversionTable &EMCT) const
   {
      return (EMCT.morse > morse);
   }
};

class EnglishMorseTranslator
{
   private:
      string text;
      string translatedText;
      vector<EnglishMorseConversionTable> englishToMorse;
      treespc::bintree<EnglishMorseConversionTable> morseToEnglish;

      void matchMorseToEnglish(const string morse);

   public:
      static const string MORSE_CODE_FILE;

      string loadFile(const string file) const;
      void loadTranslationFile(const string file);
      void loadMorseCodeFile();
      void printFile(const string file) const;
      void convertEnglishToMorse();
      void convertMorseToEnglish();
      bool isMorse(const char character) const;

      EnglishMorseTranslator()
      {
         text = "";
         translatedText = "";
      }
};

#endif