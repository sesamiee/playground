// 디미게임
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int player_number,nameint,turn = 0;
int infor_player[4] = {0};
int infor_freeze[4] = {0};
int infor_twice[4] = {0};
const char *name[10] = {"red", "yellow","green","blue"};

int find_player(int x) {
   //printf("%d",player_number);
      int a = x % player_number;
   switch (a)
   {
   case 0: nameint = 0; break;
   case 1: nameint = 1; break;
   case 2: nameint = 2; break;
   case 3: nameint = 3; break;
   }
   printf("\n%d번째 순서인 player %s님 환영합니다!",x+1,name[nameint]);
   infor_player[nameint]++;
   Sleep(1000);
}

int make_name() {
   int a = turn % player_number;
   switch (a)
   {
   case 0: nameint = 0; break;
   case 1: nameint = 1; break;
   case 2: nameint = 2; break;
   case 3: nameint = 3; break;
   }
}

int mkran() {
   int a;
    a = rand() % 100 + 1;
   return a;
}


int freeze() {
   infor_freeze[turn % player_number]--;
   turn++;
}

int twice() {
   infor_twice[turn % player_number]--;
}

int swap() {
   int a,b;
   printf("\n자리를 바꿀 상대를 입력해주세요\n1.red 2.Yellow 3.green 4.blue : ");
   scanf("%d",&a); while (getchar() != '\n');
   if(infor_player[a-1] == 0) {
      printf("\n없는 대상입니다 ");
      swap();
   }
   else if(a-1 == turn % player_number) {
      if(player_number == 1) printf("\n혼자인 것을 다행이 여기십시오 인간");
      else {
         printf("\n자신을 선택할 수 없습니다");
         swap();
      }
   }

   else {
      b = infor_player[a-1] ;
      infor_player[a-1] = infor_player[turn % player_number];
      infor_player[turn % player_number] = b;
   }
}

void eat() {
   int a,b = mkran();
   printf("\n간식을 섭취합니다! 섭취할 간식을 골라주세요 : ");
   printf("\n1. 초콜릿을 섭취합니다 한칸 앞으로 이동합니다 (인터렉트 적발확률 2%%)");
   printf("\n2. 탄산음료를 섭취합니다 세칸 더 앞으로 이동합니다 (인터렉트 적발확률 10%%)");
   printf("\n3. 과자를 섭취합니다 다섯칸 더 앞으로 이동합니다 (인터렉트 적발확률 30%%)");
   printf("\n4. 라면을 섭취합니다 일곱칸 더 앞으로 이동합니다 (인터렉트 적발확률 60%%)");
   printf("\n 위에 값에 맞는 숫자를 입력해주세요 : ");
   scanf("%d",&a); while (getchar() != '\n');
   Sleep(2000);
   switch (a)
   {
   case 1:
      if(b > 2) {
         printf("\n섭취에 성공했습니다! 정의된 칸만큼 앞으로 이동합니다!");
         infor_player[turn % player_number]++;
      }
      else {
         printf("\n인터렉트가 당신을 주시합니다! 데스노트에 이름이 적히는 것이 보입니다!(프리징 1)");
         infor_freeze[turn % player_number]++;
      }
      break;
   case 2:
      if(b > 10) {
         printf("\n섭취에 성공했습니다! 정의된 칸만큼 앞으로 이동합니다!");
         infor_player[turn % player_number]+= 3;
      }
      else {
         printf("\n인터렉트가 당신을 주시합니다! 데스노트에 이름이 적히는 것이 보입니다!(프리징 1)");
         infor_freeze[turn % player_number]++;
      }
      break;
   case 3:
      if(b > 30) {
         printf("\n섭취에 성공했습니다! 정의된 칸만큼 앞으로 이동합니다!");
         infor_player[turn % player_number]+= 5;
      }
      else {
         printf("\n인터렉트가 당신을 주시합니다! 데스노트에 이름이 적히는 것이 보입니다!(프리징 1)");
         infor_freeze[turn % player_number]++;
      }
      break;
   case 4:
      if(b > 60) {
         printf("\n섭취에 성공했습니다! 정의된 칸만큼 앞으로 이동합니다!");
         infor_player[turn % player_number] += 7;
      }
      else {
         printf("\n인터렉트가 당신을 주시합니다! 데스노트에 이름이 적히는 것이 보입니다!(프리징 1)");
         infor_freeze[turn % player_number]++;
      }
      break;
   default: eat(); break;
   }
}

void meet() {
   int a = mkran();
   if(a >0 &&a <21) printf("\n담임 선생님을 만났습니다! 밀린 배네듀가 기억났습니다 (추가턴 0)");

   else if(a >20 &&a <41) {
      printf("\n사감 선생님을 만났습니다! 형연할 수 없는 공포가 당신을 지배합니다! (프리징 1)");
      infor_freeze[turn % player_number] ++;
   }
   else if(a >40 &&a <61) {
      printf("\n교장 선생님을 만났습니다! 웃으시면서 500원 쿠폰을 선물하십니다!(추가턴 2)");
      infor_twice[turn % player_number] += 2;
   }
   else if(a >60 &&a <101) {
      printf("\n교감 선생님을 만났습니다! 저멀리서 축구공이 날아옵니다! (추가턴 1)");
      infor_twice[turn % player_number] ++;
   }
}

void study() {
      int a = mkran();
   if(a >0 &&a <= 40) {
      printf("\n교과서위주로 공부합니다! 그런데 나는 성적이 늘지 않는 것 같습니다! (뒤로 한칸)");
      infor_player[turn % player_number] --;
   }
   else if(a >40 &&a <= 65) {
      printf("\n확원숙제를 시작합니다! 습관적으로 답안지를 찾습니다! (뒤로 두칸)");
      infor_player[turn % player_number] -= 2;
   }
   else if(a >65 &&a <= 90) {
      printf("\n모의고사를 시작합니다! 그날의 공포가 느껴지는 것 같습니다! (뒤로 세칸)");
      infor_player[turn % player_number] -= 3;
   }
   else if(a >90 &&a <= 100) {
      printf("\n수능특강을 시작합니다! 수시만이 살 길임을 느낍니다! (뒤로 다섯칸)");
      infor_player[turn % player_number] -= 5;
   }
}

void wa_sleep() {
      int a = mkran();
   if(a >0 &&a <= 20) {
      printf("\n개꿈을 꿨습니다! 나의 상상력에 다시금 놀랍니다! (상대와 스왑)");
      swap();
   }
   else if(a == 100) {
      printf("\n꿈에서 디미신이 강림했습니다! 삼라만상의 진리를 깨닫습니다! (게임승리)");
      infor_player[turn % player_number] = 100;
   }
   else if(a >20 &&a <= 50) {
      printf("\n엄청 커다란 모기가 보입니다! 아무생각없이 발을 긁었습니다! (뒤로 세칸)");
      infor_player[turn % player_number] -= 3;
   }
   else if(a >50 &&a <= 99) {
      printf("\n황금돼지꿈을 꿨습니다! 말해줬던 8자리 숫자가 기억이 나지 않습니다! (앞으로 다섯칸)");
      infor_player[turn % player_number] += 5;
   }
}

void test() {
      int a = mkran();
   if(a >0 &&a <= 30) {
      printf("\n쪽지시험을 진행합니다! 쪽지가 B4용지입니다! (프리징 0)");
   }
   else if(a >50 &&a <= 98) {
      printf("\n수행평가를 진행합니다! 다음수행은 잘볼꺼라 다짐합니다! (프리징 1)");
      infor_freeze[turn % player_number]++;
   }
   else if(a >30 &&a <= 50) {
      printf("\n기말고사를 진행합니다! 못난 자식이라 부모님에게 죄송합니다! (프리징 2)");
      infor_freeze[turn % player_number] += 2;
   }
   else if(a >98 &&a <= 100) {
      printf("\n수능을 진행합니다! 대학이 인생의 전부는 아니잖아아! (프리징 4)");
      infor_player[turn % player_number] += 4;
   }
}

void set() {
   char c;

   do{
   printf("플레이어의 수를 입력해주세요(1-4) : ");
   if(scanf("%d",&player_number))
   {
      if(player_number > 4 || player_number < 1) set();
      break;
   }
   else
   {
      while(c = getchar() != '\n' && c!=EOF);
      continue;
   }

   }while(1);
}

int dice_roll() {
   int dice_number;
    dice_number = rand() % 10 + 1;
   make_name();
   printf("\n\n현재 플레이어 : %s 진행정도 : %d 프리징 상태 : %d",
   name[nameint],infor_player[turn % player_number],infor_freeze[turn % player_number]);
   Sleep(1000);
   printf("\n 룰렛을 돌립니다!\n룰렛이 돌아가는 중");
   for(int i = 0; i <3; i++) {
      printf(". ");
      Sleep(1200);
   }
   printf("\n룰렛에서 %d이 나왔습니다!",dice_number);
   infor_player[turn % player_number] += dice_number;
   return dice_number;
}

void act() {
   int a = mkran();
   printf("\n이동 중입니다! 디미고 안이라 무슨 일이 일어날지 모르겠습니다!");
   printf("\n이동 중");
   for(int i = 0; i <4; i++) {
      printf(". ");
      Sleep(1200);
   }
   if(a >0 &&a <21) test();
   else if(a >20 &&a <41) eat();
   else if(a >40 &&a <61) meet();
   else if(a >60 &&a <81) study();
   else if(a >80 &&a <101) wa_sleep();
}

void end() {
   int wa_sans;
   make_name();
   printf("\n\n현재 플레이어 : %s 진행정도 : %d 프리징 상태 : %d",
   name[nameint],infor_player[turn % player_number],infor_freeze[turn % player_number]);
   turn++;
   printf("\n아무키나 눌러서 다음차례를 진행합니다! : ");
   scanf("%d",&wa_sans); while (getchar() != '\n');
}


int main(){
   srand(time(NULL));
   printf("< THE DIMIGAME >\n\n");
   set();
   for(int i =0; i < player_number; i++) find_player(i);
   while(1){
      if(infor_freeze[turn % player_number] < 1) {
         dice_roll();
         act();
         if(infor_twice[turn % player_number] < 1) end();
         else printf("\n추가턴을 진행합니다! (남은 추가턴 %d)",--infor_twice[turn % player_number]);
      }
      else {
         printf("\n프리징 상태임으로 다음 플레이어가 진행합니다 (남은 프리징 %d)",
         --infor_freeze[turn % player_number]);
         turn++;
      }
      if(infor_player[(turn-1) % player_number] > 72 ){
         if(infor_freeze[(turn-1) %player_number] < 1) break;
         else printf("\n교문이 눈앞이지만 몸이 얼어붙어 움직이지 않습니다! (프리징이 풀려야 승리)");
      }
    }
   
    printf("\n수많은 억까를 이겨내고 승리하셨습니다! player %s!",name[nameint]);
}