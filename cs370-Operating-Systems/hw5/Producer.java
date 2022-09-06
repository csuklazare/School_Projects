import java.util.Random;

public class Producer extends java.lang.Thread {
	//Necessary variables and object declaration
	Random randomWithSeed;
	Bdbuffer buff;
	int count;
	int id;
	StringBuilder returnString = new StringBuilder();

	public Producer(Bdbuffer buff, int count, int id, int seed) {
		//Assign values to the variables
		randomWithSeed = new Random(seed);
		this.buff = buff;
		this.count = count;
		this.id = id;
	}

	@Override
	public void run() {
        while (count != 0) {
        	try {
        		char letter = (char)(this.randomWithSeed.nextInt(26) + 'a');
        		buff.insert(letter, id);
        		returnString.append(letter);
			count--;
        	} catch(InterruptedException ie) {
        		break;
        	}
        }

	}
	public String getProducedStr() {
		String returnValue = returnString.toString();
		return returnValue;
	}
	
}

