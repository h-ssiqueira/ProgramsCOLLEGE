public class BankAccount{
	private int numero_conta; // Declaração das variáveis
	private String nome_correntista, senha;
	private float saldo, limite;
	private Date openingDate;
	
	public BankAccount(){ // Construtor sem parâmetros
		//setNome_Correntista("ze");
		//setNumero_Conta(5);
		//setLimite(1000);
		this.saldo = 0;
		this.senha = "0000";
		//this.openingDate = new Date(1,9,2020);
	}
	
	public BankAccount(String nome, int num, float real, Date opening){ // Construtor com parâmetros
		setNome_Correntista(nome);
		setNumero_Conta(num);
		setLimite(real);
		this.saldo = 0;
		this.senha = "0000";
		this.openingDate = opening;
	}
	
	public void setNumero_Conta(int num){ // SET para cada variável, atribuindo o valor coletado para a variável
		this.numero_conta = num;
	}
	
	public void setNome_Correntista(String nome){
		this.nome_correntista = nome;
	}
	
	public void setLimite(float real){
		this.limite = real;
	}
	
	/*
	public void setSaldo(float real){
		saldo = real;
	}
	*/
	
	public int getNumero_Conta(){ // retorna o valor com GET
		return this.numero_conta;
	}
	
	public String getNome_Correntista(){
		return this.nome_correntista;
	}
	
	public float getSaldo(){
		return this.saldo;
	}
		
	public float getLimite(){
		return this.limite;
	}
	
	public Date getDate(){
		//return this.openingDate;
		return openingDate;
	}
	
	public void withdraw(double value){
		if(value < this.saldo || value < this.limite){
			this.saldo -= value; 
		}
	}
	
	public void deposit(double value){
		this.saldo += value;
	}
	
	public void juros(float j){
		float saldo = getSaldo();
		if(saldo < 0){
			j *= saldo;
			deposit(j); // deposita valor negativo
		}
	}
	
	public String changePassword(String oldPass, String newPass){
		if(oldPass.equals(this.senha)){
			this.senha = newPass;
			return String.format("\nSenha alterada com sucesso.");
		}
		else{
			return String.format("\nSenha incorreta!");
		}
	}
	
	public void Mensagens(){
		System.out.printf("\nNumero da conta: %d", getNumero_Conta());
		System.out.printf("\nNome do correntista: %s", getNome_Correntista());
		System.out.printf("\nSaldo: %.2f", getSaldo());
		System.out.printf("\nLimite: %.2f", getLimite());
		System.out.printf("\nData de crição: " + openingDate);
	}
}
