/**
 * @param {number[]} nums
 * @return {boolean}
 */

let v;
let solve = function(index){
    if(index == 0 || index == v.length)return true;
    v[index] = v[index-1];
     for(let x = 1; x<v.length; x++){
        if(v[x] >= v[x-1])continue;
        else return false;
    }
    return true;
}

var checkPossibility = function(nums) {    
    let idx = 0 , cnt = 0;
    v = [...nums];
    for(let x = 1; x<nums.length; x++){
        if(nums[x] < nums[x-1])idx = x, cnt ++;            
    }
    
    if(cnt > 1)return false;
    let path1 = solve(idx);
    v[idx] = nums[idx];
    let path2 = solve(idx-1);
    v[idx-1] = nums[idx-1];
    return path1 || path2;
};