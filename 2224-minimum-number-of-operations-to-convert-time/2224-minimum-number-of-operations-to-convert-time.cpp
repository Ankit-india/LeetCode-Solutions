class Solution {
public:
    int sti(string str)
    {
        int temp = 0;
        for (int i = 0; i < str.length(); i++) {
            temp = temp * 10 + (str[i] - '0');
        }
        return temp;
    }
    
    int convertTime(string current, string correct) {
        
        vector<int>op;
        op.push_back(1);
        op.push_back(5);
        op.push_back(15);
        op.push_back(60);
        string cub="",cua="";
        int flag=0;
        for(int i=0;i<current.length();i++){
            
            if(current[i] == ':'){
                flag=1;
            }
            else if(flag!=1){
                cub+=current[i];
            }
            else{
                cua+=current[i];
            }
        }
        
        // cout<<"hello2"<<endl;
        int curb=sti(cub);
        int cura=sti(cua);
        // cout<<"curb"<<curb<<endl;
        // cout<<"cura"<<cura<<endl;
        
        string cob="",coa="";
        int flag2=0;
        for(int i=0;i<correct.length();i++){
            
            if(correct[i] == ':'){
                flag2=1;
            }
            else if(flag2 == 0){
                cob+=correct[i];
            }
            else if(flag2==1){
                coa+=correct[i];
            }
        }
        // cout<<"coa"<<coa<<endl;
        // cout<<"cob"<<cob<<endl;
        // cout<<"hello"<<endl;
        int corb=sti(cob);
        int cora=sti(coa);
        // cout<<corb<<endl;
        // cout<<cora<<endl;
        
        int db=corb-curb; // hours
        int da=cora-cura; // minutes 
        // cout<<"da"<<da<<endl;
        db = db * 60; 
        if(da < 0){
            db=db+da;
        }
        else{
            db+=da;
        }
        cout<<"db"<<db<<endl;
        int cnt=0;
        while(db > 0){
            // cout<<"db"<<db<<endl;
            cnt++;
            cout << "ankit" << endl;
            int k=upper_bound(op.begin(),op.end(),db)-op.begin();
            int s=op[k-1];
            db=db-s;
        }
        return cnt;
    }
};