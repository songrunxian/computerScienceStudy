###列表
####R语言中的列表就是C中的struct,不过也要按照向量的思维去思考
####创建列表
j <- list(name="joe", salary=55000, union = T)
j
j$name
j$salary
j$union
j1 <- list("joe", 55000, T)
j1     #j1因为没有tag所以不能使用$模式
z <- vector(mode = "list")   #按照向量的思维去思考列表
z[["abc"]] <- 3
z[["df"]] <- 5
z
####列表索引
j$salary
j[["salary"]]
j[[2]]   
j[1:2]
j2 <- j[2]   #这种结果的本质j2还是一个list
j2
class(j2)
str(j2)
j2a <- j[[2]]  #这种方式是提取组件本身，返回的是组件本身的类型
class(j2a)
####增加删除列表元素
#通过标签添加
z <- list(a="abc", b=12)
z$c <- "haah"
#通过索引添加
z[[4]] <- "kalami"
z[5:7] <- c("FALSE","TRUE","TRUE")
#删除元素就是把这个数值设置成NULL
z$b <- NULL
#多个列表拼接
z1 <- c(list("joe",55000,T), list(5))
#从数组的角度思考，获取列表长度
length(z1)
#4.2.4 使用R语言的列表确定文本词汇的索引
#wl[[wrd]] 表示列表 wl 中名为 wrd 的元素，这个元素是一个向量，保存了单词 wrd 在文本中出现的所有位置。c(wl[[wrd]],i) 表示将新的位置 i 添加到该向量中，并将更新后的向量赋值给 wl[[wrd]]。
#这样，当函数遍历完整个文本后，wl 列表中的每个元素都是一个单词及其在文本中出现的所有位置。
findwords <- function(tf) {
  txt <- scan(tf," ")
  wl <- list(txt)
  for (i in 1:length(txt)) {  #遍历 txt 向量中的每个单词
    wrd <- txt[i]
    wl[[wrd]] <- c(wl[[wrd]],i)
  }
  return(wl)
}
####访问元素和值
j <- list(name="joe", salary=55000, union = T)
names(j)  #获取list名
unlist(j) #获取list值
class(unlist(j))
j1 <- list(1,2,3)
unlist(j1)
class(unlist(j1))
j2 <- list("hhhh",1)
unlist(j2)
class(unlist(j2))
####去list名
j <- list(name="joe", salary=55000, union = T)
names(j) <- NULL
class(j)
j <- list(name="joe", salary=55000, union = T)
unname(j)
class(j)
####lapply【list apply】和sapply【simplified lapply 简化了的lapply()】
class(lapply(list(1:3,25:29), median))
class(sapply(list(1:3,25:29), median))
####单词按照字母排序4.4.2
alphawl <- function(wrdlist){
  nms <- names(wrdlist)
  sn <- sort(nms)
  return(wrdlist[sn])
}
####按照词频排序4.4.2
freqwl <- function(wrdlist) {
  freqs <- sapply(wrdlist, length)
  return(wrdlist[order(freqs)])
}
####根据词频绘图
nyt <- findwords("nyt.txt")
snyt <- freqwl(nyt)
nwords <- length(ssnyt)
freqwl <- sapply(ssnyt[round(0.9*nwords):nwords], length) #这里绘制就是出现频率排名占前10%的单词画在图中
barplot(freqwl)
####列表的组件也可能是列表
b <- list(u=5,v=12)
c <- list(w=13)
a <- list(b,c)
a
#c()这个拼接函数，有一个可选参数recursive，其作用是把原列表压扁
newlist <- c(list(a=1,b=2,c=list(d=5,e=9)))
class(newlist)
newlist <- c(list(a=1,b=2,c=list(d=5,e=9)), recursive=T)
newlist
class(newlist)
