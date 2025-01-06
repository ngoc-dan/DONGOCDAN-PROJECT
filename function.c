#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include"function.h"
#include <windows.h> 

Student students[100];
Teacher teachers[100];
int number = 0;
int numbers = 0;

void printMenuHome(){
	printf("\n");
	printf("\t   CHOOSE YOUR ROLE\n");
	printf("\t======================\n");
	printf("\t[1] Admin.\n");
	printf("\t[2] Exit the program.\n");
	printf("\t======================\n");
}

void printMenu(){
	printf("\n");
	printf("\t\tMENU\n");
	printf("\t======================\n");
	printf("\t[1] Student management.\n");
	printf("\t[2] teacher management.\n");
	printf("\t[3] Exit the menu.\n");
	printf("\t======================\n");
}

void inputMenu(){
	int choice;
	do{
		printMenu();
		printf("\tnhap lua chon cua ban : ");
		scanf("%d", &choice);
		printf("\n");
		fflush(stdin);
		switch(choice){
			case 1:
				system("cls");
				inputStudentMenu();
				break;
			case 2:
				system("cls");
				inputTeacherMenu();
				break;
			case 3:
				system("cls");
				break;
			default:
				printf("\tsai cu phap!\n");
		}
	}while(choice != 3);
}

void inputStudentMenu(){
	loadFromFileStudent();
	int choice;
    do {
    	displayMenuStudent();
        printf("Moi Ban nhap lua chon : ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                displayStudents();
                pressToExitOrReturn();
                break;
            case 2:
                addStudent();
                pressToExitOrReturn();
                break;
            case 3:
                editStudent();
                pressToExitOrReturn();
                break;
            case 4:
                deleteStudent();
                pressToExitOrReturn();
                break;
            case 5:
                searchStudentByName();
                pressToExitOrReturn();
                break;
            case 6:
                sortStudentsByName();
                pressToExitOrReturn();
                break;
            case 7:
                saveToFileStudent();
                printf("du lieu duoc luu thanh cong!\n");
                pressToExitOrReturn();
                break;
            case 8:
                saveToFileStudent();
                break;
            default:
            	system("cls");
                printf("luu chon khong hop le.\n");
                pressToExitOrReturn();
        }
    }while(choice != 8);
}

void inputTeacherMenu(){
	loadFromFileTeacher();
	int choice;
    do{
    	displayMenuTeacher();
        
        printf("Moi Ban nhap lua chon : ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                displayTeachers();
                pressToExitOrReturn();
                break;
            case 2:
                addTeacher();
                pressToExitOrReturn();
                break;
            case 3:
                editTeacher();
                pressToExitOrReturn();
                break;
            case 4:
                deleteTeacher();
                pressToExitOrReturn();
                break;
            case 5:
                searchTeacherByName();
                pressToExitOrReturn();
                break;
            case 6:
                saveToFileTeacher();
                printf("du lieu duoc luu thanh cong!\n");
                pressToExitOrReturn();
                break;
            case 7:
                saveToFileTeacher();
                break;
            default:
            	system("cls");
                printf("luu chon khong hop le.\n");
                pressToExitOrReturn();
        }
    }while(choice != 7);
}

void printExit(){
	printf("\t====Thank You======\n");
	printf("\t====See You Soon===");
	printf("\n");
}

void displayMenuStudent() {
	system("cls");
    printf("***Student Management System Using C***\n");
	printf("                  STUDENT MENU\n");
	printf("       =======================================\n");
	printf("       | [1] Hien thi danh sach sinh vien.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [2] Tim sinh vien vao danh sach.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [3] Sua  thong tin sinh vien tru id.|\n");
	printf("       |-------------------------------------|\n");
	printf("       | [4] Xoa sinh vien.                  |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [5] Tim kiem sinh vien.             |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [6] Sap sep sinh vien theo ten.     |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [7] Luu lai danh sach hoc sinh.     |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [8] Exit.                           |\n");
	printf("       =======================================\n");
	printf("\n");	
}

void displayMenuTeacher() {
	system("cls");
    printf("***Student Management System Using C***\n");
	printf("                  TEACHER MENU\n");
	printf("       =======================================\n");
	printf("       | [1] Hien thi danh sach giao vien.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [2] Them giao vien vao danh sach.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [3] Sua  thong tin giao vien tru id.|\n");
	printf("       |-------------------------------------|\n");
	printf("       | [4] Xoa giao vien khoi danh sach.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [5] Tim kiem giao vien.             |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [6] Luu lai danh sach giao vien.     |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [7] Exit.                           |\n");
	printf("       =======================================\n");
	printf("\n");	
}

void displayStudents() {
	system("cls");
	int i;
	printf("\n                          --- Display All Students ---\n");
	printf("\nStudent list:\n");
	printf("=================================================================================");
    printf("\n| %-3s | %-20s | %-30s | %-15s |\n", "ID", "Name", "Email", "Phone");
    printf("=================================================================================\n");
    for ( i = 0; i < number; i++) {
        printf("| %-3d | %-20s | %-30s | %-15s |\n", students[i].id, students[i].name, students[i].email, students[i].phone);
        printf("---------------------------------------------------------------------------------\n");
    }
    printf("\n");
}

void displayTeachers() {
	system("cls");
	int i; 
	printf("\n                           --- Display All Teacher ---\n");
	printf("\nTeacher list:\n");
	printf("=================================================================================");
    printf("\n| %-3s | %-20s | %-30s | %-15s |\n", "ID", "Name", "Email", "Phone");
    printf("=================================================================================\n");
    for ( i = 0; i < numbers; i++) {
        printf("| %-3d | %-20s | %-30s | %-15s |\n", teachers[i].id, teachers[i].name, teachers[i].email, teachers[i].phone);
        printf("---------------------------------------------------------------------------------\n");
    }
    printf("\n");
}

void addStudent() {
	system("cls");
	int add=number;
    char choice[1];
	int i;
	char afterGmail[] = "@gmail.com";
	printf("\t\t---Add a new student---\n");
	addStudent:
	printf("\tEnter the ID: ");
	int check = 0;
	scanf("%d", &students[add].id);
	fflush(stdin);
	for(i = 0; i < number; i++){
		if(students[add].id == students[i].id||students[add].id < 1||students[add].id > 1000){
			check = 1;
		}
	}
	if(check != 1){
		addName:
		printf("\tnhap ten hoc sinh: ");
		fgets(students[add].name, sizeof(students[add].name), stdin);
		students[add].name[strcspn(students[add].name,"\n")] = '\0';
		for(i=0;i<strlen(students[add].name);i++){		
			if(students[add].name[i]== 32&&students[add].name[i+1]==32){
				printf("\tError: ten kong hop le.\n");
				goto addName;	
			}
			if((students[add].name[i] < 65 ||students[add].name[i] > 122)&&students[add].name[i]!=32){
				printf("\tError: ten kong hop le.\n");
				goto addName;	
			}
		}
		if(students[add].name[0]== 32||strlen(students[add].name) < 1){
			printf("\tError: ten kong hop le.\n");
			goto addName;	
		}
		addMail:
		printf("\tnhap email hoc sinh : ");
		fgets(students[add].email, sizeof(students[add].email), stdin);
		students[add].email[strcspn(students[add].email,"\n")] = '\0';
		int same = 0;
		for(i = 0; i < number; i++){
			if(strcmp(students[add].email, students[i].email) == 0){
				same = 1;
			}
		}
		if(same == 1){
			printf("\tError: email da ton tai.\n");
			goto addMail;
		}
		for(i=0;i<strlen(students[add].email);i++){		
			if(students[add].email[i]== 32){
				goto addMail;		
			}
		}
		int len = strlen(students[add].email);
		int emailLen = strlen(afterGmail);
		if (len <= emailLen){
			goto addMail;
		}
		if (strcmp(students[add].email + len - emailLen, afterGmail) != 0){
			goto addMail;
		}
		addPhone:
		printf("\tEnter the Phone hoc sinh: ");
		same = 0;
		fgets(students[add].phone, sizeof(students[add].phone), stdin);
		students[add].phone[strcspn(students[add].phone,"\n")] = '\0';
		for(i = 0; i < number; i++){
			if(strcmp(students[add].phone, students[i].phone) == 0){
				same = 1;
			}
		}
		if(same == 1){
			printf("\tError: Phone da ton tai.\n");
			goto addPhone;
		}
		for(i=0;i<strlen(students[add].phone);i++){		
			if(students[add].phone[i]== 32) {
				goto addPhone;		
			}
		}
		if (strlen(students[add].phone)!=10) {
	        goto addPhone;
	    }
	    for (i = 0; i < strlen(students[add].phone); i++){
	        if (students[add].phone[i] < '0' || students[add].phone[i] > '9'){
	            goto addPhone;
	        }
	    }
		(number)++;
		printf("\tthem sinh vien thanh cong!!\n");
		
	}else{
		printf("\tError: id da ton tai.\n");
		goto addStudent;
	}
}

void addTeacher() {
    system("cls");
    int add = numbers;
    char choice[1];
    int i;
    char afterGmail[] = "@gmail.com";
    printf("\t\t---Add a new teacher---\n");
	addTeacher:
    printf("\tnhap ID: ");
    int check = 0;
    scanf("%d", &teachers[add].id);
    fflush(stdin);
    for (i = 0; i < numbers; i++) {
        if (teachers[add].id == teachers[i].id || teachers[add].id < 1 || teachers[add].id > 1000) {
            check = 1;
        }
    }
    if (check != 1) {
    addName:
        printf("\tnhap ten giao vien : ");
        fgets(teachers[add].name, sizeof(teachers[add].name), stdin);
        teachers[add].name[strcspn(teachers[add].name, "\n")] = '\0';
        for (i = 0; i < strlen(teachers[add].name); i++) {        
            if (teachers[add].name[i] == 32 && teachers[add].name[i + 1] == 32) {
                printf("\tError: ten khong hop le.\n");
                goto addName;    
            }
            if ((teachers[add].name[i] < 65 || teachers[add].name[i] > 122 )&&teachers[add].name[i]!=32){
                printf("\tError: ten khong hop le.\n");
                goto addName;    
            }
        }
        if (teachers[add].name[0] == 32 || strlen(teachers[add].name) < 1) {
            printf("\tError: ten khong hop le.\n");
            goto addName;    
        }
    	addMail:
        printf("\tNhap email giao vien : ");
        fgets(teachers[add].email, sizeof(teachers[add].email), stdin);
        teachers[add].email[strcspn(teachers[add].email, "\n")] = '\0';
        int same = 0;
        for (i = 0; i < numbers; i++) {
            if (strcmp(teachers[add].email, teachers[i].email) == 0) {
                same = 1;
            }
        }
        if (same == 1) {
            printf("\tError: Email da ton tai.\n");
            goto addMail;
        }
        for (i = 0; i < strlen(teachers[add].email); i++) {        
            if (teachers[add].email[i] == 32) {
                goto addMail;        
            }
        }
        int len = strlen(teachers[add].email);
        int emailLen = strlen(afterGmail);
        if (len <= emailLen) {
            goto addMail;
        }
        if (strcmp(teachers[add].email + len - emailLen, afterGmail) != 0) {
            goto addMail;
        }
    	addPhone:
        printf("\tNhap Phone: ");
        same = 0;
        fgets(teachers[add].phone, sizeof(teachers[add].phone), stdin);
        teachers[add].phone[strcspn(teachers[add].phone, "\n")] = '\0';
        for (i = 0; i < number; i++) {
            if (strcmp(teachers[add].phone, teachers[i].phone) == 0) {
                same = 1;
            }
        }
        if (same == 1) {
            printf("\tError: so dien thoai da ton tai.\n");
            goto addPhone;
        }
        for (i = 0; i < strlen(teachers[add].phone); i++) {        
            if (teachers[add].phone[i] == 32) {
                goto addPhone;        
            }
        }
        if (strlen(teachers[add].phone) != 10) {
            goto addPhone;
        }
        for (i = 0; i < strlen(teachers[add].phone); i++) {
            if (teachers[add].phone[i] < '0' || teachers[add].phone[i] > '9') {
                goto addPhone;
            }
        }
        (numbers)++;
        printf("\tTeacher duoc them thanh cong!!\n");
    } else {
        printf("\tError: ID da ton tai.\n");
        goto addTeacher;
    }
}

void editStudent() {
	system("cls");
	char afterGmail[] = "@gmail.com";
	int i, edit; 
	char choice[1];
	Student:
	printf("\t\t---Edit student---\n");
	int Id;
	printf("\tNhap id hoc sinh muon sua : ");
	scanf("%d", &Id);
	int check = 0;
	fflush(stdin);
	printf("\tThong tin sinh vien muon sua\n");
	printf("\t----------------------\n");
	for(i = 0; i < number; i++){
	    if(Id == students[i].id){
	        check = 1;
	        edit = i;
	        printf("\tID: %d\n", students[i].id);
	        printf("\tName: %s\n", students[i].name);
	        printf("\tEmail: %s\n", students[i].email);
	        printf("\tPhone: %s\n", students[i].phone);
	    }
	}
	if(check == 1){
	    printf("\t\t---Update The New Student---\n");
	    char temp[100];
	    Name:
	    printf("\tNhap name hoc sinh moi : ");
	    strcpy(temp, students[edit].name);
	    fgets(students[edit].name, sizeof(students[edit].name), stdin);
	    students[edit].name[strcspn(students[edit].name,"\n")] = '\0';
	    for(i = 0; i < strlen(students[edit].name); i++){
	        if(students[edit].name[i] == 32 && students[edit].name[i+1] == 32){
	            printf("\tError: Ten nay khong hop le.\n");
	            goto Name;    
	        }
	        if((students[edit].name[i] < 65 || students[edit].name[i] > 122) && students[edit].name[i] != 32){
	            printf("\tError: Ten nay khong hop le.\n");
	            goto Name;
	        }
	    }
	    if(students[edit].name[0] == 32 || strlen(students[edit].name) < 1){
	        printf("\tError: Ten nay khong hop le.\n");
	        goto Name;    
	    }
	    Mail:
	    printf("\tNhap email hoc sinh moi: ");
	    strcpy(temp, students[edit].email);
	    fgets(students[edit].email, sizeof(students[edit].email), stdin);
	    students[edit].email[strcspn(students[edit].email,"\n")] = '\0';
	    int same = 0;
	    for(i = 0; i < number; i++){
	        if(strcmp(students[edit].email, students[i].email) == 0 && edit != i){
	            same = 1;
	        }
	    }
	    if(same == 1){
	        printf("\tError: Email da ton tai.\n");
	        strcpy(students[edit].email, temp);
	        goto Mail;
	    }
	    for(i = 0; i < strlen(students[edit].email); i++){        
	        if(students[edit].email[i] == 32){
	            strcpy(students[edit].email, temp);
	            goto Mail;        
	        }
	    }
	    int len = strlen(students[edit].email);
	    int emailLen = strlen(afterGmail);
	    if (len <= emailLen){
	        strcpy(students[edit].email, temp);
	        goto Mail;
	    }
	    if (strcmp(students[edit].email + len - emailLen, afterGmail) != 0){
	        strcpy(students[edit].email, temp);
	        goto Mail;
	    }
	    Phone:
	    printf("\tNhap phone hoc sinh moi: ");
	    strcpy(temp, students[edit].phone);
	    fgets(students[edit].phone, sizeof(students[edit].phone), stdin);
	    students[edit].phone[strcspn(students[edit].phone,"\n")] = '\0';
	    for(i = 0; i < strlen(students[edit].phone); i++){        
	        if(students[edit].phone[i] == 32) {
	            strcpy(students[edit].phone, temp);
	            goto Phone;        
	        }
	    }
	    if (strlen(students[edit].phone) != 10) {
	        strcpy(students[edit].phone, temp);
	        goto Phone;
	    }
	    for (i = 0; i < strlen(students[edit].phone); i++){
	        if (students[edit].phone[i] < '0' || students[edit].phone[i] > '9'){
	            strcpy(students[edit].phone, temp);
	            goto Phone;
	        }
	    }
	    end:
	    printf("\tCap nhat thanh cong !!!\n\n");
	}else{
	    printf("\tError: ID da ton tai.\n\n");
	    goto Student;
	}
}

void editTeacher() {
	system("cls");
	char afterGmail[] = "@gmail.com";
	int i, edit; 
	char choice[1];
	Teacher:
	printf("\t\t---Edit teacher---\n");
	int Id;
	printf("\tNhap ID giao vien muon sua: ");
	scanf("%d", &Id);
	int check = 0;
	fflush(stdin);
	printf("\tThong tin giao vien muon sua\n");
	printf("\t----------------------\n");
	for (i = 0; i < numbers; i++) {
	    if (Id == teachers[i].id) {
	        check = 1;
	        edit = i;
	        printf("\tID: %d\n", teachers[i].id);
	        printf("\tName: %s\n", teachers[i].name);
	        printf("\tEmail: %s\n", teachers[i].email);
	        printf("\tPhone: %s\n", teachers[i].phone);
	    }
	}
	if (check == 1) {
	    printf("\t\t---Update The New Teacher---\n");
	    char temp[100];
	    Name:
	    printf("\tNhap name giao vien moi: ");
	    strcpy(temp, teachers[edit].name);
	    fgets(teachers[edit].name, sizeof(teachers[edit].name), stdin);
	    teachers[edit].name[strcspn(teachers[edit].name, "\n")] = '\0';
	    for (i = 0; i < strlen(teachers[edit].name); i++) {
	        if (teachers[edit].name[i] == 32 && teachers[edit].name[i + 1] == 32) {
	            printf("\tError: Ten nay khong hop le.\n");
	            goto Name;    
	        }
	        if ((teachers[edit].name[i] < 65 || teachers[edit].name[i] > 122) && teachers[edit].name[i] != 32) {
	            printf("\tError: Ten nay khong hop le.\n");
	            goto Name;
	        }
	    }
	    if (teachers[edit].name[0] == 32 || strlen(teachers[edit].name) < 1) {
	        printf("\tError: Ten nay khong hop le.\n");
	        goto Name;    
	    }
	    Mail:
	    printf("\tNhap email giao vien moi: ");
	    strcpy(temp, teachers[edit].email);
	    fgets(teachers[edit].email, sizeof(teachers[edit].email), stdin);
	    teachers[edit].email[strcspn(teachers[edit].email, "\n")] = '\0';
	    int same = 0;
	    for (i = 0; i < numbers; i++) {
	        if (strcmp(teachers[edit].email, teachers[i].email) == 0 && edit != i) {
	            same = 1;
	        }
	    }
	    if (same == 1) {
	        printf("\tError: Email da ton tai.\n");
	        strcpy(teachers[edit].email, temp);
	        goto Mail;
	    }
	    for (i = 0; i < strlen(teachers[edit].email); i++) {        
	        if (teachers[edit].email[i] == 32) {
	            strcpy(teachers[edit].email, temp);
	            goto Mail;        
	        }
	    }
	    int len = strlen(teachers[edit].email);
	    int emailLen = strlen(afterGmail);
	    if (len <= emailLen) {
	        strcpy(teachers[edit].email, temp);
	        goto Mail;
	    }
	    if (strcmp(teachers[edit].email + len - emailLen, afterGmail) != 0) {
	        strcpy(teachers[edit].email, temp);
	        goto Mail;
	    }
	    Phone:
	    printf("\tNhap phone giao vien moi : ");
	    strcpy(temp, teachers[edit].phone);
	    fgets(teachers[edit].phone, sizeof(teachers[edit].phone), stdin);
	    teachers[edit].phone[strcspn(teachers[edit].phone, "\n")] = '\0';
	    for (i = 0; i < strlen(teachers[edit].phone); i++) {        
	        if (teachers[edit].phone[i] == 32) {
	            strcpy(teachers[edit].phone, temp);
	            goto Phone;        
	        }
	    }
	    if (strlen(teachers[edit].phone) != 10) {
	        strcpy(teachers[edit].phone, temp);
	        goto Phone;
	    }
	    for (i = 0; i < strlen(teachers[edit].phone); i++) {
	        if (teachers[edit].phone[i] < '0' || teachers[edit].phone[i] > '9') {
	            strcpy(teachers[edit].phone, temp);
	            goto Phone;
	        }
	    }
	    end:
	    printf("\tCap nhat thanh cong !!!\n\n");
	} else {
	    printf("\tError: ID da ton tai.\n\n");
	    goto Teacher;
	}
}
void deleteStudent() {
	system("cls");
	printf("\n          --- delete student information ---\n");
    int id;
    int i,j;
    printf("nhap id sinh vien muon xoa: ");
    scanf("%d", &id);
    getchar();

    for ( i = 0; i < number; i++) {
        if (students[i].id == id) {
            printf("ban co chac muon xoa sinh vien thu %s? (y/n): ", students[i].name);
            char confirm;
            scanf("%c", &confirm);
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for ( j = i; j < number - 1; j++) {
                    students[j] = students[j + 1];
                }
                number--;
                printf("sinh vien duoc xoa thanh cong!\n");
            } else {
                printf("da huy xoa.\n");
            }
            return;
        }
    }

    printf("Error: khong co id hoc sinh.\n");
}

void deleteTeacher() {
    system("cls");
    printf("\n          --- Delete Teacher Information ---\n");
    int id;
    int i, j;
    printf("Nhap ID giao vien muon xoa: ");
    scanf("%d", &id);
    getchar();

    for (i = 0; i < numbers; i++) {
        if (teachers[i].id == id) {
            printf("Ban co chac muon xoa giao vien '%s'? (y/n): ", teachers[i].name);
            char confirm;
            scanf("%c", &confirm);
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for (j = i; j < numbers - 1; j++) {
                    teachers[j] = teachers[j + 1];
                }
                numbers--;
                printf("Giao vien duoc xoa thanh cong!\n");
            } else {
                printf("Da huy xoa.\n");
            }
            return;
        }
    }

    printf("Error: Khong co ID giao vien.\n");
}

void searchStudentByName() {
	system("cls");
	printf("\n          --- Search student information ---\n");
    char query[50];
    int i;
    printf("nhap ten hoc sinh can tim: ");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = 0;

    printf("\nket qua tim kiem duoc la :\n");
    printf("==================================================================================\n");
    printf("| %-5s | %-20s | %-30s | %-15s|\n", "ID", "Name", "Email", "Phone");
    printf("==================================================================================\n");
    int found = 0;
    for ( i = 0; i < number; i++) {
        if (strstr(students[i].name, query) != 0) {
            printf("| %-5d | %-20s | %-30s | %-15s|\n", students[i].id, students[i].name, students[i].email, students[i].phone);
            printf("----------------------------------------------------------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
    	printf("============================================\n");
        printf("||khong tim thay hoc sinh trong danh sach.||\n");
        printf("============================================\n");
    }
}

void searchTeacherByName() {
    system("cls");
    printf("\n          --- Search Teacher Information ---\n");
    char query[50];
    int i;
    printf("Nhap ten giao vien can tim: ");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = 0;

    printf("\nKet qua tim kiem duoc la:\n");
    printf(" %-5s  %-20s  %-30s  %-15s\n", "ID", "Name", "Email", "Phone");
    printf("-------------------------------------------------------------\n");
    int found = 0;
    for (i = 0; i < numbers; i++) {
        if (strstr(teachers[i].name, query) != 0) {
            printf(" %-5d %-20s %-30s %-15s\n", teachers[i].id, teachers[i].name, teachers[i].email, teachers[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay giao vien.\n");
    }
}

void sortStudentsByName() {
	system("cls");
	printf("\n          --- arrange students ---\n");
	int i,j;
    for ( i = 0; i < number - 1; i++) {
        for ( j = i + 1; j < number; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("hoc sinh duoc sap sep theo ten.\n");
    displayStudents();
}

void saveToFileStudent() {
	system("cls");
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error: khong the luu tru vao file.\n");
        return;
    }
    fwrite(&number, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), number, file);
    fclose(file);
}

void saveToFileTeacher() {
    system("cls");
    FILE *file = fopen("teachers.dat", "wb");
    if (file == NULL) {
        printf("Error: khong the luu tru vao file.\n");
        return;
    }
    fwrite(&numbers, sizeof(int), 1, file);
    fwrite(teachers, sizeof(Teacher), numbers, file);
    fclose(file);
}

void loadFromFileStudent() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("khong tim thay du lieu.\n");
        return;
    }
    fread(&number, sizeof(int), 1, file);
    fread(students, sizeof(Student), number, file);
    fclose(file);
}

void loadFromFileTeacher() {
    FILE *file = fopen("teachers.dat", "rb");
    if (file == NULL) {
        printf("No data found.\n");
        return;
    }
    fread(&numbers, sizeof(int), 1, file);
    fread(teachers, sizeof(Teacher), numbers, file);
    fclose(file);
}

void pressToExitOrReturn() {
    char choice;
    printf("\n           [0] Exit      [1] Back to menu\n");
    scanf("%c", &choice);  
    getchar();  

    if (choice == '0') {
        printf("Exiting...\n");
        return ; 
    } else if (choice == '1') {
    	
        return;
    } else {
        printf("lua chon khong hop le !\n");
        return;
    }
}
