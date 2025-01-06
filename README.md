# Football Guessing Game

## Descriere :

Bine ai venit la Memory Game! Scopul jocului este simplu: memorează sportivii pe care i-ai selectat pentru a-i alege pe toți fără să te repeți. Atenție! Dacă te repeți, scorul tău va deveni 0 și va trebui să o iei de la capăt! Ai grijă, ai voie să greșești doar de 3 ori înainte de a pierde.

🎯 Atenție la detalii! Nu toți sportivii din listă sunt fotbaliști — unii sunt boxeri, iar alții înotători. Pentru a te ajuta, fiecare sportiv are un hint: un număr care reprezintă fie numărul de pe tricoul fotbalistului, fie greutatea boxerului, fie timpul record al înotătorului.

💡 De fiecare dată când selectezi un sportiv, lista acestora se va amesteca. Fii atent și concentrează-te pentru a câștiga! Mult succes! 🏆

## Tema 1

#### Cerințe

- [x] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [x] constructori de inițializare cu parametri
- [x] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
  <!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
  <!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [x] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [x] cât mai multe `const` (unde este cazul)
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [x] scenariu de utilizare a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [x] tag de `git`: de exemplu `v0.1`
- [x] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe

- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [x] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [x] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [x] apelarea constructorului din clasa de bază din constructori din derivate
  - [x] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [x] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [x] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [x] smart pointers (recomandat, opțional)
- [x] excepții
  - [x] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [x] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [x] funcții și atribute `static`
- [x] STL
- [x] cât mai multe `const`
- [x] funcții _de nivel înalt_, de eliminat cât mai mulți getters/setters/funcții low-level
- [x] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate** din aceeași ierarhie
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
- [x] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe

- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
  <!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

Sau pe Windows cu GCC:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.

2. Pasul de compilare

```sh
cmake --build build --config Debug --parallel 6
```

Cu opțiunea `parallel` specificăm numărul de fișiere compilate în paralel.

3. Pasul de instalare (opțional)

```sh
cmake --install build --config Debug --prefix install_dir
```

Vezi și [`scripts/cmake.sh`](scripts/cmake.sh).

## Resurse

- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
