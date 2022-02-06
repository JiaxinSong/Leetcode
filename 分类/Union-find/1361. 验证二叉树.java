class Solution {
	class Union {

		public int n;
		public int[] root;
		public int[] sizes;
		public int[] parent;
		public int rootSize;

		public Union(int n) {
			this.n = n;
			this.rootSize = n;
			this.root = new int[n];
			this.sizes = new int[n];
			this.parent = new int[n];
			for (int i = 0; i < n; i++) {
				root[i] = i;
				sizes[i] = 1;
				parent[i] = -1;
			}
		}

		public int findRoot(int num) {
            if(root[num]==num) return num;
            else{
                this.root[num]=findRoot(this.root[num]);
                return this.root[num];
            }
		}

		public boolean union(int num1, int num2) {
			if (this.parent[num2] != -1 || this.parent[num1] == num2) {   // nums有父节点   或  成环 false
				return false;
			}
			this.parent[num2] = num1;
			int p1 = this.findRoot(num1);
			int p2 = this.findRoot(num2);
            if(p1==p2) return false;                                       //已经在同一集合中 return false

			if (p1 != p2) {
				int size1 = this.sizes[p1];
				int size2 = this.sizes[p2];
				if (size1 < size2) {
					this.root[p1] = p2;
					this.sizes[p2] += size1;
					// this.sizes[p1] = 0;
				} else {
					this.root[p2] = p1;
					this.sizes[p1] += size2;
					// this.sizes[p2] = 0;
				}
				this.rootSize--;
			}
			return true;
		}

	}

	public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
		Union union = new Union(n);
		for (int i = 0; i < n; i++) {
			int left = leftChild[i];
			if (left != -1 && !union.union(i, left)) {
				return false;
			}
			int right = rightChild[i];
			if (right != -1 && !union.union(i, right)) {
				return false;
			}
		}
		return union.rootSize == 1;// 必须有一个根
	}
}
