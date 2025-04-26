using System;

public class Address
{
    public string? Street { get; set; }
    public string? City { get; set; }
}

public class Company
{
    public string? Name { get; set; }
    public Address? Address { get; set; }
}

public class User
{
    public string? Username { get; set; }
    public Company? Company { get; set; }
}

public class Program
{
    public static void Main(string[] args)
    {
        User user1 = new User
        {
            Username = "JohnDoe",
            Company = new Company
            {
                Name = "Acme Corp",
                Address = new Address
                {
                    Street = "123 Main St",
                    City = "Anytown"
                }
            }
        };

        DisplayUserInfo(user1);
    }
    public static void DisplayUserInfo(User user)
    {
        Console.WriteLine($"Username: {user?.Username ?? "N/A"}");
        Console.WriteLine($"Company: {user?.Company?.Name ?? "N/A"}");
        Console.WriteLine($"Street: {user?.Company?.Address?.Street ?? "N/A"}");
        Console.WriteLine($"City: {user?.Company?.Address?.City ?? "N/A"}");
    }
}
