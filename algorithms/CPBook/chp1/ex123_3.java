import java.util.Calendar;
import java.util.GregorianCalendar;
class ex123_3
{
	public static void main(String [] args)
	{
		String names[]={"","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
		Calendar date = new GregorianCalendar(2016,5,6);
		System.out.println(names[date.get(Calendar.DAY_OF_WEEK)]);
	}
}