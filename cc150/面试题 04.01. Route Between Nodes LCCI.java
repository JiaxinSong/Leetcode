        class AnimalShelf {
            LinkedList<Integer> dog = new LinkedList<>();
            LinkedList<Integer> cat = new LinkedList<>();
            public AnimalShelf() {
            }
            public void enqueue(int[] animal) {
                if (animal[1] == 0) {
                    cat.add(animal[0]);
                }
                if (animal[1] == 1) dog.add(animal[0]);
            }

            public int[] dequeueAny() {
                if (dog.isEmpty() && cat.isEmpty()) return new int[]{-1, -1};
                if (dog.isEmpty()) return new int[]{cat.pollFirst(), 0};
                if (cat.isEmpty()) return new int[]{dog.pollFirst(), 1};
                if (dog.peekFirst() < cat.peekFirst()) return new int[]{dog.pollFirst(), 1};
                return new int[]{cat.pollFirst(), 0};
            }

            public int[] dequeueDog() {
                if (dog.isEmpty()) return new int[]{-1, -1};
                return new int[]{dog.pollFirst(), 1};
            }

            public int[] dequeueCat() {
                if (cat.isEmpty()) return new int[]{-1, -1};
                return new int[]{cat.pollFirst(), 0};
            }
        }


/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf obj = new AnimalShelf();
 * obj.enqueue(animal);
 * int[] param_2 = obj.dequeueAny();
 * int[] param_3 = obj.dequeueDog();
 * int[] param_4 = obj.dequeueCat();
 */
