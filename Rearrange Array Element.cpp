


So if this question has been asked to you then it means you will most likely to get followed question as what if the order doesn't matter.
Means you just have to put positive and negative in alternative order.
Ex: [4, -2, -5, 9]
So your answer could be [4, -5, 9, 2] since order doesn't matter.

So first let's focus on the question where order matters.

No. of positives = No. of negatives
So if I start first from positive if will end at negative. 
or Either I can start first from negative.
We will follow first one , which is starting from positive.
So next positive would be after 2 index and so on in the gap of 2.
Our negative would start from 1 and would step up by 2 each time.
image.png

Since we have fixed index for positive and negative. I can fetch the positives and negatives in an array and then one by one put into result array.

Ex: [3,1,-2,-5,2,-4]
Pos: [3, 1, 2]
Neg: [-2, -5, -4]

Now put all positives at even place
result: [3, _, 1, _, 2, _] ( here _ means we have not inserted)
Now put all negatives at odd place
result: [3, -2, 1, -5, 2, -4]

So we can see that now positive are all at even index and negatives
are all at odd index in their original order.
You : Are we good with this approach ?
Interviewer: Let's discuss time and space complexity, then we can go ahead.
You : Space Compelxity would be O(n) to store positives and negatives. and Time Complexity would also be O(n) we will traverse each element twice. Once for filling in positives and negatives list and second time for inserting into result array at their specified position.
Interviewer : Cool ! Then write code for it.

*Le Keyboard: (TAPA, TAP, TAPA, TAP ... )

class Solution {
    public int[] rearrangeArray(int[] nums) {
        List<Integer> pos = new ArrayList();
        List<Integer> neg = new ArrayList();
        
        for(int x: nums) {
            if(x >= 0) pos.add(x);
            else neg.add(x);
        }

        for(int i=0;i<nums.length;i++) {
            if(i%2 == 0) {
                nums[i] = pos.get(i/2);
            } else {
                nums[i] = neg.get(i/2);
            }
        }

        return nums;
    }
}
Interviewer : Here you have used two iteration, can you do it in one iterations ?
You : Okay, let me think. and What about space ?
Interviewer: Space can be O(n) and if you can optimise the space as well then go ahead.
You : Ok, I think since we need to preserve order It would not be possible to done it in-place. So I will use one array of size n. Since I know if the element is even it's position would be 0 for the first time and next time += 2 and so on.

So I will use two pointer for even and odd which will be at the position where I can insert even and odd element.

Interviewer : Okay, write code for it.
You : Sure.

*Le Keyboard: (TAPA, TAP, TAPA, TAP ... )

Code
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int pos = 0, neg = 1;
        for(int i=0;i<n;i++) {
            if(nums[i] >= 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
}
Here time complexity would be O(n) because in question we have been 
asked to modify the input array itself. If we were asked not to modify
it we would be having our time complexity as O(1).
Interviewer : We have some time left, I have one follow up question on this what if the order doesn't matter , can you do that in-place ?
You : Ok, Let me think.

As we know that order doesn't matter and also we have equal no. of positive and negatives.
So what if positive is not at the correct index, we can get negative and swap it. same for the negative if it is not at correct index , we can get positive and swap.

image.png

Interviewer : Ok, what about time and space complexity here ?
You: As we are swapping the element in existing array itself, we don't need any extra space so space complexity would be O(1).
and Time Complexity would be O(n) because we will traverse n elements once.
Interviewer : You can write code for this.
You : Sure !

class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int pos = 0, neg = 1;
        while(pos < n && neg < n) {
            if(nums[pos] >= 0) pos += 2;
            else if(nums[neg] < 0) neg += 2;
            else {
                int temp = nums[pos];
                nums[pos] = nums[neg];
                nums[neg] = temp;
            }
        }
        return nums;
    }
}
Interviewer : I am done with my side, if you have any questions let me know.
You : No. ( FO )

There is one more version to this question, where instead of 
positive and negatives we have even and odd. So the concept 
would remain same just some condition will change.
Thanks All !!!
