/*
https://github.com/Seungyeon-Lee/CV-Study/blob/main/CV-Study/0404_flood_fill.cpp
소스코드를 응용하여 작성

*/
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

bool visit[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1,-1, 0, 0 };

bool is_Same_Color(Vec3b a, Vec3b b) {
   return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

void dfs(int curY, int curX, Mat& image,Vec3b flood)
{
   Vec3b origin = image.at<Vec3b>(Point(curX,curY));
   image.at<Vec3b>(curY, curX) = flood;

   for (int i = 0; i < 4; i++)
   {
      int nextY = curY + dy[i];
      int nextX = curX + dx[i];

      //이미 방문 했거나 범위를 벗어나는 경우
      if (visit[nextY][nextX] || nextY < 0 || nextY >= image.rows || nextX < 0 || nextX >= image.cols)
         continue;
      if (is_Same_Color(origin,image.at<Vec3b>(nextY, nextX)))
      {
         visit[nextY][nextX] = 1;
         image.at<Vec3b>(nextY, nextX) = flood;
         dfs(nextY, nextX, image, flood);
      }
      
   }
}

int main()
{
   Mat input = imread("C:/Users/ksq11/source/repos/OPEN_CV/aero1.jpg", IMREAD_COLOR); // 이미지를 읽어 MAT에 대입; 
   Mat output = imread("C:/Users/ksq11/source/repos/OPEN_CV/aero1.jpg", IMREAD_COLOR); // 이미지를 읽어 MAT에 대입;
   
   
   if (input.empty() || output.empty())
   {
      cout << "Image Open Error!" << endl;
      return -1;
   }
   for (int r = 0; r < input.rows; r++)
      for (int c = 0; c < input.cols; c++) {
         if (!visit[r][c]) {
            
            visit[r][c] = true;
            Vec3b rand_color = Vec3b((unsigned)theRNG() & 255, (unsigned)theRNG() & 255, (unsigned)theRNG() & 255);
            dfs(r, c, output, rand_color);
         }
      }
   
   imshow("origin", input);
   imshow("result", output);

   waitKey(0);

   
   return 0;

}
