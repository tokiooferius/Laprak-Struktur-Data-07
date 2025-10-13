#ifndef MAHASISWA_H_ICLUDED
#define MAHASISWA_H_ICLUDED

struct mahasiswa
{
   char nim [10];
   int nilai1, nilai2; /* data */
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif