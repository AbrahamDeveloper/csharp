using System;
using System.Text;

class Program
{
    static string GenerateRandomPassword(int length, bool includeUppercase, bool includeLowercase, bool includeDigits, bool includeSpecialChars)
    {
        const string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
        const string digitChars = "0123456789";
        const string specialChars = "!@#$%^&*()";

        StringBuilder passwordBuilder = new StringBuilder();
        string allChars = "";

        if (includeUppercase)
            allChars += uppercaseChars;
        if (includeLowercase)
            allChars += lowercaseChars;
        if (includeDigits)
            allChars += digitChars;
        if (includeSpecialChars)
            allChars += specialChars;

        if (allChars.Length == 0)
        {
            Console.WriteLine("Error: No character set selected for generating the password.");
            return "";
        }

        Random random = new Random();
        for (int i = 0; i < length; i++)
        {
            int randomIndex = random.Next(0, allChars.Length);
            char randomChar = allChars[randomIndex];
            passwordBuilder.Append(randomChar);
        }

        return passwordBuilder.ToString();
    }

    static void Main()
    {
        Console.WriteLine("Welcome to the Random Password Generator!");
        Console.WriteLine("-----------------------------------------");

        Console.Write("Enter the desired length of the password: ");
        int length = int.Parse(Console.ReadLine());

        Console.Write("Include uppercase letters? (Y/N): ");
        bool includeUppercase = Console.ReadLine().ToUpper() == "Y";

        Console.Write("Include lowercase letters? (Y/N): ");
        bool includeLowercase = Console.ReadLine().ToUpper() == "Y";

        Console.Write("Include digits? (Y/N): ");
        bool includeDigits = Console.ReadLine().ToUpper() == "Y";

        Console.Write("Include special characters? (Y/N): ");
        bool includeSpecialChars = Console.ReadLine().ToUpper() == "Y";

        string generatedPassword = GenerateRandomPassword(length, includeUppercase, includeLowercase, includeDigits, includeSpecialChars);

        Console.WriteLine();
        Console.WriteLine("Generated Password: " + generatedPassword);

        Console.WriteLine();
        Console.WriteLine("Thank you for using the Random Password Generator!");
    }
}
