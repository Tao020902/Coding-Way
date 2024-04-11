# include <iostream>
# include <vector>
# include <algorithm>
using namespace  std;
// 他的时间复杂度为O(n^2)
//int findinglengthList(vector<long long>numbers){
//    long long find_result = 0;
//    if(numbers.size() == 1) return 1;
//    vector<long long>dp(numbers.size(),1); // 表示以i结尾的最长接龙数列
//    for(int i = 0; i < dp.size(); i++){
//        for(int j = 0; j < i; j++){
//            long long numberend = numbers[j] % 10;
//            long long numberbegin = numbers[i];
//            while(numberbegin >= 10){
//                numberbegin /= 10;
//            }
//            // cout<<numberbegin<<" "<<numberend<<endl;
//            if(numberbegin == numberend){
//                dp[i] = max(dp[j] + 1, dp[i]);
//                find_result = max(find_result, dp[i]);
//            }
//        }
//    }
//    for(int i = 0; i < dp.size(); i++){
//        cout<<dp[i]<<" ";
//    }
//    return find_result;
//};
//int main(){
//    int number;
//    cin>>number;
//    vector<long long>numbers(number,1);
//    for(int i = 0; i < number; i++){
//        cin>>numbers[i];
//
//    }
//    cout<<number - findinglengthList(numbers);
//};
// 让我们来进行优化吧
int main(){
    int number; long long numbers;
    cin>>number;
    vector<long long>dp(10,0);
    for(int i = 0; i < number; i++){
        cin>>numbers;
        long long numberend = numbers % 10;
        long long numberbegin = numbers;
        while(numberbegin >= 10){
            numberbegin /= 10;
        }
        dp[numberend] = max(dp[numberend], dp[numberbegin] + 1);
    }
    cout<<number - *max_element(dp.begin(),dp.end());
    return 0;
}
