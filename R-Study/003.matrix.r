#矩阵和数组
###矩阵是一种包含了行数和列数两种属性的特殊向量，一般情况下矩阵是按列存储的，不过也可以通过设定byrow调试为按行
####创建矩阵
x <- matrix(c(1,2,3,4), nrow = 2, ncol = 2)
y <- matrix(c(1,2,3,4), nrow = 1)
z <- matrix(c(1,2,3,4), ncol = 1)
y <- matrix(nrow = 2,ncol = 2)
y[1,1] <- 1
y[1,2] <- 2
y[2,1] <- 3
y[2,2] <- 4
m <- matrix(c(1,2,3,4,5,6),nrow = 2)
m <- matrix(c(1,2,3,4,5,6), nrow=2,byrow = TRUE)
####矩阵线性运算(矩阵相乘，矩阵数量乘，矩阵加法)
y <- matrix(c(1,2,3,4), nrow = 2, ncol = 2)
y %*% y
y * 3
y + y
####根据索引提取矩阵,注意区分：和，
z <- matrix(c(1,2,3,4,1,1,0,0,1,0,1,0), nrow = 4, ncol = 3)
z[,2:3]
y <- matrix(c(11,21,31,12,22,32), nrow = 3, ncol = 2)
y[2:3,]
y[2:3,2]
y <- matrix(c(1,2,3,4,5,6),nrow = 3)
y[c(1,3),] <- matrix(c(1,1,8,12),nrow = 2)
y
x <- matrix(nrow = 3,ncol = 3)
y <- matrix(c(4,5,2,3),nrow = 2)
x[2:3,2:3] <- y
x
#####负值索引删除元素
x
x[-1,]
####矩阵元素筛选
m <- matrix(c(1,2,3,4,5,6), nrow = 3, ncol = 2)
m[m[,1] > 1 & m[,2]>5, ]
####矩阵也是向量，向量运算也适用于矩阵，这个矩阵试一个竖着看组合的向量
m <- matrix(c(5,2,9,-1,10,11),ncol = 2)
which(m > 2) ##展示第几个元素大于2
####协方差矩阵
#row() col()两个函数的参数都是矩阵 row(a[2,8])返回行号2
####3.3.1
z <- matrix(c(1,2,3,4,5,6),ncol = 2)
apply(z, 2, mean)
apply(z, 1, sd)
t(z) #转置函数
####rbind()和cbind()
#矩阵的长度和维度是固定的，不能随意的增加或者删除行或者列，但是可以给矩阵重新赋值，根据索引提取或者合并，以及重新赋值
one <- c(1,1,1,1)
z <- matrix(c(1,2,3,4,1,1,0,0,1,0,1,0), ncol = 3)
cbind(one,z)
cbind(2,z) #循环补齐
q <- cbind(c(1,2), c(3,4))
####矩阵是一个带有属性的向量（再次理解）
z <- matrix(1:8,nrow = 4)
length(z)
class(z)
attributes(z) #所以说matrix有一个属性，这个属性由行数列数组成的向量，我们用nrow ncol访问
nrow(z)
ncol(z)
####R语言的降维和统计学中的降维是不同的，R语言矩阵降维就变成向量了，一般情况我们要避免这种情况
#避免自动降维：
z <- matrix(c(1:8), ncol = 2)
r <- z[2,] #此时R变成了一个向量
attributes(z)
attributes(r)
str(z)
str(r)
r1 <- z[2,,drop=FALSE] #避免自动降维
attributes(r1)
str(r1)
one <- c(1,2,3)
as.matrix(one) #一般情况下，向量自动转换为矩阵
####矩阵的行列命名
z <- matrix(c(1:8), ncol = 2)
colnames(z)
rownames(z)
colnames(z) <- c("a","b")
rownames(z) <- c("c","d","e","f")
colnames(z)
rownames(z)
z
####多维数组背景介绍见3.8 矩阵的分层合并
firsttest <- matrix(c(46,21,50,30,25,50),ncol = 2)
secondtest <- matrix(c(46,41,50,43,35,50),ncol = 2)
tests <- array(data = c(firsttest,secondtest), dim = c(3,2,2)) #dim 这是一个3行两列的两个矩阵合并而成，
class(tests)
attributes(tests)
tests[3,2,1:2]
tests
