# Transformare din Numere Hexazecimale în Numere Zecimale

Acest program în limbajul C transformă un număr în format hexazecimal într-un număr în format zecimal.

## Cum funcționează
Programul citește un număr în format hexazecimal de la utilizator și apoi efectuează conversia în număr zecimal. Pentru a face acest lucru, se utilizează următorii pași:

1. Citirea numărului în format hexazecimal de la utilizator.
2. Pentru fiecare cifră din numărul hexazecimal:
  * Se verifică dacă cifra este un caracter valid hexazecimal.
  * Se calculează valoarea corespunzătoare a cifrei în sistemul zecimal, luând în considerare puterea de 16 corespunzătoare poziției cifrei.
  * Se adaugă valoarea la suma totală.
  * Se afișează rezultatul conversiei în format zecimal.

## Cum să folosești
1. Compilează fișierul sursă `HexadecimaltoDecimalConverter.c` folosind un compilator C.
gcc -Wall -o test HexadecimaltoDecimalConverter.c

2. Rulează executabilul generat
./test

3. Introdu numărul în format hexazecimal când se solicită de către program.

## Rezultat
Programul va afișa numărul convertit în format zecimal.

# Note
* Pentru fiecare caracter hexazecimal introdus, programul afișează formula utilizată pentru calculul valorii sale zecimale.
* Se utilizează gestionarea alocării de memorie pentru a evita scurgerile de memorie și pentru a verifica dacă alocarea de memorie a fost realizată cu succes.
