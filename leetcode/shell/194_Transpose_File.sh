# Solution for https://leetcode.com/problems/transpose-file/
#
awk -F" " '{h=NF;w=NR;for(i=1;i<=NF;i++)key[i,NR]=$i;}END{for(i=1;i<=h;i++){printf("%s",key[i,1]);for(j=2;j<=w;j++){printf(" %s",key[i,j]);}printf("\n");}}' file.txt 

