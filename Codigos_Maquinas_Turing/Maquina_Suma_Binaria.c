#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define MAX 50

void gotoxy(int x, int y);
void pantalla1();
int maquina(char cinta1[], char cinta2[]);
void dibujar_cintas(char cinta1[], char cinta2[], char aca[], char res[], int c1, int c2, int cA, int cR, char estado[]);

int main(){

	int i;
	char dec;
	char cinta1[MAX], cinta2[MAX];

    pantalla1();
	do{
		for(i=0;i<MAX;i++){
			cinta1[i] = 0;
			cinta2[i] = 0;
		}
		system("cls");
		printf("\n\t1er Numero binario: -[ ");
		gets(cinta1);
		printf("\n\t2do Numero binario: -[ ");
		gets(cinta2);
		if(!maquina(cinta1,cinta2)){
			printf("\n\tLas cadenas no son aceptadas por la maquina...");
		}else{
			printf("\n\tLas cadenas son aceptadas por la maquina...");
		}
		printf("\n\tDesea validar otra cadena? -[s = si || n = no] -[ ");
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

void pantalla1(){
    
    printf("\n\t\tMaquina de Turing Multicinta para suma de nuemros binarios.\n\n");
    printf("\t\tDefinicion formal de la maquina:\n");
    printf("\t\tM = ( Q, S, T, s, F, d )\n");
    printf("\t\tQ = {q0,q1,q2}\n");
    printf("\t\tS = {0,1,-}\n");
    printf("\t\tT = {0,1,-}\n");
    printf("\t\ts = {q0}\n");
    printf("\t\tF = {q0}\n");
    printf("\t\td:\n");

    printf("\t\td(q0,(0,0)) = (q0,(0,0,-,0),(L,L,S,L))\td(q1,(1,-)) = (q1,(1,-,1,0),(L,L,S,L))\n");
    printf("\t\td(q0,(0,1)) = (q0,(0,1,-,1),(L,L,S,L))\td(q2,(0,0)) = (q0,(0,0,-,1),(L,L,S,L))\n");
    printf("\t\td(q0,(1,0)) = (q0,(1,0,-,1),(L,L,S,L))\td(q2,(0,1)) = (q2,(0,1,1,0),(L,L,S,L))\n");
    printf("\t\td(q0,(1,1)) = (q1,(1,1,1,0),(L,L,S,L))\td(q2,(1,0)) = (q2,(1,0,1,0),(L,L,S,L))\n");
    printf("\t\td(q0,(-,0)) = (q0,(-,0,-,0),(L,L,S,L))\td(q2,(1,1)) = (q1,(1,1,1,1),(L,L,S,L))\n");
    printf("\t\td(q0,(0,-)) = (q0,(0,-,-,0),(L,L,S,L))\td(q2,(-,-)) = (q0,(-,-,-,1),(L,L,S,L))\n");
    printf("\t\td(q0,(-,1)) = (q0,(-,1,-,1),(L,L,S,L))\td(q2,(-,0)) = (q0,(-,0,-,1),(L,L,S,L))\n");
    printf("\t\td(q0,(1,-)) = (q0,(1,-,-,1),(L,L,S,L))\td(q2,(0,-)) = (q0,(0,-,-,1),(L,L,S,L))\n");
    printf("\t\td(q1,(1,1)) = (q1,(1,1,1,1),(L,L,S,L))\td(q2,(-,1)) = (q1,(-,1,1,0),(L,L,S,L))\n");
    printf("\t\td(q1,(0,1)) = (q2,(0,1,1,0),(L,L,S,L))\td(q2,(1,-)) = (q1,(1,-,1,0),(L,L,S,L))\n");
    printf("\t\td(q1,(1,0)) = (q2,(1,0,1,0),(L,L,S,L))\n");
    printf("\t\td(q1,(0,0)) = (q0,(0,0,-,1),(L,L,S,L))\n");
    printf("\t\td(q1,(-,-)) = (q0,(-,-,-,1),(L,L,S,L))\n");
    printf("\t\td(q1,(-,0)) = (q0,(0,-,-,1),(L,L,S,L))\n");
    printf("\t\td(q1,(0,-)) = (q0,(-,0,-,1),(L,L,S,L))\n");
    printf("\t\td(q1,(-,1)) = (q0,(-,1,1,0),(L,L,S,L))\n");
    
	printf("\n\t\t");
	system("pause");

}

int maquina(char cinta1[], char cinta2[]){
	
	int i, j, t = 0;
	char aux[MAX];
	char aca[MAX];
	char res[MAX];
	int c1,c2,cA=1,cR;
	
	c1 = strlen(cinta1);
	c2 = strlen(cinta2);
	
	aca[0] = '-';
	
	if(c1>c2){
		strcpy(aux,cinta2);
		for(i = 0; i<c1;i++){
			cinta2[i] = '-';
		}
		cinta2[i] = '\0';
		j=0;
		for(i = c1-c2;i<c1;i++){
			cinta2[i] = aux[j];
			j++;
		}
		cinta2[i] = '\0';
		cR = c1+1;
		for(i=0;i<cR;i++){
			res[i] = '-';
		}
		res[i] = '\0';
		c2 = c1;
		c1;
	}else if(c2>c1){
		strcpy(aux,cinta1);
		for(i = 0; i<c2;i++){
			cinta1[i] = '-';
		}
		cinta1[i] = '\0';
		j=0;
		for(i = c2-c1;i<c2;i++){
			cinta1[i] = aux[j];
			j++;
		}
		cinta1[i] = '\0';
		cR = c2+1;
		for(i=0;i<cR;i++){
			res[i] = '-';
		}
		res[i] = '\0';
		c1 = c2;
		c2;
	}else{
		cR = c1+1;
		for(i=0;i<cR;i++){
			res[i] = '-';
		}
	}
	
	dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q0");
	while(t==0){
		
		while(cinta1[c1-1] == '0' && cinta2[c2-1] == '0' || cinta1[c1-1] == '0' && cinta2[c2-1] == '1' ||cinta1[c1-1] == '1' && cinta2[c2-1] == '0' ||cinta1[c1-1] == '1' && cinta2[c2-1] == '-'||cinta1[c1-1] == '-' && cinta2[c2-1] == '1'||cinta1[c1-1] == '0' && cinta2[c2-1] == '-'||cinta1[c1-1] == '-' && cinta2[c2-1] == '0'){
			if(cinta1[c1-1] == '0' && cinta2[c2-1] == '0'||cinta1[c1-1] == '-' && cinta2[c2-1] == '0'||cinta1[c1-1] == '0' && cinta2[c2-1] == '-'){
				res[cR-1] = '0';
				cR--;
				c1--;
				c2--;
			}else if(cinta1[c1-1] == '0' && cinta2[c2-1] == '1' || cinta1[c1-1] == '1' && cinta2[c2-1] == '0'||cinta1[c1-1] == '1' && cinta2[c2-1] == '-'||cinta1[c1-1] == '-' && cinta2[c2-1] == '1'){
				res[cR-1] = '1';
				cR--;
				c1--;
				c2--;
			}
			dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q0");
			if(c1 == 1){
				return 1;
			}
		}
		
		if(cinta1[c1-1] == '1' && cinta2[c2-1] == '1'){
			aca[0] = '1';
			res[cR-1] = '0';
			c1--;
			c2--;
			cR--;
			dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q1");
			while(cinta1[c1-1] == '1' && cinta2[c2-1] == '1'){
				aca[0] = '1';
				res[cR-1] = '1';
				c1--;
				c2--;
				cR--;
				dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q1");
			}
			while(cinta1[c1-1] == '-' && cinta2[c2-1] == '1'||cinta1[c1-1] == '1' && cinta2[c2-1] == '-'){
				aca[0] = '1';
				res[cR-1] = '0';
				c1--;
				c2--;
				cR--;
				dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q1");
			}
			if(cinta1[c1-1] == '0' && cinta2[c2-1] == '1'||cinta1[c1-1] == '1' && cinta2[c2-1] == '0'){
				aca[0] = '1';
				res[cR-1] = '0';
				c1--;
				c2--;
				cR--;
				dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q2");
				while(cinta1[c1-1] == '0' && cinta2[c2-1] == '1'||cinta1[c1-1] == '1' && cinta2[c2-1] == '0'){
					aca[0] = '1';
					res[cR-1] = '0';
					c1--;
					c2--;
					cR--;
					dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q2");
				}
				while(cinta1[c1-1] == '-' && cinta2[c2-1] == '1'||cinta1[c1-1] == '1' && cinta2[c2-1] == '-'){
					aca[0] = '1';
					res[cR-1] = '0';
					c1--;
					c2--;
					cR--;
					dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q1");
				}
				if(cinta1[c1-1] == '0' && cinta2[c2-1] == '0'){
					aca[0] = '-';
					res[cR-1] = '1';
					c1--;
					c2--;
					cR--;
					dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q0");
				}else if(cinta1[c1-1] == '0' && cinta2[c2-1] == '-'||cinta1[c1-1] == '-' && cinta2[c2-1] == '0'){
					aca[0] = '-';
					res[cR-1] = '1';
					c1--;
					c2--;
					cR--;
					dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q0");
				}else{
					aca[0] = '-';
					res[cR-1] = '1';
					cR--;
					dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q0");
					return 1;
				}
			}else if(cinta1[c1-1] == '0' && cinta2[c2-1] == '0'){
				aca[0] = '-';
				res[cR-1] = '1';
				c1--;
				c2--;
				cR--;
				dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q0");
			}else if(cinta1[c1-1] == '0' && cinta2[c2-1] == '-'||cinta1[c1-1] == '-' && cinta2[c2-1] == '0'){
				aca[0] = '-';
				res[cR-1] = '1';
				c1--;
				c2--;
				cR--;
				dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q0");
			}else{
				aca[0] = '-';
				res[cR-1] = '1';
				cR--;
				dibujar_cintas(cinta1, cinta2, aca, res, c1, c2, cA, cR, "q0");
				return 1;
			}
		}else{
			t = 1;
		}
	}
	
	return 0;

}

void dibujar_cintas(char cinta1[], char cinta2[], char aca[], char res[], int c1, int c2, int cA, int cR, char estado[]){
	int n1, n2, nA, nR;
	int i, j;
	int x = 10, y = 7, m = 12;
	int a = 12, b = 17, c = 22; 
	n1 = strlen(cinta1);
	n2 = strlen(cinta2);
	nA = cA;
	nR = strlen(res);

	Sleep(1000);
	
	//Cinta 1
	gotoxy(x,y-2);
	printf("Cinta numero 1:");
	gotoxy(x-1,y-1);
	printf("%c",218);
	gotoxy(x-1,y);
	printf("%c",179);
	gotoxy(x-1,y+1);
	printf("%c",192);
	j=0;
	for(i=0;i<n1+4;i++){
		gotoxy(x+(i*2),y-1);
		printf("%c%c",196,194);
		if(i>1 && i<n1+2){
			gotoxy(x+(i*2),y);
			printf("%c%c",cinta1[j],179);
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
	
	gotoxy(m+(c1*2)-2,y+2);
	printf(" ");
	gotoxy(m+(c1*2),y+2);
	printf("%c",202);
	gotoxy(m+(c1*2)+2,y+2);
	printf(" ");
	
	//cinta 2
	gotoxy(x,a-2);
	printf("Cinta numero 2:");
	gotoxy(x-1,a-1);
	printf("%c",218);
	gotoxy(x-1,a);
	printf("%c",179);
	gotoxy(x-1,a+1);
	printf("%c",192);
	j=0;
	for(i=0;i<n2+4;i++){
		gotoxy(x+(i*2),a-1);
		printf("%c%c",196,194);
		if(i>1 && i<n2+2){
			gotoxy(x+(i*2),a);
			printf("%c%c",cinta2[j],179);
			j++;
		}else{
			gotoxy(x+(i*2),a);
			printf("-%c",179);
		}
		gotoxy(x+(i*2),a+1);
		printf("%c%c",196,193);
	}
	gotoxy(x+(i*2)-1,a-1);
	printf("%c",191);
	gotoxy(x+(i*2)-1,a);
	printf("%c",179);
	gotoxy(x+(i*2)-1,a+1);
	printf("%c",217);
	
	gotoxy(m+(c2*2)-2,a+2);
	printf(" ");
	gotoxy(m+(c2*2),a+2);
	printf("%c",202);
	gotoxy(m+(c2*2)+2,a+2);
	printf(" ");
	
	//Cinta Acarreo
	gotoxy(x,b-2);
	printf("Cinta de acarreo:");
	gotoxy(x-1,b-1);
	printf("%c",218);
	gotoxy(x-1,b);
	printf("%c",179);
	gotoxy(x-1,b+1);
	printf("%c",192);
	j=0;
	for(i=0;i<nA+4;i++){
		gotoxy(x+(i*2),b-1);
		printf("%c%c",196,194);
		if(i>1 && i<nA+2){
			gotoxy(x+(i*2),b);
			printf("%c%c",aca[j],179);
			j++;
		}else{
			gotoxy(x+(i*2),b);
			printf("-%c",179);
		}
		gotoxy(x+(i*2),b+1);
		printf("%c%c",196,193);
	}
	gotoxy(x+(i*2)-1,b-1);
	printf("%c",191);
	gotoxy(x+(i*2)-1,b);
	printf("%c",179);
	gotoxy(x+(i*2)-1,b+1);
	printf("%c",217);
	
	gotoxy(m+(cA*2)-2,b+2);
	printf(" ");
	gotoxy(m+(cA*2),b+2);
	printf("%c",202);
	gotoxy(m+(cA*2)+2,b+2);
	printf(" ");
	
	//Cinta Resultado
	gotoxy(x,c-2);
	printf("Cinta Resultado:");
	gotoxy(x-1,c-1);
	printf("%c",218);
	gotoxy(x-1,c);
	printf("%c",179);
	gotoxy(x-1,c+1);
	printf("%c",192);
	j=0;
	for(i=0;i<nR+4;i++){
		gotoxy(x+(i*2),c-1);
		printf("%c%c",196,194);
		if(i>1 && i<nR+2){
			gotoxy(x+(i*2),c);
			printf("%c%c",res[j],179);
			j++;
		}else{
			gotoxy(x+(i*2),c);
			printf("-%c",179);
		}
		gotoxy(x+(i*2),c+1);
		printf("%c%c",196,193);
	}
	gotoxy(x+(i*2)-1,c-1);
	printf("%c",191);
	gotoxy(x+(i*2)-1,c);
	printf("%c",179);
	gotoxy(x+(i*2)-1,c+1);
	printf("%c",217);
	
	gotoxy(m+(cR*2)-2,c+2);
	printf(" ");
	gotoxy(m+(cR*2),c+2);
	printf("%c",202);
	gotoxy(m+(cR*2)+2,c+2);
	printf(" ");
	
	
	gotoxy(x,c+3);
	printf("Estado -[ %s",estado);
}


