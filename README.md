# ATR2MAX
Convert ATARI ATR files to Atarimax 128 KB Flash cartridge

Atarimax 128 KB Flash cartridge to cart gdzie mamy tylko jeden przełączany obszar. Z jednej strony jest to zaleta, bo za dużo nam się danych nie przełącza (mniejsze szanse na migotanie obrazu), no ale z drugiej strony trzeba jakoś się zmieścić z danymi i kodem obsługi carta. Kopiowanie procedur do RAM nie wchodzi w grę, bo zwykle tego miejsca nie ma. Dlatego maksymalnie dużo trzeba ogarnąć w pamięci carta.

Bank 0 jest uprzywilejowany. Zawiera procedurę startową i mapę sektorów. Każdy inny bank zawiera sektory oraz 256 blok na końcu z kodem obsługi. Kod obsługi wszędzie jest taki sam, więc jest odporny na przełączanie banków.

Ponieważ liczba sektorów w banku nie jest wielokrotnością dwójki, to żeby się doliczyć gdzie są dane to albo trzeba zrobić skomplikowaną procedurę dzielenia modulo, albo stablicować. 

Do budowy tablicy przygotowano specjalny programik SectorMap. Buduje on mapę sektorów dla wersji 128 i 256 bajtów na sektor. Ostatecznie jest to podłączane do ASM i dwa startery są kompilowane.

Finalny konwerter to atr2max.c z dwoma inkludami: "starter128m.h" i "starter256m.h".

W praktyce Maxflash 128kB da radę obskoczyć tylko dyski SD. Ale w przyszłości pojawi się MaxFlash 128kB PLUS oraz SimpleCART obsługujący flashe do 512kB i do tego już został konwerter dostosowany.
