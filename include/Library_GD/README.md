Explanation of the structure of the code.

There is one base class: GD_Abstract: it implements the algorithm of gradient descent with the check of the stopping criteria; it is abstract because it doesn't implement
any rule to update the learning rate.

There are 3 more classes which inherit from the above mentioned abstract one, and they specify the updating rule for alpha: approximate line search, inverse decay and 
exponential decay.

The parameters for the constructor of the base class are read from a parameter file through a struct that uses GetPot library (uploaded in the include folder).

Results of the different method are printed in the terminal but the function to print can print also on file, you just need to specify an output string in the input.
