/*Դ�ļ���������:
 *1.һ��Դ�ļ���ֻ����һ��public�ࡣ
 *2.һ��Դ�ļ������ж����public�ࡣ
 *3.Դ�ļ�������Ӧ�ú�public�����������һ�¡�
 *4.���һ���ඨ����ĳ�����У���ôpackage���Ӧ����Դ�ļ������С�
 *5.���Դ�ļ�����import��䣬��ôӦ�÷���package�����ඨ��֮�䡣���û��package��䣬��ôimport���Ӧ����Դ�ļ���ǰ�档
 *  import��package����Դ�ļ��ж���������඼��Ч����ͬһԴ�ļ��в��ܸ���ͬ���಻ͬ�İ�������
 */

/*private*/ class Rectangle     //private�������������ⲿ�ֻ࣬�������ڲ���(������Ƕ�׵���)�������ⲿ��ֱ�ӱ��뱨��
{
	public double length;
	public double width;
	
	public void acceptDetail()
	{
		length = 3.5;
		width = 4.5;
	}
	
	private double getArea()
	{
		return length * width;
	}
	
	public void display()
	{
		System.out.println("length ="+length+", width ="+width+" ,area ="+getArea());
	}
	
}        //Java��C#�����β������Ҫ�ӷֺ�";"��β��

public class RectangleTest
{
	public static void main(String[] args)
	{
		Rectangle rect = new Rectangle();
		rect.acceptDetail();
		rect.display();
		
		rect.length = 10;
		rect.width = 11;
		rect.display();
	}
}