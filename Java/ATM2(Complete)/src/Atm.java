/**
 * 
 */

/**
 * @author anoop
 *
 */
public interface Atm {
	
	
	abstract void withdrawl(Users usr, int amount);
	abstract void debit(Users usr, int dp);
	abstract void changepin(Users usr, String p);
	
}


