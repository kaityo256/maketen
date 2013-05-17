------------------------------------------------------------------------
# Make Ten Enumerator
------------------------------------------------------------------------
[Japanese](README_ja.md)
------------------------------------------------------------------------
## Summary

This program enumerates all possible solutions of the Make Ten problem.

------------------------------------------------------------------------
## Usage

    $ make
    $ ./maketen
------------------------------------------------------------------------
## Result

    (1+1)*(1+4)=10
    (1+1)*(1*5)=10
    ((1+1)*1)*5=10
    (1+(1*1))*5=10
    ((1+1)/1)*5=10
    (1+(1/1))*5=10
    (1+1)/(1/5)=10
       (snip)
    9-((9/9)-2)=10
    ((9+9)/9)*5=10
    (9+9)/(9/5)=10
    ((9+9)/9)+8=10
    (9+(9*9))/9=10
    ((9*9)+9)/9=10
------------------------------------------------------------------------

