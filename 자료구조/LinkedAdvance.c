#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct person { //구조체 생성

    int age; //나이
    char name[10]; //이름
    int gender; //성별
    struct person *link; //나이가 같을 때의 연결리스트
} PERSON;

typedef struct node { //person 관련 구조체 생성

    int data; //나이 데이터
    struct person* p; //신청자 person 정보 포인터
    struct node* left; //왼쪽 서브트리 링크 필드
    struct node* right; //오른쪽 서브트리 링크 필드
} NODE;

int cnt = 0; //순회 횟수

void appInfo(NODE* node) { //신청자 정보 출력
    PERSON* per; //person 포인터
    per = node->p; //node 정보를 포인터로 연결
    printf("\n%d세 재난 지원금 신청자 목록은 다음과 같습니다. \n\n", node->data); //검색한 나이에 대한 신청자 목록 출력

    char gender[10] = ""; //성별을 나타낼 문자열
    while (per != NULL) { //포인터가 null일때까지

        printf("이름 : %s \n", per->name); //신청자 이름 출력

        if (per->gender == 1) strcpy(gender, "여성"); //gender 1 = 여성
        else if (per->gender == 2) strcpy(gender,"남성"); //gender 2 = 남성

        printf("성별 : %s \n", per->gender); // 신청자 성별 출력

        per = per->link;//같은 나이가 있다면 계속 출력, 없다면 break
    }
    printf("순회 횟수 : %d번 \n\n", cnt);//순회 횟수 출력
}

void applicant(NODE* node, int age, char *name, int gender) { //신청자 정보 생성
    PERSON* per; //PERSON타입 포인터

    per = (PERSON*)malloc(sizeof(PERSON)); //malloc형식으로 동적메모리 할당

    per->age = age; //나이 할당
    strcpy(per->name, name);//이름 복사 후 할당
    per->gender = gender; // 성별 할당

    per->link = node->p; //최신순 저장
    node->p = per; //최신 신청자
}

void inorder(NODE* node) //트리 오름차순 출력
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d,  ", node->data);
        inorder(node->right);
    }
}

NODE* newNODE(int age, char *name, int gender) //노드 생성 (중복 나이)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = age;
    node->left = node->right = NULL;
    node->p = NULL;
    applicant(node, age, name, gender); //신청자 정보
    return node;
}

NODE* insert(NODE* node, int age, char *name, int gender) //노드 삽입
{
    if (node == NULL) return newNODE(age, name, gender); //newNode에 추가

    if (age < node->data)
        node->left = insert(node->left, age, name, gender);
    else if (age > node->data)
        node->right = insert(node->right, age, name, gender);
    else if (age == node->data)
        applicant(node, age, name, gender);
    //node 값과 나이가 동일할 때 연결

    return node;
}

NODE* search(NODE* node, int age) //노드 탐색
{
    cnt++; //순회 횟수 추가

    if (node == NULL) {
        printf("\n해당 나이의 신청자가 없습니다.\n");
        return node;
    }

    if (node->data == age) //나이에 값이 있을 때
        appInfo(node);

    if (node->data > age) //나이가 data보다 작으면
        return search(node->left, age); //왼쪽 서브트리 검색

    if (node->data < age) //나이가 data보다 크면
        return search(node->right, age); //오른쪽 서브트리 검색
}   


int main() 
{
    srand((unsigned int)time(NULL)); //난수 생성
    NODE* node = NULL;

    for (int i = 0; i < 80; i++) {
        int setAge = rand() % 81 + 20; //랜덤 + 중복 없이 그대로 유지되게
        int setGender = rand() % 2 + 1; // 성별 랜덤 생성 (남자 / 여자) 
        
        char n[10], setName[10]; //이름 설정

        for (int j = 0; j < 4; j++) { //이름 랜덤 생성 
            n[j] = (char) 'a' + (rand() % 26);
        }
        n[6] = 0;

        strcpy(setName, n); //n으로 생성한 이름을 setName으로

        if (node == NULL) node = insert(node, setAge, setName, setGender);
        else insert(node, setAge, setName, setGender);
    }

    int findAge = 1;

    do {
        cnt = 0;

        printf("\n검색할 나이를 입력하세요 : ");
        scanf("%d", &findAge); //data 탐색
        if (findAge == 0) printf("\n\n----- 프로그램 종료 -----\n\n"); //0일 때 프로그램 종료
        else if (findAge < 20) printf("\n 미성년자는 재난지원금 대상자가 아닙니다. 다시 입력하세요. \n"); //20 미만
        else if (findAge > 100) printf("\n 100세 이상은 해당 프로그램으로 확인할 수 없습니다. 다시 입력하세요.  \n");//100 초과
        else search(node, findAge);
        
    } while (findAge != 0);

    return 0;
}
