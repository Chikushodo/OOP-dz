public interface IWeapon
{
    void Use();
}

public interface IRangedWeapon : IWeapon
{
    void Reload();
}

public interface IMeleeWeapon : IWeapon
{
    void Swing();
}

public class Bow : IRangedWeapon
{
    public void Use()
    {
        Console.WriteLine("Стреляю из лука!");
    }

    public void Reload()
    {
        Console.WriteLine("Перезарядка лука.");
    }
}

public class Sword : IMeleeWeapon
{
    public void Use()
    {
        Console.WriteLine("Атакую мечом!");
    }

    public void Swing()
    {
        Console.WriteLine("Размахиваю мечом.");
    }
}

public class Crossbow : IRangedWeapon
{
    public void Use()
    {
        Console.WriteLine("Стреляю из арбалета!");
    }

    public void Reload()
    {
        Console.WriteLine("Перезарядка арбалета.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        IRangedWeapon bow = new Bow();
        bow.Use();
        bow.Reload();

        IMeleeWeapon sword = new Sword();
        sword.Use();
        sword.Swing();

        IRangedWeapon crossbow = new Crossbow();
        crossbow.Use();
        crossbow.Reload();
    }
}
