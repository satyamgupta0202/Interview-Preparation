class Solution {
    int MOD = (int)1e9 + 7;
    
    public int maxArea(int h, int w, int[] hc, int[] vc) {
        int n = hc.length , m = vc.length;
        
        int []hc1 = new int[n + 2] , vc1 = new int[m + 2];
        
        hc1[0] = vc1[0] = 0; hc1[n + 1] = h; vc1[m + 1] = w ;
        
        for(int i = 0 ; i < n ; i++){
            hc1[i + 1] = hc[i];
        }
        
        for(int i = 0; i < m ; i++){
            vc1[i + 1] = vc[i];
        }
        
        Arrays.sort(hc1) ; Arrays.sort(vc1);
        // System.out.println(Arrays.toString(hc1)  + " " + Arrays.toString(vc1));
        int max1 = -1 , max2 = -1;
        
        for(int i = 0 ; i < hc1.length - 1 ; i++){
            max1 = Math.max(max1 , hc1[i + 1] - hc1[i]);
        }
        
        for(int i = 0 ; i < vc1.length - 1 ; i++){
            max2 = Math.max(max2 , vc1[i + 1] - vc1[i]);
        }
        
        return (int)(((long)(max1%MOD)*(max2%MOD))%(long)MOD);
    }
}