package sandBox;

import java.util.ArrayList;

interface Subject {
	public void registerObserver(Observer ob);
	public void removeObserver(Observer ob);
	public void notifyObservers();
}

class WeatherData implements Subject {
	private ArrayList<Observer> observers;
	private float tempature;
	private float humidity;
	private float pressure;
	
	public WeatherData() {
		observers = new ArrayList<Observer>();
	}
	
	@Override
	public void registerObserver(Observer ob) {
		observers.add(ob);
	}

	@Override
	public void removeObserver(Observer ob) {
		int index = observers.indexOf(ob);
		if (index != -1) {
			observers.remove(index);
		}
		else {
			throw new RuntimeException("Error!");
		}
	}

	@Override
	public void notifyObservers() {
		for (int i = 0; i < observers.size(); i++) {
			observers.get(i).update(tempature, humidity, pressure);
		}
	}
	
	public void measurementsChanged() { // this function gets called when weather station changes.
		notifyObservers();
	}
	
	public void setMeasurements(float temp, float hum, float press) {
		this.tempature = temp;
		this.humidity = hum;
		this.pressure = press;
		measurementsChanged();
	}
	
	
}

interface Observer {
	public void update(float temp, float humidity, float pressure);
}

interface Display {
	public void display();
}
