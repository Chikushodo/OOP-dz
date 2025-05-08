using System;
namespace pain
{   
    class Student
    {
        public string name;
        public string surname;
        public int age;

        public void PrintInfo()
        {
            Console.WriteLine($"имя студента {name} фамилия студента {surname} возраст студента {age}");
        }
    }
    enum Grade
    {
        bad = 2,
        satisfactory,
        good,
        excellent
    }
    class Program
    {
        static void Main(string[] args)
        {
            Student student1 = new Student();
            student1.name = "Эдвард";
            student1.surname = "Каллен";
            student1.age = 17;
            student1.PrintInfo();
            Console.WriteLine("Выьерите какую оценку поставить: 2 - плохо, 3 - удовлетворительно, 4 - хорошо, 5 - отлично");
            Grade grade = (Grade)Convert.ToInt32(Console.ReadLine());

            switch (grade)
            {
                case Grade.bad:
                    Console.WriteLine("оценка плохо");
                    break;
                case Grade.satisfactory:
                    Console.WriteLine("оценка удовлетворительно");
                    break;
                case Grade.good:
                    Console.WriteLine("оценка хорошо");
                    break;
                case Grade.excellent:
                    Console.WriteLine("оценка отлично");
                    break;
            }
        
        }
    }
}
