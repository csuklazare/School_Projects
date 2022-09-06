import java.lang.Exception;
import java.util.Random;
import java.time.Instant;
import java.time.Clock;
import java.time.Duration;
import java.util.Arrays;

class Invoker {
	public static void main(String[] args) {
		// check to make sure valid input was given
		if (args.length == 0) {
			System.out.println("Error: Please provide a seed!");
			System.exit(1);
		}
		// create buffer, 5-10 elements, inclusive
		int bufferSize = randomNumber(5,10);
		Bdbuffer buffer = new Bdbuffer(bufferSize);
		// create number of items to be produced, between 10-20
		int itemsProducedConsumed = randomNumber(10,20);
		// create number of producers and consumers
		int numberProducer = randomNumber(2,5);
		int numberConsumer = randomNumber(2,5);
		int idProducer = 1;
		int idConsumer = 1;
		// print statements
		System.out.println("[Invoker] Buffer Size: " + bufferSize);
		System.out.println("[Invoker] Total Items: " + itemsProducedConsumed);
		System.out.println("[Invoker] No. of Producers: " + numberProducer);
		System.out.println("[Invoker] No. of Consumers: " + numberConsumer);
		Producer[] producers = new Producer[numberProducer];
		Consumer[] consumers = new Consumer[numberConsumer];
		// initialize all producers
		for (int i = 0; i < numberProducer; i++) {
				if (i == (numberProducer - 1)) {
					producers[i] = new Producer(buffer, (itemsProducedConsumed/numberProducer) + (itemsProducedConsumed % numberProducer), idProducer, Integer.parseInt(args[0]));
					continue;
				}
				producers[i] = new Producer(buffer, itemsProducedConsumed/numberProducer, idProducer, Integer.parseInt(args[0]));
			idProducer++;
		}
		// initialize all consumers
		for (int i = 0; i < numberConsumer; i++) {

			if (i == (numberConsumer - 1)) {
				consumers[i] = new Consumer(buffer, (itemsProducedConsumed/numberConsumer) + (itemsProducedConsumed % numberConsumer), idConsumer);
				continue;
			}
			consumers[i] = new Consumer(buffer, itemsProducedConsumed/numberConsumer, idConsumer);
			idConsumer++;
		}
		//start all threads
		for (int i = 0; i < producers.length; i++) {
			producers[i].start();
		}
		for (int i = 0; i < consumers.length; i++) {
			consumers[i].start();
		}
		
		//wait for all threads to finish, while obtaining string from the methods
		StringBuilder producerFinal = new StringBuilder();
		StringBuilder consumerFinal = new StringBuilder();
		
		try {
			for (int i = 0; i < producers.length; i++) {
				producers[i].join();
				producerFinal.append(producers[i].getProducedStr());
			}
			for (int i = 0; i < consumers.length; i++) {
				consumers[i].join();
				consumerFinal.append(consumers[i].getConsumedStr());
			}
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	// sort returned strings and compare
	String temp1 = producerFinal.toString();
	String temp2 = consumerFinal.toString();
	char producer[] = temp1.toCharArray();
	Arrays.sort(producer);
	char consumer[] = temp2.toCharArray();
	Arrays.sort(consumer);
	if (Arrays.equals(producer, consumer)) {
		System.out.print("The sorted Produced and Consumed strings are the same as shown: ");
		for (int i = 0; i < producer.length; i++) {
			System.out.print(producer[i]);
		}
		System.out.println("");
	}
	else {
		System.out.println("The sorted strings do not match!");
	}

		
	}
	//Call this function from your producer or your consumer to get the time stamp to be displayed
	public static String getTime() {
		Clock offsetClock = Clock.offset(Clock.systemUTC(), Duration.ofHours(-9));
		Instant time = Instant.now(offsetClock);
		String timeString = time.toString();
		timeString = timeString.replace('T', ' ');
		timeString = timeString.replace('Z', ' ');
		return(timeString);
	}
	// helper method to return a random number between two numbers
	public static int randomNumber(int min, int max) {
		return (int)Math.floor(Math.random()*(max-min+1)+min);
	}
}

