#include <iostream>
#include <stdexcept>
#include <cstring>

#include "EnglishMorseTranslator.h"

using namespace std;

const int TYPE = 1;
const int FILE_IN = 2;
const int FILE_OUT = 3;

int main(int argc, char *argv[])
{
   if (argc == 4) 
   {
      try
      {
         string fileIn = argv[FILE_IN];
         string fileOut = argv[FILE_OUT];

         if (fileIn == fileOut) 
         {
            throw runtime_error("File in and File out should have different names");
         }

         EnglishMorseTranslator translator;

         translator.loadMorseCodeFile();
         translator.loadTranslationFile(fileIn);

         if (strcmp(argv[TYPE], "e") == 0)
         {
            translator.convertEnglishToMorse();
         }
         else if (strcmp(argv[TYPE], "d") == 0)
         {
            translator.convertMorseToEnglish();
         }
         else
         {
            throw runtime_error("Choose correct first parameter, e(encode) or d(decode)");
         }

         translator.printFile(fileOut);
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