/**
 * @param {string} n
 * @return {number}
 */
var minPartitions = function(n) {
    let mx = '0';
    for(let x = 0; x<n.length; x++){
        mx = Math.max(n[x] , mx);
    }
    return mx-'0';
};