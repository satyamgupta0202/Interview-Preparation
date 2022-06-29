
class Solution {
public:
      double maxAverageRatio(vector<vector<int>>& classes, int extra) {
       priority_queue<pair<double,pair<int,int>>>pq;
        int n=classes.size();
        //calculating the difference between the previous ration and new ratio
        //here I will increament student and pass student of each class by one and will chaeck where difference is maximum
        //thats why I am using preiority queue so that my max profit will be on top;
        for(int i=0;i<n;i++)
        {
            int pass=classes[i][0];
            int stud=classes[i][1];
            double diff=(double)(pass+1)/(stud+1)-(double)(pass)/(stud);
            pq.push({diff,{pass,stud}});
        }
        //now keep adding one by one new students to the class untill extra will not become zero
        while(extra--)
        {
            auto x=pq.top();
            pq.pop();
            
            int pass=x.second.first;
            int stud=x.second.second;
            pass++;
            stud++;
            //chck your new difference and reassign to the priority queue after popping the previous one
            double newdiff=(double)(pass+1)/(stud+1)-(double)(pass)/(stud);
            pq.push({newdiff,{pass,stud}});
            
        }
        //till here you have successfully assinged the student in optimal class
        //just take the avarage and this is your ans;
        double ans=0.0;
         while(!pq.empty())
         {
             auto x=pq.top();
             pq.pop();
             ans+=(double)(x.second.first)/(x.second.second);
         }
        return ans/n;
    }
};