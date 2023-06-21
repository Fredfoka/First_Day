#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include"toolea.h"


int main()
{

	bool bZ0neu, bZ0,  bX1, bX0, bY1, bY0;
	char cEin;
	
	const char* slEing[2][2] = { "1 Euro ", "2 Euro ", "Abbruch" };
	const char* slAusg[2][2] = { "nichts", "1E Rueck", "2E Rueck" , "Einlass"};
	const char* slZstd[2]    = { "Guth=0E", "Guth=1E" };
	

	TitelLz("Simulation eines Einlassautomaten", DOPPELT);
	
	puts("Moegliche Eingaben");
	puts("(1)   Euro Eingeben    (2) EuroEingeben");
	puts("(a)   Abbruch    n");
	puts("-----------------------------------------\n");

	Titel("\n Zustand   Eingabe   neuer Zst. Ausgabe  ", EINFACH);

	bZ0 = 0; 
	while (1)
	{
		printf(" %s    ", slZstd[bZ0]);
		cEin = _getch();

		if (cEin != '1' && cEin != '2' && cEin != 'a') break;
		
		switch (cEin)
		{
		case '1': bX1 = 0; bX0 = 0; break;
		case '2': bX1 = 0; bX0 = 1; break;
		case 'a': bX1 = 1; bX0 = 0; break;
		}

		//nAus = iiMatA[nZst][nEin];  // Ausgabe über Alter Zustand und Angabe
		bY1 = !bZ0 * !bX1 * bX0 || bZ0 * !bX1 * !bX0 || bZ0 * !bX1 * bX0;
		bY0 = !bZ0 * !bX1 * bX0 || bZ0 * !bX1 * !bX0 || bZ0 * bX1 * !bX0;
		bZ0neu = !bZ0 * !bX1 * !bX0 || bZ0 * !bX1 * bX0;
		bZ0 = bZ0neu;

	//	nZst = iiMatU[nZst][nEin];  // neuer Zustand über Alter Zustand und Eingabe
		printf(" %s   %s    %s  \n", slEing[bX1][bX0], slZstd[bZ0], slAusg[bY1][bY0]);
		
	}

	printf("\n\nProgramm mit ENTER beenden!");
	getchar();
	return 1;
	
}