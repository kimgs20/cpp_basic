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

// 다차원 배열 인자로 사용하기
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221329432324
void matmul(int (*aMat)[2], int (*bMat)[3], int (*ans)[3]) {

     // highschool type calculation
     (*(ans))[0] = (*(aMat))[0] * (*(bMat))[0] + (*(aMat))[1] * (*(bMat + 1))[0];
     (*(ans))[1] = (*(aMat))[0] * (*(bMat))[1] + (*(aMat))[1] * (*(bMat + 1))[1];
     (*(ans))[2] = (*(aMat))[0] * (*(bMat))[2] + (*(aMat))[1] * (*(bMat + 1))[2];

     (*(ans + 1))[0] = (*(aMat + 1))[0] * (*(bMat))[0] + (*(aMat + 1))[1] * (*(bMat + 1))[0];
     (*(ans + 1))[1] = (*(aMat + 1))[0] * (*(bMat))[1] + (*(aMat + 1))[1] * (*(bMat + 1))[1];
     (*(ans + 1))[2] = (*(aMat + 1))[0] * (*(bMat))[2] + (*(aMat + 1))[1] * (*(bMat + 1))[2];

     (*(ans + 2))[0] = (*(aMat + 2))[0] * (*(bMat))[0] + (*(aMat + 2))[1] * (*(bMat + 1))[0];
     (*(ans + 2))[1] = (*(aMat + 2))[0] * (*(bMat))[1] + (*(aMat + 2))[1] * (*(bMat + 1))[1];
     (*(ans + 2))[2] = (*(aMat + 2))[0] * (*(bMat))[2] + (*(aMat + 2))[1] * (*(bMat + 1))[2];

     // 보통 for loop 세개로 구현함
     // for (int i = 0; i < n-1; i++) {
     //      for (int j = 0; j < n-1; j++) {
     //           for (int k = 0; k < n-1; k++) {
     //                c_ij = c_ij + a_ik * b_kj;
     //           }
     //      }
     // }
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
          }
     }

     // 각 array의 첫 번째 주소 전달
     matmul(aMat, bMat, ans);

     std::cout << "after matmul in main" << std::endl;
     for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
               std::cout << ans[i][j] << " ";
          }
          std::cout << std::endl;
     }

     return 0;
}
