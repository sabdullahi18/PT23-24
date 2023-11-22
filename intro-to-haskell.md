# Introduction to Haskell
## Lists and Tuples
### Lists
Haskell lists are __homogeneous__ data structures, meaning all the elements of the list must be the same type. A list is surrounded by square brackets and the elements are separated by commas. Use ```let``` as keyword to define a name in GHCi.
```
Prelude> let x = 5
Prelude> x
5
```
#### Concatenation
Appending
```
Prelude> "Hello" ++ " " ++ "World"
"Hello World"
```
#### Cons
Prepending
```
Prelude> 'H' : "ello"
"Hello"
```
### Accessing List Elements
Get list member by index
```
Prelude> "Hello" !! 0
'H'
```
### List Comparison
Lists can be compared if the items contained in the lists can be compared (e.g. letters, integers, etc.) Items are compared in lexicographical (i.e. dictionary) order using <, <=, >, >=.
```
Prelude> [5,3,7] > [4,0,0]
True
Prelude> [7,90,45,5] > [7,67,5,6]
True
Prelude> [7,90,45,5] > [7,90,45,6]
False
```
The nonempty list is considered greater than an empty one.
### Using Ranges with Lists
```
Prelude> [1..10]
[1,2,3,4,5,6,7,8,9,10]
Prelude> [‘m’..’q’]
“mnopq”
Prelude> [‘A’..’J’]
“ABCDEFGHIJ”
```
### Steps and Ranges
```
Prelude> [2,4..10]
[2,4,6,8,10]
Prelude> [3,6..30]
[3,6,9,12,15,18,21,24,27,30]
Prelude> [20..1]
[ ]
Prelude> [20,19..1]
[20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1]
```
### Laziness and infinite lists
```
Prelude> take 11 [13,26..]
[13,26,39,52,65,78,91,104,117,130,143]
```
#### cycle
```
Prelude> take 5 (cycle [4,3,2])
[4,3,2,4,3]
```
#### repeat
```
Prelude> take 6 (repeat 7)
[7,7,7,7,7,7]
```
#### replicate
```
Prelude> replicate 5 ‘a’
“aaaaa”
```
__CAUTION:__ floating point numbers only have finite precision
```
Prelude> [0.1, 0.3..1]
[0.1,0.3,0.5,0.7,0.899999999999,1.0999999999]
```
### List Comprehension
Similar to set comprehension in mathematics, e.g. {2.x | x>0 and x in Z} (set of all even whole numbers).
```
Prelude> [ x*2 | x <- [1..10]]
[2,4,6,8,10,12,14,16,18,20]
Prelude> [ x*2 | x <- [1..10], x*2 >= 12]
[12,14,16,18,20]
Prelude> [ x | x <- [50..100], x `mod` 7 == 5]
[54,61,68,75,82,89,96]
Prelude> [ x | x <- [10..30], x /= 13, x /= 23, odd x ]
[11,15,17,19,21,25,27,29]
Prelude> [ x + y | x <- [17..20], y <- [10,100,0]]
[27,117,17,28,118,18,29,119,19,30,120,20]
Prelude> [ x*y | x <- [2,5,10], y <- [8,10,11]]
[16,20,22,40,50,55,80,100,110]
Prelude> [ x*y | x <- [2,5,10], y <- [8,10,11], x*y > 50]
[55,80,100,110]
```
#### sum
This calculates the length of a list by mapping each element to the integer 1 and calculating the sum of all those integers.
```
length’ xs = sum [ 1 | _ <- xs]
```
#### elem
This makes the string lowercase by checking if the character in the list is an element of the alphabet (i.e. an element of the list of all characters).
```
keepLowerCase st = [ c | c <- st, c ‘elem’ [‘a’..’z’]]
```
### Nested List Comprehension
For each list in the list of lists, only select the elements that are even.
```
xxs = [[1,3,5,7,8,7,6,2],[2,3,4,5,6,1],[12,6,7,8,9,4,6,77]]
Prelude> [ [x | x <- xs, even x] | xs <- xxs ]
[[8,6,2],[2,4,6],[12,6,8,4,6]]
```
### Tuples
Lists only have homogeneous elements vs Tuples can have heterogeneous elements. Lists have flexible size: grow, shrink vs Tuples have a fixed size.
```
Prelude> (1,10)
(1,10)
Prelude> (“Hi!”, ‘a’, 72, 1.01)
(“Hi!”, ’a’, 72, 1.01)
```
Use of tuples enforces a type discipline. The type discipline extends to within the tuples, so [(1,2),(1,’a’)] is a problem too.
#### zip
```
Prelude> zip [1,3,5,7,9] [‘a’,’b’,’c’,’j’,’k’]
[(1,’a’),(3,’b’),(5,’c’),(7,’j’),(9,’k’)]
Prelude> zip [5,3,4,2,6,7,8,9,0,1,2,3] [5,6,7]
[(5,5),(3,6),(4,7)]
Prelude> zip [10..] [5,6,7]
[(10,5),(11,6),(12,7)]
```
## Types and Classes
### Types
A type is a collection of related values. We use the notation e :: T to mean that evaluating the expression e will produce a value of type T.
```
False :: Bool
not :: Bool → Bool
not False :: Bool
False && True :: Bool
```
Every expression must have a valid type, which is calculated prior to evaluating the expression by a process called __type inference__. Haskell programs are __type safe__, because type errors can never occur during evaluation. Type inference detects a very large class of programming errors, and is one of the most powerful and useful features of Haskell.

- ```Bool``` - Logical values
- ```Char``` - Single characters
- ```String``` - Strings of characters
- ```Int``` - Fixed-precision integers
- ```Integer``` - Arbitrary-precision integers
### List Types
A list is sequence of values of the same type. [T] is the type of lists with elements of type T. For example:
```
[False,True,False] :: [Bool]
[’a’,’b’,’c’,’d’] :: [Char]
```
The type of the list says nothing about its length. 
### Tuple Types
A tuple is a sequence of values of different types:
```
(False,True) :: (Bool,Bool)
(False,’a’,True) :: (Bool,Char,Bool)
```
(T1,T2,…,Tn) is the type of n-tuples whose
components have type Ti for any i in 1…n. The type of a tuple encodes its arity:
```
(False,True) :: (Bool,Bool)
(False,True,False) :: (Bool,Bool,Bool)
(’a’,(False,’b’)) :: (Char,(Bool,Char))
(True,[’a’,’b’]) :: (Bool,[Char])
```
### Function Types
```
not :: Bool → Bool
isDigit :: Char → Bool
```
A function is a mapping from values of one type to values of another type: T1 → T2 is the type of functions that map arguments of type T1 to results of type T2.
### Curried Functions
Functions with multiple arguments are also possible by returning functions as results.
```
add’ :: Int → (Int → Int)
add’ x y = x+y
```
add’ takes an integer x and returns a function. In turn, this function takes an integer y and returns the result x+y.

add and add’ produce the same final result, but add
takes its two arguments at the same time, whereas
add’ takes them one at a time:
```
add :: (Int,Int) → Int
add’ :: Int → (Int → Int)
```
Functions with more than two arguments can be
curried by returning nested functions.
```
mult :: Int → (Int → (Int → Int))
mult x y z = x*y*z
```
The brackets are not strictly necessary.
### Polymorphic Types
The type for length includes a type variable `a`:
```
length :: [a] → Int
```
It means 'For any type a, length takes a list of values of
type a and returns an integer'. A type with variables is called __polymorphic__.
### Overloaded Types
The arithmetic operator + calculates the sum of any two numbers of the same numeric type. For example:
```
> 1+2
 3
> 1.1 + 2.2
 3.3
```
This idea is made precise in the type for + by the inclusion of a class constraint:
```
(+) :: Num a ⇒ a → a → a
```
It means 'For any type a in the class Num of
numeric types, + takes two values of
type a and returns another'. A type with constraints is called __overloaded__.
### Classes
A class is a collection of types that support certain operations, called the methods of the class.
- ```Eq``` - Equality
- ```Ord``` - Ordered
- ```Show``` - Showable
- ```Read``` - Readable
- ```Num``` - Numeric

For example:
```
(==) :: Eq a ⇒ a → a → Bool
(<) :: Ord a ⇒ a → a → Bool
show :: Show a ⇒ a → String
read :: Read a ⇒ String → a
(∗) :: Num a ⇒ a → a → a
```
## Defining Functions
### Conditional Expressions
```
abs :: Int → Int
abs n = if n ≥ 0 then n else -n
```
They can be nested too.
```
signum :: Int → Int
signum n = if n < 0 then -1 else
 if n == 0 then 0 else 1
```
There must __always__ be an else branch. As an alternative, you can use guarded equations.
```
abs n | n ≥ 0 = n
      | otherwise = -n

signum n | n < 0 = -1
         | n == 0 = 0
         | otherwise = 1
```
### Pattern Matching
```
(&&) :: Bool → Bool → Bool
True && True = True
True && False = False
False && True = False
False && False = False
```
This can be defined compactly by:
```
True && True = True
 _ && _ = False
```
However, this is more efficient as it avoids evaluating the second argument if the first argument is False.
```
False && _ = False
True && b = b
```
_ means wildcard (it can by anything).
### head and tail
```
head :: [a] → a
head (x:_) = x
tail :: [a] → [a]
tail (_:xs) = xs
```
### Lambda Expressions
A function can be constructed without giving it a name by using a lambda expression.
```
λx → x+1
\x -> x+1 --Haskell syntax
```
This is equivalent to 'The nameless function that takes a
number x and returns the result x+1'. For example:
```
add x y = x+y
means
add = λx → (λy → x+y)
```
## Recursive Functions
### Factorial
```
factorial 0 = 1
factorial n = n * factorial (n-1)
```
### Product
```
product :: [Int] → Int
product [] = 1
product (x:xs) = x * product xs
```
### Quicksort
```
qsort :: [Int] → [Int]
qsort [] = []
qsort (x:xs) = qsort [a | a ← xs, a ≤ x]
 ++ [x] ++
 qsort [b | b ← xs, b > x]
```
### General Pattern for Recursion
f maps the empty list to a value v, and any non-empty list to a function ⊕ applied to its head and f of its tail.
```
f [] = v
f (x:xs) = x ⊕ f xs
```
## Higher-order Functions
Takes a function as a parameter and returns a function.
### map
```
map :: (a → b) → [a] → [b]

> map (+1) [1,3,5,7]
[2,4,6,8]

map f xs = [f x | x ← xs] --list comprehension

map f [] = []
map f (x:xs) = f x : map f xs --recursion
```
### filter
```
filter :: (a → Bool) → [a] → [a]

> filter even [1..10]
[2,4,6,8,10]

filter p xs = [x | x ← xs, p x] --list comprehension

filter p [] = []
filter p (x:xs)
 | p x = x : filter p xs
 | otherwise = filter p xs --recursion
```
### foldr
```
foldr ::(a -> b -> b) -> b -> [a] -> b

sum [1,2]
= foldr (+) 0 [1,2]
= foldr (+) 0 (1 : (2 : []))
= 1 + (foldr (+) 0 (2 : []))
= 1 + (2 + (foldr (+) 0 []))
= 1 + (2 + 0)
= 3

foldr (⊕) v [] = v
foldr (⊕) v (x:xs) = x ⊕ foldr (⊕) v xs
```
### Sum of Squares of Positive Integers in a List
```
f :: [Int] -> Int
f xs = foldr (+) 0 (map sqr (filter pos xs))
 where
 sqr x = x*x
 pos x = x > 0
```
### The Largest Number Under 100,000 Divisible by 3829
```
largestDivisible :: (Integral a) => a  
largestDivisible = head (filter p [100000,99999..])  
    where p x = x `mod` 3829 == 0
```
## User Defined Types
### Type Declaration
```
type Pos = (Int,Int)

origin :: Pos
origin = (0,0)

left :: Pos -> Pos
left (x,y) = (x-1,y)
```
They can also have parameters
```
mult :: Pair Int -> Int
mult (m,n) = m*n
copy :: a -> Pair a
copy x = (x,x)
```
### Data Declarations
A completely new type can be defined by specifying its values by using data declaration.
```
data Bool = False | True
```
Bool is a new type, with two new values False and True. The two values False and True are called the __constructor__ for the type Bool.

- Type and constructor names must be always begin with an uppercase letter
- Data declaration are similar to content free grammar. The former specifies the values of a type, the latter the sentences of a language.
```
data Answer = Yes | No | Unknown
answers :: [Answer]
answers :: [Yes, No, Unknown]
flip :: Answer -> Answer
flip Yes = No
flip No = Yes
flip Unknown = Unknown
```
The constructor in a data declaration can also have parameters.
```
Circle :: Float -> Shape
Rect :: Float -> Float -> Shape

data Shape = Circle Float | Rect Float Float

square :: Float -> Shape
square n = Rect n n

area :: Shape -> Float
area (Circle r) = pi * r^2
area (Rect x y) = x * y
```
### Recursive Types
```
data Nat = Zero | Succ Nat
```
Nat is a new type, with constructors Zero :: Nat and Succ:: Nat -> Nat. A value of type Nat is either Zero, or of the form Succ n where n :: Nat.

Using recursion, it is easy to define functions that convert between values of type Nat and Int
```
nat2int :: Nat -> Int
nat2int Zero = 0
nat2int (Succ n) = 1 + nat2int n
int2nat :: Int -> Nat
int2nat 0 = Zero
int2nat n = Succ (int2nat (n-1))
```
### Binary Tree
Using recursion, a suitable new type to represent binary trees can be declared.
```
data Tree a = Leaf a | Node (Tree a) a (Tree a)

t :: Tree Int
t = Node (Node (Leaf 5) 2 (Leaf 6)) 1 (Node (Leaf 7) 3 (Leaf 8))
```
## Efficiency
Naive approach to reversing a list
```
reverse :: [a] -> [a]
reverse [] = []
reverse (x : xs) = reverse xs ++ [x]
```
It's slow because:
- It takes (length of xs) calls to reverse
- Each call to reverse takes (length of xs) calls to ++
- Reversing a list of length n requires (n-1) + (n-2) + . . . + 2 + 1 = O (n*n) steps

More efficient approach
```
reverse1:: [a] -> [a]
reverse1 xs = revInto [] xs
 where revInto ys [] = ys
 revInto ys (x:xs) = revInto (x:ys) xs
```
### Queue
FIFO - first in, first out (i.e. you add to the back and take out from the front)
```
empty :: Q a -- an empty queue
add :: a -> Q a -> Q a -- add element at back
remove :: Qa -> Qa -- remove element from front
front :: Qa -> a -- inspect front element
isEmpty :: Qa -> Bool -- check if queue is empty

data Q a = Q [a] deriving (Eq, Show)
empty = Q [ ]
add x (Q xs) = Q (xs ++ [x])
remove (Q (x : xs)) = Q XS
front (Q (x : xs)) = x
isEmpty (Q xs) = null xs
```
### Smart Queue
```
data Q a = Q [a] [a] deriving (Eq, Show)
```
One list to represent front of the queue, and the other for the back. Front is only empty when back is also empty.
```
empty = Q [] []
isEmpty q = q == empty
add x (Q front back) = fixQ (Q front (x:back))
front (Q (x:front) back) = x
remove (Q (x:front) back) = fixQ (Q front back)
```
#### Flipping
If front is empty, replace it with reverse back.
```
fixQ (Q [] back) = Q (reverse back) []
fixQ q = q
```
- fixQ takes one call per element
- each element is flipped exactly once
- so O(1) to add, O(1) to flip, O(1) to remove
## Problem Solving
### foldl
Like foldr, but fold from the left instead of right.
```
foldr (op) z [ ] = z
foldr (op) z (x : xs) = x op (foldr (op) z xs)

foldl (op) z [ ] = z
foldl (op) z (x : xs) = foldl (op) (z op x) xs

foldl (+) 0 [1,2]
= foldl (+) 0 (1:(2:[]))
= foldl (+) (0 + 1) (2:[])
= foldl (+) ((0 + 1) + 2) []
= ((0 + 1) + 2)
= 3
```
### Reverse Polish Notation
```3 * (8 - 5) + 7``` becomes ```3 8 5 - * 7 +```

Implementation (don't worry too much about this)
```
import Data.List
evalRPN :: (Num a, Read a) => String -> a
evalRPN = head . foldl procStack [ ] . words 

procStack :: (Num a, Read a) => [a] -> String -> [a]
procStack (x : y : ys) “*” = (y*x) : ys
procStack (x : y : ys) “+” = (y+x) : ys
procStack (x : y : ys) “-” = (y-x) : ys
procStack xs numString = read numString : xs

evalRPN “3 8 5 - * 7 +”
= head . foldl procStack [ ] . words “3 8 5 - * 7 +”
= head . foldl procStack [ ] [“3”, “8”, “5”, “-”, “*”, “7”, “+”]
= head . foldl procStack (procStack [ ] “3”) [“8”, “5”, “-”, “*”, “7”, “+”]
= head . foldl procStack (procStack [3] “8”) [“5”, “-”, “*”, “7”, “+”]
= head . foldl procStack (procStack [8,3] “5”) [“-”, “*”, “7”, “+”]
= head . foldl procStack (procStack [5,8,3] “-”) [“*”, “7”, “+”]
= head . foldl procStack (procStack [8-5,3] “*”) [“7”, “+”]
= head . foldl procStack (procStack [3 *(8-5)] “7”) [“+”]
= head . foldl procStack (procStack [7, 3 *(8-5)] “+”) [ ]
= head (procStack [7, 3*(8-5)] “+”)
= head [3 *(8-5) + 7]
= 3*(8-5)+7
= 16
```
### Matrices
```
type Matrix = [[Int]]
```
1.  Every list in the list has the same length
2.  There is at least one row and one column

Map length over list; check every number is the same for 1. The list is non-empty for 2.
```
valid :: Matrix -> Bool
valid [ ] = False
valid (x : xs) = not (null x) && uniform (map length (x : xs))
```
#### all
```
all :: (a -> Bool) -> [a] -> Bool
all p xs = foldr (&&) True (map p xs)
```
Function Composition
```
all :: (a -> Bool) -> [a] -> Bool
all p = foldr (&&) True . map p
```
#### uniform
```
uniform :: [Int] -> Bool
uniform [ ] = True
uniform xs = all (== head xs) (tail xs)
```
### Adding Matrices
zipWith is a library function, but here is its implementation
```
zipWith’ :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith’ f xs ys = [f x y | (x, y) <- zip xs ys]
```
Calculating width
```
matrixWidth :: Matrix -> Int
matrixWidth xss = length (head xss)
```
Calculating height
```
matrixHeight :: Matrix -> Int
matrixHeight xss = length xss
```
Therefore:
```
plusM :: Matrix -> Matrix -> Matrix
plusM m n | ok = zipWith (zipWith (+)) m n
 where ok = valid m && valid n
&& matrixWidth m == matrixWidth n
&& matrixHeight m == matrixHeight n
```
```plusM m n | ok = zipWith (zipWith (+)) m n```: This line performs the matrix addition if the condition ok is true. It uses the zipWith function twice: first to combine the rows of the matrices (zipWith (+)) m n) and then again to combine the individual elements of each row.
## Interactive Programs
Haskell programs have no side effects, but interactive programs do. Side effects are reading from the keyboard and writing to the screen.
- ```IO Char``` - the type of actions that return Char
- ```IO ( )``` - The type of purely side effecting actions that return no result value.
### getChar
Reads a character from the keyboard, echoes to the screen, and returns the character as a result.
```
getChar :: IO Char
```
### putChar
Writes the character c to the screen, and returns no result value.
```
putChar :: Char -> IO ()
```
### return
The action return v simply returns the value v, without performing any interaction.
```
return :: a -> IO a
```
### Sequencing Actions
```
getTwo :: IO (Char,Char)
getTwo = do
    x <- getChar
    y <- getChar
    return (x,y)
```
Layout rules apply. The value returned by the last action is the value returned by the sequence as a whole.
### getLine
Reading a string from the keyboard
```
getLine :: IO String
getLine = do
    x <- getChar
    if x == '\n' then
        return []
    else
        do xs <- getLine
            return (x:xs)
```
### putStr
Writing a string to the screen.
```
putStr :: String -> IO ()
putStr [] = return ()
putStr (x:xs) = do
    putChar x
    putStr xs
```
### putStrLine
Writing a new string and moving to the next line.
```
putStrLn :: String -> IO ()
putStrLn xs = do
    putStr xs
    putChar '\n'
```
### strlen
```
strlen :: IO ()
strlen = do
    putStr "Enter a string: "
    xs <- getLine
    putStr "The string has "
    putStr (show (length xs))
    putStrLn " characters"
```