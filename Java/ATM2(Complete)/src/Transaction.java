

public class Transaction {

	double trans_id;
	Users ur;
	int typ;
	public double getTrans_id() {
		return trans_id;
	}

	public void setTrans_id(int trans_id) {
		this.trans_id = trans_id;
	}


	public Transaction(double d,Users usr, int type,int amount,String p) {
		// TODO Auto-generated constructor stub
		this.trans_id = d;
		this.ur = usr;
		this.typ = type;
		Bank bk =  new Bank();
		if(!usr.getPin().equals(p)){
			System.out.println("Wrong Pin!!!");
		}else if(type == 1){ //withdrawl
			bk.withdrawl(usr,amount);
		}
		else if(type == 2){// deposit
			bk.debit(usr,amount);
		}
	}
	
	public Transaction(double d,Users usr, int type,String a) {
		this.trans_id = d;
		this.ur = usr;
		this.typ = type;
		Bank bk =  new Bank();
		bk.changepin(usr, a);
	}
	

	@Override
	public String toString() {
		return "Transaction [trans_id=" + trans_id + ", ur=" + ur + ", typ=" + typ + "]";
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Users u = new Users("123", "Anoop", 1000, "999");
		
		Transaction t = new Transaction(Math.random(),u,1,100,"999");
		System.out.println(t);
		
		Transaction tt = new Transaction(Math.random(),u,2,200,"99");
		System.out.println(tt);
		
		Transaction ttt = new Transaction(Math.random(),u,2,"0000");
		System.out.println(tt);

	}

}
