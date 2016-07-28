
public class Users {

	private String acctNo;
	private int balanace;
	private String pin;
	private String name;
	
	public String getAcctNo() {
		return acctNo;
	}

	public void setAcctNo(String acctNo) {
		this.acctNo = acctNo;
	}

	public int getBalanace() {
		return balanace;
	}

	public void setBalanace(int balanace) {
		this.balanace = balanace;
	}

	public String getPin() {
		return pin;
	}

	public void setPin(String pin) {
		this.pin = pin;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	
	@Override
	public String toString() {
		return "Users [acctNo=" + acctNo + ", balanace=" + balanace + ", pin=" + pin + ", name=" + name + "]";
	}

	public Users(String accno, String name, int balance, String pin) {
		// TODO Auto-generated constructor stub
		this.acctNo = accno;
		this.balanace = balance;
		this.name = name;
		this.pin = pin;
	}

}
