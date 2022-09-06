public class Bdbuffer {

	int maxSize;
	char[] array;
	int start, end, currentSize;
	public Bdbuffer(int size) {
		maxSize = size;
		start = 0;
		end = -1;
		currentSize = 0;
		array = new char[maxSize];
	}
	
	public synchronized void insert(char c, int id) throws InterruptedException {
		while (isFull()) {
			wait();
		}
		end = (end + 1) % maxSize;
		System.out.println("\033[0;4mProducer " + id + " inserted " + c + " at index " + end + " at time\033[0;0m " + Invoker.getTime());
		array[end] = c;
		currentSize++;
		notifyAll();
	}
	
	public synchronized char remove(int id) throws InterruptedException {
		char returnChar;
		while (isEmpty()) {
			wait();
		}
		returnChar = array[start];
		System.out.println("Consumer " + id + " consumed " + returnChar + " at index " + start + " at time " + Invoker.getTime());
		start = (start+1)%maxSize;
		currentSize--;
		notifyAll();
		return returnChar;
	}
	public boolean isFull() {
		if (currentSize == maxSize) {
			return true;
		}
		return false;
	}
	public boolean isEmpty() {
		if (currentSize == 0) {
			return true;
		}
		return false;
	}
}

