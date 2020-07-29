#include <iostream>
using namespace std;
//인풋값 선언
int H, W, N;
int r[100];
int c[100];
//두 스티커 넓이들의 최고값
//못붙이는경우의 max값을 0으로 출력시켜주기위해 0으로 초기화
int maxx = 0;

//스티커하나를 붙인뒤 다른 하나의 스티커를 붙일 수 있는지, 없는지 체크하는 함수
//ri = 붙여진 스티커의 r값
//ci = 붙여진 스티커의 c값
//j = 현재 붙이려고 하는 스티커의 번호
//스티커를 붙일 수 있으면 true, 붙일 수 없으면 false 리턴
bool inandout(int ri, int ci, int j){
    int x = r[j];
    int y = c[j];
    if(((H>=x)&&(W-ci>=y))||((H-ri>=x)&&(W>=y))) return true;
    if(((H>=y)&&(W-ci>=x))||((H-ri>=y)&&(W>=x))) return true;
    return false;
    
}

int main(void) {
    //인풋
    cin>>H>>W;
    cin>>N;
    if(N == 1) {
        cout<<0<<"\n";
        return 0;
    }
    for(int i = 0; i<N;i++) {
        cin>>r[i]>>c[i];
    }
    //이중 for문 두번돌면서 모든 경우의 수체크(같은 스티커를 고를경우는 continue로 점프)
    //if문을 이용하여 정방향으로 붙이는 경우, 수직방향으로 붙이는 경우 고려
    //어떤 한 방향을 붙일 수 있는경우, 다른 스티커를 붙일 수 있는지를 inandout함수로 체크
    //붙일 수 있는경우 현재의 max값과 비교해서 집어넣는다.
    for(int i = 0; i<N; i++) {
        if((r[i]<=H && c[i]<=W)){
            for(int j = 0; j<N; j++) {
                if(i == j) continue;
                if(inandout(r[i],c[i],j)) maxx = maxx>(r[i]*c[i]+r[j]*c[j])? maxx:(r[i]*c[i]+r[j]*c[j]);
                }
        }
        if((c[i]<=H && r[i]<=W)){
            for(int j = 0; j<N; j++) {
                if(i == j) continue;
                if(inandout(c[i],r[i],j)) maxx = maxx>(r[i]*c[i]+r[j]*c[j])? maxx:(r[i]*c[i]+r[j]*c[j]);
                }
        }
    }
    cout<<maxx<<"\n";

}
