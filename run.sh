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

./translator d morse.txt me.txt
printf "\nMorse - English (Wira)\n"
cat me.txt
echo END

/home/glingard/morse d morse.txt me-glingard.txt
printf "\nMorse - English (Glingard)\n"
cat me-glingard.txt
echo END