import random
import time
import numpy

dim = 512
matrix1 = []
matrix2 = []
result = []
c_result = []
c = 2 * dim * dim * dim

for i in range(dim):
    row1 = []
    row2 = []
    row3 = []
    row4 = []
    for j in range(dim):
        row1.append(random.uniform(-10, 10))
        row2.append(random.uniform(-10, 10))
        row3.append(0)
        row4.append(0)
    matrix1.append(row1)
    matrix2.append(row2)
    result.append(row3)
    c_result.append(row4)
start = time.time()
for i in range(dim):
    for j in range(dim):
        k = 0
        while k < dim:
            result[i][j] += matrix1[i][k] * matrix2[k][j] 
            k += 1
end = time.time()
t = end - start
p = c / t * 0.000001
print ("1. Линейное перемножение", t, p)
s_start = time.time()
r = numpy.dot(matrix1, matrix2)
s_end = time.time()
s_t = s_end - s_start
s_p = c / s_t * 0.000001
print ("2. Алгоритм cblas_sgemm", s_t, s_p)

c_start = time.time()

for i in range(dim):
    for j in range(dim):
        k = 0
        while k < dim:
            c_result[i][j] += matrix1[i][k] * matrix2[k][j] + matrix1[i][k + 1] * matrix2[k + 1][j] + matrix1[i][k + 2] * matrix2[k + 2][j] + matrix1[i][k + 3] * matrix2[k + 3][j] + matrix1[i][k + 4] * matrix2[k + 4][j] + matrix1[i][k + 5] * matrix2[k + 5][j] + matrix1[i][k + 6] * matrix2[k + 6][j] + matrix1[i][k + 7] * matrix2[k + 7][j]
            k += 8

c_end = time.time()
c_t = c_end - c_start
c_p = c / c_t * 0.000001
print ("3. Оптимизированный алгоритм", c_t, c_p )