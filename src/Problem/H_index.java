class Solution {
    public int hIndex(int[] citations) {
        // 개수와 크기로 나눈다.
        // 크기 <= 개수 인 최대 크기를 찾아야한다.
        
        int num = 0; // 개수
        int citationsLength = citations.length;
        int citation = 0; // 크기 : citations중 최대의 숫자로 디폴트 값 정함.
        
        // citations중 최대의 숫자 알아내기
        for (int i = 0; i < citationsLength; i++){
            if(citation < citations[i]){
                citation = citations[i];
            }
        }
        
        // 크기 <= 개수 알아내기.
        for(; citation >= 0; citation--){
            num = 0;
            for (int i = 0; i < citationsLength; i++){
                if(citation <= citations[i]){
                    num++;
                }
            }
            if(citation <= num){
                break;
            }
        }
        return citation;
    }
}