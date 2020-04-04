#include<stdio.h>

#include<math.h>

void main() {

  int i, j, m, n;
  printf("Enter the dimension of the dataset: ");
  scanf("%d %d", & m, & n);
  double a[m][n];
  printf("Enter the data: ");
  //Getting the input data
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", & a[i][j]);
    }

  }
  
  //Calculating the sum and mean
  double mean[n];
  for (int col = 0; col < n; col++){
     double colsum = 0;
     for (int row = 0; row < m; row++){
         colsum +=  a[row][col];
        }
        mean[col] = colsum / (double) m;
     //printf("Sum for col %d = %lf\n", col, colsum);
     //printf("column sum/m is %f \n", colsum/(double)m);
    }
  
  
  
  
  
  //Calculating the subtacted matrix
  double sub[m][n];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      sub[i][j] = a[i][j] - mean[j];
     // printf("sub of i j is %f \n", sub[i][j]);
    }
  }
  
  //printing multtrans
  
  for(i=0; i<m;i++){
      for( j=0;j<n;j++){
          //printf("sub is %f \n", sub[i][j]);
      }
  }
  
  //Calculating the transpose
  double tran[n][m];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      tran[j][i] = sub[i][j];
    }
  }

  //printing transpose
  for(i=0; i<n;i++){
      for( j=0;j<m;j++){
         // printf("Tran is %lf \n", tran[i][j]);
      }
  }

  //Correct until now
  
  //Removing the garbage value
  double mult[m][n];
  for ( i = 0; i < m; ++i) {
    for ( j = 0; j < n; ++j) {
      mult[i][j] = 0;
    }
  }

  //New multitran
  double multtrans1[m][m];
  for (i=0; i<m; i++)
    for (int j=0; j<m; j++)
        for (int k=0; k<n; k++) //j = row
        {
            multtrans1[i][j] += sub[i][k] * tran[k][j];
        }
  
  //printing multtrans
  
  for(i=0; i<m;i++){
      for( j=0;j<m;j++){
         // printf("multitans is %lf \n", multtrans1[i][j]);
      }
  }
  
  //Working until here 
  
  //Calculating covariance
  double cov[m][m];
  for(i=0; i<m;i++){
      for( j=0;j<m;j++){
        //printf("fraction is %lf \n",(double) (1/(m-1)));
          cov[i][j] = (double) (1/(m-1)) * multtrans1[i][j];
      }
  }

  for(i=0; i<m;i++){
      for( j=0;j<m;j++){
          //printf("cov is %lf \n", cov[i][j]);

      }
  }
  
//finding the eigenvalues
  double b = (cov[0][0] + cov[1][1]);
  double c = (cov[0][0] * cov[1][1]) - (cov[0][1] * cov[1][0]);

  double d = -b + sqrt(pow(b, 2) - 4 * c);
  double f = -b - sqrt(pow(b, 2) - 4 * c);
  double e = d / 2;
  double g = f / 2;
//finding the eigenvectors
  double v1[2][1], v2[2][1];
  if (cov[0][1] != 0) {
    v1[0][0] = -cov[0][1];
    v1[1][0] = cov[0][0] - e;
    v2[0][0] = -cov[0][1];
    v2[1][0] = cov[0][0] - g;
  } else {
    v1[1][0] = -cov[0][1];
    v1[0][0] = cov[0][0] - e;
    v2[1][0] = -cov[0][1];
    v2[0][0] = cov[0][0] - g;
  }

  double sum1 = e + g;

  double t = e / sum1;
  double y = g / sum1;
  //correct values are obtaining
  double ne[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      ne[i][j] = 0;
    }
  }
//finding the principle components.
  if (t > y) {
    for (i = 0; i < m; i++) {
      for (j = 0; j < m; j++) {
        for (int k = 0; k < n-1; k++) {
          ne[i][j] += a[i][k] * v1[k][j];
        }
      }
    }
  } else {
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        for (int k = 0; k < n-1; k++) {
          ne[i][j] += a[i][k] * v2[k][j];
        }
      }
    }
  }
  printf("The principle components of the given values are");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n-1; j++) {
      printf("%lf\n", ne[i][j]);
    }

  }

}
//checked till here
