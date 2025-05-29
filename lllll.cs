public class BankAccount
{

    private readonly string _accountNumber; 
    private string _owner;                  
    private decimal _balance;               

    public BankAccount(string accountNumber, string owner)
    {
        _accountNumber = accountNumber;
        _owner = owner;
        _balance = 0; 
    }

    public string AccountNumber
    {
        get { return _accountNumber; }
    }

    public string Owner
    {
        get { return _owner; }
        set { _owner = value; }
    }

    public decimal Balance
    {
        get { return _balance; }
    }

    public void Deposit(decimal amount)
    {
        if (amount <= 0)
        {
            throw new ArgumentException("Сумма депозита должна быть положительной.");
        }
        _balance += amount;
    }

    public void Withdraw(decimal amount)
    {
        if (amount <= 0)
        {
            throw new ArgumentException("Сумма снятия должна быть положительной.");
        }
        if (amount > _balance)
        {
            throw new InvalidOperationException("Недостаточно средств для снятия.");
        }
        _balance -= amount;
    }
}

class Program
{
    static void Main(string[] args)
    {

        BankAccount account = new BankAccount("123456789", "Эдвард Каллен");


        account.Deposit(1000);
        Console.WriteLine($"Баланс после депозита: {account.Balance}");


        account.Withdraw(500);
        Console.WriteLine($"Баланс после снятия: {account.Balance}");


        try
        {
            account.Withdraw(600);
        }
        catch (InvalidOperationException ex)
        {
            Console.WriteLine(ex.Message);
        }
        account.Owner = "Эдвард Каллен";
        Console.WriteLine($"Новый владелец: {account.Owner}");
    }
}

