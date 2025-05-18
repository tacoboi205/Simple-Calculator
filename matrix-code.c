void displayMatrix2x2(int matrix[2][2])                 //displaying the 2x2 matrix
{
    for (int i = 0; i < 2; i++)
    {
        printf("%d %d\n", matrix[i][0], matrix[i][1]);
    }
}
void displayMatrix3x3(int matrix[3][3])             //displaying the 3x3 matrix
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}
void add2x2(int A[2][2], int B[2][2], int result[2][2]) //adding 2 matrices of 2x2 type
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = A[i][j] + B[i][j];
}
void add3x3(int A[3][3], int B[3][3], int result[3][3]) //adding 2 matrices of 3x3 type
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result[i][j] = A[i][j] + B[i][j];
}
void subtract2x2(int A[2][2], int B[2][2], int result[2][2])    //subtracting 2 matrices of 2x2 type
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = A[i][j] - B[i][j];
}
void subtract3x3(int A[3][3], int B[3][3], int result[3][3])    //subtracting 2 matrices of 3x3 type
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result[i][j] = A[i][j] - B[i][j];
}
void multiply2x2(int A[2][2], int B[2][2], int result[2][2])    //multiplying 2 matrices of 2x2 type
{
    result[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    result[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    result[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    result[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
}
void multiply3x3(int A[3][3], int B[3][3], int result[3][3])    //multiplying 2 matrices of 3x3 type
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
}
int determinant2x2(int matrix[2][2])                        //finding determinant of a 2x2 matrix
{
    return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
}
int determinant3x3(int m[3][3])                             //finding determinant of a 3x3 matrix
{
    int det;
    det =  m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1])
         - m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0])
         + m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);
    return det;
}
