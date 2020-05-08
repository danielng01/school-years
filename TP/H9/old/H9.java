import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
class Student{
  String klas;
	String name;
	String number;
	String email;
	String belt;
	Homework[] homes;
}
class Homework{
	String number;
	String title;
	String deadLine;
	String submitDate;
	boolean inTime;
	String[] url;
}
class H9{
	public static void main(String[] args) throws Exception{
	  List<Student> ListOfStudents = new ArrayList<Student>();
		System.out.println("Homework 9");
		File file = new File("1.csv");
		BufferedReader CSVFile = new BufferedReader(new FileReader(file));
		String dataRow = CSVFile.readLine();
		dataRow = CSVFile.readLine();
		while(dataRow!=null){
			Student student = new Student();
			String[] dataArray = dataRow.split(",");
			/*for (String item:dataArray){
				student.klas=item;
			}*/
			//dataArray[1];
			if(dataArray.length>5){
				student.klas = dataArray[1];
				student.homes = new Homework[15];
				student.homes[0].submitDate=dataArray[0];
				student.number=dataArray[2];
				student.name=dataArray[3];
				student.email=dataArray[4];
			}
			ListOfStudents.add(student);
			//System.out.println();
			dataRow = CSVFile.readLine();
		}
		CSVFile.close();
		Iterator it=ListOfStudents.iterator();
		while(it.hasNext()){
			Student stud = (Student)it.next();
			System.out.println(stud.name);
		}
	}
}

