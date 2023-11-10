# Compiler-Design-Lab
CSE 3142 (Compiler Design Lab)

# Problem - 01 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_01.cpp)
    Problem description:
	    Write a C/C++ program tha read the following string: "Md. Tareq Zaman, Part-3, 2011"
		    a) Count number of words, letters, digits and other characteristics
		    b) Separates letters, digits and others characters.

# Problem - 02 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_02.cpp)
    Problem description:
	    Write a program that read the following string: "Munmun is the student of Computer Science & Engineering".
		    a) Count how many vowels and Consonants are there?
		    b) Find out which vowels are consonants are existed in the above string?
		    c) Divide the given string into two separate strings, where one string only contains the word started with vowel,
		    and another contains the words started with consonant.
# Problem - 03 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_03.cpp)
    Problem descrition: 
	    Write a program that abbreviates the following code:
		    CSE-3141 as Computer Science & Engineering, 3rd year, 1st Semester, Compiler Design, Theory.
# Problem - 04 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_04.cpp)
    Problem description:
	    Write a program to build a lexical analyzer implementing the following regular expressions.
	    It takes a text as input from a file (e.g. input.txt) and displays output in console mode:
	        Integet variable = (i-nI-N)(a-zA-Z0-9)*
	        ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
	        LongInt Number = (1-9)(0-9)(0-9)(0-9)(0-9)+
	        Invalid Input or Undefined = otherwise
# Problem 05 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_05.cpp)
    Problem description: 
	    Write a program to build a lexical analyzer implementing the following regular expressions.
	    It takes a text as input from a file (e.g. input.txt) and display output in console mode:
	        Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-0)*
	        Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
	        Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
	        Invalid input or Undefined = Otherwise
# Problem 06 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_06.cpp)
    Problem description:
	    Build a lexical analyzer implementing the following regular expressions:
			Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)*
			Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)*
			Binary Number =0(0|1)(0|1)*
			Invalid Input or Undefined = Otherwise
# Problem 07 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_07.cpp)
    Problem description:
	    Write a program to recognize C++
			i) Keyword ii) Identifier iii) Operator iv) Constant
# Problem 08 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_08.cpp)
    Problem description:
		Write a program which converts a word of C++ program to its equivalent token.
			RESULT:
			Input: 646.45
			Output: Float
			Input: do
			Output: Keyword
			Input: 554
			Output: Integer
			Input: abc
			Output: Identifier
			Input: +
			Output: Arithmetic Operator
# Problem 09 [code](https://github.com/Zannatul-Naim/Compiler-Design-Lab/blob/main/problem_09.cpp)
 	   Problem description:
			Write a program that will check an English sentence given in the present indefinite form to justify
   			whether it is syntactically valid or invalid according to the following Chomsky Normal Form:
				S → SUB PRED
				SUB → PN|P
				PRED → VIV N
				PN → Sagor | Selim | Salma | Nipu
				P → he| she |1/ we | you | they
				N → book | cow | dog | home | grass |rice |mango
				V → read | eat | take | run | write
# Problem 10 [code]()
	Problem description:
 		Write a program to implement a shift-reducing parsing.

# Problem 11 [code](#)
	Problem description:
 		Write a program to generate a syntax tree for the sentence a+b*c with the following grammar:
			E → E+E | E-E | E*E | E/E | (E) | a | b | c
