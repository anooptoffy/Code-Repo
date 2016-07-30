
public class Car {

	private int type;
	private String Name;
	public Car(int type,String name) {
		// TODO Auto-generated constructor stub
		this.setType(type);
		this.setName(name);
	}
	public String getName() {
		return Name;
	}
	public void setName(String name) {
		Name = name;
	}
	public int getType() {
		return type;
	}
	public void setType(int type) {
		this.type = type;
	}
	@Override
	public String toString() {
		return "Car [type=" + type + ", Name=" + Name + "]";
	}

}
