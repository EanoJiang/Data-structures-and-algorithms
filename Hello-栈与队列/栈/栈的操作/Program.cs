namespace 栈的操作;

class Program
{
    static void Main(string[] args)
    {
        //初始化栈
        Stack<int> stack = new();

        //入栈
        stack.Push(1);
        stack.Push(3);
        stack.Push(2);
        stack.Push(5);
        stack.Push(4);

        //访问栈顶元素
        int peek = stack.Peek();
        //出栈
        int pop = stack.Pop();
        //获取栈的长度
        int size = stack.Count;
        //判断是否为空
        bool isEmpty = (stack.Count == 0);
        

    }
}
