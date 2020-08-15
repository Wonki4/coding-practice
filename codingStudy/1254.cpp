#include <iostream>
#include <cstring>
using namespace std;
char F[1001];
//펠린드롬인지 아닌지 체크한다.
bool checkFelin(int left, int right, int len) {
    while(right < len) {
        if(F[left] != F[right]) return false;
        left--;
        right++;
    }
    return true;
}
//
int felindrome(int len) {
    int mid = len / 2;
    //홀수, 그 자체가 펠린드롬일 경우
    if(len % 2 == 1) {
        if(checkFelin(mid-1, mid+1, len)) return len;
        mid += 1;
    }
    for(int i = mid; i < len-1; i++) {
        //짝수 펠린드롬이 되는 경우 체크
        if(checkFelin(i-1, i, len)) return i * 2;
        //홀수 펠림드롬이 되는 경우 체크
        if(checkFelin(i-1, i+1, len)) return i * 2 + 1;
    }
    //마지막 두 원소가 일치하는 경우
    if(checkFelin(len-2, len-1, len)) return (len-1)*2;
    //아예 일치하는 경우가 없을때.
    return (len - 1) * 2 + 1;
}


int main(void) {
    cin>>F;
    unsigned long len = strlen(F);
    cout<<felindrome(len)<<endl;
}
