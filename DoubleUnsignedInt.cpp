#include "DoubleUnsignedInt.h"

template<class T>
DoubleUnsignedInt<T> ConstructDoubleUnsignedInt(const T& A, const T& B) {
	DoubleUnsignedInt<T> D;
	D.U = A;
	D.B = B;
	return D;
}
template<class T>
DoubleUnsignedInt<T> ConstructDoubleUnsignedInt(DoubleUnsignedInt<T> In) {
	DoubleUnsignedInt<T> D=In;
//	D.U = A;
//	D.B = B;
	return D;
}
template<class T>
DoubleUnsignedInt<T> ConstructDoubleUnsignedInt(T In) {
	DoubleUnsignedInt<T> D;
	D = Add(D, In);
//	D.U = A;
//	D.B = B;
	return D;
}
template<class T>
bool Free(T& In) {
	return true;
}
template<class T>
bool Free(DoubleUnsignedInt<T>& In) {
	Free(In.U);
	Free(In.B);

	return true;
}
bool And(const bool& A, const bool& B) {
	return A & B;
}

bool OR(const bool& A, const bool& B) {
	return A | B;
}
bool Not(const bool& A) {
	return !A;
	//  return ~A;//why not work this line...
}

bool Xor(const bool& A, const bool& B) {
	return A ^ B;
}
bool Nand(const bool& A, const bool& B) {
	return !(A & B);
}

bool Nor(const bool& A, const bool& B) {
	return !(A | B);
}
bool Equal(const bool& A, const bool& B) {
	return !(A ^ B);
}

Pair<bool> HarfAdder(const bool& A, const bool& B) {//std::get<0>() => S. std::get<1>() => C.
	bool S = Xor(A, B);
	bool C = And(A, B);

	return { S,C };
}


Pair<bool> FullAdder(const bool& A, const bool& B, const bool& X) {//std::get<0>() => S. std::get<1>() => C.
	auto AA = HarfAdder(A, B);
	auto BB = HarfAdder(AA.A, X);

	bool S = BB.A;
	bool C = OR(AA.B, BB.B);

	return { S,C };
}
template<class T>
size_t Size(T& In) {
	return sizeof(T);
}
template<class T>
size_t BitCount(DoubleUnsignedInt<T>& In) {
	return (Size(In.U) + Size(In.B)) * CHAR_BIT;
}

template<class T>
size_t Size(DoubleUnsignedInt<T>& In) {
	return Size(In.U) + Size(In.B);
}
template<class T>
bool BitIndex(T In, size_t P) {
	if (Size(In) >= P) { return false; }
	return In & (1 << P);
}
template<class T>
bool BitIndex(DoubleUnsignedInt<T>& In, size_t P) {
	intmax_t X = ((P - 1) * CHAR_BIT;
	intmax_t Y = X >= 0 ? X : 0;
	intmax_t Z = Y + (P & CHAR_BIT);

	intmax_t A = Size(In.U) * CHAR_BIT;
	intmax_t B = Z - A;
	if (B < 0) { return In.B & (1 << B); }
	return In.U & (1 << B);

}
template<class T>
DoubleUnsignedInt<T> LeftShift(T& In, size_t N) {
	DoubleUnsignedInt<T> R;

	for (size_t i = 0; i < (Size(In) * CHAR_BIT) - N; i++) {
		SetBit(R, I + N, BitIndex(In, I));
	}

	return R;
}
template<class T>
DoubleUnsignedInt<T> LeftShift(DoubleUnsignedInt<T>& In, size_t N) {
	DoubleUnsignedInt<T> R;

	for (size_t i = 0; i < (Size(In) * CHAR_BIT) - N; i++) {
		SetBit(R, I + N, BitIndex(In, I));
	}

	return R;

}
template<class T>
DoubleUnsignedInt<T> LeftShift(T& In, size_t N) {
	DoubleUnsignedInt<T> R;

	for (size_t i = 0; i < (Size(In) * CHAR_BIT); i++) {
		SetBit(R, I, BitIndex(In, I + N));
	}

	return R;
}
template<class T>
DoubleUnsignedInt<T> RightShift(DoubleUnsignedInt<T>& In, size_t N) {
	DoubleUnsignedInt<T> R;

	for (size_t i = 0; i < (Size(In) * CHAR_BIT); i++) {
		SetBit(In, I, BitIndex(In, I + N));
	}

	return R;

}
template<class T>
bool SetBit(T& In, size_t Idx, bool B) {
	T A = In & (1 << Idx);
	T B = ((In ^ 0) & ((1 << Idx) ^ 0);
	T C = B & A;
	In = C;

	return true;
}

template<class T>
DoubleUnsignedInt<T> SetBit(DoubleUnsignedInt<T>& In, size_t Idx, bool B) {
	DoubleUnsignedInt<T> R = ConstructDoubleUnsignedInt<T>(In.U, In.B);
	if (Size(R.U) * CHAR_BIT > Idx) { SetBit(R.U, Idx, B); }
	size_t P = Idx - (Size(R.U) * CHAR_BIT);

	SetBit(R.U, P, B);

	return R;

}
template<class T>
bool BitIndex(DoubleUnsignedInt<T>& In, size_t P) {
	if (P >= BitCount(In)) { return false; }
	intmax_t = ((P - 1) * CHAR_BIT;
	intmax_t Y = X >= 0 ? X : 0;
	intmax_t Z = Y + (P & CHAR_BIT);

	intmax_t A = Size(In.U) * CHAR_BIT;
	intmax_t B = Z - A;
	if (B < 0) { return In.B & (1 << B); }
	return In.U & (1 << B);

}
template<class T>
bool AddEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> C = Add(In, B);
	In = C;
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Add(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;

	for (size_t i = 0; i < Size(B), i++) {
		SetBit(X, i, BitIndex(In, P));
	}

	return Add(In, X);
}
template<class T>
DoubleUnsignedInt<T> Add(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {

	size_t L = Max(Size(In), Size(B));
	Pair<bool> X{ false,false };
	DoubleUnsignedInt<T> V = ConstructDoubleUnsignedInt(0, 0);

	L += L % 2;

	for (std::size_t i = 0; i < L; i++) {
		X = FullAdder((BitIndex(In, i) ? true : false), (BitIndex(B, i) ? true : false), X.B);
		//V |= (X.A ? 1 : 0) << i;
		//BitPush(V, X.A);
		SetBit(V, I, X.A);
	}

	return V;
}
template<class T>
bool SubEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> C = Sub(In, B);
	In = C;
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Sub(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;

	for (size_t i = 0; i < Size(B), i++) {
		SetBit(X, i, BitIndex(In, P));
	}

	return Sub(In, X);
}
template<class T>
DoubleUnsignedInt<T> Sub(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {

	size_t L = Max(Size(In), Size(B));
	Pair<bool> X{ false,true };
	DoubleUnsignedInt<T> V = ConstructDoubleUnsignedInt<T>(0, 0);

	L += L % 2;

	for (std::size_t i = 0; i < L; i++) {
		X = FullAdder((BitIndex(In, i) ? true : false), (BitIndex(B, i) ? true : false), X.B);
		//V |= (X.A ? 1 : 0) << i;
		//BitPush(V, X.A);
		SetBit(V, I, X.A);
	}

	return V;
}
template<class T>
bool MUlEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> C = Mul(In, B);
	In = C;
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Mul(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;

	for (size_t i = 0; i < Size(B), i++) {
		SetBit(X, i, BitIndex(In, P));
	}

	return Mul(In, X);
}
template<class T>
DoubleUnsignedInt<T> Mul(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> C = ConstructDoubleUnsignedInt<T>(0, 0);
	size_t L = BitCount(B);
	for (size_t i = 0; i < L; i++) {
		if ((BitIndex(In, i) & true) == true) {
			DoubleUnsignedInt<T> X = LeftShift(In, i);
			AddEQ(C, X);
		}

	}
	return C;
}
template<class T>
bool DivEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> C = Div(In, B);
	In = C;
	return true;
}

template<class T,class U>
DoubleUnsignedInt<T> Div(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;

	for (size_t i = 0; i < Size(B), i++) {
		SetBit(X, i, BitIndex(In, P));
	}

	return Div(In, X);
}
template<class T>
DoubleUnsignedInt<T> Div(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> C = ConstructDoubleUnsignedInt<T>(0, 0);
	size_t L = BitCount(B);
	for (intmax_t i = L; i >= 0; i--) {
		if (BitIndex(In, i) & true) == true){
			DoubleUnsignedInt<T> X = LeftShift(In, i);
			SubEQ(C, X);
	}

	}
	return C;
}
template<class T>
bool ModEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> C = Mod(In, B);
	In = C;
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Mod(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;

	for (size_t i = 0; i < Size(B), i++) {
		SetBit(X, i, BitIndex(In, P));
	}

	return Mod(In, X);
}
template<class T>
DoubleUnsignedInt<T> Mod(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> C = Div(In, B);
	DoubleUnsignedInt<T> D = Mul(C, B);
	DoubleUnsignedInt<T> E = Sub(In, D);

	return E;
}
template<class T>
bool And(DoubleUnsignedIntT > & In, bool B, size_t N) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	bool Y = BitIndex(In, N) & BitIndex(X, N);
	return Y;
}
template<class T>
bool Or(DoubleUnsignedIntT > & In, bool B, size_t N) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	bool Y = BitIndex(In, N) | BitIndex(X, N);
	return Y;

}

template<class T>
bool Not(DoubleUnsignedIntT > & In, size_t N) {
	bool Y = !BitIndex(In, N);
	return Y;
}
template<class T>
bool Xor(DoubleUnsignedIntT > & In, bool B, size_t N) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	bool Y = BitIndex(In, N) ^ BitIndex(X, N);
	return Y;

}
template<class T>
bool Nand(DoubleUnsignedIntT > & In, bool B, size_t N) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	bool Y = BitIndex(In, N) & BitIndex(X, N);
	return !Y;

}
template<class T>
bool Nor(DoubleUnsignedIntT > & In, bool B, size_t N) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	bool Y = BitIndex(In, N) | BitIndex(X, N);
	return !Y;

}
template<class T>
bool Equal(DoubleUnsignedIntT > & In, bool B, size_t N) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	bool Y = BitIndex(In, N) ^ BitIndex(X, N);
	return !Y;
}
template<class T,class U>
DoubleUnsignedInt<T> And(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;
	for (size_t i = 0; i < Size(B); i++) {
		SetBit(X, i, BitIndex(B, i));
	}
	return And(In, X);
}
template<class T>
bool AndEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	In = And(In, B);
	return true;
}
template<class T>
bool And(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	for (size_t i = 0 < i < BitCount(In), i++) {
		SetBit(X, i, (BitIndex(In, i) & BitIndex(B, i)));
	}
	return true;
}
template<class T>
bool OrEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	In = Or(In, B);
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Or(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;
	for (size_t i = 0; i < Size(B); i++) {
		SetBit(X, i, BitIndex(B, i));
	}
	return Or(In, X);
}
template<class T>
bool Or(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	for (size_t i = 0 < i < BitCount(In), i++) {
		SetBit(X, i, (BitIndex(In, i) | BitIndex(B, i)));
	}
	return true;
}
template<class T>
bool NotEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	In = Not(In, B);
	return true;
}

template<class T>
bool Not(DoubleUnsignedIntT > & In) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	for (size_t i = 0 < i < BitCount(In), i++) {
		SetBit(X, i, (!BitIndex(In, i))));
	}
	return true;
}
template<class T>
bool XorEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	In = Xor(In, B);
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Xor(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;
	for (size_t i = 0; i < Size(B); i++) {
		SetBit(X, i, BitIndex(B, i));
	}
	return Xor(In, X);
}
template<class T>
bool Xor(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	for (size_t i = 0 < i < BitCount(In), i++) {
		SetBit(X, i, (BitIndex(In, i) ^ BitIndex(B, i)));
	}
	return true;
}
template<class T>
bool NandEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	In = Nand(In, B);
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Nand(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;
	for (size_t i = 0; i < Size(B); i++) {
		SetBit(X, i, BitIndex(B, i));
	}
	return Nand(In, X);
}
template<class T>
bool Nand(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	for (size_t i = 0 < i < BitCount(In), i++) {
		SetBit(X, i, !(BitIndex(In, i) & BitIndex(B, i)));
	}
	return true;
}
template<class T>
bool NorEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	In = Nor(In, B);
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Nor(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;
	for (size_t i = 0; i < Size(B); i++) {
		SetBit(X, i, BitIndex(B, i));
	}
	return Nor(In, X);
}
template<class T>
bool Nor(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	for (size_t i = 0 < i < BitCount(In), i++) {
		SetBit(X, i, !(BitIndex(In, i) | BitIndex(B, i)));
	}
	return true;
}
template<class T>
bool EqualEQ(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	In = Equal(In, B);
	return true;
}
template<class T,class U>
DoubleUnsignedInt<T> Equal(DoubleUnsignedInt<T>& In, const U& B) {
	DoubleUnsignedInt<T> X;
	for (size_t i = 0; i < Size(B); i++) {
		SetBit(X, i, BitIndex(B, i));
	}
	return Nor(In, X);
}
template<class T>
bool Equal(DoubleUnsignedIntT > & In, DoubleUnsignedInt<T>& B) {
	DoubleUnsignedInt<T> X = ConstructDoubleUnsignedInt();
	for (size_t i = 0 < i < BitCount(In), i++) {
		SetBit(X, i, !(BitIndex(In, i) ^ BitIndex(B, i)));
	}
	return true;
}


template<class T>
int Comp(DoubleUnsignedInt<T>& In, DoubleUnsignedInt<T>& B) {
	return memcmp((void*)&In, (void*)&B, Size(In));
}
template<class T>
bool Inc(DoubleUnsignedInt<T>& In) {
	return AddEQ(In, 1);
}
template<class T>
bool Dec(DoubleUnsignedInt<T>& In) {
	return SubEQ(In, 1);
}

template<class T,class U>
T Add(const T& In, const U& B) {
	return In + B;
}
template<class T,class U>
T Sub(const T& In, const U& B) {
	return In - B;
}
template<class T,class U>
T Mul(const T& In, const U& B) {
	return In * B;
}
template<class T,class U>
T Div(const T& In, const U& B) {
	return In / B;
}
template<class T,class U>
T Mod(const T& In, const U& B) {
	return In % B;
}
template<class T,class U>
T And(const T& In, const U& B) {
	return In & B;
}
template<class T,class U>
T Or(const T& In, const U& B) {
	return In | B;
}
template<class T,class U>
T Not(const T& In) {
	return In^0;
}
template<class T,class U>
T Nand(const T& In, const U& B) {
	return (In & B)^0;
}
template<class T,class U>
T Nor(const T& In, const U& B) {
	return (In | B)^0;
}
template<class T,class U>
T Equal(const T& In, const U& B) {
	return (In ^ B)^0;
}