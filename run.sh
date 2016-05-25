#!/usr/bin/env bash

cp /home/glingard/morsecodes.txt .

./translator e english.txt em.txt
printf "\nEnglish - Morse (Wira)\n"
cat em.txt
echo END

/home/glingard/morse e english.txt em-glingard.txt
printf "\nEnglish - Morse (Glingard)\n"
cat em-glingard.txt
echo END

./translator d em.txt em-converted.txt
printf "\nMorse - English (Wira-Converted)\n"
cat em-converted.txt
echo END

/home/glingard/morse d em-glingard.txt em-glingard-converted.txt
printf "\nMorse - English (Glingard-Converted)\n"
cat em-glingard-converted.txt
echo END

./translator d morse.txt me.txt
printf "\nMorse - English (Wira)\n"
cat me.txt
echo END

/home/glingard/morse d morse.txt me-glingard.txt
printf "\nMorse - English (Glingard)\n"
cat me-glingard.txt
echo END

./translator e me.txt me-converted.txt
printf "\nEnglish - Morse (Wira-Converted)\n"
cat me-converted.txt
echo END

/home/glingard/morse e me-glingard.txt me-glingard-converted.txt
printf "\nEnglish - Morse (Glingard-Converted)\n"
cat me-glingard-converted.txt
echo END