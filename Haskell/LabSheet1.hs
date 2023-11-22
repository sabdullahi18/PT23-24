import Data.Char (toUpper, toLower)

-- Consider a function called square which squares integers.
square :: Int -> Int
square x = x * x

-- Consider a function called pyth which takes a pair of integers and returns the sum of the squares of the two integers.
pyth :: Int -> Int -> Int
pyth x y = square x + square y

-- Write (with a type declaration) a function isTriple that takes three integers and checks whether they form the sides of a right angled 
-- triangle.
-- The last number should be the hypotenuse. Use the function pyth.
-- Improve isTriple so that the hypotenuse can be in any position. Call the new function isTripleAny.
isTriple, isTripleAny :: Int -> Int -> Int -> Bool
isTriple x y z = pyth x y == square z
isTripleAny x y z = isTriple x y z || isTriple x z y || isTriple y z x

-- Use the functions div, mod :: Int -> Int -> Int and list comprehension to write a function halfEvens :: [ Int ] -> [ Int ] which
-- halves each even number in a list. E.g. halfEvens [1,2,3,4,5,6] == [1,1,3,2,5,3]
halfEvens :: [Int] -> [Int]
halfEvens xs = [if even x then x `div` 2 else x | x <- xs] -- list comprehension

-- Use list comprehension to write a function inRange :: Int -> Int -> [Int] -> [Int] to return all numbers in the input list within the 
-- range given by the first two arguments (inclusive). For example,
-- inRange 5 10 [1..15] == [5,6,7,8,9,10]
inRange :: Int -> Int -> [Int] -> [Int]
inRange x y zs = [z | z <- zs, z >= x, z <= y]

-- Write a function countPositives to count the positive numbers in a list (the ones strictly greater than 0). For example,
-- countPositives [0,1,-3,-2,8,-1,6] == 3
countPositives :: [Int] -> Int
countPositives xs = length[x | x <- xs, x > 0]

-- Write a function capitalised :: String -> String which, given a word, capitalises it. That means that the first character should be made
-- uppercase and any other letters should be made lowercase. For example,
-- capitalised "mELboURNe" == "Melbourne"

-- Your definition should use a list comprehension and the library functions toUpper and toLower that change the case of a character. 
-- Use the internet to find out which library module they are in and how to load a module.
capitalised :: String -> String
capitalised (x:xs) = toUpper x : [toLower y | y <- xs]
capitalised [] = []

-- Using the function capitalised from the previous question, write a function title :: [String] -> [String] which, given a list of words, 
-- capitalises them as a title should be capitalised. The proper capitalisation of a title (for our purposes) is as follows: 
-- The first word should be capitalised. Any other word should be capitalised if it is at least four letters long. For example,
-- title ["tHe", "bOSun", "ANd", "thE", "BriDGe"] == ["The", "Bosun", "and", "the", "Bridge"]
-- Your function should use a list comprehension, and you will probably need some other auxiliary functions. You may use library functions 
-- that change the case of a character and the function length. You will need to write a recursive definition to cover the case when the 
-- string is empty.
title :: [String] -> [String]
title st = [if length c > 3 || c == head st then capitalised c else map toLower c | c <- st]
