public class ValidNumber {
    public boolean isNumber(String s) {
        s = s.trim();
        if (s.length() == 0) {
            return false;
        }
        int pos = s.indexOf('e');
        if(pos == -1) {
            pos = s.indexOf('E');
        }
        if (pos == -1) {
            return this.isFloat(s);
        }
        if (!this.isFloat(s.substring(0, pos))) {
            return false;
        }

        if (pos == s.length() - 1||pos==0) {
            return false;
        }
        return this.isInteger(s.substring(pos + 1));
    }

    public boolean isFloat(String s) {
        if (s.length() == 0) {
            return false;
        }
        int pos = s.indexOf('.');
        //System.out.println(s+" index of . "+pos);
        
        
        if (pos == -1) {
            return this.isInteger(s);
        }
        if (pos == s.length() - 1 ) {
            return this.isInteger(s.substring(0,pos));
        }
        if(pos==0) {
            //. or .+11
            if(s.length()==1||s.charAt(1)=='-'||s.charAt(1)=='+') {
                return false;
            }
            return this.isInteger(s.substring(1));
        }
        // 11.+11
        char fr = s.charAt(pos + 1);
        if (fr == '+' || fr == '-') {
            return false;
        }
        String left = s.substring(0, pos );
        String right = s.substring(pos + 1);
        boolean ret = this.isInteger(left);
        if(left.equals("+")||left.equals("-")) {
            ret = true;
        }
         ret &= this.isInteger(right);
        //System.out.println("left:"+left+" right:"+right+" "+ ret);
        return ret;
    }

    public boolean isInteger(String s) {
        if (s.indexOf('.') != -1) {
            return false;
        }
        if (s.length() == 0) {
            return false;
        }
        int id = 0;
        if (s.charAt(id) == '+' || s.charAt(id) == '-') {
            id++;
        }
        if(id==s.length()) {
            return false;
        }
        for (; id < s.length(); id++) {
            if (s.charAt(id) > '9' || s.charAt(id) < '0') {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] arg) {
        ValidNumber s = new ValidNumber();
//      String []test={"111.","+11.23","-111","0"," 0.1","abc","1 a",
//              "2e10","-2e-20","-2e+20","-2.1e+20","-2.1e+20.1",
//              "-2.1e+20.0",".1",
//              "20.0","3.","4e+"};
        String[] test = { "4e+",".-4","+.8e5" };
        for (int id = 0; id < test.length; id++) {
            System.out.println(test[id] + " " + s.isNumber(test[id]));
        }
    }

    public void print(String[] s) {
        // System.out.println(s.length);
        for (int id = 0; id < s.length; id++) {
            System.out.println(s[id]);
        }
        System.out.println("----");
    }
}

