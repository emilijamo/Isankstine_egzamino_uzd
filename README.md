# Išankstinė egzamino užduotis

*Aprašymas*

Ši užduotis skirta patyrinėti, kad asociatyvūs konteineriai, t.y. tokie, kurie elementų į konteinerį įrašymo metu juos "surūšiuoja" yra labiau tinkami ir efektyvesni lyginant su sekos konteineriais tokio tipo užduotims. 

Programos rezultatas yra 3 tekstiniai failai - žodžių dažnių lentelė, cross-reference tipo lentelė, URL adresų sąrašas (išsamesnius jų aprašymus galima rasti skiltyje veiksmingumų aprašymai).

Programa veikia su 'input.txt', kuris yra nukopijuotas tekstas iš https://en.wikipedia.org/wiki/Queen_(band). 

*Įdiegimo instrukcija*

1. Kompiuteryje turėkite įdiegtus cmake interpretatorių bei C++ kompiliatorių. Jei neturite, galite juos įsidiegti čia: https://cmake.org/download/ https://cmake.org/download/ https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022
2. Iš šios github repozitorijos atsisiųskite aplanką 'programa'
3. Tuomet per terminalą nueikite iki atsisiųsto aplanko 'programa' ir paleiskite šias komandas:
   
   i. cmake CmakeLists.txt
   
   ii. cmake --build .
   
   iii. copy src\\*.txt Debug\\*.txt
   
   iv. cd .\Debug\
   
   v. .\teksto_apdorojimas.exe

*Veiksmingumų aprašymai*

1. Žodžių dažnių lentelė

Nurodomi žodžiai, pasikartojantys daugiau nei vieną kartą, bei šalia nurodomas jų dažnis. Žodžių dažnio lentelės su 'input.txt' iškarpa:

<img width="618" height="330" alt="image" src="https://github.com/user-attachments/assets/653bca03-adc1-4eee-bc5d-a092fe47a7a8" />

Šiam veiksmingumui realizuoti naudojama map<string, vector<int>>. Jo string reikšmė yra žodis, o vector kaupia eilučių, kuriose pasikartoja tas žodis, numerius. Šio vektoriaus dydis ir yra žodžio pasikartojimo dažnis. Šiuo atveju naudoti map patogu, nes žodžiai be atskiro sort mechanizmo jau rikiuojami pagal abėcėlę. Taip pat nereikia kurti atskirų string ir vektoriaus objektų.

2. Cross-reference lentelė
   
Lentelėje nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas. Cross-reference lentelės su 'input.txt' iškarpa: 

<img width="671" height="331" alt="image" src="https://github.com/user-attachments/assets/fdbd88b9-63e1-4a60-9c69-f09959bf5d32" />

Patikrinimas rankine paieška. Pavyzdžiui, imame žodį 'absolutely', kuris matome, kad pasikartoja 2 kartus, 195 ir 337 eilutėse. Tuo įsitikiname tekstiniame faile įvykdžius paiešką.

<img width="857" height="278" alt="image" src="https://github.com/user-attachments/assets/3f7ae54c-bb4e-4fd7-a35a-0a26f52162eb" />
<img width="580" height="278" alt="image" src="https://github.com/user-attachments/assets/802818cf-7436-43ee-8dde-6811ed4364a1" />

Šiam veiksmingumui realizuoti naudojama map<string, vector<int>>. Jo string reikšmė yra žodis, o vector kaupia eilučių, kuriose pasikartoja tas žodis, numerius.

3. URL sąrašas

Iš teksto išrenkami URL'ai, pateikti "pilnu" https://www.vu.lt/, http://www.vu.lt ar "sutrumpintu" pavidalu: www.vu.lt, vu.lt, saitas.xyz, kurių URL galūnė yra 'url_galunes.txt' faile (tai yra https://data.iana.org/TLD/tlds-alpha-by-domain.txt nukopijuotas URL sąrašas). URL sąrašo su 'input.txt' iškarpa: 

<img width="348" height="208" alt="image" src="https://github.com/user-attachments/assets/15422c6d-730d-46a0-ae16-3577981e5344" />

URL sąrašui patogu naudoti set<string>, nes jame kaupiamos tik nepasikartojančios URL.
