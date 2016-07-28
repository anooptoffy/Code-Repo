


public class Bank implements Atm{

	public Bank() {
		// TODO Auto-generated constructor stub
	}

	

	@Override
	public void withdrawl(Users usr, int amount) {
		// TODO Auto-generated method stub
		usr.setBalanace(usr.getBalanace() - amount);
		
	}

	@Override
	public void debit(Users usr, int dp) {
		// TODO Auto-generated method stub
		usr.setBalanace(usr.getBalanace() + dp);
	}

	@Override
	public void changepin(Users usr, String p) {
		// TODO Auto-generated method stub
		usr.setPin(p);
	}

}
