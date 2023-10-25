# Platypus Programming Language Lexical Analyzer

Platypus programming language lexical analyzer developed using vanilla C++.
- language/automata analizador léxico.xlsx contains all the reserved words for the Platypus programming language
- media/Automata.pdf is a graphical representation of the implemented automata for the lexical analysis.

## Capabilities 
The lexical analyzer is capable of:
- Detecting reserved keywords
- Detecting variables
- Detecting operators
- Detecting literal/hard coded values
- Generating errors indicating the line and column where it was originated
- Generate the table of symbols
- Inspect an entire file
- Inspect the file indicated in the arguments of the command line binary
- Argument/parameter engine to manage the arguments of the command line binary
- Continiue the lexical analysis even if an error was generated
- Store all the generated errors in a structure to then output them after the lexical analysis is done
- Provide feedback to the user
- Detect multiple symbols that are together without whitespaces

## Usage
```bash
$ ./Platypus <filepath>.jec
```

## Lexican Analyzer Automata
![Alt text](./media/Automata.pdf?raw=true)

## Authors

- [@EmilioRivera0](https://github.com/EmilioRivera0)
- [@JuanPabloGHC](https://github.com/JuanPabloGHC)
- [@C4ncino](https://github.com/C4ncino)
