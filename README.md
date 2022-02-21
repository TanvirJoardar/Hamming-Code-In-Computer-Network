
# Hamming Code


## Redundant bits –

Redundant bits are extra binary bits that are generated and added to the information-carrying bits of data transfer to ensure that no bits were lost during the data transfer.
The number of redundant bits can be calculated using the following formula:

        2^r ≥ m + r + 1 

where, r = redundant bit, m = data bit
Suppose the number of data bits is 7, then the number of redundant bits can be calculated using:

        = 2^4 ≥ 7 + 4 + 1

Thus, the number of redundant bits= 4
## Parity bits –
A parity bit is a bit appended to a data of binary bits to ensure that the total number of 1’s in the data is even or odd. Parity bits are used for error detection. There are two types of parity bits:

#### Even parity bit:

In the case of even parity, for a given set of bits, the number of 1’s are counted. If that count is odd, the parity bit value is set to 1, making the total count of occurrences of 1’s an even number. If the total number of 1’s in a given set of bits is already even, the parity bit’s value is 0.

#### Odd Parity bit –

In the case of odd parity, for a given set of bits, the number of 1’s are counted. If that count is even, the parity bit value is set to 1, making the total count of occurrences of 1’s an odd number. If the total number of 1’s in a given set of bits is already odd, the parity bit’s value is 0.

Read more on [Geeksforgeeks](https://www.geeksforgeeks.org/hamming-code-in-computer-network/)
