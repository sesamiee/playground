// ��̰���
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
   printf("\n%d��° ������ player %s�� ȯ���մϴ�!",x+1,name[nameint]);
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
   printf("\n�ڸ��� �ٲ� ��븦 �Է����ּ���\n1.red 2.Yellow 3.green 4.blue : ");
   scanf("%d",&a); while (getchar() != '\n');
   if(infor_player[a-1] == 0) {
      printf("\n���� ����Դϴ� ");
      swap();
   }
   else if(a-1 == turn % player_number) {
      if(player_number == 1) printf("\nȥ���� ���� ������ ����ʽÿ� �ΰ�");
      else {
         printf("\n�ڽ��� ������ �� �����ϴ�");
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
   printf("\n������ �����մϴ�! ������ ������ ����ּ��� : ");
   printf("\n1. ���ݸ��� �����մϴ� ��ĭ ������ �̵��մϴ� (���ͷ�Ʈ ����Ȯ�� 2%%)");
   printf("\n2. ź�����Ḧ �����մϴ� ��ĭ �� ������ �̵��մϴ� (���ͷ�Ʈ ����Ȯ�� 10%%)");
   printf("\n3. ���ڸ� �����մϴ� �ټ�ĭ �� ������ �̵��մϴ� (���ͷ�Ʈ ����Ȯ�� 30%%)");
   printf("\n4. ����� �����մϴ� �ϰ�ĭ �� ������ �̵��մϴ� (���ͷ�Ʈ ����Ȯ�� 60%%)");
   printf("\n ���� ���� �´� ���ڸ� �Է����ּ��� : ");
   scanf("%d",&a); while (getchar() != '\n');
   Sleep(2000);
   switch (a)
   {
   case 1:
      if(b > 2) {
         printf("\n���뿡 �����߽��ϴ�! ���ǵ� ĭ��ŭ ������ �̵��մϴ�!");
         infor_player[turn % player_number]++;
      }
      else {
         printf("\n���ͷ�Ʈ�� ����� �ֽ��մϴ�! ������Ʈ�� �̸��� ������ ���� ���Դϴ�!(����¡ 1)");
         infor_freeze[turn % player_number]++;
      }
      break;
   case 2:
      if(b > 10) {
         printf("\n���뿡 �����߽��ϴ�! ���ǵ� ĭ��ŭ ������ �̵��մϴ�!");
         infor_player[turn % player_number]+= 3;
      }
      else {
         printf("\n���ͷ�Ʈ�� ����� �ֽ��մϴ�! ������Ʈ�� �̸��� ������ ���� ���Դϴ�!(����¡ 1)");
         infor_freeze[turn % player_number]++;
      }
      break;
   case 3:
      if(b > 30) {
         printf("\n���뿡 �����߽��ϴ�! ���ǵ� ĭ��ŭ ������ �̵��մϴ�!");
         infor_player[turn % player_number]+= 5;
      }
      else {
         printf("\n���ͷ�Ʈ�� ����� �ֽ��մϴ�! ������Ʈ�� �̸��� ������ ���� ���Դϴ�!(����¡ 1)");
         infor_freeze[turn % player_number]++;
      }
      break;
   case 4:
      if(b > 60) {
         printf("\n���뿡 �����߽��ϴ�! ���ǵ� ĭ��ŭ ������ �̵��մϴ�!");
         infor_player[turn % player_number] += 7;
      }
      else {
         printf("\n���ͷ�Ʈ�� ����� �ֽ��մϴ�! ������Ʈ�� �̸��� ������ ���� ���Դϴ�!(����¡ 1)");
         infor_freeze[turn % player_number]++;
      }
      break;
   default: eat(); break;
   }
}

void meet() {
   int a = mkran();
   if(a >0 &&a <21) printf("\n���� �������� �������ϴ�! �и� ��׵డ ��ﳵ���ϴ� (�߰��� 0)");

   else if(a >20 &&a <41) {
      printf("\n�簨 �������� �������ϴ�! ������ �� ���� ������ ����� �����մϴ�! (����¡ 1)");
      infor_freeze[turn % player_number] ++;
   }
   else if(a >40 &&a <61) {
      printf("\n���� �������� �������ϴ�! �����ø鼭 500�� ������ �����Ͻʴϴ�!(�߰��� 2)");
      infor_twice[turn % player_number] += 2;
   }
   else if(a >60 &&a <101) {
      printf("\n���� �������� �������ϴ�! ���ָ��� �౸���� ���ƿɴϴ�! (�߰��� 1)");
      infor_twice[turn % player_number] ++;
   }
}

void study() {
      int a = mkran();
   if(a >0 &&a <= 40) {
      printf("\n���������ַ� �����մϴ�! �׷��� ���� ������ ���� �ʴ� �� �����ϴ�! (�ڷ� ��ĭ)");
      infor_player[turn % player_number] --;
   }
   else if(a >40 &&a <= 65) {
      printf("\nȮ�������� �����մϴ�! ���������� ������� ã���ϴ�! (�ڷ� ��ĭ)");
      infor_player[turn % player_number] -= 2;
   }
   else if(a >65 &&a <= 90) {
      printf("\n���ǰ�縦 �����մϴ�! �׳��� ������ �������� �� �����ϴ�! (�ڷ� ��ĭ)");
      infor_player[turn % player_number] -= 3;
   }
   else if(a >90 &&a <= 100) {
      printf("\n����Ư���� �����մϴ�! ���ø��� �� ������ �����ϴ�! (�ڷ� �ټ�ĭ)");
      infor_player[turn % player_number] -= 5;
   }
}

void wa_sleep() {
      int a = mkran();
   if(a >0 &&a <= 20) {
      printf("\n������ ����ϴ�! ���� ���¿� �ٽñ� ����ϴ�! (���� ����)");
      swap();
   }
   else if(a == 100) {
      printf("\n�޿��� ��̽��� �����߽��ϴ�! ��󸸻��� ������ ���ݽ��ϴ�! (���ӽ¸�)");
      infor_player[turn % player_number] = 100;
   }
   else if(a >20 &&a <= 50) {
      printf("\n��û Ŀ�ٶ� ��Ⱑ ���Դϴ�! �ƹ��������� ���� �ܾ����ϴ�! (�ڷ� ��ĭ)");
      infor_player[turn % player_number] -= 3;
   }
   else if(a >50 &&a <= 99) {
      printf("\nȲ�ݵ������� ����ϴ�! ������� 8�ڸ� ���ڰ� ����� ���� �ʽ��ϴ�! (������ �ټ�ĭ)");
      infor_player[turn % player_number] += 5;
   }
}

void test() {
      int a = mkran();
   if(a >0 &&a <= 30) {
      printf("\n���������� �����մϴ�! ������ B4�����Դϴ�! (����¡ 0)");
   }
   else if(a >50 &&a <= 98) {
      printf("\n�����򰡸� �����մϴ�! ���������� �ߺ����� �����մϴ�! (����¡ 1)");
      infor_freeze[turn % player_number]++;
   }
   else if(a >30 &&a <= 50) {
      printf("\n�⸻��縦 �����մϴ�! ���� �ڽ��̶� �θ�Կ��� �˼��մϴ�! (����¡ 2)");
      infor_freeze[turn % player_number] += 2;
   }
   else if(a >98 &&a <= 100) {
      printf("\n������ �����մϴ�! ������ �λ��� ���δ� �ƴ��ݾƾ�! (����¡ 4)");
      infor_player[turn % player_number] += 4;
   }
}

void set() {
   char c;

   do{
   printf("�÷��̾��� ���� �Է����ּ���(1-4) : ");
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
   printf("\n\n���� �÷��̾� : %s �������� : %d ����¡ ���� : %d",
   name[nameint],infor_player[turn % player_number],infor_freeze[turn % player_number]);
   Sleep(1000);
   printf("\n �귿�� �����ϴ�!\n�귿�� ���ư��� ��");
   for(int i = 0; i <3; i++) {
      printf(". ");
      Sleep(1200);
   }
   printf("\n�귿���� %d�� ���Խ��ϴ�!",dice_number);
   infor_player[turn % player_number] += dice_number;
   return dice_number;
}

void act() {
   int a = mkran();
   printf("\n�̵� ���Դϴ�! ��̰� ���̶� ���� ���� �Ͼ�� �𸣰ڽ��ϴ�!");
   printf("\n�̵� ��");
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
   printf("\n\n���� �÷��̾� : %s �������� : %d ����¡ ���� : %d",
   name[nameint],infor_player[turn % player_number],infor_freeze[turn % player_number]);
   turn++;
   printf("\n�ƹ�Ű�� ������ �������ʸ� �����մϴ�! : ");
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
         else printf("\n�߰����� �����մϴ�! (���� �߰��� %d)",--infor_twice[turn % player_number]);
      }
      else {
         printf("\n����¡ ���������� ���� �÷��̾ �����մϴ� (���� ����¡ %d)",
         --infor_freeze[turn % player_number]);
         turn++;
      }
      if(infor_player[(turn-1) % player_number] > 72 ){
         if(infor_freeze[(turn-1) %player_number] < 1) break;
         else printf("\n������ ���������� ���� ���پ� �������� �ʽ��ϴ�! (����¡�� Ǯ���� �¸�)");
      }
    }
   
    printf("\n������ �� �̰ܳ��� �¸��ϼ̽��ϴ�! player %s!",name[nameint]);
}