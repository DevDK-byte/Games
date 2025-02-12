import java.util.Scanner;
import java.util.Random;

class Game
{
	int comp_num; int numOfGuess = 0; 
	int UserInput;
	public Game()
	{
		Random r = new Random();
	    comp_num = r.nextInt(1,5);
	}
	public void userinput()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter any number you want = ");
		UserInput = sc.nextInt(); 
	}
	public void isCorrectNumber()
	{
		if(UserInput==comp_num)
		{
			System.out.println(" You win ");
		}
		if(UserInput>comp_num)
		{
			System.out.println(" Guessed number is bigger by " + (UserInput-comp_num));
			numOfGuess++;
		}
		if(UserInput<comp_num)
		{
			System.out.println(" Guessed number is smaller by " + (comp_num-UserInput));
			numOfGuess++;
		}
		
	}
}

public class method_overloading
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Game game = new Game();
		
		System.out.println(" ***************************************WELCOME TO MY EXCITING GAME*********************************************** ");
		
		while(game.UserInput != game.comp_num)
		{
			game.userinput();
			if(game.UserInput <1 || game.UserInput>5)
			{
				System.out.println("Invalid input !");
				continue;
				//break;
			}
			game.isCorrectNumber();
			
			System.out.println(" Guesses taken = " + game.numOfGuess);
		}
		System.out.println("Total guesses taken to win = " + game.numOfGuess);
	}
}

