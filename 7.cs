using System;

namespace pain;

public static class StringExtension
{
    public static string FullnameAndGrade(this Student student)
    {
        return $" {student.Name}, {student.Surname}, успеваемость: {student.Grade}";
    }
}
public class Student
{
    public string Name { get; set; }
    public string Surname { get; set; }

    public int Grade { get; set; }

    public Student(string name, string surname, int grade)
    {
        Name = name;
        Surname = surname;
        Grade = grade;
    }

}


class Program
{
    static void Main(string[] args)
    {
        Student student = new Student("Эдвард", "Каллен" , 5);
        string result = student.FullnameAndGrade();
        Console.WriteLine(result);
    }
}
