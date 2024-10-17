#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define MAX 50

void gotoxy(int x, int y);
void bienvenida();
void info();
int maquina(char cinta[]);
void dibujar_cinta(char cinta[], int cabezal, char estado[]);

int main(){

	char dec;
	char cinta[MAX];
	
    system("cls");
    bienvenida();
    system("cls");
    info();
	do{
		system("cls");
		printf("\n\tIngrese una cadena de 0´s y 1´s en cualquier orden: -[ ");
		gets(cinta);
		if(!maquina(cinta)){
			printf("\n\n\tLa cadena no es aceptada por la maquina...");
		}else{
			printf("\n\n\tLa cadena es aceptada por la maquina...");
		}
		printf("\n\n\tDesea validar otra cadena? -[s = si || n = no] -[ ");
		dec = getch();
	}while(dec != 110);
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void bienvenida(){
    int x=40, y=2;
    int i;
    char tema[] = {"Maquina de Turing de una Cinta"};
    int largo = sizeof(tema) - 1;
    int ancho = 1;

    largo+=4;

    gotoxy(x,y);
	printf("%c",201);
	for(i=1;i<=largo;i++){
		gotoxy(x+i,y);
		printf("%c",205);
		gotoxy(x+i,y+ancho+1);
		printf("%c",205);
	}
	gotoxy(x+i,y);
	printf("%c",187);
	
	gotoxy(x,y+ancho+1);
	printf("%c",200);
	for(i=1;i<=ancho;i++){
		gotoxy(x,y+i);
		printf("%c",186);
		gotoxy(x+largo+1,y+i);
		printf("%c",186);
	}
	gotoxy(x+largo+1,y+i);
	printf("%c",188);

    for (i = 0; i < largo-4; i++) {
    	gotoxy(x+i+3,y+1);
        printf("%c", tema[i]);
    }

    gotoxy(15,6);
    printf("Una maquina de Turing es un modelo computacional que realiza una lectura/escritura de");
    gotoxy(15,7);
    printf("manera automatica sobre una entrada llamada cinta, generando una salida en esta misma.\n\n\t");
    system("pause");
}

void info(){
    
    printf("\n\t\tMaquina de Turing para duplicacion de una cadena de un lenguaje dado.\n\n");
    printf("\t\tDefinicion formal de la maquina:\n");
    printf("\t\tM = ( Q, S, T, s, F, d )\n");
    printf("\t\tQ = {a0,q1,q2,q3,q4,q5,q6,q7,p1,p2,p3,p4,p5,p6,p7,a1}\n");
    printf("\t\tS = {0,1}\n");
    printf("\t\tT = {0,1,a,-}\n");
    printf("\t\ts = {a0}\n");
    printf("\t\tF = {a1}\n");
    printf("\t\td:\n");

    printf("\t\td(0,a0) = (q1,-,R)\td(1,q3) = (q6,-,R)\td(0,a0) = (p1,-,R)\td(1,p3) = (p6,-,R)\n");
    printf("\t\td(0,q1) = (q1,0,R)\td(0,q6) = (q6,0,R)\td(0,p1) = (p1,0,R)\td(0,p6) = (p6,0,R)\n");
    printf("\t\td(0,q1) = (q1,1,R)\td(1,q6) = (q6,1,R)\td(0,p1) = (p1,1,R)\td(1,p6) = (p6,1,R)\n");
    printf("\t\td(-,q1) = (q2,a,L)\td(a,q6) = (q6,a,R)\td(-,p1) = (p2,a,L)\td(a,p6) = (p6,a,R)\n");
    printf("\t\td(0,q2) = (q2,0,L)\td(-,q6) = (q7,1,L)\td(0,p2) = (p2,0,L)\td(-,p6) = (p7,1,L)\n");
    printf("\t\td(1,q2) = (q2,1,L)\td(0,q7) = (q7,0,L)\td(1,p2) = (p2,1,L)\td(0,p7) = (p7,0,L)\n");
    printf("\t\td(-,q2) = (q3,0,R)\td(1,q7) = (q7,1,L)\td(-,p2) = (p3,0,R)\td(1,p7) = (p7,1,L)\n");
    printf("\t\td(0,q3) = (q4,-,R)\td(a,q7) = (q7,a,L)\td(0,p3) = (p4,-,R)\td(a,p7) = (p7,a,L)\n");
    printf("\t\td(0,q4) = (q4,0,R)\td(-,q7) = (q3,1,R)\td(0,p4) = (p4,0,R)\td(-,p7) = (p3,1,R)\n");
    printf("\t\td(1,q4) = (q4,1,R)\td(a,q3) = (a1,0,S)\td(1,p4) = (p4,1,R)\td(a,p3) = (a1,0,S)\n");
    printf("\t\td(a,q4) = (q4,a,R)\t                  \td(a,p4) = (p4,a,R)\n");
    printf("\t\td(-,q4) = (q5,0,L)\t                  \td(-,p4) = (p5,0,L)\n");
    printf("\t\td(0,q5) = (q5,0,L)\t                  \td(0,p5) = (p5,0,L)\n");
    printf("\t\td(1,q5) = (q5,1,L)\t                  \td(1,p5) = (p5,1,L)\n");
    printf("\t\td(a,q5) = (q5,a,L)\t                  \td(a,p5) = (p5,a,L)\n");
    printf("\t\td(-,q5) = (q3,0,R)\t                  \td(-,p5) = (p3,0,R)\n");
    printf("\n\t\t");
	system("pause");
}

int maquina(char cinta[]){
	
	int cabezal = 0;
	int x = 12, y = 4;
	int ne = 0;
	
	ne = strlen(cinta);
	cinta[ne] = '-';
	cinta[ne + 1] = '\0';
	
	dibujar_cinta(cinta,cabezal,"a0");
	
	if(cinta[cabezal] == '0'){
		
		dibujar_cinta(cinta,cabezal+1,"a0");
		cinta[cabezal] = '-';
		dibujar_cinta(cinta,cabezal+1,"q1");
		cabezal++;
		
		while (cinta[cabezal] == '0' || cinta[cabezal] == '1') {
		    dibujar_cinta(cinta, cabezal+1, "q1");
		    cabezal++;
		}
		
		dibujar_cinta(cinta, cabezal+1, "q1");
		
		if(cinta[cabezal] != '-'){
			return 0;
		}
		cinta[cabezal] = 'a';
		dibujar_cinta(cinta,cabezal+1,"q2");
		cabezal--;
		while (cinta[cabezal] == '0' || cinta[cabezal] == '1') {
		    dibujar_cinta(cinta, cabezal+1, "q2");
		    cabezal--;
		}
		cinta[cabezal] = '0';
		dibujar_cinta(cinta,cabezal+1,"q3");
		cabezal++;
		
		while(cinta[cabezal] != 'a'){
			
			if(cinta[cabezal] == '0'){
				ne = strlen(cinta);
				cinta[ne] = '-';
				cinta[ne + 1] = '\0';
				
				cinta[cabezal] = '-';
				dibujar_cinta(cinta,cabezal+1,"q4");
				cabezal++;
				
				while (cinta[cabezal] == '0' || cinta[cabezal] == '1' || cinta[cabezal] == 'a') {
				    dibujar_cinta(cinta, cabezal+1, "q4");
				    cabezal++;
				}
				
				dibujar_cinta(cinta, cabezal+1, "q4");
				
				cinta[cabezal] = '0';
				dibujar_cinta(cinta,cabezal+1,"q5");
				cabezal--;
				while (cinta[cabezal] == '0' || cinta[cabezal] == '1' || cinta[cabezal] == 'a') {
				    dibujar_cinta(cinta, cabezal+1, "q5");
				    cabezal--;
				}
				cinta[cabezal] = '0';
				dibujar_cinta(cinta,cabezal+1,"q3");
				cabezal++;
			}else if(cinta[cabezal] == '1'){
				ne = strlen(cinta);
				cinta[ne] = '-';
				cinta[ne + 1] = '\0';
				
				cinta[cabezal] = '-';
				dibujar_cinta(cinta,cabezal+1,"q6");
				cabezal++;
				
				while (cinta[cabezal] == '0' || cinta[cabezal] == '1' || cinta[cabezal] == 'a') {
				    dibujar_cinta(cinta, cabezal+1, "q6");
				    cabezal++;
				}
				
				dibujar_cinta(cinta, cabezal+1, "q6");
				
				cinta[cabezal] = '1';
				dibujar_cinta(cinta,cabezal+1,"q7");
				cabezal--;
				while (cinta[cabezal] == '0' || cinta[cabezal] == '1' || cinta[cabezal] == 'a') {
				    dibujar_cinta(cinta, cabezal+1, "q7");
				    cabezal--;
				}
				cinta[cabezal] = '1';
				dibujar_cinta(cinta,cabezal+1,"q3");
				cabezal++;
			}
		}
		dibujar_cinta(cinta,cabezal+1,"q3");
		cinta[cabezal] = '0';
		dibujar_cinta(cinta,cabezal+1,"a0");
		
	}else if(cinta[cabezal] == '1'){
		
		dibujar_cinta(cinta,cabezal+1,"a0");
		cinta[cabezal] = '-';
		dibujar_cinta(cinta,cabezal+1,"p1");
		cabezal++;
		
		while (cinta[cabezal] == '0' || cinta[cabezal] == '1') {
		    dibujar_cinta(cinta, cabezal+1, "p1");
		    cabezal++;
		}
		
		dibujar_cinta(cinta, cabezal+1, "p1");
		
		if(cinta[cabezal] != '-'){
			return 0;
		}
		cinta[cabezal] = 'a';
		dibujar_cinta(cinta,cabezal+1,"p2");
		cabezal--;
		while (cinta[cabezal] == '0' || cinta[cabezal] == '1') {
		    dibujar_cinta(cinta, cabezal+1, "p2");
		    cabezal--;
		}
		cinta[cabezal] = '1';
		dibujar_cinta(cinta,cabezal+1,"p3");
		cabezal++;
		
		while(cinta[cabezal] != 'a'){
			
			if(cinta[cabezal] == '0'){
				ne = strlen(cinta);
				cinta[ne] = '-';
				cinta[ne + 1] = '\0';
				
				cinta[cabezal] = '-';
				dibujar_cinta(cinta,cabezal+1,"p4");
				cabezal++;
				
				while (cinta[cabezal] == '0' || cinta[cabezal] == '1' || cinta[cabezal] == 'a') {
				    dibujar_cinta(cinta, cabezal+1, "p4");
				    cabezal++;
				}
				
				dibujar_cinta(cinta, cabezal+1, "p4");
				
				cinta[cabezal] = '0';
				dibujar_cinta(cinta,cabezal+1,"p5");
				cabezal--;
				while (cinta[cabezal] == '0' || cinta[cabezal] == '1' || cinta[cabezal] == 'a') {
				    dibujar_cinta(cinta, cabezal+1, "p5");
				    cabezal--;
				}
				cinta[cabezal] = '0';
				dibujar_cinta(cinta,cabezal+1,"p3");
				cabezal++;
			}else if(cinta[cabezal] == '1'){
				ne = strlen(cinta);
				cinta[ne] = '-';
				cinta[ne + 1] = '\0';
				
				cinta[cabezal] = '-';
				dibujar_cinta(cinta,cabezal+1,"p6");
				cabezal++;
				
				while (cinta[cabezal] == '0' || cinta[cabezal] == '1' || cinta[cabezal] == 'a') {
				    dibujar_cinta(cinta, cabezal+1, "p6");
				    cabezal++;
				}
				
				dibujar_cinta(cinta, cabezal+1, "p6");
				
				cinta[cabezal] = '1';
				dibujar_cinta(cinta,cabezal+1,"p7");
				cabezal--;
				while (cinta[cabezal] == '0' || cinta[cabezal] == '1' || cinta[cabezal] == 'a') {
				    dibujar_cinta(cinta, cabezal+1, "p7");
				    cabezal--;
				}
				cinta[cabezal] = '1';
				dibujar_cinta(cinta,cabezal+1,"q3");
				cabezal++;
			}
		}
		dibujar_cinta(cinta,cabezal+1,"p3");
		cinta[cabezal] = '1';
		dibujar_cinta(cinta,cabezal+1,"a0");	
	}else{
		return 0;
	}

}

void dibujar_cinta(char cinta[], int cabezal, char estado[]){
	int ne;
	int i, j = 0;
	int x = 10, y = 4, m = 12;
	ne = strlen(cinta);
	
	Sleep(500);
	
	gotoxy(x-1,y-1);
	printf("%c",218);
	gotoxy(x-1,y);
	printf("%c",179);
	gotoxy(x-1,y+1);
	printf("%c",192);
	
	for(i=0;i<ne+4;i++){
		gotoxy(x+(i*2),y-1);
		printf("%c%c",196,194);
		if(i>1 && i<ne+2){
			gotoxy(x+(i*2),y);
			printf("%c%c",cinta[j],179);
			j++;
		}else{
			gotoxy(x+(i*2),y);
			printf("-%c",179);
		}
		gotoxy(x+(i*2),y+1);
		printf("%c%c",196,193);
	}
	gotoxy(x+(i*2)-1,y-1);
	printf("%c",191);
	gotoxy(x+(i*2)-1,y);
	printf("%c",179);
	gotoxy(x+(i*2)-1,y+1);
	printf("%c",217);
	
	gotoxy(m+(cabezal*2)-2,y+2);
	printf(" ");
	gotoxy(m+(cabezal*2),y+2);
	printf("%c",202);
	gotoxy(m+(cabezal*2)+2,y+2);
	printf(" ");
	
	gotoxy(x-1,y+3);
	printf("Estado -[ %s",estado);
}


