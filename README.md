# Start Up Code for Polynomial Class
## Purpose
The goal of this lab is to practice dynamic memory with a simple class.

## Design
This Polynomial class will store the coefficients of a one variable polynomial
in a dynamically created array. This class has two data members:
```
	size_t _degree;
	float* _coefficients;
```
It is straightforward to see what they represent.
For example:
![equation](https://latex.codecogs.com/gif.latex?7x%5E4-2x%5E2&plus;0.5x&plus;2.23)
would be:
``` 
	_degree = 4
	_coefficients => {2.23, 0.5, -2.0, 0.0, 7}
```
Notice that the array size is `_degree + 1`.

## What is given?
You will be provided with the code of the constructors, the ToString, Minus, Assignment Operator, Equals, Read and Write  methods
the rest of the methods you will implement yourself.
Additionally you will be provided with the unit tests to test your code.

## What is expected?
- Your code ***must*** compile.
- Your grade will be *almost* the percentage of your passed unit tests.
- Your code needs to show good programming practices: indentation, meaningful variable names, identifiers convention (CamelCase for functions, 
camelCase for variables, _camelCase for data members, SNAKE_CASE for constants), header comments, correct file names, etc. Failure to 
code appropriate will result in strong points penalization.
- You will need to provide implementation of the following methods:
  1. Destructor
  2. Add
  3. Subtract
  4. Multiply
  5. Derive
  6. Evaluate
- The following methods will count toward extra credit, some code will be provided to guarantee compilation:
  1. Divide
  2. Integrate

## Brief description of the methods
- `Polynomial(size_t degree)`. GIVEN. Creates a polynomial of degree `degree`, dynamically allocates an array of size `degree + 1` and sets the coefficients to 0.0
- `Polynomial(size_t degree, const float* coefficients)`. GIVEN. Creates a polynomial of degree `degree` and with the values of the coefficients in the `coefficients` array
- `Polynomial(const Polynomial& other)`. GIVEN. Copy constructor, creates a deep copy of the `other` polynomial.
- `~Polynomial`. TODO. Destructor, deallocates the allocated memory.
- `const Polynomial Sum(const Polynomial& rhs)const`. TODO. Returns a polynomial that will contain the sum of `this` with `rhs`. Notice that this operation does not change `this`.
- `const Polynomial Subtract(const Polynomial& rhs)const`. TODO. Returns a polynomial that will contain the subtraction of `this` with `rhs`. Notice that this operation does not change `this`.
- `const Polynomial Minus()const`. TODO. Returns a polynomial that will contain the additive inverse of `this`. For instance if the polynomial is p = 2x^2 - 2, then p.Minus() would return -2x^2 + 2. Notice that this operation does not change `this`.
- `const Polynomial Multiply(const Polynomial& rhs)const`. TODO. Returns a polynomial that will contain the multiplication of `this` with `rhs`. Notice that this operation does not change `this`.
- `const Polynomial Divide(const Polynomial& rhs)const`. TODO. EXTRA CREDIT. Returns a polynomial that will contain the division of `this` with `rhs`. Notice that this operation does not change `this`. The reminder is lost if there was one.
- `const Polynomial Derive()const`. TODO. Returns a polynomial that will contain the derivative of `this`. Notice that this operation does not change `this`.
- `float Evaluate(float x)const`. TODO. Returns the value of evaluating the polynomial with value `x`. Notice that this operation does not change `this`.
- `float Integrate(float a, float b)const`. TODO. EXTRA CREDIT. Returns the value of the definite integral evaluated from `a` to `b`. Notice that this operation does not change `this`.
- `const Polynomial& operator=(const Polynomial& rhs)`. GIVEN. Assigns the polynomial `rhs` to `this`.
- `string ToString()const`. GIVEN. Returns a `string` representation of the polynomial.
- `bool Equals(const Polynomial& rhs)const`. GIVEN. Returns `true` if `this` is equal to `rhs`.
- `ostream& Write(ostream& output)const`. GIVEN. Writes a polynomial from the `output` stream.
- `istream& Read(istream& input)`. GIVEN. Reads a polynomial from the `input` stream.



