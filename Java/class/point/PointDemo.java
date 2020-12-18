//һ��Java���������Ϊ��һϵ�ж���ļ��ϣ�����Щ����ͨ�����ñ˴˵ķ�����Эͬ����

/*Java������ļ�������������һ�£�(C#���ļ������Բ�ͬ���������)
 *1.����ļ���ֻ��һ���࣬�ļ�������������һ�£�
 *2.һ��Java�ļ���ֻ����һ��public�ࣻ
 *3.����ļ��в�ֹһ���࣬�ļ���������public����һ�£�
 *4.����ļ��в�ֹһ���࣬����û��public�࣬�ļ���������һ����һ�¡�
 */

//Java���Ա�е����ַ���Ȩ�ޣ�private��default��protected��public�����ǵ�Ȩ�޼���private<default<protected<public

class Point
{
	double x;          //Java��class��Ĭ��Ȩ����default�������Ա�������������ʣ�C#��C++��class��Ĭ��Ȩ����public��
	private double y;
	
	public Point(double x,double y)
	{
		this.x = x;
		this.y = y;
	}
	
	public void setX(double x)
	{
		this.x = x;
	}
	
	public double getX()
	{
		return x;
	}
	
	public void setY(double y)
	{
		this.y = y;
	}
	
	public double getY()
	{
		return y;
	}
	
	public void show()
	{
		System.out.println("("+x+","+y+")");
	}
}

//java��String������ĸ��д��C#��string������ĸСд
public class PointDemo {
	public static void main(String[] args){    //C#��Main�������Բ��ü�publicȨ�ޣ���Java��main���������publicȨ��
		Point point = new Point(4,5);
		point.show();
		
		point.x = 7;
		point.setY(8);
		System.out.println("x ="+point.getX());
		System.out.println("y ="+point.getY());
		point.show();
	}
}