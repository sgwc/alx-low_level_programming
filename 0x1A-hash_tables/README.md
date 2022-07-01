# 1. Dictionary data types

A hash table is typically used to implement a  **dictionary data type**, where keys are mapped to values, but unlike an array, the keys are not conveniently arranged as integers 0, 1, 2, ... . Dictionary data types are a fundamental data structure often found in  [scripting languages](http://en.wikipedia.org/wiki/Scripting%20language "WikiPedia")  like  [AWK](http://en.wikipedia.org/wiki/AWK "WikiPedia"),  [Perl](http://en.wikipedia.org/wiki/Perl "WikiPedia"),  [Python](http://en.wikipedia.org/wiki/Python "WikiPedia"),  [PHP](http://en.wikipedia.org/wiki/PHP "WikiPedia"),  [Lua](http://en.wikipedia.org/wiki/Lua "WikiPedia"), or  [Ruby](http://en.wikipedia.org/wiki/Ruby "WikiPedia"). For example, here is some Python code that demonstrates use of a dictionary accessed using an array-like syntax:

[Toggle line numbers](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#)

 [1](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-a26cb3507718c247fb6486e4d13551d1c18ef5c2_1) title = {}   # empty dictionary
 [2](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-a26cb3507718c247fb6486e4d13551d1c18ef5c2_2) title["Barack"] = "President"
 [3](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-a26cb3507718c247fb6486e4d13551d1c18ef5c2_3) user = "Barack"
 [4](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-a26cb3507718c247fb6486e4d13551d1c18ef5c2_4) print("Welcome" + title[user] + "  " + user)

In C, we don't have the convenience of reusing  []  for dictionary lookups (we'd need C++ for that), but we can still get the same effect with more typing using functions. For example, using an abstract dictionary in C might look like this:

[Toggle line numbers](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#)

 [1](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-fe0794db2b395a0947c905642fe6ca0afde75d94_1) Dict *title;
 [2](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-fe0794db2b395a0947c905642fe6ca0afde75d94_2) const char *user;
 [3](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-fe0794db2b395a0947c905642fe6ca0afde75d94_3) title = dictCreate();
 [4](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-fe0794db2b395a0947c905642fe6ca0afde75d94_4) dictSet(title, "Barack", "President");
 [5](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-fe0794db2b395a0947c905642fe6ca0afde75d94_5) user = "Barack";
 [6](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-fe0794db2b395a0947c905642fe6ca0afde75d94_6) printf("Welcome %s %s\n", dictGet(title, user), user);

As with other abstract data types, the idea is that the user of the dictionary type doesn't need to know how it is implemented. For example, we could implement the dictionary as an array of structs that we search through, but that would be expensive: O(n) time to find a key in the worst case.

# 2. Basics of hashing

If our keys were conveniently named 0, 1, 2, ..., n-1, we could simply use an array, and be able to find a record given a key in constant time. Unfortunately, naming conventions for most objects are not so convenient, and even enumerations like Social Security numbers are likely to span a larger range than we want to allocate. But we would like to get the constant-time performance of an array anyway.

The solution is to feed the keys through some hash function H, which maps them down to array indices. So in a database of people, to find "Smith, Wayland", we would first compute H("Smith, Wayland") = 137 (say), and then look in position 137 in the array. Because we are always using the same function H, we will always be directed to the same position 137.

# 3. Resolving collisions

But what if H("Smith, Wayland") and H("Hephaestos") both equal 137? Now we have a  _collision_, and we have to resolve it by finding some way to either (a) effectively store both records in a single array location, or (b) move one of the records to a new location that we can still find later. Let's consider these two approaches separately.

## 3.1. Chaining

We can't really store more than one record in an array location, but we can fake it by making each array location be a pointer to a linked list. Every time we insert a new element in a particular location, we simply add it to this list.

Since the cost of scanning a linked list is linear in its size, this means that the worst-case cost of searching for a particular key will be linear in the number of keys in the table that hash to the same location. Under the assumption that the hash function is a random function (which does not mean that it returns random values every time you call it but instead means that we picked one of the many possible hash functions uniformly at random), we can analyze the expected cost of a failed search as a function of the load factor α = n/m, where n is the number of elements in the table and m is the number of locations. We have

-   E[number of elements hashed to the same location as x]
    
    = ∑all elements y  Pr[y is hashed to the same location as x]  = n * (1/m) = n/m.
    

So as long as the number of elements is proportional to the available space, we get constant-time FIND operations.

## 3.2. Open addressing

With  _open addressing_, we store only one element per location, and handle collisions by storing the extra elements in other unused locations in the array. To find these other locations, we fix some  _probe sequence_  that tells us where to look if A[H(x)] contains an element that is not x. A typical probe sequence (called  _linear probing_) is just H(x), H(x)+1, H(x)+2, ..., wrapping around at the end of the array. The idea is that if we can't put an element in a particular place, we just keep walking up through the array until we find an empty slot. As long as we follow the same probe sequence when looking for an element, we will be able to find the element again. If we are looking for an element and reach an empty location, then we know that the element is not present in the table.

For open addressing, we always have that α = n/m is less than or equal to 1, since we can't store more elements in the table than we have locations. In fact, we must ensure that the load factor is strictly less than 1, or some searches will never terminate because they never reach an empty location. Assuming α < 1 and that the hash function is uniform, we can calculate the worst-case expected cost of a FIND operation, which as before will occur when we have an unsuccessful FIND.

Let T(n,m) be the expected number of probes in an unsuccessful search in a hash table with open addressing, n elements, and m locations. We always do at least one probe. With probability n/m we found something and have to try again in the next location, at cost T(n-1,m-1). So we have

-   T(n,m) = 1 + (n/m) T(n-1,m-1)

and

-   T(0,m) = 1.

This is an annoying recurrence to have to solve exactly. So instead we will get an upper bound by observing that the probability that we keep going is always less than or equal to n/m (since (n-i)/(m-i) < n/m when n < m). If we further leave off the case where m = 0, we get a coin-flipping problem where we are waiting to see a coin with probability n/m of coming up heads come up tails. This has the much simpler recurrence

-   T = 1 + (n/m) T

for which the solution is

-   T = 1/(1-n/m).

# 4. Choosing a hash function

Here we will describe three methods for generating hash functions. The first two are typical methods used in practice. The last has additional desirable theoretical properties.

## 4.1. Division method

We want our hash function to look as close as it can to a random function, but random functions are (provably) expensive to store. So in practice we do something simpler and hope for the best. If the keys are large integers, a typical approach is to just compute the remainder mod m. This can cause problems if m is, say, a power of 2, since it may be that the low-order bits of all the keys are similar, which will produce lots of collisions. So in practice with this method m is typically chosen to be a large prime.

What if we want to hash strings instead of integers? The trick is to treat the strings as integers. Given a string a1a2a3...ak, we represent it as ∑i  aibi, where b is a base chosen to be larger than the number of characters. We can then feed this resulting huge integer to our hash function. Typically we do not actually compute the huge integer directly, but instead compute its remainder mod m, as in this short C function:

[Toggle line numbers](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#)

 [1](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_1) /* treat strings as base-256 integers */
 [2](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_2) /* with digits in the range 1 to 255 */
 [3](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_3) #define BASE (256)
 [4](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_4) 
 [5](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_5) unsigned long
 [6](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_6) hash(const char *s, unsigned long m)
 [7](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_7) {
 [8](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_8)     unsigned long h;
 [9](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_9)     unsigned const char *us;
 [10](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_10) 
 [11](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_11)     /* cast s to unsigned const char * */
 [12](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_12)     /* this ensures that elements of s will be treated as having values >= 0 */
 [13](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_13)     us = (unsigned const char *) s;
 [14](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_14) 
 [15](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_15)     h = 0;
 [16](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_16)     while(*us != '\0') {
 [17](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_17)         h = (h * BASE + *us) % m;
 [18](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_18)         us++;
 [19](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_19)     } 
 [20](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_20) 
 [21](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_21)     return h;
 [22](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-df63c300322c630f02dbbd6a10ec3a37f640bc87_22) }

The division method works best when  m  is a prime, as otherwise regularities in the keys can produce clustering in the hash values. (Consider, for example, what happens if  m  equals 256). But this can be awkward for computing hash functions quickly, because computing remainders is a relatively slow operation.

## 4.2. Multiplication method

For this reason, the most commonly-used hash functions replace the modulus  m  with something like 232  and replace the base with some small prime, relying on the multiplier to break up patterns in the input. This yields the "multiplication method." Typical code might look something like this:

[Toggle line numbers](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#)

 [1](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_1) #define MULTIPLIER (37)
 [2](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_2) 
 [3](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_3) unsigned long
 [4](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_4) hash(const char *s)
 [5](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_5) {
 [6](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_6)     unsigned long h;
 [7](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_7)     unsigned const char *us;
 [8](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_8) 
 [9](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_9)     /* cast s to unsigned const char * */
 [10](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_10)     /* this ensures that elements of s will be treated as having values >= 0 */
 [11](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_11)     us = (unsigned const char *) s;
 [12](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_12) 
 [13](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_13)     h = 0;
 [14](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_14)     while(*us != '\0') {
 [15](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_15)         h = h * MULTIPLIER + *us;
 [16](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_16)         us++;
 [17](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_17)     } 
 [18](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_18) 
 [19](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_19)     return h;
 [20](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29#CA-08148226748ac82ed7f36d02117ac84ef05bbb0c_20) }

The only difference between this code and the division method code is that we've renamed  BASE  to  MULTIPLIER  and dropped  m. There is still some remainder-taking happening: since C truncates the result of any operation that exceeds the size of the integer type that holds it, the  h = h * MULTIPLIER + *us;  line effectively has a hidden mod 232  or 264  at the end of it (depending on how big your  unsigned longs are). Now we can't use, say, 256, as the multiplier, because then the hash value  h  would be determined by just the last four characters of  s.

The choice of 37 is based on folklore. I like 97 myself, and 31 also has supporters. Almost any medium-sized prime should work.

## 4.3. Universal hashing

The preceding hash functions offer no guarantees that the adversary can't find a set of n keys that all hash to the same location; indeed, since they're deterministic, as long as the keyspace contains at least nm keys the adversary can always do so. Universal families of hash functions avoid this problem by choosing the hash function randomly, from some set of possible functions that is small enough that we can write our random choice down.

The property that makes a family of hash functions {Hr} universal is that, for any distinct keys x and y, the probability that r is chosen so that Hr(x) = Hr(y) is exactly 1/m.

Why is this important? Recall that for chaining, the expected number of collisions between an element x and other elements was just the sum over all particular elements y of the probability that x collides with that particular element. If Hr  is drawn from a universal family, this probability is 1/m for each y, and we get the same n/m expected collisions as if Hr  were completely random.

Several universal families of hash functions are known. Here is a simple one that works when the size of the keyspace and the size of the output space are both powers of 2. Let the keyspace consist of n-bit strings and let m = 2k. Then the random index r consists of nk independent random bits organized as n m-bit strings a1,a2,...an. To compute the hash function of a particular input x, compute the bitwise exclusive or of ai  for each position i where the i-th bit of x is a 1. Formally, using XOR to mean bitwise exclusive or, we might write this as

As you can see, this requires a lot of bit-fiddling. It also fails if we get a lot of strings that are identical for the first  MAX_STRING_SIZE  characters. Conceivably, the latter problem could be dealt with by growing  x  dynamically as needed. But we also haven't addressed the question of where we get these random values from---see  [C/Randomization](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html)  for some possibilities.

Why is this family universal? Consider two distinct inputs x and y. Because they are distinct, there must be some position j where the bits xj  and yj  are different. Assume without loss of generality that xj  is zero and yj  is 1. Let

-   X = XORi != j  xiai
    

and

-   Y = XORi != j  yiai,
    

so that H(x) = X and H(y) = Y XOR ai. Suppose that we fix all the bits except for the ones in ai; then H(x) = H(y) precisely when ai  = X XOR Y, where the right-hand side is some constant value independent of ai. The probability that ai  is chosen to be exactly this value is 1/m.

In practice, universal families of hash functions are seldom used, since a reasonable fixed hash function is unlikely to be correlated with any patterns in the actual input. But they are useful for demonstrating provably good performance.

# 5. Maintaining a constant load factor

All of the running time results for hash tables depend on keeping the load factor α small. But as more elements are inserted into a fixed-size table, the load factor grows without bound. The usual solution to this problem is rehashing: when the load factor crosses some threshold, we create a new hash table of size 2n or thereabouts and migrate all the elements to it. This approach raises the worst-case cost of an insertion to O(n); however, we can bring the expected cost down to O(1) by rehashing only with probability O(1/n) for each insert after the threshold is crossed, or can apply  [AmortizedAnalysis](https://www.cs.yale.edu/homes/aspnes/pinewiki/AmortizedAnalysis.html)  to argue that the amortized cost (total cost divided by number of operations) is O(1) assuming we double the table size on each rehash.
