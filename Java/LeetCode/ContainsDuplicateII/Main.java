import java.util.HashMap;
class Main {
    public static void main(String[] args) {
        System.out.println("Hello, world!");
        int[] testNumbers = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
        System.out.println(containsNearbyDuplicate(testNumbers, 5));
    }
    public static boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> lastIndex = new HashMap<>();
        for(int i=0; i<nums.length; i++)
        {
            if(lastIndex.containsKey(new Integer(nums[i])))
            {
                if(i-((Integer)lastIndex.get(new Integer(nums[i]))).intValue() <= k)
                    return true;
            }
            lastIndex.put(new Integer(nums[i]), new Integer(i));
        }
        return false;
    }
}