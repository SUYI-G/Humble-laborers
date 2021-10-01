class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        # 定义一个无限大的数
        res = float("inf")
        Sum = 0
        index = 0
        for i in range(len(nums)):
            Sum += nums[i]
            while Sum >= s:
                res = min(res, i-index+1)
                Sum -= nums[index]
                index += 1
        if res==float("inf"):
          return 0
        else: 
          return res
