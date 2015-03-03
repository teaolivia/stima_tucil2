#include "DivandCon.h"

DivandCon::DivandCon(){
	// atribut
	n = 0; // ukuran array
	D[]; // larik kosong
	
	// method
	void DivandCon::SelectSort(int D[], int left, int right){
		int pivot; // pivot dalam pembagian array
		int l_hold; // sayap kiri array setelah pembagian
		int r_hold; // sayap kanan array setelah pembagian
		
		l_hold = left;
		r_hold = right;
		pivot = D[left];
		while(left &lt; right){
			while ((D[right] &gt ;= pivot)&&(left &lt;right))
				right--;
			if (left != right){
				D[left] = D[right];
				left++;
			}
				while ((D[left] &lt;= pivot) && (&lt; right))
					left++;
				if (left != right){
					D[right] = D[left];
					right--;
				}
		}
		D[left] = pivot;
		pivot = left;
		left = l_hold;
		right = r_hold;
		if (left &lt; pivot)
			SelectSort(D, left, pivot-1);
		if (right &gt; pivot)
			SelectSort(D, pivot+1, right)
	};
};

DivandCon::~DivandCon(){
	
};
