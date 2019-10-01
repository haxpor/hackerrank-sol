/**
 * Solution to Overload Operators problem
 * at https://www.hackerrank.com/challenges/overload-operators/problem
 *
 * Analysis
 *  - the pre-existing code is locked, thus we need to create free function as operator overload.
 */

//Operator Overloading

// -- locked code -- //
#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};
// -- end of locked code -- //

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator+ (const Complex& obja, const Complex& objb)
{
    Complex result;
    result.a = obja.a + objb.a;
    result.b = obja.b + objb.b;
    return result;
}

std::ostream& operator<< (std::ostream& out, const Complex& obj)
{
    out << obj.a << "+i" << obj.b;
    return out;
}

// -- locked code -- //
int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
// -- end of locked code -- //
