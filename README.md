# Football Guessing Game

## Descriere :

Bine ai venit la Memory Game! Scopul jocului este simplu: memorează sportivii pe care i-ai selectat pentru a-i alege pe toți fără să te repeți. Atenție! Dacă te repeți, scorul tău va deveni 0 și va trebui să o iei de la capăt! Ai grijă, ai voie să greșești doar de 3 ori înainte de a pierde.

🎯 Atenție la detalii! Nu toți sportivii din listă sunt fotbaliști — unii sunt boxeri, iar alții înotători. Pentru a te ajuta, fiecare sportiv are un hint: un număr care reprezintă fie numărul de pe tricoul fotbalistului, fie greutatea boxerului, fie timpul record al înotătorului.

💡 De fiecare dată când selectezi un sportiv, lista acestora se va amesteca. Fii atent și concentrează-te pentru a câștiga! Mult succes! 🏆

# Jucători și Reguli de Penalizare

## Jucător Fotbal

### Numele jucătorului

- Se va schimba înlocuind un caracter din nume cu **numărul de pe tricou**.
- Poziția caracterului schimbat este aleasă aleatoriu.
- Dacă acel caracter este un spațiu, procesul se repetă până când se selectează o poziție validă.

### Numărul de pe tricou

- Numărul de pe tricou va fi modificat astfel încât să devină o repetare a sa.
- Numărul va fi concatenat de atâtea ori cât reprezintă **numărul de încercări greșite**.
  - Exemplu:
    - Dacă numărul este `7` și ai greșit de **două ori**, va deveni `777`.
    - Dacă numărul este `21` și ai greșit de **o data**, va deveni `2121`.

---

## Jucător Box

### Numele jucătorului

- Prenumele și numele vor fi inversate.
  - Exemplu:
    - Dacă numele este `Ion Popescu`, va deveni `Popescu Ion`.

### Greutatea

- Greutatea va fi modificată astfel încât să fie concatenată cu suma cifrelor propriei valori minus numărul de încercări greșite.
  - Exemplu:
    - Dacă greutatea este `75` și ai greșit de **două ori**, suma cifrelor este `7 + 5 = 12`. Noua greutate devine `7512 - 2 = 7510`.

---

## Jucător Înot

### Numele jucătorului

- Se va schimba prin interschimbarea ultimului caracter al numelui cu ultimul caracter al prenumelui.
  - Exemplu:
    - Dacă numele este `Ion Popescu`, va deveni `Iou Popescn`.

### Timpul record

- Timpul va fi modificat prin înmulțirea acestuia cu 10 și adăugarea numărului de încercări.
  - Exemplu:
    - Dacă timpul este `50` și numărul de încercări este egal cu 2, noul timp va deveni `502`.

---

## Jucător Tenis

### Numele jucătorului

- Două caractere aleatorii din nume vor fi înlocuite cu simbolul `*`.
  - Exemplu:
    - Dacă numele este `Roger Federer`, poate deveni `R*ger F*derer`.

### Clasamentul WTA

- Clasamentul WTA va fi ridicat la **puterea numărului de încercări greșite plus 1**.
  - Exemplu:
    - Dacă clasamentul este `5` și ai greșit de **două ori**, va deveni `5^3 = 125`.

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

- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [ ] smart pointers (recomandat, opțional)
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] funcții _de nivel înalt_, de eliminat cât mai mulți getters/setters/funcții low-level
- [ ] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate** din aceeași ierarhie
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
- [ ] tag de `git`: de exemplu `v0.2`

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
