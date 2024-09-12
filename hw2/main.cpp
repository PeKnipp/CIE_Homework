/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 02/05/2024
// Name: main.cpp
// Description: Runs a series of tests to ensure correctness of Fraction class
//
/////////////////////////////////////////////////////////////

#include <iostream>
#include "Fraction.h"
int main() {

    //TEST #0
    //ensure constructor works properly

    //0.1 no arguments
    Fraction noArg;
    if (noArg.getNumerator() == 1 && noArg.getDenominator() == 1){
        cout << "TEST 0.1 PASSED - correctly constructed Fraction without arguments"<<endl;
    }
    else cout << "TEST 0.1 FAILED - incorrectly constructed Fraction without arguments"<<endl;

    //0.2 one arguments
    Fraction oneArg(5);
    if (oneArg.getNumerator() == 5 && oneArg.getDenominator() == 1){
        cout << "TEST 0.2 PASSED - correctly constructed Fraction with one arguments"<<endl;
    }
    else cout << "TEST 0.2 FAILED - incorrectly constructed Fraction with one arguments"<<endl;

    //0.3 two arguments
    Fraction twoArg(6,7);
    if (twoArg.getNumerator() == 6 && twoArg.getDenominator() == 7){
        cout << "TEST 0.3 PASSED - correctly constructed Fraction with two arguments"<<endl;
    }
    else cout << "TEST 0.3 failed - incorrectly constructed Fraction with two arguments"<<endl;


    //TEST #1
    //Ensure setter and getters are working properly

    //1.1 check getNumerator
    Fraction a(2,4);
    if (a.getNumerator() == 2){
        cout << "TEST 1.1 PASSED - getNumerator returned correct value: " << a.getNumerator()<<endl;
    }
    else cout << "*TEST 1.1 FAILED - getNumerator returned incorrect value: " << a.getNumerator() << "; correct value: 2"<<endl;

    //1.2 check getDenominator
    Fraction b(3,5);
    if (b.getDenominator() == 5){
        cout << "TEST 1.2 PASSED - getDenominator returned correct value: " << b.getDenominator()<<endl;
    }
    else cout << "*TEST 1.2 FAILED - getDenominator returned incorrect value: " << b.getDenominator() << "; correct value: 5"<<endl;

    //1.3 check correct sign is in numerator
    //1.3.1 negative sign starts in numerator
    Fraction c(-4,6);
    if (c.getNumerator() == -4 && c.getDenominator() == 6){
        cout << "TEST 1.3.1 PASSED - negative sign is in numerator: "<<c.getNumerator()<<"/"<<c.getDenominator()<<endl;
    }
    else cout << "*TEST 1.3.1 FAILED - negative sign is not in numerator: "<<c.getNumerator()<<"/"<<c.getDenominator()<<"; correct value: -4/6"<<endl;

    //1.3.2 negative sign starts in denominator
    c.setFraction(5, -7);
    if (c.getNumerator() == -5 && c.getDenominator() == 7){
        cout << "TEST 1.3.2 PASSED - negative sign is in numerator: "<<c.getNumerator()<<"/"<<c.getDenominator()<<endl;

    }
    else cout << "*TEST 1.3.2 FAILED - negative sign is not in numerator: "<<c.getNumerator()<<"/"<<c.getDenominator()<<"; correct value: -5/7"<<endl;

    //1.3.3 both numbers have negative sign
    c.setFraction(-6,-8);
    if (c.getNumerator() == 6 && c.getDenominator() == 8){
        cout << "TEST 1.3.3 PASSED - neither number have a negative sign: " <<c.getNumerator()<<"/"<<c.getDenominator()<<endl;
    }
    else cout <<"*TEST 1.3.3 FAILED - one or both numbers have a negative sign: "<<c.getNumerator()<<"/"<<c.getDenominator()<<"; correct value: 6/8"<<endl;

    //1.4 check for correct interactions with zero
    //1.4.1 zero in numerator
    Fraction d(0, 10);
    if (d.getNumerator() == 0){
            cout << "TEST 1.4.1 PASSED - correctly sets numerator as zero: "<< d.getNumerator()<<"/"<<d.getDenominator()<<endl;
    }
    else cout << "*TEST 1.4.1 FAILED - incorrectly set numerator: "<<d.getNumerator()<<"/"<<d.getDenominator()<<"; correct value: 0/10"<<endl;

    //1.4.2 zero in denominator
    d.setFraction(20, 0);
    if (d.getDenominator() == 1){
            cout << "TEST 1.4.2 PASSED - correctly ignores invalid input: "<<d.getNumerator()<<"/"<<d.getDenominator()<<endl;
    }
    else cout <<"*TEST 1.4.2 FAILED - accepted invalid input: "<<d.getNumerator()<<"/"<<d.getDenominator()<<"; correct value: 20/1"<<endl;

    //1.5 check setter works on predefined variable
    Fraction e(7,9);
    e.setFraction(8,10);
    if (e.getNumerator() == 8 && e.getDenominator() == 10){
            cout <<"TEST 1.5 PASSED - correctly sets new numerator and denominator values: "<<e.getNumerator()<<"/"<<e.getDenominator()<<endl;
    }
    else cout <<"*TEST 1.5 FAILED - incorrectly sets new numerator and denominator values - "<<e.getNumerator()<<"/"<<e.getDenominator()<<"; correct value: 8/10"<<endl;


    //TEST 2
    //ensure toFloat conversion function works properly
    Fraction f(9,11);
    if (f.toFloat() - 9.0/11.0 < 0.00001){
        cout << "TEST 2 PASSED - correctly converts Fraction to float: "<<f.toFloat()<<endl;
    }
    else cout << "TEST 2 FAILED - incorrectly converts Fraction: "<<f.toFloat()<<"; correct value: "<<9.0/11.0<<endl;

    //TEST 3
    //ensure print function works properly
    Fraction g(10,12);
    g.print();
    cout << "IF THE ABOVE READ 10/12, TEST 3 PASSED" << endl;

    //TEST 4
    //ensure add function works properly

    //4.1 positive numbers
    //4.1.1 same denominator
    Fraction h(2,5);
    Fraction i(1,5);
    h.add(i);
    if (h.getNumerator() == 3 && h.getDenominator() == 5){
        cout << "TEST 4.1.1 PASSED - correctly adds positive Fractions with same denominator: " << h.getNumerator() <<"/" <<h.getDenominator() <<endl;
    }
    else cout << "*TEST 4.1.1 FAILED - incorrectly adds positive Fractions with the same denominator: " << h.getNumerator() << "/" << h.getDenominator() << "; correct value = 3/5 " << endl;

    //4.1.2 different denominator
    h.setFraction(4,5);
    i.setFraction(1,9);
    h.add(i);
    if (h.getNumerator() == 41 && h.getDenominator() == 45){
        cout << "TEST 4.1.2 PASSED - correctly adds positive Fractions with different denominators: "<< h.getNumerator() <<"/" <<h.getDenominator() <<endl;;
    }
    else cout << "*TEST 4.1.2 FAILED - incorrectly adds positive Fractions with different denominators: " << h.getNumerator() << "/" << h.getDenominator() << "; correct value = 41/45 " << endl;

    //4.2 negative numbers
    //4.2.1 same denominator
    Fraction j(-2,6);
    Fraction k(-3,6);
    j.add(k);
    if (j.getNumerator() == -5 && j.getDenominator() == 6){
        cout << "TEST 4.2.1 PASSED - correctly adds negative Fractions with the same denominator: "<< j.getNumerator() <<"/" <<j.getDenominator() <<endl;
    }
    else cout << "*TEST 4.2.1 FAILED - incorrectly adds negative Fractions with the same denominator: "<< j.getNumerator() << "/" << j.getDenominator() <<"; correct value: -5/6" <<endl;

    //4.2.2 different denominator
    j.setFraction(-1,2);
    k.setFraction(-3,7);
    j.add(k);
    if (j.getNumerator() == -13 && j.getDenominator() == 14){
        cout << "TEST 4.2.2 PASSED - correctly adds negative Fractions with different denominators: "<< j.getNumerator() <<"/" << j.getDenominator() <<endl;
    }
    else cout << "*TEST 4.2.2 FAILED - incorrectly adds negative Fractions with different denominators: " << j.getNumerator() << "/" << j.getDenominator() << "; correct value: -13/14 " << endl;

    //4.3 different signs
    //4.3.1 larger magnitude positive first
    Fraction l(2,3);
    Fraction m(-2,9);
    l.add(m);
    if (l.getNumerator() == 4 && l.getDenominator() == 9){
        cout << "TEST 4.3.1 PASSED - correctly adds Fractions with different signs if a positive Fraction with larger magnitude is first: " << l.getNumerator() << "/" << l.getDenominator() <<endl;
    }
    else cout << "*TEST 4.3.1 FAILED - incorrectly adds Fractions with different signs if a positive Fraction with larger magnitude is first: " << l.getNumerator() << "/" << l.getDenominator() << "; correct value: 4/9" << endl;

    //4.3.2 larger magnitude positive second
    l.setFraction(2,3);
    m.setFraction(-2,9);
    m.add(l);
    if (m.getNumerator() == 4 && m.getDenominator() == 9){
        cout << "TEST 4.3.2 PASSED - correctly adds Fractions with different signs if a positive Fraction with larger magnitude is second: "<< m.getNumerator() << "/" << m.getDenominator() <<endl;
    }
    else cout << "*TEST 4.3.2 FAILED - incorrectly adds Fractions with different signs if a positive Fraction with larger magnitude is second: " << m.getNumerator() << "/" << m.getDenominator() << "; correct value: 4/9" << endl;

    //4.3.3 smaller magnitude positive first
    l.setFraction(-2,3);
    m.setFraction(2,9);
    m.add(l);
    if (m.getNumerator() == -4 && m.getDenominator() == 9){
        cout << "TEST 4.3.3 PASSED - correctly adds Fractions with different signs if a positive Fraction with smaller magnitude is first: " << m.getNumerator() << "/" << m.getDenominator() << endl;
    }
    else cout << "*TEST 4.3.3 FAILED - incorrectly adds Fractions with different signs if a positive Fraction with smaller magnitude is first: " << m.getNumerator() << "/" << m.getDenominator() << "; correct value: -4/9" << endl;

    //4.3.4 smaller magnitude positive second
    l.setFraction(-2,3);
    m.setFraction(2,9);
    l.add(m);
    if (l.getNumerator() == -4 && l.getDenominator() == 9){
        cout << "TEST 4.3.4 PASSED - correctly adds Fractions with different signs if a positive Fraction with smaller magnitude is second: "<< l.getNumerator() << "/" << l.getDenominator() <<endl;
    }
    else cout << "*TEST 4.3.4 FAILED - incorrectly adds Fractions with different signs if a positive Fraction with smaller magnitude is second: " << m.getNumerator() << "/" << m.getDenominator() << "; correct value: -4/9" << endl;


    //TEST 5
    //ensure subtract function works properly

    //5.1 positive numbers
    //5.1.1 same denominator
    Fraction n(2,5);
    Fraction o(1,5);
    n.subtract(o);
    if (n.getNumerator() == 1 && n.getDenominator() == 5){
        cout << "TEST 5.1.1 PASSED - correctly subtracts positive Fractions with same denominator: " << n.getNumerator() <<"/" << n.getDenominator() <<endl;
    }
    else cout << "*TEST 5.1.1 FAILED - incorrectly subtracts positive Fractions with the same denominator: " << n.getNumerator() << "/" << n.getDenominator() << "; correct value = 1/5 " << endl;

    //5.1.2 different denominator
    n.setFraction(4,5);
    o.setFraction(1,9);
    n.subtract(o);
    if (n.getNumerator() == 31 && n.getDenominator() == 45){
        cout << "TEST 5.1.2 PASSED - correctly subtracts positive Fractions with different denominators: "<< n.getNumerator() <<"/" << n.getDenominator() <<endl;;
    }
    else cout << "*TEST 5.1.2 FAILED - incorrectly subtracts positive Fractions with different denominators: " << n.getNumerator() << "/" << n.getDenominator() << "; correct value = 31/45 " << endl;

    //5.1.3 negative result
    n.setFraction(2,5);
    o.setFraction(1,2);
    n.subtract(o);
    if (n.getNumerator() == -1 && n.getDenominator() == 10){
        cout << "TEST 5.1.3 PASSED - correctly subtracts positive Fractions with different denominators: "<< n.getNumerator() <<"/" << n.getDenominator() <<endl;;
    }
    else cout << "*TEST 5.1.3 FAILED - incorrectly subtracts positive Fractions with different denominators: " << n.getNumerator() << "/" << n.getDenominator() << "; correct value = -1/10 " << endl;

    //5.2 negative numbers
    //5.2.1 same denominator
    Fraction p(-3,6);
    Fraction q(-2,6);
    p.subtract(q);
    if (p.getNumerator() == -1 && p.getDenominator() == 6){
        cout << "TEST 5.2.1 PASSED - correctly subtracts negative Fractions with the same denominator: "<< p.getNumerator() <<"/" <<p.getDenominator() <<endl;
    }
    else cout << "*TEST 5.2.1 FAILED - incorrectly subtracts negative Fractions with the same denominator: "<< p.getNumerator() << "/" << p.getDenominator() <<"; correct value: -1/6" <<endl;

    //5.2.2 different denominator
    p.setFraction(-1,2);
    q.setFraction(-3,7);
    p.subtract(q);
    if (p.getNumerator() == -1 && p.getDenominator() == 14){
        cout << "TEST 5.2.2 PASSED - correctly subtracts negative Fractions with different denominators: "<< p.getNumerator() <<"/" << p.getDenominator() <<endl;
    }
    else cout << "*TEST 5.2.2 FAILED - incorrectly subtracts negative Fractions with different denominators: " << p.getNumerator() << "/" << p.getDenominator() << "; correct value: -1/14 " << endl;

    //5.2.3 positive result
    p.setFraction(-1,8);
    q.setFraction(-1,2);
    p.subtract(q);
    if (p.getNumerator() == 3 && p.getDenominator() == 8){
        cout << "TEST 5.2.3 PASSED - correctly subtracts positive Fractions with different denominators: "<< p.getNumerator() <<"/" << p.getDenominator() <<endl;;
    }
    else cout << "*TEST 5.2.3 FAILED - incorrectly subtracts positive Fractions with different denominators: " << p.getNumerator() << "/" << p.getDenominator() << "; correct value = 3/8 " << endl;


    //5.3 different signs
    //5.3.1 larger magnitude positive first
    Fraction r(2,3);
    Fraction s(-2,9);
    r.subtract(s);
    if (r.getNumerator() == 8 && r.getDenominator() == 9){
        cout << "TEST 5.3.1 PASSED - correctly subtracts Fractions with different signs if a positive Fraction with larger magnitude is first: " << r.getNumerator() << "/" << r.getDenominator() <<endl;
    }
    else cout << "*TEST 5.3.1 FAILED - incorrectly subtracts Fractions with different signs if a positive Fraction with larger magnitude is first: " << r.getNumerator() << "/" << r.getDenominator() << "; correct value: 8/9" << endl;

    //5.3.2 larger magnitude positive second
    r.setFraction(2,3);
    s.setFraction(-2,9);
    s.subtract(r);
    if (s.getNumerator() == -8 && s.getDenominator() == 9){
        cout << "TEST 5.3.2 PASSED - correctly subtracts Fractions with different signs if a positive Fraction with larger magnitude is second: "<< s.getNumerator() << "/" << s.getDenominator() <<endl;
    }
    else cout << "*TEST 5.3.2 FAILED - incorrectly subtracts Fractions with different signs if a positive Fraction with larger magnitude is second: " << s.getNumerator() << "/" << s.getDenominator() << "; correct value: -8/9" << endl;

    //5.3.3 smaller magnitude positive first
    r.setFraction(-2,3);
    s.setFraction(2,9);
    s.subtract(r);
    if (s.getNumerator() == 8 && s.getDenominator() == 9){
        cout << "TEST 5.3.3 PASSED - correctly subtracts Fractions with different signs if a positive Fraction with smaller magnitude is first: " << s.getNumerator() << "/" << s.getDenominator() << endl;
    }
    else cout << "*TEST 5.3.3 FAILED - incorrectly subtracts Fractions with different signs if a positive Fraction with smaller magnitude is first: " << s.getNumerator() << "/" << s.getDenominator() << "; correct value: 8/9" << endl;

    //5.3.4 smaller magnitude positive second
    r.setFraction(-2,3);
    s.setFraction(2,9);
    r.subtract(s);
    if (r.getNumerator() == -8 && r.getDenominator() == 9){
        cout << "TEST 5.3.4 PASSED - correctly subtracts Fractions with different signs if a positive Fraction with smaller magnitude is second: "<< r.getNumerator() << "/" << r.getDenominator() <<endl;
    }
    else cout << "*TEST 5.3.4 FAILED - incorrectly subtracts Fractions with different signs if a positive Fraction with smaller magnitude is second: " << s.getNumerator() << "/" << s.getDenominator() << "; correct value: -8/9" << endl;


    //TEST 6
    //ensure multiply function works properly

    //6.1 positive numbers
    Fraction t(5,6);
    Fraction u(2,3);
    t.multiply(u);
    if (t.getNumerator() == 5 && t.getDenominator() == 9){
        cout << "TEST 6.1 PASSED - correctly multiplies positive Fractions: " << t.getNumerator() << "/" << t.getDenominator() << endl;
    }
    else cout <<  "*TEST 6.1 FAILED - incorrectly multiplies positive Fractions: " << t.getNumerator() << "/" << t.getDenominator() << "; correct value: 5/9" << endl;

    //6.2 negative numbers
    t.setFraction(-2,5);
    u.setFraction(-5,7);
    t.multiply(u);
    if (t.getNumerator() == 2 && t.getDenominator() == 7){
        cout << "TEST 6.2 PASSED - correctly multiplies negative Fractions: " << t.getNumerator() << "/" << t.getDenominator() << endl;
    }
    else cout <<  "*TEST 6.2 FAILED - incorrectly multiplies negative Fractions: " << t.getNumerator() << "/" << t.getDenominator() << "; correct value: 2/7" << endl;

    //6.3 different signs
    t.setFraction(-5,9);
    u.setFraction(1,3);
    t.multiply(u);
    if (t.getNumerator() == -5 && t.getDenominator() == 27){
        cout << "TEST 6.3 PASSED - correctly multiplies Fractions with different signs: " << t.getNumerator() << "/" << t.getDenominator() << endl;
    }
    else cout <<  "*TEST 6.3 FAILED - incorrectly multiplies Fractions with different signs: " << t.getNumerator() << "/" << t.getDenominator() << "; correct value: -5/27" << endl;


    //TEST 7
    //ensure divide function works properly
    
    //7.1 positive numbers
    Fraction v(1,6);
    Fraction w(5,7);
    v.divide(w);
    if (v.getNumerator() == 7 && v.getDenominator() == 30){
        cout << "TEST 7.1 PASSED - correctly divides positive Fractions: " << v.getNumerator() << "/" << v.getDenominator() << endl;
    }
    else cout <<  "*TEST 7.1 FAILED - incorrectly divides positive Fractions: " << v.getNumerator() << "/" << v.getDenominator() << "; correct value: 7/18" << endl;

    //7.2 negative numbers
    v.setFraction(-9,10);
    w.setFraction(-1,2);
    v.divide(w);
    if (v.getNumerator() == 9 && v.getDenominator() == 5){
        cout << "TEST 7.2 PASSED - correctly divides negative Fractions: " << v.getNumerator() << "/" << v.getDenominator() << endl;
    }
    else cout <<  "*TEST 7.2 FAILED - incorrectly divides negative Fractions: " << v.getNumerator() << "/" << v.getDenominator() << "; correct value: 9/5" << endl;

    //7.3 different signs
    v.setFraction(8,9);
    w.setFraction(-5,2);
    v.divide(w);
    if (v.getNumerator() == -16 && v.getDenominator() == 45){
        cout << "TEST 7.3 PASSED - correctly divides Fractions with different signs: " << v.getNumerator() << "/" << v.getDenominator() << endl;
    }
    else cout <<  "*TEST 7.3 FAILED - incorrectly divides Fractions with different signs: " << v.getNumerator() << "/" << v.getDenominator() << "; correct value: -16/45" << endl;

    //7.4 divide by zero
    v.setFraction(1,2);
    w.setFraction(0,5);
    v.divide(w);
    if (v.getNumerator() == 1 && v.getDenominator() == 2){
        cout << "TEST 7.4 PASSED - correctly ignores division by zero. retained original value of: " << v.getNumerator() << "/" << v.getDenominator() << endl;
    }
    else cout <<  "*TEST 7.4 FAILED - does not ignore division by zero: " << v.getNumerator() << "/" << v.getDenominator() << "; correct value: 1/2" << endl;


    //TEST 8
    //ensure simplify function works properly

    //8.1 positive fraction
    Fraction x(580, 6620);
    x.simplify();
    if (x.getNumerator() == 29 && x.getDenominator() == 331){
        cout << "TEST 8.1 PASSED - correctly simplifies positive Fraction: " << x.getNumerator() << "/" << x.getDenominator() <<endl;
    }
    else cout <<"TEST 8.1 FAILED - incorrectly simplifies positive Fraction: " << x.getNumerator() << "/" << x.getDenominator() <<"; correct value 29/331"<<endl;

    //8.2 negative fraction
    Fraction y(-735, 4820);
    y.simplify();
    if (y.getNumerator() == -147 && y.getDenominator() == 964){
        cout << "TEST 8.2 PASSED - correctly simplifies negative Fraction: " << x.getNumerator() << "/" << x.getDenominator() <<endl;
    }
    else cout <<"TEST 8.2 FAILED - incorrectly simplifies negative Fraction: " << x.getNumerator() << "/" << x.getDenominator() <<"; correct value -147/964"<<endl;


    //for satisfaction
    Fraction z(06,13);

    return 0;
}

