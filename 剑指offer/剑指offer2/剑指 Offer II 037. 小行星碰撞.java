class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stk = new Stack<>();
        for (int i:asteroids) {                 //如果遇到 正行星，直接入栈
            if(i>0){
                stk.push(i);
            }

            else if (i<0){                      //如果遇到负行星；
                while(!stk.isEmpty()&&((0<stk.peek())&&(stk.peek()<-i))){
                    stk.pop();                 //首先将前面所有比它小的正行星撞碎
                }
                //运行到这里，说明只有三种情况，（1）空了；（2）栈里没有正的；（3）遇到某个大于等于的正行星相撞了
                if (stk.isEmpty())           //（1）栈空了，则直接把这个负行星入栈
                    stk.push(i);            

                else {
                    if(stk.peek()<0){stk.push(i);}    //（2）栈里没有正的,把这个负的放进去 //只要栈顶是负的，就说明这个栈里面
                    else {                            //（3）遇到某个大于等于的正行星相撞了
                        {
                            if(stk.peek()>-i){} //大于；什么都不做，相当于把当前的这颗负行星撞毁了；
                            else {stk.pop();}   //等于；则把栈顶的这颗正行星弹出，相当于两颗行星同归于尽；
                        }
                    }
                }
            }   
        }                                           //关键代码结束；
        int size = stk.size();                      //将栈内保存的行星转换为数组传回；
        int[] col = new int[size]; 

        for (int i = 0; i < size; i++) {
            col[size-i-1] =  stk.pop();
        }

        return col;
    }
}
