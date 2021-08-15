class LRUCache {
    private Map<Integer, Integer> map;
    private int cap;

    public LRUCache(int capacity) {
        map = new LinkedHashMap<>();
        cap = capacity;
    }
    
    public int get(int key) {
        // key不存在，访问不到
        if (!map.containsKey(key)) {
            return-1;
        }

        // key存在，需要将keyPair放到最后
        int val = map.remove(key);
        map.put(key, val);
        return val;
    }
    
    public void put(int key, int value) {
        // key存在，将存在的keyPair放到最后，并更新上新value
        if (map.containsKey(key)) {
            map.remove(key);
            map.put(key, value);
            return;
        }

        // key不存在，直接放到最后
        map.put(key, value);

        // 检查缓存容量，超出上限，则移除第一个
        if (map.size() > cap) {
            // Iterator<Map.Entry<Integer,Integer>> it=map.entrySet().iterator();
            // Map.Entry<Integer,Integer> en=it.next();
            // it.remove();
            map.remove(map.entrySet().iterator().next().getKey());
        }
    }
}

