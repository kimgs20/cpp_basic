/*
A = [1 4
     2 5
     3 6]

B = [ 7  8  9
     10 11 12]

ans = [47 52 57
       64 71 78
       81 90 99]
*/

// https://docs.microsoft.com/ko-kr/cpp/cpp/arrays-cpp?view=msvc-170
// array, vector, list

// http://arma.sourceforge.net/docs.html
// Armadillo C++ library for linear algebra & scientific computing


#include <iostream>

void matmul(int (*aMat)[2]) {
     // 이게... 맞나...?
     // https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221329432324
     std::cout << (*(aMat))[0] << std::endl;
     std::cout << (*(aMat))[1] << std::endl;
     std::cout << (*(aMat + 1))[0] << std::endl;
     std::cout << (*(aMat + 1))[1] << std::endl;
     std::cout << (*(aMat + 2))[0] << std::endl;
     std::cout << (*(aMat + 2))[1] << std::endl;
}

int main() {

     // aMat 자체는 배열 첫 번째 위치의 주소
     int aMat[3][2] = {
          {1, 4},
          {2, 5},
          {3, 6}
     };

     int bMat[2][3] = {
          {7, 8, 9},
          {10, 11, 12}
     };

     int ans[3][3];
     for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
               ans[i][j] = 0;
               // std::cout << ans[i][j] << " ";
          }
          // std::cout << std::endl;
     }

     // std::cout << aMat << std::endl;

     matmul(aMat);

     return 0;
}
/* 
TODO

row, col을 구해서 print 하는 함수
 */