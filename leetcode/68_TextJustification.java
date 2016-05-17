import java.util.ArrayList;
import java.util.List;


public class TextJustification_68 {
      public List<String> fullJustify(String[] words, int maxWidth) {
        
        int total = words.length;
        List<String> ans = new ArrayList<String>();
        int left = 0;
        if(maxWidth==0) {
            while(left<total){
               ans.add("");
               left++;
            }
            return ans;
        }
        while(left<total){
            
            int curLen = 0;
            int right = left;
            while(right<total) {
                int addLen =words[right].length();
                if(right>left){
                    addLen+=1;
                }
                if(curLen+addLen>maxWidth) {
                    break;
                }
                curLen +=addLen;
                right ++;
            }
            
            int num = right-left;
            if(num==0){
                ans.add(words[left]);
                left++;
                continue;
            }
            
            int leftLength = maxWidth-curLen;
            int each = leftLength;
            int modLeft=0;
            if(num>1){
               each=leftLength/(num-1)+1;
               modLeft = leftLength%(num-1);
               if(right>=total){
                    each=1;
                    modLeft=0;
               }
            }
            StringBuffer sb = new StringBuffer();
            StringBuffer eachSlots = new StringBuffer();
            System.out.println("each:"+each+" num:"+num+" maxWidth:"+maxWidth+" curlen:"+curLen);
            
            for(int id=0;id<each;id++){
                eachSlots.append(" ");
            }
            
            while(left<right){
                sb.append(words[left]);
                left++;
                if(num>1&&left>=right){
                    break;
                }
                sb.append(eachSlots.toString());
                if(modLeft>0) {
                    sb.append(" ");
                    modLeft--;
                }
                
            }
            while(sb.length()<maxWidth){
                sb.append(" ");
            }
            ans.add(sb.toString());
        }
        return ans ;
            
      }
      
      public static void main(String []args){
//        String []words = {""};
//        //String []words = {"a"};
//        //String []words={"This", "is", "an", "example", "of", "text", "justification."};
//        TextJustification_68 sl = new TextJustification_68();
//        List<String> ans = sl.fullJustify(words, 10);
//        for(int id=0;id<ans.size();id++){
//            System.out.printf("%2d:'%s'\n",id,ans.get(id));
//        }
//        
         
//        String []words = {"a","ccc"};
//        //String []words={"This", "is", "an", "example", "of", "text", "justification."};
//        TextJustification_68 sl = new TextJustification_68();
//        List<String> ans = sl.fullJustify(words, 5);
//        for(int id=0;id<ans.size();id++){
//            System.out.printf("%2d:'%s'\n",id,ans.get(id));
//        }
          
        
          String []words={"This", "is", "an", "example", "of", "text", "justification."};
          TextJustification_68 sl = new TextJustification_68();
          List<String> ans = sl.fullJustify(words, 16);
          for(int id=0;id<ans.size();id++){
              System.out.printf("%2d:'%s'\n",id,ans.get(id));
          }
//        
//        String []words = {"What","must","be","shall","be."};
//        //String []words = {"a"};
//        //String []words={"This", "is", "an", "example", "of", "text", "justification."};
//        TextJustification_68 sl = new TextJustification_68();
//        List<String> ans = sl.fullJustify(words, 12);
//        for(int id=0;id<ans.size();id++){
//            System.out.printf("%2d:'%s'\n",id,ans.get(id));
//        }
//        
      }
      
     
}

