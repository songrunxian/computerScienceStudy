#数据框，和矩阵不同，矩阵每一类的类型相同，数据框可以不同
##创建
kids <- c("Jack","Jill")
ages <- c(12,10)
d <- data.frame(kids,ages,stringsAsFactors = FALSE) #让字符向量为非因子
##访问数据框的三种方式
d[[1]]
d[,1]
d$kids
Exam.1 <- c(2,3.3,4,2.3,2.3,3.3)
Exam.2 <- c(3.3,2,4,0,1,3.7)
Quiz <- c(4,3.7,4,3.3,3.3,4)
d <- data.frame(Exam.1,Exam.2,Quiz)
head(d) # head函数是一个在R语言中比较常用的函数,用于查看数据框或向量的前几行数据
str(d) #str()经常用来解析结果
##提取子数据框
d[2:5,]
d[2:5,2]
class(d[2:5,2])
class(d[2:5,2,drop = FALSE])
d[d$Exam.2 > 1 , ]
##处理NA
x <- c(2,NA,4)
mean(x)
mean(x,na.rm = TRUE)
subset(d,d$Exam.1 > 1)
subset(d,Exam.1 > 1)
##complete.case()和subset()类似，可以让我们更方便的去除NA
kids <- c("hack",NA,"jillian","john")
states <- c("CA","MA","MA",NA)
d4 <- data.frame(kids,states)
d5 <- d4[complete.cases(d4),]
##rbind()添加行,cbind()添加列
c1 <- c("jack","jill")
c2 <- c(12,19)
d <- data.frame(c1,c2)
rbind(d,list("Laura",19))
cbind(d,d$c2+1)
d$newcol <- d$c2+1
d
class(apply(d, 2, max))
##合并数据框
kids <- c("jack","jill","jillian","john")
stats <- c("CA","MA","MA","HI")
t1 <- data.frame(kids, stats)

ages <- c(10,7,12)
kids <- c("jill","jillian","john")
t2 <- data.frame(ages,kids)

d <- merge(t1,t2)

ages <- c(12,10,7)
pals <- c("jack","jill","lillian")
t3 <- data.frame(ages, pals)
merge(t1,t3, by.x = "kids", by.y = "pals")
