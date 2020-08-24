/* HakinCodes 2020
 * 
 * AFFINE CIPHER :-
 * 		It is one of the methods from cryptography.
 * 
 * 		Algorithm :- 
 * 			1) Input text
 * 			2) Find numeric value associated with each letter in the text as "A as 0", "B as 1",..."a as 26", ... etc.
 * 			3) Apply the encryption or decryption formula according to the given instructions.
 * 			4) Now you will get a numeric value, find its equivalent letter (described in step 2).
 * 			5) Collect all the letters and form the cipher text.
 * 			6) Display Cipher text.
 * 
 * 		The Encryption and Decryption formula's followed by the Affine Cipher are as follows :
 *
 * 			Encryption :-
 *				cipherCode = ((a * inputCode) + b) % z
 *
 *			Decrytion :-
 * 				decipherCode = ((a^-1) * (inputCode - b)) % z
 * 
 * 			Symbols :-
 * 			1) z => It is the total no. of alphabets used as a dictionary to encrypt or decrypt the text.
 * 					In this case, we are considering english language so the dictionary has "A to Z" and "a to z"
 * 
 * 			2) a => It is a multiplication factor to the input code. It should be coprime with z to work this algorithm.
 * 					In this case, we will be randomly choosing 'a' from the set of coprime no.s of z.
 * 
 * 			3) a^-1 => 	This is the a-inverse i.e. the multiplicative inverse of a with respect to z. Means
 * 						(a x a-inverse) mod z = 1.
 * 
 * 			4) b => It is a addition factor. There are no specific constraints other than 0 <= b <= z.
 */

import java.util.*;

public class AffineCipher {
	//Creating objects that will be used throughout the code. 
	List<Character> alphabets = new ArrayList<Character>();
	Random randomObject = new Random();
	int z, a, b, a_inverse;
	
	//Constructor which initiates all objects.
	public AffineCipher() {
		//Creating list of "A to Z" and "a to z".
		char alphabet;
		for(alphabet='A'; alphabet<='Z'; alphabet++) {
			alphabets.add(alphabet);
		}
		for(alphabet='a'; alphabet<='z'; alphabet++) {
			alphabets.add(alphabet);
		}
		
		//Assigning values to the various factors used in the encryption/decryption formulas. 
		z = alphabets.size();
		a = getCoprimeFactor();
		b = randomObject.nextInt(z+1);
		a_inverse = getAInverse();
	}
	
	//Function for creating a list of coprime factors of 'z' and randomly assigning one of them to 'a'.
	public int getCoprimeFactor() {
		List<Integer> coprimeFactors = new ArrayList<Integer>();
		for(int coprimeFactor=1; coprimeFactor<=z; coprimeFactor+=2) {
			if((z % coprimeFactor) !=0) {
				coprimeFactors.add(coprimeFactor);
			}
		}
		return coprimeFactors.get(randomObject.nextInt(coprimeFactors.size()));
	}
	
	//Function to find the multiplicative inverse of 'a'.
	public int getAInverse() {
		int a_inverse_temp;
		for(a_inverse_temp=2; a_inverse_temp<=z; a_inverse_temp++) {
			if((a * a_inverse_temp) % z == 1) {
				break;
			}
		}
		return a_inverse_temp;
	}
	
	//Function for applying affine cipher encryption formula
	public String encryptCipher(String input) {
		String output = "";
		for (char charInInput : input.toCharArray()) {
			int inputCode = alphabets.indexOf(charInInput); //Taking one character of text at a time and assigning its numeric value.
			int cipherCode = ((a * inputCode) + b) % z; //Applying encryption formula.
			if(cipherCode < 0) {
				cipherCode += z;
			}
			output += alphabets.get(cipherCode); //Finding the character matching with the calculated cipher code.
		}
		return output;
	}
	
	public String decryptCipher(String input) {
		String output = "";
		for(char charInInput : input.toCharArray()) {
			int inputCode = alphabets.indexOf(charInInput);
			int decipherCode = (a_inverse * (inputCode - b)) % z; //Applying decryption formula.
			if(decipherCode < 0) {
				decipherCode += z;
			}
			output += alphabets.get(decipherCode);
		}
		return output;
	}
	
	public static void main(String[] args) {
		//Creating class object so that constructor will instantiate all the constraints.
		AffineCipher affineCipher = new AffineCipher();
		Scanner scanner = new Scanner(System.in);
		
		String outputText;
		String string;
		
		do {
			System.out.println("Menu :-\n1. Encryption\n2. Decryption");
			int choice = scanner.nextInt();
			
			switch(choice) {
			
			case 1	:	//Encrypting given input text to cipher text.
						System.out.print("Enter input text :- ");
						scanner.nextLine();
						String encryptInputText = scanner.nextLine();
						encryptInputText = encryptInputText.replaceAll("\\s", ""); //Removing white spaces
						outputText = affineCipher.encryptCipher(encryptInputText); //Encrypting input text
						
						System.out.println("Input Text :- "+encryptInputText);
						System.out.println("Encrypted Text :- "+outputText);
						break;
						
			case 2	:	//Decrypting given cipher text to normal text.
						System.out.print("Enter input text :- ");
						scanner.nextLine();
						String decryptInputText = scanner.nextLine();
						decryptInputText = decryptInputText.replaceAll("\\s", ""); //Removing white spaces
						outputText = affineCipher.decryptCipher(decryptInputText); //Decrypting cipher text

						System.out.println("Input Text :- "+decryptInputText);
						System.out.println("Encrypted Text :- "+outputText);
						break;
			}
			
			System.out.println("Do you want to continue (Y/N) ? ");
			string = scanner.next();
			
		}while(string.equals("Y"));
		
		scanner.close();
	}
}
