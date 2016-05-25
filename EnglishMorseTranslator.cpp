#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

#include "EnglishMorseTranslator.h"

const string EnglishMorseTranslator::MORSE_CODE_FILE = "morsecodes.txt";

string EnglishMorseTranslator::loadFile(const string file) const
{
   ifstream fin;
   string line = "";
   string text = "";

   fin.open(file.c_str(), ios::in);
   if (!fin) 
   {
      throw runtime_error("Can't open " + file);
   }

   try
   {
      while (!fin.eof()) 
      {
         getline(fin, line);
         text += line + "\n";
      }
   }
   catch (exception &ex)
   {
      cout << "\nERROR - Exception thrown\n" << ex.what() << "\n";
      fin.close();
   }

   fin.close();
   text.erase(text.end() - 1);
   return text;
}

void EnglishMorseTranslator::printFile(const string file) const
{
   ofstream fout;
   fout.open(file.c_str(), ios::out);

   try
   {
      fout << this->translatedText;
   }
   catch (exception &ex)
   {
      cout << "\nERROR - Exception thrown\n" << ex.what() << "\n";
      fout.close();
   }

   fout.close();
}

void EnglishMorseTranslator::loadTranslationFile(const string file)
{
   this->text = this->loadFile(file);
}

void EnglishMorseTranslator::convertEnglishToMorse()
{
   vector<EnglishMorseConversionTable>::iterator iterator;

   for (int charCounter = 0; charCounter < this->text.length(); charCounter++)
   {
      char character = text[charCounter];
      if (isalpha(character))
      {
         EnglishMorseConversionTable match;
         match.character = character;
         iterator = find(this->englishToMorse.begin(), this->englishToMorse.end(), match);
         this->translatedText += (*iterator).morse + " ";
      }
      else
      {
         this->translatedText += character;
      }
   }
}

bool EnglishMorseTranslator::isMorse(char character) const
{
   return (character == '-' || character == '*');
}

void EnglishMorseTranslator::convertMorseToEnglish()
{
   string morse = "";

   for (int charCounter = 0; charCounter < this->text.length(); charCounter++)
   {
      char character = this->text[charCounter];
      if (this->isMorse(character))
      {
         morse += character;
      }
      else if (morse != "")
      {
         this->matchMorseToEnglish(morse);
         morse = "";
      }
      else
      {
         this->translatedText += character;
      }
   }
   if (morse != "")
   {
      this->matchMorseToEnglish(morse);
   }
}

void EnglishMorseTranslator::matchMorseToEnglish(const string morse)
{
   treespc::const_iterator<EnglishMorseConversionTable> iterator;
   EnglishMorseConversionTable match;

   match.morse = morse;
   iterator = this->morseToEnglish.find(match);
   this->translatedText += (*iterator).character;
}

void EnglishMorseTranslator::loadMorseCodeFile()
{
   string conversionTable = this->loadFile(EnglishMorseTranslator::MORSE_CODE_FILE);
   istringstream text(conversionTable);
   string line = "";

   string character = "";
   string morse = "";
   EnglishMorseConversionTable table;

   while (getline(text, line))
   {
      character = line[0];
      morse = line.substr(2);

      table.character = character;
      table.morse = morse;

      this->englishToMorse.push_back(table);
      this->morseToEnglish.insert(table);
      this->morseToEnglish.balance();

   }
}