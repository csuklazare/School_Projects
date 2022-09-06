import java.util.Random;

public class Consumer extends java.lang.Thread {
	Bdbuffer buff;
	int count;
	int id;
	StringBuilder returnString = new StringBuilder();
	

	public Consumer(Bdbuffer buff, int count, int id) {
		//Assign values to the variables
		this.buff = buff;
		this.count = count;
		this.id = id;
	}
	@Override
	public void run() {
		while (count != 0) {
        	try {
        		char letter = buff.remove(id);
			returnString.append(letter);
			count--;
        	} catch(InterruptedException ie) {
        		break;
        	}
        }
	}
	public String getConsumedStr() {
		String returnValue = returnString.toString();
		return returnValue;
	}
}

