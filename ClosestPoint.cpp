#include <cfloat>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <time.h>

// tipe untuk menentukan lokasi titik dalam bidang 3D
struct Point
{
    int x, y,z;
};
 
// Sort array dari titik X
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// Sort array dari titik Y
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
 
// Sort array dari titik Z
int compareZ(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->z - p2->z);
}
 
// Rumus mencari jarak antari tiga titik dalam dimensi tiga 
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y) +
				(p1.z - p2.z)*(p1.z - p2.z)
               );
}
 
 // Generate Point random
 void randomPoint(int n, Point P){
	 srand(time(NULL));
	 for(int i = 0; i < n; i++){
		 // generate n koordinat random
		float P.x = rand() % n;
		float P.y = rand() % n;
		float P.z = rand() % n;
	 }
 }
 
// Algoritma Brute Force untuk mengembalikan jarak terkecil antar dua titik
// dalam larik P[] berukuran n
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
 
// Fungsi untuk membandingkan dua float A utility function to find minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}
 
 
// mencari jarak di strip dengan metode O(n) dan O(n^2)
float stripClosest(Point strip[], int size, float d)
{
    float min = d;  // Inisiasi jarak minimal d
 
    qsort(strip, size, sizeof(Point), compareY); 
 
    // Ambil satu per satu sampai terdapat perbedaan
    // antara koordinat y lebih kecil daripada d
    // bukti bahwa loop akan melakukan run sebanyak 6 kali
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
 
    return min;
}
 
// Fungsi rekursif (Divide and Conquer)untuk mencari jarak terdekat. Array P mengandung
// semua titik tersusun menurut koordinat x
float closestUtil(Point P[], int n)
{
    // Jika ada dua dan tiga poin, pakai brute force
    if (n <= 3)
        return bruteForce(P, n);
 
    // cari pivot
    int mid = n/2;
    Point midPoint = P[mid];
 
    // Asumsikan terdapat garis vertikal melewati titik tengah (pivot)
    // hitung jarak terdekat kiri dl dan kanan dr
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);
 
    // tentukan mana yang paling kecil di antara kedua nilai jarak
    float d = min(dl, dr);
 
    // Buat array strip[] yang mengandung titik terdekat (lebih dekat dari d)
    // terhadap garis yang memotong pivot
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
 
    // Mencari poin terdekat di strip.
    // Mengembalikan nilai d minimum dan jarak minimal di dalam strip[]
    return min(d, stripClosest(strip, j, d) );
}
 
// Fungsi utama yang menemukan jarak terkecil
// Memanggil closestUtil()
float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
 
    // Memakai fungsi rekursif closestUtil() untuk menemukan jarak terdekat
    return closestUtil(P, n);
}

int main()
{	
	int n; // input untuk ukuran array
	Point P;
	cout << "Masukkan nilai N" << n << "\n";
    randomPoint(n,P.x,P.y,P.z);
    int n = sizeof(P) / sizeof(P[0]);
    cout << "Jarak terkecil antar titik adalah %f "<< closest(P, n)) << "\n";
	cout << "x : " << P.x << "y : " << P.y << "z : " << P.z << "\n\n\n";
//	cout << "Banyak operasi perhitungan : " << countEu(dist);
	
    return 0;
}
