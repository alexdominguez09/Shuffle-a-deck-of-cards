# Shuffle-a-deck-of-cards  
This is a C portable program to simulate shuffling a deck of cards as many times as the final result would be the deck of carts totally well sorted.

The programme has ben compiled and ported into 2 diferent plataforms so far:

Linux -> CPU i5-5200U -> Linux ubuntu 4.15.0-128-generic #131~16.04.1-Ubuntu SMP Wed Dec 9 17:33:47 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux
      -> Compiled with code::blocks usin gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.12)
      -> Run in single core -> Speed: 6056856 shuffles per second.
      
MS-DOS -> CPU 80286 -> MS-DOS 6.22
       -> Compiled in Turbo C++ 1.01
       -> Run in single core -> Speed: 743 shuffles per second.
       
       
       
The reason to write it in C and in a single file was to be able to port it into as many plataforms posible and to make a easy and portable as possible.

The programme is very short, less than 150 lines and written in plain standard C. Is a bit self-explanatory, but un summary what it does, is:
1. Creates an array of 48 numbers, each of one represents one of the cards of a deck. 
2. It shuffles the array using the Fisher–Yates shuffle Algorithm. It can be improved, but it dose the job.
3. Compares the shuffled array with the one that is sorted by lower numbers.
4. Creates an index called **equality** that adds a unit for every position that is in the supposed sorted position. 
Eg: if the final goal of an array is : 1 2 3 4 5 6  and we have  6 2 3 1 5 4 after shuffling it, this array has a equality index of 3, as it has 3 positions in teh correct orter, that is, 2, 3 and 5. 
5. It cycles shuffling and comparing arrays, till the maximun equality index is achived.
Eg: In the previous example teh array 1 2 3 4 5 6, will have a equality of 6, as all 6 positions are the the corresponded one to name this array as sorted, that is, to be the deck of cards, ordered by numbers after a few shuffles.

Have a look to it and try to run it in any plataform and see the speed of your system.

![Image of screen 1](https://github.com/alexdominguez09/Shuffle-a-deck-of-cards/blob/main/screen01.png)

![Image of screen 2](https://github.com/alexdominguez09/Shuffle-a-deck-of-cards/blob/main/screen02.png)

![Image of screen 3](https://github.com/alexdominguez09/Shuffle-a-deck-of-cards/blob/main/screen03.png)
