/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function(cardPoints, k) {
    let prefixSum = [];
    let suffixSum = [...cardPoints];
    prefixSum.push(cardPoints[0]);
    for(let x = 1; x<cardPoints.length; x++) prefixSum.push(prefixSum[x-1] + cardPoints[x]);
    prefixSum.unshift(0);
    suffixSum[cardPoints.length-1] = cardPoints[cardPoints.length-1];
    for(let x = cardPoints.length-2; x>=0; x--){
        suffixSum[x] = suffixSum[x+1] + cardPoints[x];
    }
    suffixSum.push(0);
    for(let x = 0; x<prefixSum.length; x++)console.log(prefixSum[x]);
    console.log("-----------------------");
    for(let x = 0; x<suffixSum.length; x++)console.log(suffixSum[x]);
    console.log("-----------------------");

    let ret = 0;
    for(let x = 0; x<=k; x++){
        ret = Math.max(prefixSum[k-x] + suffixSum[suffixSum.length-1-x] ,ret);
    }
    return ret;
    
    return ret;
};