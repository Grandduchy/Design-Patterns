package sandBox;

public class SandBox {
	public static void main(String[] args) {
		Beverage beverage = new Expresso();
		System.out.println(beverage.getDescription() + " $" + beverage.cost() + "\n");
		
		Beverage beverage2 = new Expresso();
		beverage2 = new Mocha(beverage2);
		beverage2 = new Soy(beverage2);
		System.out.println(beverage2.getDescription() + " $" + beverage2.cost() + "\n");
		
		Beverage beverage3 = new HouseBlend();
		beverage3 = new Soy(beverage3);
		System.out.println(beverage3.getDescription() + " $" + beverage3.cost());
	}
}

// ----------------------------
// Beverage types
// ----------------------------

class Expresso extends Beverage {
	
	public Expresso() {
		this.description = "Expresso";
	}

	@Override
	public double cost() {
		return 1.99;
	}
}

class HouseBlend extends Beverage {
	public HouseBlend() {
		this.description = "House Blend";
	}

	@Override
	public double cost() {
		
		return .89;
	}
	
}

//----------------------------
// Concrete Decorators
//----------------------------
// Important to note that the abstract Decorator type also inherits from the abstract Beverage type.
// This allows for type matching
class Mocha extends Decorator {
	Beverage beverage;
	
	public Mocha(Beverage beverage) {
		this.beverage = beverage;
	}
	
	// delegate the calls to the object being decorated
	@Override
	public String getDescription() {
		return beverage.getDescription() + ", Mocha";
	}

	@Override
	public double cost() {
		return .20 + beverage.cost(); 
	}
	
}

class Soy extends Decorator {
	Beverage beverage;
	
	public Soy(Beverage beverage) {
		this.beverage = beverage;
	}
	
	@Override
	public String getDescription() {
		return beverage.getDescription() + ", Soy";
	}

	@Override
	public double cost() {
		return .15 + beverage.cost();
	}
	
}
