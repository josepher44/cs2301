Joseph Gallagher

To run the programs, run make, then run either ./sorttest or ./sorttest2
For arguments, sorttest takes a series of numbers from the command line. It will always sort
using arrays
Sorttest 2 takes a number of values, and will use a random number generator to generate
this many values. It also takes two flags. run 'a' to sort with arrays, and 'p' to sort with
pointers. flag 's' after the sort type flag to reseed the RNG. 

For 50000 values
With pointers: 12s, 662914us
With arrays: 23s, 219669us

For 5 values
With pointers: 0s, 84us
With arrays: 0s, 79us

For small arrays, they are nearly identical, with array sort having a slight advantage
With larger datasets, pointers show a signifigant advantage. 

