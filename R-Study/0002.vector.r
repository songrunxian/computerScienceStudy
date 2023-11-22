#向量
###查看R语言变量的类型模式为mode();R向量索引从1开始；
###理解向量长度length()
x <- c(1,2,4)
length(x)

first1 <- function(x) {
  for (i in 1:length(x)){
    if(x[i] == 1) break
  }
  return(i)
}
first1(c(2,1,2))

x<-c()
x
length(x)
1:length(x)
###变量声明
y <- vector(length = 2)
y[1] <- 5
y[2] <- 12
y

x <- c(1,5)
x
###向量的循环补齐,下面二者等价
c(1,2,4) + c(6,0,9,20,22)
c(1,2,4,1,2) + c(6,0,9,20,22)
###向量运算，按照元素逐个计算
x <- c(1,2,4)
x + c(5,0,-1)
x * c(5,0,-1)
x / c(5,0,1)
x %% c(5,4,1)
###向量间的运算,记住循环补齐
u <- c(5,2,8)
v <- c(1,3,9)
u > v
w <- function(x) return(x+1)
w(u)
sqrt(1:9)
y <- c(1.2,3.9,0.4)
z <- round(y)
f <- function(x,c) return((x+c)^2)
f(1:3,0)
f(1:3,1)
f1 <- function(x) return(c(x,x^2))
x <- c(1:9)
f1(x)
matrix(f1(x),ncol = 2)#构建矩阵
sapply(x, f1) #对x中的每个元素，使用f1处理，将结果转化为矩阵，该函数要后续学习很重要
###向量索引,如果索引是负数，表示剔除该元素
y <- c(1.2, 3.9, 0.4, 0.12)
y[c(1,3)]
y[c(1:3)]
z <- c(5,12,13)
z[-1:-2]
###seq()
seq(12,3,by=-3)
seq(3,12,by=3)
seq(1,10,length.out=10)
####在R编程中，seq(x)函数用于生成一个序列。根据默认设置，如果你只提供了一个参数x,x本质上是x向量的长度，那么seq(x)将生成一个从1到x的整数序列
x <- c(5,12,13)
x
seq(x)
y <- c(111,2)
y
seq(y)
###rep()
x <-rep(8,4)
x
y <-rep(c(1,2,3),2)
y
z <-rep(1:3,4)
z
h <- rep(c(5,11,13,8), each=2)
h
###all()any()cumsum()
x <- 1:10
any(x > 8)
all(x > 8)
y <- c(5,2,-3,8)
cumsum(y)

findruns<-function(x,k){
  n <- length(x)
  runs <- NULL
  for(i in 1:(n-k+1)) {
    if(all(x[i:(i+k-1)]==1)) runs<-c(runs,i)
  }
  return(runs)
}
y<-c(1,0,0,1,1,1,0,1,1)
findruns(y,3)
findruns(y,2)
findruns(y,6)
###NA和NULL
#NA，该数值存在，但是不知道这是什么；NULL表示根本不存在这个数值
x <- c(88,NA,12,168,13)
x
mean(x)
mean(x,na.rm = T)
x <- c(88,NULL,12,168,13)
mean(x)
x <- c(5,NA,12)
mode(x[1])
mode(x[2])
y <- c("abc", "def", NA)
mode(y[2])
mode(y[3])
###筛选，分为找元素和找位置两种
#####找元素：
z <- c(5,2,-3,8)
w <- z[ z*z > 8 ]
w
#####subset筛选元素的关键区别还是在于NA的处理上
x <- c(6,1:3,NA,12)
x[x>5]
subset(x,x>5)
#####找位置：
z <- c(5,2,-3,8)
which(z*z > 8)
#寻找元素中首次出现的位置，下面二者等价：
##1
first1 <- function(x){
  for(i in 1:length(x)) {
    if(x[i] == 1) break
  }
  return (i)
}
##2
firsta <- function(x) return(which(x == 1)[1])
###ifelse()函数
#ifelse(b,u,v)
#该函数返回值也是一个向量，如果b[i]为真，返回u[i],如果是假返回v[i]
x <- 1:10
y <- ifelse(x %% 2 == 0, 5,12)
y

x <- c(5,2,9,12)
ifelse(x > 6, 2*x, 3*x)
###几个经典的操作：
#vud <- vud[-1] - v[-length(v)]这是什么意思
#diff()功能与之近似，sign()可以根据参数向量中的正负0，直接将它们转化成1，0，-1
u <- c(1,6,7,2,3,5)
diff(u)
sign(diff(u))
#将向量vud中从第二个元素开始到最后一个元素的值，依次减去向量v中从第一个元素开始到倒数第二个元素的值。这样做的结果是，vud中的每个元素都减去了与其相邻的v中对应元素的值。
#ud <- lapply(list(x,y), findud)是什么意思
#代码将会将函数findud分别应用于列表中的x和y。这意味着findud(x)和findud(y)将会被调用，并返回一个包含结果的列表。
####ifelse()函数的扩展写法：
g <- c("M","F","F","I")
ifelse(g=="M", 1, ifelse(g == "F",2,3))
###判断向量相同否？
x <- c(1,3,4)
y = 1:3
x == y
#注，identical()，判断两个对象是否完全一致
x <- 1:2
y <- c(1,2)
x
y
x == y
identical(x,y)
typeof(x)
typeof(y)
###向量元素命名
x <- c(1,2,4)
names(x)
names(x) <- c("a","b","c")
names(x)
x
x["b"]
###去除向量元素名
names(x) <- NULL
x
