using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Guess the Number Game");
        Console.WriteLine("---------------------");

        Random random = new Random();
        int targetNumber = random.Next(1, 101);
        int attempts = 0;

        Console.WriteLine("I'm thinking of a number between 1 and 100. Can you guess it?");

        while (true)
        {
            Console.Write("Enter your guess: ");
            int guess = int.Parse(Console.ReadLine());
            attempts++;

            if (guess == targetNumber)
            {
                Console.WriteLine("Congratulations! You guessed the number correctly in " + attempts + " attempts.");
                break;
            }
            else if (guess < targetNumber)
            {
                Console.WriteLine("Too low! Try again.");
            }
            else
            {
                Console.WriteLine("Too high! Try again.");
            }
        }

        Console.WriteLine();
        Console.WriteLine("Thank you for playing Guess the Number!");
    }
}
