class Solution {
    public int trap(int[] height) {
        // 从最高的那个柱子开始一行一行的往下算，计算每一行的water值。
        // 每一行的water值等于，最右边的index - 最左边的index - 这一行的实体块个数 + 1
        int water = 0;
        // 高度最高的柱子的索引
        int max = 0;
        ArrayList<Integer> heights = new ArrayList<Integer>();
        // 用 map 来记录，key 是高度为 h 的柱子， value 是所有柱子索引的数组。
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
        for(int i = 0; i < height.length; i++) {
            int h = height[i];
            if (h > max) 
            	max = h;
            if (map.containsKey(h)) {
                map.get(h).add(i);
            } else {
                heights.add(h);
                ArrayList<Integer> indexes = new ArrayList<Integer>();
                indexes.add(i);
                map.put(h, indexes);
            }
        }

        // 降序排列
        Collections.sort(heights, Collections.reverseOrder());
        
        // 从最高往下找，将所有找过的柱子的索引加入到 set 当中，在遍历到底下的行时，就不用数了。
        Set<Integer> indexSet = new HashSet<Integer>();
        // 遍历heights的指针
        int point = 0;

        while (max > 0) {
        	while (point < heights.size() && heights.get(point) >= max) {
        		ArrayList<Integer> is = map.get(heights.get(point));
                indexSet.addAll(is);
        		point++;
        	}

            ArrayList<Integer> total = new ArrayList<Integer>(indexSet);
            Collections.sort(total);
            if (total.size() > 1) {
                int w = total.get(total.size()-1) - total.get(0) - 1 - total.size() + 2;
                water += w;
            }
            
            max--;
        }
        return water;
    }
}