class StackOfPlates {

    private LinkedList<LinkedList<Integer>> setOfStacks;
    private int cap;

    public StackOfPlates(int cap) {
        this.setOfStacks = new LinkedList<>();
        this.cap = cap;
    }

    private boolean setIsEmpty() {
        return setOfStacks.isEmpty();
    }

    private boolean lastStackIsFUll() {
        if (setIsEmpty()) {
            return true;
        }
        return setOfStacks.getLast().size()==cap;
    }

    private boolean lastStackIsEmpty() {
        return setOfStacks.getLast().isEmpty();
    }

    public void push(int val) {
        if (cap <= 0) {
            return;
        }
        if (setIsEmpty() || lastStackIsFUll()) {
            setOfStacks.add(new LinkedList<>());
        }
        setOfStacks.getLast().add(val);
    }

    public int pop() {
        int val = -1;
        if (setIsEmpty()) {
            return val;
        }
        val = setOfStacks.getLast().removeLast();
        if (lastStackIsEmpty()) {
            setOfStacks.removeLast();
        }
        return val;
    }

    public int popAt(int index) {
        int val = -1;
        if (setIsEmpty() ||setOfStacks.size()-1<index ) {
            return val;
        }
        val = setOfStacks.get(index).removeLast();
        if (setOfStacks.get(index).isEmpty()) {
            setOfStacks.remove(index);
        }
        return val;
    }
}



/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates obj = new StackOfPlates(cap);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAt(index);
 */
