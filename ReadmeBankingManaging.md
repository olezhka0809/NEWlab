# Gestionare Conturi Bancare

![imagine](https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.linkedin.com%2Fpulse%2F5-digital-banking-must-haves-malavika-kumar&psig=AOvVaw3PWM7rrLsJLOnYlRmhXZWr&ust=1713634859418000&source=images&cd=vfe&opi=89978449&ved=0CBIQjRxqFwoTCKDUpbvpzoUDFQAAAAAdAAAAABAI)

Acest proiect implementează un sistem simplu de gestionare a conturilor bancare, permițând utilizatorilor să efectueze operații precum crearea de conturi, depozitarea și retragerea de fonduri, precum și transferurile între conturi.

## Cum funcționează
Programul primește comenzi de la utilizator dintr-un fișier de test și efectuează operațiile bancare corespunzătoare în funcție de comanda dată. Operațiile disponibile sunt:

1. **Creare Banc Account:** Permite utilizatorului să creeze un nou cont bancar cu informațiile necesare precum nume, IDNP, ID și parolă.
2. **Depozit:** Permite utilizatorului să depună fonduri în contul său bancar specificând suma de bani.
3. **Transfer:** Permite utilizatorului să efectueze transferuri de bani între două conturi bancare.
4. **Extrage Bani:** Permite utilizatorului să retragă fonduri din contul său bancar.
5. **Exit:** Permite utilizatorului să iasă din program.

# Cum să folosești
1. Compilează fișierul sursă `BankingManaging` folosind n compilator C.
```gcc proiect_banca.c -o proiect_banca```
2. Rulează executabilul generat.
```./proiect_banca fisierTest```
3. În fișierul de test (fisierTest), introdu comenzile corespunzătoare pentru a efectua operațiile dorite. Asigură-te că fiecare comandă este introdusă într-o linie separată conform formatului specificat în codul sursă.

## Rezultat
Programul va afișa rezultatul fiecărei operații efectuate și va gestiona în mod corespunzător erorile întâmpinate.