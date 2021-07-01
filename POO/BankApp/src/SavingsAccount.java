public class SavingsAccount extends BankAccount{ // Não pode ficar negativa e tem rendimentos com uma taxa de juros definida pelo gerente
	private float rendimentos;
	public SavingsAccount(float rendimento){
		// Sem limite
		this.rendimentos = rendimento;
	}

	public SavingsAccount(String nome, int num, float real, Date opening,float rendimento){
		super(nome, num, real, opening);
		this.setRendimentos(rendimento);
	}
	
	public void setRendimentos(float real){
		this.rendimentos = real;
	}
	
	public float getRendimentos(){
		return this.rendimentos;
	}
	
	public void render(){
		float dinheiro = getSaldo();
		
		dinheiro *= this.rendimentos;
		
		deposit(dinheiro);
	}
	
	@Override
	public void Mensagens(){
		System.out.printf("\nNumero da conta: %d", getNumero_Conta());
		System.out.printf("\nNome do correntista: %s", getNome_Correntista());
		System.out.printf("\nSaldo: %.2f", getSaldo());
		System.out.printf("\nRendimentos: %.2f", getRendimentos());
		System.out.printf("\nData de crição: " + getDate());
	}
}
