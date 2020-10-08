#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int reality[4] = {0};
    int try[4] = {0};
    int tool = 0; //工具
    int sameNumber = 0;//相同的数个数
    int sameLocation = 0;
    srand(time(0));//刷新时间
    //并用户输入
    for (int i = 0;i <= 3;i++){
        reality[i] = rand()%9+1;
        //判断是否有重复,成功
        for(int y = 0;y < i;){
            if (reality[i] == reality[y]){
                reality[i] = rand()%9+1;
                y = 0;
            }
            else y++;
        }
        scanf("%d",&try[i]);
    }
    for (int i = 0;i <= 3;i++){
        //比较大小并排序，成功
        for (int x = 0;x < i;){
            if (reality[x] >= reality[i]){
                tool = reality[x];
                reality[x] = reality[i];
                reality[i] = tool;
                x = 0;
            }else if (try[x] >= try[i]){
                tool = try[x];
                try[x] = try[i];
                try[i] = tool;
                x = 0;
            }
            else x++;
        }
    }
    //开始判断，判断有几个相同
    for (int i = 0;i <= 3;i++){
        for (int j =0;j <= 3;j++){
            if (try[j] == reality[i])
                sameNumber++;
        }
    }
    for (int i = 0;i <= 3;i++){
        if(reality[i] = try[i])
            sameLocation++;
        if(sameLocation == 4)
            printf("成功！");
    }
    printf("%dA%dB",sameLocation,sameNumber - sameLocation);
    return 0;
}