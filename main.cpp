#include <iostream>
#include <stdexcept>
#include <cstring>

#include "EnglishMorseTranslator.h"

using namespace std;

int main(int argc, char *argv[])
{
   if (argc == 4) 
   {
      try
      {
         EnglishMorseTranslator translator;

         translator.loadMorseCodeFile();
         translator.loadTranslationFile(argv[2]);

         if (strcmp(argv[1], "e") == 0)
         {
            translator.convertEnglishToMorse();
         }
         else if (strcmp(argv[1], "d") == 0)
         {
            translator.convertMorseToEnglish();
         }
         else
         {
            throw runtime_error("Choose correct first parameter, e(encode) or d(decode)");
         }

         translator.printFile(argv[3]);
         // translator.convert();
         // translator.printWholeText();
      }
      catch (exception &ex)
      {
         cout << "\nERROR - Exception thrown\n" << ex.what() << "\n";
      }
   }
   else
   {
      cout << "\nERROR - Invalid command line arguments\n";
   }

   return 0;
}