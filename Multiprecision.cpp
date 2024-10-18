#include "Multiprecision.h"

FixedMultiprecision ConstructFixedMultipecision(double X) {
	FixedMultiprecision M;
	M.Frac = MakeBasic(log10(X));
	M.Number = MakeBasic(log2(X * X));
	return M;
}

template<class T>
T MakeBasic(const T& In) {
	Multiprecision X;
	X.Frac = ConstructDoubleUnsignedInt<int64_t>(log10(X));
	X.Number = ConstructDoubleUnsignedInt<int64_t>(log2(Mul(X,X)));
	return X;
}
bool Free(FixedMultiprecision& In) {
	Free(In.Frac);
	Free(In.Number);

	return true;
}
FixedMultiprecision Add(FixedMultiprecision& In, FixedMultiprecision& B) {
	FixedMultiprecision C;

	C.Frac = Add(In.Frac, B.Frac);
	C.Number = Add(In.Number, B.Number);

	return C;
}
FixedMultiprecision Sub(FixedMultiprecision& In, FixedMultiprecision& B) {
	FixedMultiprecision C;

	C.Frac = Sub(In.Frac, B.Frac);
	C.Number = Sub(In.Number, B.Number);

	return C;
}
FixedMultiprecision Mul(FixedMultiprecision& In, FixedMultiprecision& B) {
	FixedMultiprecision C;

	C.Frac = Mul(In.Frac, B.Number);
	C.Number = Mul(In.Frac, B.Number);

	return C;
}
FixedMultiprecision Div(FixedMultiprecision& In, FixedMultiprecision& B) {
	FixedMultiprecision C;

	C.Frac = Mul(In.Frac, B.Number);
	C.Number = Mul(In.Frac, B.Number);

	return C;
}
FixedMultiprecision Mod(FixedMultiprecision& In, FixedMultiprecision& B) {
	FixedMultiprecision C;

	C.Frac = Div(In.Frac, B.Number);
	C.Number = Div(In.Frac, B.Number);

	return C;
}
template<class T>
FixedMultiprecision Add(FixedMultiprecision& in,const T& N) {
	FixedMultiprecision X = ConstructFixedMultipecision(N);
	FixedMultiprecision A = Add(In, X);
	//Free(X);
	return A;
}
template<class T>
FixedMultiprecision Sub(FixedMultiprecision& in, const T& N) {
	FixedMultiprecision X = ConstructFixedMultipecision(N);
	FixedMultiprecision A = Sub(In, X);
	//Free(X);
	return A;
}
template<class T>
FixedMultiprecision Mul(FixedMultiprecision& in, T N) {
	FixedMultiprecision X = ConstructMultipecision(N);
	FixedMultiprecision A = Mul(In, X);
	//Free(X);
	return A;
}
template<class T>
FixedMultiprecision Div(FixedMultiprecision& in, T N) {
	FixedMultiprecision X = ConstructFixedMultipecision(N);
	FixedMultiprecision A = Div(In, X);
	Free(X);
	return A;
}

template<class T>
FixedMultiprecision Mod(FixedMultiprecision& in, T N) {
	FixedMultiprecision X = ConstructFixedMultipecision(N);
	FixedMultiprecision A = Mod(In, X);
	Free(X);
	return A;
}
template<class T>
bool EQ(FixedMultiprecision& In, T& B) {
	FixedMultiprecision C = ConstructFixedMultipecision(B);
	if (NotEQ(C.Frac, In.Frac) == false) { return false; }
	if (NotEQ(C.Number, In.Number) == false) { return false; }
	Free(C);
	return true;
}
bool EQ(FixedMultiprecision& In, FixedMultiprecision& B) {
	if (NotEQ(B.Frac, In.Frac) == false) { return false; }
	if (NotEQ(B.Number, In.Number) == false) { return false; }

	return true;
}
template<class T>
bool NotEQ(FixedMultiprecision& In, T& B) {
	FixedMultiprecision C = ConstructFixedMultipecision(B);
	if (NotEQ(C.Frac, In.Frac) == false) { return false; }
	if (NotEQ(C.Number, In.Number) == false) { return false; }
	Free(C);
	return true;
}
bool NotEQ(FixedMultiprecision& In, FixedMultiprecision& B) {
	if (EQ(B.Frac, In.Frac) == false) { return false; }
	if (EQ(B.Number, In.Number) == false) { return false; }

	return true;
}
template<class T>
bool UpperLeft(FixedMultiprecision& In, T& B) {
	Multiprecision C = ConstructMultipecision(B);
	if (UpperLeft(C.Frac, In.Frac) == false) { return false; }
	Free(C);
	return true;
}
bool UpperLeft(FixedMultiprecision& In, FixedMultiprecision& B) {
	if (UpperLeft(B.Frac, In.Frac) <= 0) { return false; }

	return true;
}
template<class T>
bool UpperRight(FixedMultiprecision& In, T& B) {
	Multiprecision C = ConstructMultipecision(B);
	if (UpperRight(C.Frac, In.Frac) == false) { return false; }
	Free(C);
	return true;
}
bool UpperRight(FixedMultiprecision& In, FixedMultiprecision& B) {
	if (UpperRight(B.Frac, In.Frac) >= 0) { return false; }

	return true;
}

template<class T>
FixedMultiprecision Abs(FixedMultiprecision& In) {
	FixedMultiprecision M = Mul(In, -1);
	FixedMultiprecision T = ConstructFixedMultipecision(In.Frac, In.Number);

	int X = UpperRight(T, M);

	FixedMultiprecision Y = X == 1 ? T : M;
	FixedMultiprecision* P = X == 1 ? &M : &T;

	//Free(*P);
	return Y;
}

template<class T, class U>
FixedMultiprecision NewtonMethod(FixedMultiprecision& X, T& (*Fun)(const U&), T(*FunDash)(const U&), size_t Lim) {
	FixedMultiprecision XN = ConstructFixedMultipecision(0);
	FixedMultiprecision XT = ConstructFixedMultipecision(1);
	size_t C = 0;
	FixedMultiprecision A = ABS(XT);
	FixedMultiprecision B = ConstructFixedMultipecision(0);
	while (EQ(A, B) == true) {
		FixedMultiprecision XX = Div(Fun(X), (FunDash(X));
		X = Sub(X, XX);
		//Free(XX);
		//Free(XT);
		XT = Sub(X, XN);
		//Free(XN);
		XN = X;
		A = ABS(XT);
		if (C == Lim && Lim != 0) { break; }
		C++;
	}
	//Free(XT);
	//Free(XN);
	//Free(B);
	return X;

}

template<class T>
bool Swap(T& A, T& B) {
	T X = A;
	A = B;
	B = X;

	return true;
}
template<class T, class U>
FixedMultiprecision BisectionMethod(FixedMultiprecision Low, FixedMultiprecision High, T *Fun(const U&), size_t Lim = 50) {
	Low = ConstructFixedMultipecision(Low.Frac, Low.Number);
	High = ConstructFixedMultipecision(High.Frac, High.Number);

	if (UpperLeft(Low, High) == 1) Swap(Low, High);


	FixedMultiprecision XN = ConstructFixedMultipecision(0);
	FixedMultiprecision P = Add(Low, High);
	FixedMultiprecision X = Div(P, 2);
	//Free(P);
	int SL = UpperLeft(Fun(Low), 0) ? 1 : -1;
	int SH = UpperLeft(Fun(High), 0) ? 1 : -1;

	size_t C = 0;
	//free(X);
	P = Add(Low, High);
	X = Div(P, 2);
	//Free(P);
	int SM = Fun(X) > 0 ? 1 : -1;
	if (SM == SL) {
		//Free(Low);
		Low = ConstructMultipecision(X.Frac, X.Number);
	}
	else {
		//Free(High);
		High = ConstructMultipecision(X.Frac, X, Number);;
	}
	C++;
	FixedMultiprecision Z = Sub(X, XN);
	FixedMultiprecision A = Abs(Z);
	while (UpperLeft(A, 0) == true) {
		if (C == Lim && Lim != 0) { break; }

		XN = X;
		P = Add(Low, High);
		X = Div(P, 2);
		//Free(P);
		int SM = UpperLeft(Fun(X), 0) ? 1 : -1;
		if (SM == SL) {
			//Free(Low);
			Low = X;
		}
		else {
			//Free(High);
			High = X;
		}
		C++;
		//Free(Z);
		Z = Sub(X, XN);
		//Free(A);
		A = Abs(Z);

	}
	//Free(Z);
	Z = Sub(X, XN);
	//Free(A);
	A = Abs(Z);
	//Free(Low) :
	//Free(High);
	return X;
}

template<class T, class U>
FixedMultiprecision NewtonBisectionMethod(FixedMultiprecision& X, T* BMFun(const U&), T* NMFun(const U&), T* NMFD(const T&), size_t Lim) {//maybe perfect answer.
	FixedMultiprecision A = NewtonMethod<T>(X, NMFun, NMFunDash, Lim);
	FixedMultiprecision B = BisectionMethod(L, H, BMFun, Lim);
	//Free(A);
	return B:
}