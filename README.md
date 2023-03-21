# Solving a knapsack problem using genetic algorithm
## "Effective programming techniques" course project

### Synopsis
This programme solves a knapsack problem read from a file.
Path to the file is provided via console input. If found data is correct, the programme then tries to find the best fitted solution. Programme is protected from user error via different error messages. Algorithm parameters are hardcoded, but can be changed in the main.cpp file. 

### File format
The file should be formatted as follows:  
< Maximum allowed capacity >  
< weight of item1 > < value of item1 >  
< weight of item2 > < value of item2 >  
.  
.  
.  

Any other formatting will result in appropriate error. A class implementation of the knapsack problem validates data read from the file and also throws errors if neccessary. The errors contain an information about the line and word where the programme encountered unexpected input. 

### Genetic algorithm
This genetic algorithm implementation solves an abstract problem. While there is currently only an implementation of the knapsak problem, the algorithm itself can be easily reused for other types of problems in the future. The algorithm validates its parameters so that each instance can be safely run.

When the algorithm is run, it creates a set number (population) of randomly generated solutions (individuals). Next steps, repeated in each iteration, are as follows:
1. Pick two individuals from the previous generation at random.
2. Calculate their fitness and store the better one.
3. Repeat steps 1-2.
4. Choose between:
    - crossing over these individuals and adding children to the new population,
    - adding these individuals as is.
5. Choose which genes of new individuals in population should be mutated if any.
6. Repeat steps 1-5 until the target population size is reached.
7. Calculate fitness of individuals in the new population and choose the best one.
8. Compare with the best fitted individual so far. Store the better one.

If the target population size is an odd number, current best individual is added to the new population in each iteration. To avoid memory bloating and long runtimes while solving big problems, individuals are stored in populations via smart pointers and are only copied if a mutation is to take place, since they can be picked an unlimited number of times. Mutations and crossovers happen according to chances passed as parameters to the algorithm.

### Smart pointer
As an excercise, I have written my own smart pointer implementation. It is used to store individuals in previous and next population vectors.



