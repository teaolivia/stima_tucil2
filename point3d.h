#ifndef _point3d_H
#define _point3d_H

class Point3d
{ public:
// Konstruktor
Point3d(); // default konstruktor, x = 0, y = 0, z = 0
Point3d(float newx, float newy, float newz); // konstruktor dengan parameter x dan y
// Destruktor
~Point3d(); // destruktor
// Getter
float GetAbsis();
float GetOrdinat();
float GetZ();
// Setter
void SetAbsis(int newx);
void SetOrdinat(int newy);
void SetZ(int newz);
// Predikat
int IsOrigin(); // menghasilkan 1 jika current objek adalah origin
// Operator Relasional
int IsEqual(Point3d P); // menghasilkan 1 jika P == current objek;
                      // nilainya absis dan ordinatnya sama
//Operator aritmetika
Point3d Add(Point3d P1, Point3d P2); // menghasilkan P1+P2
Point3d Add(Point3d P); // menghasilkan current objek+P
Point3d Add(int dx, int dy); // menghasilkan Point (P.x+dx, P.x+dy)
void AddToMe(Point3d P); // current objek = current objek + P
void AddToMe(int dx, int dy); // x=x+dx; y=y+dy
// Fungsi lain
int Kuadran(); // menghasilkan kuadran dari Current Objek
int AntarPoint(Point3d P1, Point3d P2); //dengan rumus eucledian, hitung jarak antar point.

Point3d Generate(int n); //generate random point as much as n
Point3d Solve(Point3d P1, Point3d P2); //


private:
  float x; //absis
  float y; //ordinat
  float z;
  float max; // nilai maksimum
  float min; // nilai minimum
};

#endif
