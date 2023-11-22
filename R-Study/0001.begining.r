#R入门：
mean(abs(rnorm(100)))
rnorm(100) #生成服从N（0，1）分布的随机向量，这是一个标准正太分布，均值是0，方差是1；方差表示了数据的离散程度,标准差是方差的平方根

pdf("1.1.pdf")  #创建一个pdf
hist(rnorm(100))
dev.off()

x <- c(1,2,4)
q <- c(x,x,9)
x
q
x[3]
q[3]
q[4]
x[2:3]
mean(x)
sd(x)

data() #这是R里面内置的数据集
mean(Nile)
sd(Nile)
hist(Nile)

###函数练习
oddcount <- function(x) {
  k <- 0
  for (n in x) {
    if(n %% 2 == 1) k <- k+1 # %%取余
  }
  return(k)
}
oddcount(c(1,3,5))
oddcount(c(1,2,3,5,7,8,9))
###向量
x <- c(5,12,13)
length(x)
mode(x)
x <- "abc"
length(x)
mode(x)
x <- c("abc", "29 89")
length(x)
mode(x)
u <- paste("abc", "de", "f")
u
v <- strsplit(u, " ")
v
###矩阵，这是一行一行
m <- rbind(c(1,4), c(2,2))
m
m %*% c(1,1) #矩阵乘法
###列表
x <- list(u=2,v="abc")
x
x$u
x$v
hn <- hist(Nile)
hn #hn的本质是一个列表，里面存储了描述直方图的若干直方图特征
str(hn) #一种简洁的表达
###数据框，list是一列一列
d <- data.frame(list(kids=c("Jack","Jill"),ages=c(12,10)))
d
d$ages
###类
#类要用在泛型函数中

###获取帮助
help("seq") #获取seq()函数信息
?seq
?"<"
?"for"
example(seq)
example("persp")
help.search("multivariate normal") #多元正太分布

###其它
getwd()
setwd("path") #修改工作目录
