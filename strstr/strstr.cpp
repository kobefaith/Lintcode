class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        int i=0;
        int j=0;
        int lens=0;
        int lent=0;
        if(source == NULL || target == NULL)
            return -1;
        while(source[lens]!='\0')
             lens++;
        while(target[lent]!='\0')
             lent++;
        if(lens<lent)
            return -1;
        while(i<=(lens-lent)){
            for(j=0;j<lent;j++){
                if(source[i+j] != target[j])
                    break;
            }
            if(j==lent)
               return i;
            else{
                i++;
                j=0;
            }
        }
        return -1;
    }
};
