## [文本翻译](https://leetcode.com/problems/transpose-file/)


Given a text file file.txt, transpose its content.

You may assume that each row has the same number of columns and each field is separated by the ' ' character.

For example, if file.txt has the following content:

```
name age
alice 21
ryan 30
```

Output the following:

```
name alice ryan
age 21 30
```

Subscribe to see which companies asked this question

### Answer

```
#Solution for https://leetcode.com/problems/transpose-file/
awk -F" " '{h=NF;w=NR;for(i=1;i<=NF;i++)key[i,NR]=$i;}END{for(i=1;i<=h;i++){printf("%s",key[i,1]);for(j=2;j<=w;j++){printf(" %s",key[i,j]);}printf("\n");}}' file.txt 
```
