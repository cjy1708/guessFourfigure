#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int reality[4] = {0};
    int try[4] = {0};
    int tool = 0; //工具
    srand(time(0));//刷新时间

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
    for (int i = 0;i <= 3;i++)
        printf("%d",reality[i]);
    return 0;
}