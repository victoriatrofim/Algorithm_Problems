## README TEMA1 - PA

# ----------------------- PROBLEMA 1 ---------------------------

Pentru implementare, am definit mai întâi două funcții cheie: get_min și binary_search. Funcția get_min calculează puterea sistemului, ținând cont de valorile limită de alimentare pentru fiecare server. Această funcție parcurge fiecare server și determină puterea minimă necesară la un anumit nivel de alimentare. 

Funcția binary_search efectuează o căutare binară pentru a găsi valoarea optimă a puterii individuale, pentru inceput determin capetele low si high, apoi, cat timp diferenta dintre low si high nu ajunge la valoarea minima(ajung sa fie egale), continuu determin minimul curent de alimentare pentru puterea individuala mid(care e mijlocul dintre low si high) si il compar cu minimul pentru mid + MIN(= 0.000001). In cazul in care minimul lui mid este mai mic, el devine capatul inferior, altfel, devine capatul superior. Astfel, din aproape in aproape o sa ajunga low = high = puterea individuala optima la care la final ii determinam minimul de alimentare.

În funcția principală, am citit datele de intrare din fișierul "servere.in" și am inițializat vectorii de puteri ale serverelor și limitele de alimentare. Apoi, am calculat puterea maximă necesară apeland funcția binary_search, care utilizează metoda căutării binare pentru a găsi soluția optimă. 
Am folosit o abordare eficientă pentru a găsi această soluție, astfel încât să minimizăm puterea maximă necesară pentru alimentare.

Funcția get_min: complexitatea timp este O(n), unde n este numărul de servere.
Funcția binary_search: O(logN), unde N este numărul total de posibile valori pentru putere. => O(logN), unde N este numărul total de servere.

# ---------------------------PROBLEMA 2 ---------------------------

La problema 2, am scris un program care calculează numărul total de modalități de colorare a unor blocuri orizontale și verticale.
A trebuit să folosesc funcții din biblioteci pentru lucrul cu fișiere și pentru operațiuni de baza, precum și structuri de date, cum ar fi vectorii, pentru a organiza datele.
Am definit o constantă pentru modulo pentru a gestiona numerele mari.

Pentru a calcula puterea unui număr, am implementat o funcție care folosește un algoritm eficient, evitând depășirea capacitații de stocare. 

Am folosit o buclă pentru a citi datele despre blocuri din fișier și a le stoca într-un vector de structuri.

Aplicația principală este în bucla care calculează numărul total de modalități de colorare. Am gestionat diferitele situații care apar atunci când avem blocuri orizontale și verticale în secvență, inclusiv primul bloc din secvență și blocurile care urmează după alte blocuri orizontale sau verticale.

Programul combină si utilizează funcții și structuri de date pentru a realiza obiectivul.


Complexitatea de timp a acestui cod este dominată de două bucle for, ambele parcurgând vectorul de blocuri. Prima buclă parcurge vectorul - având o complexitate de O(K), unde K este numărul de blocuri citite. 
A doua buclă - numărul de iterații este tot K. 
În interiorul acestei bucle, avem operații aritmetice și apeluri la funcția power, care are o complexitate de logaritmică în funcție de valoarea lui y. Prin urmare, complexitatea timp a celei de-a doua bucle for este O(K * log y), unde y este cel mai mare exponent întâlnit în vectorul de blocuri. Complexitatea totală a codului este O(K * log y),  K este numărul de blocuri și y este cel mai mare exponent întâlnit în vectorul de blocuri. => O(K * log y)

# ---------------------------PROBLEMA 3 ---------------------------

Pentru problema 3, am facut un program pentru a comprima secvențe reprezentate de două vectori, A și B si a verifica daca putem compresa sirurile intr-o lungime maxima astfel incat A == B

Funcția cheie get_res calculează rezultatul bazat pe vectorii A și B furnizați. Parcurge vectorii de la stanga spre dreapta, incrementând un contor când elementele corespunzătoare sunt egale și combinând elementul i cu urmatorul din A cand elementul este mai mic decat cel din b, iar daca elementul mai mic este in B, atunci le insumam pe cele de pe pozitiile j si urmatorul. Această funcție comprimă eficient secvențele în timp ce numără lungimea maximă a secvenței comprimate.

În main, valorile pentru vectorii A și B sunt citite din fișier, iar suma elementelor acestora este calculată folosind funcția accumulate pentru a verifica daca este posibil de facut comprimarea. Dacă sumele elementelor din A și B nu sunt egale, programul afișează -1 fiindca oricat le-ai insuma, dau valori diferite. În caz contrar, calculează și afișează lungimea maximă a secvenței comprimate folosind funcția get_res.

Funcția get_res: Această funcție conține două bucle for înfășurate. Cele două bucle se execută pentru fiecare element din vectorii A și B, deci avem o complexitate de => O(n * m).

# --------------------------- PROBLEMA 4 ---------------------------

Pentru rezolvarea exercitiului 4, pentru inceput citesc datele de intrare despre numărul și prețurile produselor dintr-un fișier.
Apoi, folosesc un algoritm dinamic de programare pentru a calcula costul minim al cumpărăturilor, având în vedere diferite oferte disponibile.

Folosind un vector numit minCost, calculez costul minim pentru a cumpăra diferite numere de produse. Inițializez acest vector cu o valoare mare pentru a reprezenta că nu am cumpărat încă nimic și, prin urmare, costul minim pentru orice număr de produse este inițializat la 0.

Parcurg fiecare produs și actualizez minCost în funcție de ofertele disponibile

Pentru fiecare produs în parte, actualizez costul minim pentru a cumpăra acel produs individual.
Verific dacă pot beneficia de oferte care implică gruparea de produse. Dacă da, actualizez costul minim pentru grupuri de două și trei produse, folosind funcțiile sale50 și sale100 pentru a calcula costurile specifice acestor oferte.

Obțin costul minim total al cumpărăturilor și-l scriu in fisier, cu o singură zecimală de precizie.

Inițializarea vectorului de prețuri: Inițializarea vectorului și citirea prețurilor - complexitate de O(N), unde N este numărul de produse.
Parcurgerea vectorului pentru a calcula costurile minime pentru diferite combinații de produse necesită, de asemenea, un timp liniar în funcție de dimensiunea vectorului, deci aceasta contribuie cu încă O(N). Astfel, complexitatea totală este de O(N). => O(N)
