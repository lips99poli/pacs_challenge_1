Explanation of the structure of the code.

There is one base class: GD_Abstract: it implements the algorithm of gradient descent with the check of the stopping criteria; it is abstract because it doesn't implement
any rule to update the learning rate.

There are 3 more classes which inherit from the above mentioned abstract one, and they specify the updating rule for alpha: approximate line search, inverse decay and 
exponential decay.

The parameters for the constructor of the base class are read from a parameter file through a struct that uses GetPot library (uploaded in the include folder).

Results of the different method are printed in the terminal but the function to print can print also on file, you just need to specify an output string in the input.

Finally there is a Utility file, it contains some functions (compute_norm) used by the gradient descent algorithms and the declaration of the parameters structure.
Note that the compute_norm function is a template function in oorder to implement also the computation of distance between points. Thanks to the template parameter we can know at compile time if the function will need the second input. This if is resolved at compile time thanks to a constexpr command.
