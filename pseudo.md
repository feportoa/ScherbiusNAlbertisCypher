## Pseudocode for Scherbius's/Alberti's Cypher
> Compile using "g++ -std=c++20 main.cpp -lncurses"

### Expected Result
``` 
1st Letter
###########                      |
Polyalphabetical                 |
Type your message                |
CYPH: EFGHIJKLMNOPQRSTUVWXYZABCD
RSLT: L
PTXT: H
###########                      |

2nd Letter
###########                      |
Polyalphabetical                 |
Type your message                |
CYPH: *MNOPQRSTUVWXYZABCDEFGHIJKL
RSLT: Lq
PTXT: He
###########                      |

3rd Letter
###########                      |
Polyalphabetical                 |
Type your message                |
CYPH: **JKLMNOPQRSTUVWXYZABCDEFGHI
RSLT: Lqu
PTXT: Hel
###########                      |

...
```
> The only difference between the Monoalph. and the Polyalph. is that in Monoalphabetical Cyphers, the cypher alphabet doesn't change.

### Code
```
We will use (#include) Ncurses, Iostream, Vector, String and Fstream

Function Create alphabetical string to cypher
    Pass In: Alphabet String, Starting Letter
    
    Collects amount of letters before the Starting Letter variable;
    Adds letters before Starting Letter to the end of the Alphabet String in a new string called Cypher Code;

    Pass Out: Cypher Code
Endfunction

Main 

    Alphabet String = ABCDEF...
    Decrypting Key = Key
    User Encrypted Vector
    User Input Vector

    While user is Encrypting
        If user DON'T press Space, then:
            If user press enter:
            
                Ask if user wants to put Decrypting Key
                Send encrypted message to file
                Stop encrypting

            Else:
            
            print ###########                      |
            print Monoalphabetical                 |
            print Type your message                |
            print CYPH: Function(Create alphabetical string to cypher)
            print RSLT: User Encypted Vector
            print PTXT: User Input Vector + Let user input or delete a Letter (doesn't allow spaces)

            Endif
        Endif
    Endwhile

Endmain
```