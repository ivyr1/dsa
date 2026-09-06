{-# OPTIONS_GHC -Wno-incomplete-patterns -Wno-type-defaults #-}
{-# OPTIONS_GHC -Wno-unused-binds -Wno-unused-top-binds #-}
{-# OPTIONS_GHC -Wno-x-partial #-}

module Main (main) where

-- fibs :: [Integer]
-- fibs = 0 : 1 : zipWith (+) fibs (drop 1 fibs)
--
-- fact :: [Integer]
-- fact = 1 : zipWith (*) fact [1 ..]

-- find the last element of a list
myLast :: [Integer] -> Integer
myLast = foldl1 (const id)

-- const: take the first val: const x y -> x
-- id: return the val: id x -> x
-- const id x y -> (const id x) y -> id y -> y

-- mylast' :: [a] -> a
-- mylast' = head . reverse
-- head(reverse [])

-- find the last-but-one (or second-last) of a list
myButlast :: [Integer] -> Integer
myButlast = head . tail . reverse

myButlast' :: [a] -> a
myButlast' (x : (_ : [])) = x
myButlast' (_ : xs) = myButlast' xs
myButlast' [] = error "Empty list"

-- find the K'th element of a list
elementAt :: [a] -> Int -> a
elementAt (x : _) 1 = x
elementAt (_ : xs) k | k > 1 = elementAt xs (k - 1)
elementAt _ _ = error "Empty list"

elementAt_w'pf :: Int -> [a] -> a
elementAt_w'pf = (last .) . take . (+ 1)

-- elementAt_w'pf :: index -> list -> element
-- return the last element of (k + 1)-element-list
-- last take (+ 1) k xs -> last take (k + 1) xs -> last xs [1..k+1]

-- find the number of element in a list
myLength :: [a] -> Int
myLength [] = 0
myLength (_ : xs) = 1 + myLength xs

myLength' :: [a] -> Int
myLength' = foldl' (\acc _ -> acc + 1) 0

-- foldl' + function + init value + list

-- Reverse a list

myReverse :: [a] -> [a]
myReverse xs = go [] xs
  where
    go acc [] = acc
    go acc (y : ys) = go (y : acc) ys

myReverse' :: [a] -> [a]
myReverse' [] = []
myReverse' (x : xs) = myReverse xs ++ [x]

myReverse''' :: [a] -> [a]
myReverse''' = foldl (\acc x -> x : acc) []

-- go + accumulator var + list
-- go acc (y: ys) -> go (y : acc) ys : append y to the first index of acc;

-- Find out whether a list a palindrome

isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome xs = x == y
  where
    x = xs
    y = reverse xs

isPalindrome' :: (Eq a) => [a] -> Bool
isPalindrome' [] = error "Invalid"
isPalindrome' [_] = True
isPalindrome' xs = (head xs) == (last xs) && (isPalindrome' $ init $ tail xs)

-- Flatten a nested list
data NestedList a = Elem a | List [NestedList a]

flatten :: NestedList a -> [a]
flatten (Elem x) = [x]
flatten (List (x : xs)) = flatten x ++ flatten (List xs)
flatten (List []) = []

-- Eliminate consecutive duplicates of list elements.

compress :: (Eq a) => [a] -> [a]
compress [] = []
compress (x : []) = [x]
compress (x : (y : xys)) =
  if x == y
    then compress (y : xys)
    else x : compress (y : xys)

compress' :: (Eq a) => [a] -> [a]
compress' =
  foldr
    ( \x acc ->
        -- if acc not a null ([]) value and x == first element of acc do not insert x
        if not (null acc) && x == head acc
          then acc
          -- append x to first index of acc
          else x : acc
    )
    []

-- Pack consecutive duplicates of list elements into sublists
pack :: (Eq a) => [a] -> [[a]]
pack (x : xs) =
  let (same, rest) = span (== x) xs
   in (x : same) : pack rest

-- let var = value
-- in expression
-- span + (f) + list: read list from left to right, stop at first element that fails the codition
-- span :: (a -> Bool) -> [a] -> ([a], [a])

-- Run-length encoding of a list
encode :: (Eq a) => [a] -> [(Int, a)]
encode [] = []
encode (x : xs) =
  let (same, rest) = span (== x) xs
      count = foldr (\_ acc -> acc + 1) 1 same
   in (count, x) : encode rest

-- Modify the result of problem 10 in such a way that if an element has no duplicates it is simply copied into the result list.
-- Only elements with duplicates are transferred as (N E) lists.

data ListItem a = Single a | Multiple Int a
  deriving (Show, Eq)

encodeModified :: (Eq a) => [a] -> [ListItem a]
encodeModified [] = []
encodeModified (x : xs) =
  let (same, rest) = span (== x) xs
      count = foldr (\_ acc -> acc + 1) 1 same
   in if count == 1
        then Single x : encodeModified rest
        else Multiple count x : encodeModified rest

-- Given a run-length code list generated as specified in problem 11.
-- Construct its uncompressed version.

decodeModified :: (Eq a) => [ListItem a] -> [a]
decodeModified [] = []
decodeModified (Single x : xs) = x : decodeModified xs
decodeModified (Multiple 0 _ : xs) = decodeModified xs
decodeModified (Multiple a b : xs) = b : decodeModified (Multiple (a - 1) b : xs)

decodeModified' :: [ListItem a] -> [a]
decodeModified' = concatMap decodeItem
  where
    decodeItem (Single x) = [x]
    decodeItem (Multiple n x) = replicate n x

-- Implement the so-called run-length encoding data compression method directly.
-- I.e. don't explicitly create the sublists containing the duplicates, as in problem 9, but only count them.
-- As in problem P11, simplify the result list by replacing the singleton lists (1 X) by X.
encodeDirect :: (Eq a) => [a] -> [ListItem a]
encodeDirect [] = []
encodeDirect (x : xs) = countOccur 1 x xs
  where
    countOccur n current (y : ys)
      | current == y = countOccur (n + 1) current ys
      | otherwise = makeItem n current : countOccur 1 y ys
    countOccur n current [] = [makeItem n current]

    makeItem 1 val = Single val
    makeItem n val = Multiple n val

-- Duplicate the elements of a list.
dupli :: [a] -> [a]
dupli [] = []
dupli (x : xs) = x : x : dupli xs

-- Replicate the elements of a list a given number of times.
repli :: [a] -> Int -> [a]
repli [] _ = []
repli (x : xs) n = repl n ++ repli xs n
  where
    repl 0 = []
    repl b = x : repl (b - 1)

-- Drop every N'th element from a list.

dropEvery :: [a] -> Int -> [a]
dropEvery [] _ = []
dropEvery xs n
  | n <= 0 = xs
  | otherwise = incr 1 xs
  where
    incr _ [] = []
    incr k (y : ys)
      | k /= n = y : incr (k + 1) ys
      | otherwise = incr 1 ys

-- Split a list into two parts; the length of the first part is given.
split :: [a] -> Int -> ([a], [a])
split [] _ = ([], [])
split xs n
  | n <= 0 = ([], xs)
  | otherwise = spl 0 xs []
  where
    spl _ [] acc = (reverse acc, [])
    spl k (y : ys) acc
      | k /= n = spl (k + 1) ys (y : acc)
      | otherwise = (reverse acc, (y : ys))

split' :: [a] -> Int -> ([a], [a])
split' [] _ = ([], [])
split' xs n
  | n <= 0 = ([], xs)
split' (x : ys) n = (x : firstPart, secondPart)
  where
    (firstPart, secondPart) = split ys (n - 1)

-- Extract a slice from a list.
slice :: [a] -> Int -> Int -> [a]
slice xs i k
  | null xs || (i == 1 && k == 0) = []
slice (x : xs) 1 n = x : slice xs 1 (n - 1)
slice (_ : xs) a b = slice xs (a - 1) (b - 1)

-- Rotate a list N places to the left.
rotate :: [a] -> Int -> [a]
rotate [] _ = []
rotate xs k
  | k > length xs || k < (-length xs) = xs
  | k < 0 = rotate xs (length xs + k)
  | otherwise = f xs k []
  where
    f ys 0 acc = ys ++ acc
    f (y : ys) n acc = f ys (n - 1) (acc ++ [y])

rotate' :: [a] -> Int -> [a]
rotate' [] _ = []
rotate' xs n =
  let k = n `mod` length xs
      (front, back) = s k xs
   in back ++ front
  where
    s 0 ys = ([], ys)
    s _ [] = ([], [])
    s m (y : ys) =
      let (f, b) = s (m - 1) ys
       in (y : f, b)

-- Remove the K'th element from a list.
removeAt :: Int -> [a] -> (Maybe a, [a])
removeAt _ [] = (Nothing, [])
removeAt 1 (x : xs) = (Just x, xs)
removeAt n (x : xs)
  | n < 1 = (Nothing, x : xs)
  | otherwise =
      let (val, rest) = removeAt (n - 1) xs
       in (val, x : rest)

main :: IO ()
main = do
  putStrLn "-- 99 problems --"

-- print (rotate' ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'] 3)
-- print (rotate' ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'] (-2))
-- print (slice ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k'] 3 7)
-- print (myReverse' [1, 2, 3, 4])
-- print (split "abcdefghik" 3)
-- print (dropEvery "abcdefghik" 3)
-- print (repli "alsjdlksajdlk" 99)
-- print (dupli [1, 2, 3])
-- print (decodeModified [Multiple 4 'a', Single 'b', Multiple 2 'c', Multiple 2 'a', Single 'd', Multiple 4 'e'])
-- print (encodeModified "aaaabccaadeeee")
-- print (encode "aaaabccaadeeee")
-- print (pack ['a', 'a', 'a', 'a', 'b', 'c', 'c', 'a', 'a', 'd', 'e', 'e', 'e', 'e'])
-- print (flatten (List [Elem 1, List [Elem 2, List [Elem 3, Elem 4], Elem 5]]))
-- print (isPalindrome "123321")
-- print (myReverse [1, 2, 3, 4])
-- print (myLength "hoangloi")
-- print (myLength' "hoangloi")
-- print (myLast [1, 2, 3])
-- print (myButlast [1, 2, 3])
-- print (myButlast' [1, 2, 3])
-- print (elementAt [1, 2, 3, 8] 2)
-- print (elementAt_w'pf 2 [1, 2, 3, 8])
