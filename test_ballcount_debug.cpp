#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
    int ball[3]; //총 표시할 공(숫자) 는 3개
    srand(time(NULL));

    do {
        ball[0] = rand() % 10 + 1; //ball[0]에서 1~9까지 랜덤숫자를 뽑아라
        ball[1] = rand() % 10 + 1; //ball[1]에서 1~9까지 랜덤숫자를 뽑아라
        ball[2] = rand() % 10 + 1; //ball[2]에서 1~9까지 랜덤 숫자를 뽑아라
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]); // 단, 뽑는 3개의 숫자들이 중복된 숫자여서는 안된다

    printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]); 

    while(1) //홈런을 칠때까지 반복된다
    {                             
        int input[3];
        printf("Enter the first number: "); // 유저가 선택한 첫번째 수를 기입
        scanf("%d", &input[0]);

        printf("Enter the second number: "); //유저가 선택한 2번째 수를 기입
        scanf("%d", &input[1]);

        printf("Enter the third number: "); //유저가 선택한 3번째 수를 기입
        scanf("%d", &input[2]);

        printf("input : %d %d %d\n", input[0], input[1], input[2]); //최종적으로 유저가 고른 3개의 숫자를 순서에 맞게 표시

        int strike_count = 0;
        int ball_count = 0;                   // 스트라이크,볼,아웃의 숫자카운트는 0부터 시작
        int out_count = 0;
        //숫자도 같고 위치도 같을경우에 스트라이크의 카운트가 하나씩 올라간다
        if( ball[0] == input[0] ) strike_count++; 
        if( ball[1] == input[1] ) strike_count++;
        if( ball[2] == input[2] ) strike_count++;
        // 숫자는 같으나 위치가 다른경우에 볼의 카운트가 하나씩 올라간다 
        if( ball[0] == input[1] || ball[0] == input[2] ) ball_count++;
        if( ball[1] == input[0] || ball[1] == input[2] ) ball_count++;
        if( ball[2] == input[0] || ball[2] == input[1] ) ball_count++;

        if( strike_count == 0 && ball_count == 0 ) //스트라이크가 0이고 볼이 0이면 3아웃이 된다
        {
            out_count = 3;
        }
        if( strike_count == 1 && ball_count == 0 || strike_count == 0 && ball_count == 1) //스트라이크나 볼이 1개인경우, 2아웃이 된다
        {
            out_count = 2;
        }
        if( strike_count == 2 && ball_count == 0 || strike_count == 0 && ball_count == 2 || strike_count == 1 && ball_count ==1 ) //스트라이크나 볼이 2개, 스트라이크나 볼이 각각 한개씩인 경우, 1아웃이 된다
        {
            out_count = 1;
        }

        if( ball[0] == input[0] && ball[1] == input[1] && ball[2] == input[2] ) // 유저가 선택한 숫자가 랜덤한 숫자 3개와 같고 위치도 동일한 경우 홈런을 출력하고 자동으로 프로그램을 종료한다
        {
	    printf("Home Run~\n") ;
        return 0;
        }
        else
        {
        printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count) ; //홈런의 조건을 만족하지 못한경우, 스트라이크 볼 아웃 순서로 카운트를 표시하고 다시 유저가 기입하는 곳부터 시작한다.
        }

    }
    return 0; //프로그램 종료
}


