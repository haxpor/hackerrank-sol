# hackerrank-sol

My solutions on hackerrank.com. Sources are based on C++ with focus on using not more than C++11.
Use gcc 9.0 (g++) on Linux system.

# How to compile

Each source can be compiled with `g++ -std=c++11 <source-file>` with or without optimization flag like `-O2` or `-O3`
in case you really need to optimize the application to try to make it execute within <2 second which is
the upper bound limit [environment](https://www.hackerrank.com/environment) on hackerank website.

**Note** two libraries are ok to be linked with your application which are `-lm` and `-lpthread`, with additional of
[json library](http://www.digip.org/jansson/) if you ever need it. So link as per your need.

# How to execute

Each solution will be tested with a defined test case which is given for free (no exchange of Hackos point for such test case),
but if such source is pushed on this repository (otherwise noted) it will work with upstream's test cases.

Even sometimes I exchanged a certain test case with points, but I won't push those files here to not spoil other
hackerrank participations. Test cases can be found in `testcases/` directory.

# License

MIT, Wasin Thonkaew
