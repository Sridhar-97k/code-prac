class Solution {

    public int bulbSwitch(int n) {
        
        int bulbs[]=new int[n];
        int bulbs_turned_on=0;
        int i,round=0;   
        for(round=1;round<=n;round++)
        {
            for(i=(round-1);i<n;i+=round)
            {
               bulbs[i]=(bulbs[i]==0)?1:0;
            }
        }
       for(i=0;i<n;i++)
        {
          
            if(bulbs[i]==1)
                bulbs_turned_on++;
        }
        return bulbs_turned_on;
    }
}