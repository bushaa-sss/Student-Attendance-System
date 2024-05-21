#include<stdio.h>
#include<conio.h>

struct student {
	char name[20];
	int rollno;
	char attend;
} s[100];

int i, j;

FILE *fp;

int studentStrength;

int main() {
	showMainMenu();
}

int showMainMenu() {
	
	int choice;
	
	system("cls");
	printf("\n\n\n\t=================\n");
	printf("\tAttandence System\n");
	printf("\t=================\n\n");
	printf("\tPress 1: To add Students Data\n");	
	printf("\tPress 2: To take attandence for added students\n");
	printf("\tPress 3: To view previous attandence if had taken\n");
	printf("\tpress 4: to exit\n");
	printf("\n\tYour Choice: ");
	
	scanf("%d", &choice);
	
	switch(choice) {
		case 1: {
			addStudentsData();
			break;
		}
		case 2: {
			takeAttendance();
			break;
		}
		case 3: {
			printAttendance();	
			break;
		}
		case 4: {
			system("cls");
			break;
		}
		default: {
			system("cls");
			printf("INVALID SELECTION!!");
			printf("\n\nPress any key to go main menu");
			getch();
			return main();
		}
	}
		
}

int addStudentsData() {
	
	system("cls");
	printf("Enter class strength: ");
		
	scanf("%d", &studentStrength);
	
	int rollNumbers[studentStrength];
		
	char* filename = "C:\\Users\\56614\\Desktop\\data_sheet.txt";
		
	fp = fopen(filename,"w");
		
	for(i=0; i<studentStrength; i++) {
		
		printf("\n\nEnter %d Student Name: ", i+1);
		scanf("%s", &s[i].name);
		
		setRollNo(rollNumbers);	
	
	
	}
		
	fclose(fp);
	return main();
	
}

int setRollNo(int rollNumbers[]) {
	
	int rollno = 0;
	
	printf("Enter %d Student Roll No: ", i+1);
	scanf("%d", &rollno);
	
	for (j=0; j<studentStrength; j++) {
			
		if (rollno == rollNumbers[j]) {
				
			printf("\n\n %d roll no already assinged to a student please use diffrent one\n\n", rollno);
			
			setRollNo(rollNumbers);	
			
			break;
				
		} else {
				
			s[i].rollno = rollno;
				
			rollNumbers[i] = rollno;
			
			fprintf(fp, "Roll No: %d\tName: %s\n", s[i].rollno, s[i].name);
			
			break;
				
		}
			
	}
		
}

int takeAttendance() {
	
	system("cls");
			
	char* filename = "C:\\Users\\56614\\Desktop\\attendance_sheet.txt";
						
	fp = fopen(filename,"w");
									
	for(i=0; i<studentStrength; i++) {
		
		printf("\nEnter attandence status for %d - %s: ", s[i].rollno, s[i].name);
				
		scanf(" %c", &s[i].attend);				
				
		fprintf(fp, "Roll No: %d\tName: %s\tAttendence: %c\n", s[i].rollno, s[i].name, s[i].attend);
				
	}
						
	fclose(fp);
	return main();
		
}

int printAttendance() {
	
	system("cls");
			
	char* filename = "C:\\Users\\56614\\Desktop\\attendance_sheet.txt";
			
	fp = fopen(filename, "r");
			
	if (fp == NULL) {
        		
		printf("Could not open file %s", filename);
			
    } else {
		
		char singleLine[150];
				
		while(fgets(singleLine, 150, fp) != NULL) {	
					
			printf("%s", singleLine);
			
		}
				
	}
			
	fclose(fp);
			
	printf("\n\nPress any key to go main menu");
			
	getch();
			
	return main();
}
