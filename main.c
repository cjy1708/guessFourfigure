#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int reality[4] = {0};
    int try[4] = {0};
    int tool = 0; //����
    int sameNumber = 0;//��ͬ��������
    int sameLocation = 0;
    srand(time(0));//ˢ��ʱ��
    //
    for (int i = 0;i <= 3;i++){
        //���������
        reality[i] = rand()%9+1;
        //�ж��Ƿ����ظ�,�ɹ�
        for(int y = 0;y < i;){
            if (reality[i] == reality[y]){
                reality[i] = rand()%9+1;
                y = 0;
            }
            else y++;
        }
    }
    for (int i = 0;i <= 3;i++){
        //�Ƚϴ�С�����򣬳ɹ�
        for (int x = 0;x < i;){
            if (reality[x] >= reality[i]) {
                tool = reality[x];
                reality[x] = reality[i];
                reality[i] = tool;
                x = 0;
            }
            else x++;
        }
    }
    printf("%d %d %d %d",reality[0],reality[1],reality[2],reality[3]);
    do{
        //�û�����
        for (int i = 0;i <= 3;i++)
            scanf("%d",&try[i]);
        for (int i = 0;i <= 3;i++){
        //�Ƚϴ�С�����򣬳ɹ�
        for (int x = 0;x < i;){
            if (try[x] >= try[i]){
                tool = try[x];
                try[x] = try[i];
                try[i] = tool;
                x = 0;
            }
            else x++;
        }
    }
    //��ʼ�жϣ��ж��м�����ͬ
    for (int i = 0;i <= 3;i++){
        for (int j =0;j <= 3;j++){
            if (try[j] == reality[i]){
                sameNumber++;
                break;
            }
        }
        //�жϼ�������ͬ�ֶ�λ
        if(reality[i] == try[i])
            sameLocation++;
    }
    if(sameLocation == 4)
        printf("�ɹ���");
    else {
        printf("%dA%dB\n", sameLocation, sameNumber - sameLocation);
        sameLocation = sameNumber = 0;
    }
    }while (sameLocation < 4);
    return 0;
}