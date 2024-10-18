#pragma once
#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <limits.h>

template<class T>
struct  DoubleUnsignedInt {
	T U = 0;
	T B = 0;
};

template<class T>
struct Pair {
	T A = 0;
	T B = 0;
};

template<class T> DoubleUnsignedInt<T> ConstructDoubleUnsignedInt(DoubleUnsignedInt<T> In);
template<class T> DoubleUnsignedInt<T> ConstructDoubleUnsignedInt(T In);
template<class T> DoubleUnsignedInt<T> ConstructDoubleUnsignedInt(const T& A, const T& B);
template<class T> bool Free(T& In);
template<class T> bool Free(DoubleUnsignedInt<T>& In);
bool And(const bool& A, const bool& B);
bool OR(const bool& A, const bool& B);
bool Not(const bool& A);
bool Xor(const bool& A, const bool& B);
bool Nand(const bool& A, const bool& B);
bool Nor(const bool& A, const bool& B);
bool Equal(const bool& A, const bool& B);
template<class T> size_t Size(T& In);
template<class T> size_t BitCount(DoubleUnsignedInt<T>& In);
template<class T> size_t Size(DoubleUnsignedInt<T>& In);
template<class T> bool BitIndex(DoubleUnsignedInt<T>& In, size_t P);
template<class T> DoubleUnsignedInt<T> LeftShift(DoubleUnsignedInt<T>& In, size_t N);
template<class T> DoubleUnsignedInt<T> RightShift(DoubleUnsignedInt<T>& In, size_t N);
template<class T> bool SetBit(T& In, size_t Idx, bool B);
template<class T> DoubleUnsignedInt<T> SetBit(DoubleUnsignedInt<T>& In, size_t Idx, bool B);
template<class T> bool BitIndex(DoubleUnsignedInt<T>& In, size_t P);
template<class T> bool AddEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> DoubleUnsignedInt<T> Add(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool SubEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> DoubleUnsignedInt<T> Sub(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool MUlEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> DoubleUnsignedInt<T> Mul(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool DivEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> DoubleUnsignedInt<T> Div(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool ModEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> DoubleUnsignedInt<T> Mod(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool And(DoubleUnsignedIntT > & In, bool B, size_t N);
template<class T> bool Or(DoubleUnsignedIntT > & In, bool B, size_t N);
template<class T> bool Not(DoubleUnsignedInt<T>& In, size_t N);
template<class T> bool Xor(DoubleUnsignedIntT > & In, bool B, size_t N);
template<class T> bool Nand(DoubleUnsignedIntT > & In, bool B, size_t N);
template<class T> bool Nor(DoubleUnsignedIntT > & In, bool B, size_t N);
template<class T> bool Equal(DoubleUnsignedIntT > & In, bool B, size_t N);
template<class T> bool AndEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool And(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B);
template<class T> bool OrEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool Or(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B);
template<class T> bool NotEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool Not(DoubleUnsignedIntT > & In);
template<class T> bool XorEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool Xor(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B);
template<class T> bool NandEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool Nand(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B);
template<class T> bool NorEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool Nor(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B);
template<class T> bool Equal(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B);
template<class T> bool EqualEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> int Comp(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B);
template<class T> bool Inc(DoubleUnsignedInt<T>& In);
template<class T> bool Dec(DoubleUnsignedInt<T>& In);
template<class T, class U> DoubleUnsignedInt<T> Add(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Sub(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Mul(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Div(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Mod(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> And(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Or(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Xor(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Nand(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Nor(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> DoubleUnsignedInt<T> Equal(DoubleUnsignedInt<T>& In, const U& B);
template<class T, class U> T Add(const T& In, const U& B);
template<class T, class U> T Sub(const T& In, const U& B);
template<class T, class U> T Mul(const T& In, const U& B);
template<class T, class U> T Div(const T& In, const U& B);
template<class T, class U> T Mod(const T& In, const U& B);
template<class T, class U> T And(const T& In, const U& B);
template<class T, class U> T Or(const T& In, const U& B);
template<class T, class U> T Not(const T& In);
template<class T, class U> T Nand(const T& In, const U& B);
template<class T, class U> T Nor(const T& In, const U& B);
template<class T, class U> T Equal(const T& In, const U& B);