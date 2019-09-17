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
	
	public String convert(String s, int numRows) {
        int length=s.length();
     StringBuilder sb=new StringBuilder(s);
        char array[][]=new char[numRows][length];
        int i=0,j=1,k=0,b,col=0;
        boolean zigzag=false;
        StringBuilder result_sb=new StringBuilder();    
        while(k<length)
        {
                if(zigzag)
        { 
                for(;(i>=0)&&(k<length);i--,j++)
                    {
                       array[i][j]=sb.charAt(k++);
                    }
                    zigzag=false;
        }
            else{
                    for(i=0;(i<numRows)&&(k<length);i++)
                    {
                       array[i][j]=sb.charAt(k++);
                    }
                    zigzag=true;
                    i-=2;
            
            }
        
        }
        
    
        
        
        
        
    }
	
	
	
public static void main(String args[])
{
	int n = 100,i=0;
	Solution s =new Solution();
	for(i=0;i<n;i++)	
	{
		System.out.println(i+","+s.bulbSwitch(i));
	}
	
}


}

