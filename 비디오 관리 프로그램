#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

typedef struct BOOK {
    char book_name[30];
    char auth_name[30];
    char publ_name[30];

}
BOOK;
char search_str(char * dic, char * word);
int add_book(BOOK* book_list, int* nth);
int search_book(BOOK* book_list, int total_num_book);
int print_book_list(BOOK* book_list, int total_num_book);
int retrieve_book_info(BOOK** book_list, int* total_num_book);

int main() {
    int choice=0; /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */

    BOOK* book_list;

    while (1) {
        printf("\n======================== \n");
        printf("1. 파일 읽기 \n");
        printf("2. 추가 \n");
        printf("3. 출력 \n");
        printf("4. 검색 \n");
        printf("5. 파일 쓰기 \n");
        printf("6. 프로그램 종료 \n");
        printf("======================== \n");

        book_list = (BOOK*)malloc(sizeof(BOOK) * choice);
      
        printf("\n정수값을 입력하시오 : ");
        scanf("%d", &choice);

        if (choice == 1) { /*파일 읽기 함수*/
            retrieve_book_info(&book_list, &num_total_book);
        }
        else if (choice == 2) { /* 책 추가 함수 */
            add_book(book_list, &num_total_book); 
        }
        else if (choice == 3) { /*출력 함수*/
            for (int i = 0; i < num_total_book; i++) {
                printf("제목 : %s\n", book_list[i].book_name);
                printf("저자 : %s\n", book_list[i].auth_name);
                printf("출판사 : %s\n", book_list[i].publ_name);
            }
        }
        else if (choice == 4) { /* 책을 검색하는 함수 호출 */
            search_book(book_list, &num_total_book); 
        }
        else if (choice == 5) { /*파일 쓰기 함수*/
            print_book_list(book_list, &num_total_book);
        }
     
        else { 
            break;
        }
    }
    free(book_list);
    return 0;
}
int print_book_list(BOOK* book_list, int total_num_book) {
    FILE* fp= NULL;
    fp=fopen("book_list.txt", "w");
    if (fp == NULL) {
        printf("파일 오픈 실패! ");
    }
    else {
        printf("파일 오픈 성공!");
    
    }

    fclose(fp);
    return 0;
} 
    char search_str(char* dic, char* word) {
        int loc = 0;
        int search_loc = 0;

        while (*dic) {
            if (*dic == *word) {
                while (*word) {
                    if (*dic != *word) {
                        word -= search_loc;
                        loc += search_loc;
                        search_loc = 0;
                        break;
                    }
                    dic++;
                    word++;
                    search_loc++;
                    if (*word == 0) {
                        return loc;
                    }
                }
            }
            dic++;
            loc++;
        }
        return -1;
    }


    int add_book(BOOK* book_list, int* nth) {
        printf("제목 : ");
        scanf("%s", book_list[*nth].book_name);

        printf("저자 : ");
        scanf("%s", book_list[*nth].auth_name);

        printf("출판사 : ");
        scanf("%s", book_list[*nth].publ_name);

        return 0;
    }

    int search_book(BOOK* book_list, int total_num_book) {
        int i=0;
                printf("제목 : ");
                scanf(" %s", &book_list[i].book_name);
                printf("출판사는 %s \n", book_list[i].publ_name);
        return 0;
    }
    
    int retrieve_book_info(BOOK** book_list, int* total_num_book) {
        FILE* fp =NULL ;
        fp = fopen("book_list.txt", "r");
        int total_book;
        if (fp=NULL) {
            printf("파일 오픈 실패!\n ");
        }
        else {
            printf("파일 오픈 성공!\n");
            return 0;
        }
        fscanf(fp, "%d", &total_book);
        *total_num_book = total_book;

        free(*book_list);
        (*book_list) = (BOOK*)malloc(sizeof(BOOK) * total_book);
        ;
        for (int i = 0; i < total_book; i++) {
            fscanf(fp, "제목 : %s", (*book_list)[i].book_name);
            fscanf(fp, "저자 : %s", (*book_list)[i].auth_name);
            fscanf(fp, "출판사 : %s", (*book_list)[i].publ_name);
        }

    return 0;
}
