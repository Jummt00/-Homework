#include <stdio.h>      //ㅐPRINTF, scanf를 사용하기 위해서 헤더 추가
#include <stdlib.h>    // rand, srand를 사용하기 위해서 헤더 추가
#include <time.h>   // time 함수를 사용하기 위해서 헤더 추가

int main(void)      //프로그램을 실행하는 main 함수
{                   //메인함수의 시작
    int ball[3]; // 3개의 난수 저장 배열
    srand(time(NULL)); // 난수 초기화
    // 중복 없는 3자리 난수 생성
    do {
        ball[0] = rand() % 10; //ball 0번의 난수 생성 1~9  
        ball[1] = rand() % 10; //ball 1번의 난수 생성 1~9
        ball[2] = rand() % 10; //ball 2번의 난수 생성 1~9
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]); //3개의 난수 생성 조건 서로 같지 아니 하여야 함

    //printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]); // 정답 확인용(테스트시만)

    int input[3]; //3개의 유저가 기입한 숫자 저장 배열
    int strike_count = 0 ; // 0부터 시작하는 스트라이크 카운트 수 저장 배열
    int ball_count = 0 ; // 0부터 시작하는 볼 카운트 수 저장 배열
    int out_count = 0; // 0부터 시작하는 아웃 카운트 수 저장 배열
    int try_count = 0; // 0부터 시작하는 시도 횟수 저장 배열

    clock_t start, end; //게임 시간 시작, 종료를 위한 함수
    start = clock(); // 게임 시작 시간 기록

    while (1) {                                 // 홈런이 나올때까지 계속 반복
        printf("\n숫자 3개를 입력하세요 (공백으로 구분): "); // 숫자 3개를 입력하세요 (공백으로 구분): 을 출력
        scanf("%d %d %d", &input[0], &input[1], &input[2]); //유저에게서 받은 난수 3개의 입력을 받기

        strike_count = 0; //스트라이크 카운트 시작 횟수는 0
        ball_count = 0; //볼 카운트 시작 횟수는 0

        // strike, ball 판정
        for (int i = 0; i < 3; i++) { //스트라이크,볼 판정 조건문 (0~3까지 있고 한개씩 추가됨)
            if (input[i] == ball[i]) { //스트라이크 판정 조건 ( 같은 위치 & 같은 숫자 )
                strike_count++; //스트라이크 카운트가 1씩 올라감
            } else if (input[i] == ball[(i+1)%3] || input[i] == ball[(i+2)%3]) { //그외, 볼 판정 조건(다른 위치에 있지만 숫자가 같음)
                ball_count++; //볼 카운트가 1씩 올라감
            }
        }

        out_count = 3 - (strike_count + ball_count); //아웃카운트 = 3에서 스트라이크와 볼을 합친 수를 뺸 수
        
        try_count++; //유저가 랜덤한 1~9숫자 3개를 입력할때마다 시도 횟수가 1씩 올라감

        if (strike_count == 3) { //스트라이크 카운트가 3이 됐을 경우
            end = clock(); // 게임 종료 시간 기록            
            double elapsed_sec = (double)(end - start) / CLOCKS_PER_SEC; //경과 시간 계산 (초단위)
            printf("Home Run! %d번 만에 맞췄습니다!\n", try_count); //Home Run! %d번만에 맞췄습니다! 라고 출력 %d는 시도 횟수 값을 따라감
            printf("%f 초 시간이 걸렸습니다.\n", elapsed_sec); //%f 초 시간이 걸렸습니다 라고 출력 %f는 경과 시간 을 따라감
            break; //게임을 끝냄
        } else { //if 그이외의 조건
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count); //스트라이크,볼,아웃 횟수 를 표시하고 각각 스트라이크,볼,아웃 카운트를 따라감 
        }
    }
    return 0; //프로그램 종료
}
