#pragma once
#include <stdio.h>
#include <math.h>

#include "DoubleUnsignedInt.h"

struct FixedMultiprecision
{
	DoubleUnsignedInt<char> Frac;
	DoubleUnsignedInt<char> Number;
};


FixedMultiprecision ConstructMultipecision(double X);
template<class T>FixedMultiprecision ConstructMultipecision(DoubleUnsignedInt<T>& F, DoubleUnsignedInt<T>& N);
bool Free(FixedMultiprecision& In);
FixedMultiprecision Add(FixedMultiprecision& In, FixedMultiprecision& B);
FixedMultiprecision Sub(FixedMultiprecision& In, FixedMultiprecision& B);
FixedMultiprecision Mul(FixedMultiprecision& In, FixedMultiprecision& B);
FixedMultiprecision Div(FixedMultiprecision& In, FixedMultiprecision& B);
FixedMultiprecision Mod(FixedMultiprecision& In, FixedMultiprecision& B);
template<class T> FixedMultiprecision Add(Multiprecision& in, T N);
template<class T> FixedMultiprecision Sub(Multiprecision& in, T N);
template<class T> FixedMultiprecision Mul(Multiprecision& in, T N);
template<class T> FixedMultiprecision Div(Multiprecision& in, T N);
template<class T> FixedMultiprecision Mod(Multiprecision& in, T N);
template<class T> bool EQ(Multiprecision& In, T& B);
bool EQ(FixedMultiprecision& In, FixedMultiprecision& B);
template<class T> bool NotEQ(FixedMultiprecision& In, T& B);
bool NotEQ(FixedMultiprecision& In, FixedMultiprecision& B);
template<class T> bool UpperLeft(FixedMultiprecision& In, T& B);
bool UpperLeft(FixedMultiprecision& In, FixedMultiprecision& B);
template<class T> bool UpperRight(Multiprecision& In, T& B);
bool UpperRight(FixedMultiprecision& In, FixedMultiprecision& B);

template<class T, class U> FixedMultiprecision NewtonMethod(FixedMultiprecision& X, T& (*Fun)(const U&), T(*FunDash)(const U&), size_t Lim);
template<class T, class U> FixedMultiprecision BisectionMethod(FixedMultiprecision Low, FixedMultiprecision High, T* Fun(const U&), size_t Lim);
template<class T, class U> FixedMultiprecision NewtonBisectionMethod(FixedMultiprecision& X, T* BMFun(const U&), T* NMFun(const U&), T* NMFD(const T&), size_t Lim = 50)