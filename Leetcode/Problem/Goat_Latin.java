class Solution {
    public String toGoatLatin(String S) {
        // 1. 빈칸 개수를 찾는다. => 빈칸 개수에 따라서 maaa 
        // 2. 자음으로 시작하는 지, 모음으로 시작하는 지 판별
        // 2-1. 자음으로 시작하면 없애고 맨 뒤에 붙이기
        
        String[] stringArray = S.split(" ");
        int countSpace = 0;
        
        for(int i = 0; i < S.length(); i++){
            if(S.charAt(i) == ' '){
                countSpace++;
            }
        }
        //System.out.print(countSpace);
        
        for(int i = 0; i < countSpace + 1; i++){ 
                switch(stringArray[i].charAt(0)){
                case 'a': case 'A': case 'e': case 'E': case 'i': case 'I': case 'o':
                case 'O': case 'u': case 'U':
                    break;
                        
                default:
                    
                    int charNumber = stringArray[i].length();
                    
                    stringArray[i] = stringArray[i] 
                                    + stringArray[i].charAt(0);
                        
                    stringArray[i] = stringArray[i].substring(1);    
                    break;
            }
            
            stringArray[i] += "ma";
            for(int j = 0; j <= i; j++){
                stringArray[i] += "a";
            }
            
            if(i != 0){
                stringArray[0] = stringArray[0].concat(" " + stringArray[i]);
            }
        }
        //System.out.print(stringArray[1]);
        
        return  stringArray[0];  
    }
}