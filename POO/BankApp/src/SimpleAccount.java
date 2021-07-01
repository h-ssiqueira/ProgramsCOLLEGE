public class SimpleAccount extends BankAccount{ // Saldo não pode ficar negativo
	
	public SimpleAccount(){
		// Sem valor de limite
	}

	public SimpleAccount(String nome, int num, float real, Date opening){
		super(nome, num, real, opening);
		// TODO Auto-generated constructor stub
	}
	
	
	public void Mensagens(){
		System.out.printf("\nNumero da conta: %d", getNumero_Conta());
		System.out.printf("\nNome do correntista: %s", getNome_Correntista());
		System.out.printf("\nSaldo: %.2f", getSaldo());
		System.out.printf("\nData de crição: " + getDate());
	}
}
