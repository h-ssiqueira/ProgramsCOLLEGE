import java.util.Scanner;
import java.util.*;

public class BankAccountTest{
	
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		LinkedList<BankAccount> Specials = new LinkedList<BankAccount>();  
		LinkedList<SimpleAccount> Simples = new LinkedList<SimpleAccount>();
		LinkedList<SavingsAccount> Savings = new LinkedList<SavingsAccount>();
		BankAccount Special;
		SimpleAccount Simple;
		SavingsAccount Saving;
		int num,dia,mes,ano,opt,option,op,conta, i, total_contas = 0,conta_poupanca = 0,conta_simples = 0,conta_especial = 0;
		boolean found = false;
		float real,limit,rend;
		String nome,password,newpassword;
		Date data;
		//BankAccount[] specials = new BankAccount[10];
		//SimpleAccount[] simples = new SimpleAccount[10];
		//SavingsAccount[] savings = new SavingsAccount[10];  
		
		do{
			System.out.println("\nEscolha uma opção: "); // Menu inicial
			System.out.println("\n0 - Sair.");
			System.out.println("\n1 - Gerente.");
			System.out.println("\n2 - Cliente.");
			System.out.println("\n-> ");
			option = input.nextInt();
			switch(option){
			case 1:
				do{
					System.out.println("\n0 - Sair."); // Menu do gerente
					System.out.println("\n1 - Criar nova conta.");
					System.out.println("\n2 - Visualizar informações de conta.");
					System.out.println("\n3 - Incrementar rendimentos.");
					System.out.println("\n4 - Realizar cobrança de juros.");
					System.out.println("\n5 - Ver número total de contas criadas.");
					System.out.println("\n6 - Ver número total de cada tipo de conta criada.");
					System.out.println("\n-> ");
					opt = input.nextInt();
				}while(opt < 0 || opt > 6);
				switch(opt){
				case 1: // Criar nova conta
					do{
						System.out.println("\nSelecione a conta a ser criada:");
						System.out.println("\n1 - Conta simples.");
						System.out.println("\n2 - Conta especial.");
						System.out.println("\n3 - Conta poupança.");
						System.out.println("\n-> ");
						conta = input.nextInt();
					}while(conta > 3 || conta < 1);
					
					System.out.println("\nInsira o nome do correntista: ");
					nome = input.next();
					
					found = false;
					
					System.out.println("\nInsira o número da nova conta: ");
					num = input.nextInt();
					
					while(!found){ // Conferência de conta com mesmo número
						found = true;
						for(i = 0; i < conta_simples; i++){
							Simple = Simples.get(i);
							if(num == Simple.getNumero_Conta()){
								System.out.println("\nNúmero de conta existente! Insira o número da nova conta: ");
								num = input.nextInt();
								found = false;
								break;
							}
						}
						for(i = 0; i < conta_especial && !found; i++){
							Special = Specials.get(i);
							if(num == Special.getNumero_Conta()){
								System.out.println("\nNúmero de conta existente! Insira o número da nova conta: ");
								num = input.nextInt();
								found = false;
								break;
							}
						}
						for(i = 0; i < conta_poupanca && !found; i++){
							Saving = Savings.get(i);
							if(num == Saving.getNumero_Conta()){
								System.out.println("\nNúmero de conta existente! Insira o número da nova conta: ");
								num = input.nextInt();
								found = false;
								break;
							}
						}
					}
					
					System.out.println("Entre com a data de criação: ");
					System.out.println("\nDia: ");
					dia = input.nextInt();
					System.out.println("\nMês: ");
					mes = input.nextInt();
					System.out.println("\nAno: ");
					ano = input.nextInt();
					data = new Date(dia,mes,ano);
					
					switch(conta){
					case 1:
						total_contas++;
						Simples.add(new SimpleAccount(nome, num, 0, data));
						conta_simples++;
						break;
					case 2:
						total_contas++;
						System.out.println("\nInsira o limite da conta: ");
						limit = input.nextFloat();
						Specials.add(new BankAccount(nome,num,limit,data));
						conta_especial++;
						break;
					case 3:
						total_contas++;
						System.out.println("\nInsira o rendimento da conta (%): ");
						rend = input.nextFloat();
						rend /= 100;
						Savings.add(new SavingsAccount(nome,num,0,data,rend));
						conta_poupanca++;
						break;
					}
					break;
				case 2:
					System.out.println("\nInsira o número da conta: ");
					conta = input.nextInt();
					for(i = 0; i < 10;i++){
						 Special = Specials.get(i);
						 Simple = Simples.get(i);
						 Saving = Savings.get(i);
						if(Special.getNumero_Conta() == conta){
							Special.Mensagens();
							break;
						}
						else if(Simple.getNumero_Conta() == conta){
							Simple.Mensagens();
							break;
						}
						else if(Saving.getNumero_Conta() == conta){
							Saving.Mensagens();
							break;
						}
					}
					break;
				case 3:
					for(i = 0; i < conta_poupanca; i++){
						Saving = Savings.get(i);
						Saving.render();
						Savings.set(i, Saving);
					}
					break;
				case 4:
					System.out.println("\nInsira o valor de juros (%): ");
					real = input.nextFloat();
					for(i = 0; i < conta_especial; i++){
						Special = Specials.get(i);
						Special.juros(real);
						Specials.set(i, Special);
					}
					break;
				case 5:
					System.out.printf("\nForam criadas %d contas.", total_contas);
					break;
				case 6:
					System.out.printf("\nForam criadas:\n %d contas simples.\n %d contas especiais.\n %d contas poupança.", conta_simples, conta_especial, conta_poupanca);
					break;
				}
				break;
			case 2:
				do{
					System.out.println("\n0 - Sair."); // Menu do cliente
					System.out.println("\n1 - Acessar conta corrente.");
					System.out.println("\n-> ");
					opt = input.nextInt();
				}while(opt != 0 || opt != 1);
				if(opt == 1){
					found = false;
					System.out.println("\nInsira o número da conta: ");
					num = input.nextInt();
					System.out.println("\nInsira a senha: ");
					password = input.next();
					for(i = 0; i < conta_especial; i++){ // Conferência de conta e senha para contas especiais
						Special = Specials.get(i);
						if(Special.getNumero_Conta() == num){
							if(Special.changePassword(password, password) != "\nSenha alterada com sucesso."){
								System.out.println("\nSenha inválida.");
								break;
							}
							else{
								found = true;
								do{
									do{
										System.out.println("\n0 - Sair."); // Menu do cliente após a inserção da senha
										System.out.println("\n1 - Realizar saque.");
										System.out.println("\n2 - Realizar depósito.");
										System.out.println("\n3 - Visualizar informações da conta.");
										System.out.println("\n4 - Alterar senha.");
										System.out.println("\n-> ");
										op = input.nextInt();
									}while(op > 0 || op > 4);
									switch(op){
									case 1:
										System.out.println("\nInsira o valor a ser sacado: ");
										real = input.nextFloat();
										Special.withdraw(real);
										break;
									case 2:
										System.out.println("\nInsira o valor a ser depositado: ");
										real = input.nextFloat();
										Special.deposit(real);
										break;
									case 3:
										Special.Mensagens();
										break;
									case 4:
										System.out.println("Insira a nova senha: ");
										newpassword = input.next();
										Special.changePassword(password, newpassword);
										break;
									}
								}while(op != 0);
								Specials.set(i,Special);
								break;
							}
						}
					}
					for(i = 0; i < conta_simples && !found; i++){
						Simple = Simples.get(i);
						if(Simple.getNumero_Conta() == num){
							if(Simple.changePassword(password, password) != "\nSenha alterada com sucesso."){
								System.out.println("\nSenha inválida.");
								break;
							}
							else{
								found = true;
								do{
									do{
										System.out.println("\n0 - Sair."); // Menu do cliente após a inserção da senha
										System.out.println("\n1 - Realizar saque.");
										System.out.println("\n2 - Realizar depósito.");
										System.out.println("\n3 - Visualizar informações da conta.");
										System.out.println("\n4 - Alterar senha.");
										System.out.println("\n-> ");
										op = input.nextInt();
									}while(op > 0 || op > 4);
									switch(op){
									case 1:
										System.out.println("\nInsira o valor a ser sacado: ");
										real = input.nextFloat();
										Simple.withdraw(real);
										break;
									case 2:
										System.out.println("\nInsira o valor a ser depositado: ");
										real = input.nextFloat();
										Simple.deposit(real);
										break;
									case 3:
										Simple.Mensagens();
										break;
									case 4:
										System.out.println("Insira a nova senha: ");
										newpassword = input.next();
										Simple.changePassword(password, newpassword);
										break;
									}
								}while(op != 0);
								Simples.set(i, Simple);
								break;
							}
						}
					}
					for(i = 0; i < conta_poupanca && !found; i++){
						Saving = Savings.get(i);
						if(Saving.getNumero_Conta() == num){
							if(Saving.changePassword(password, password) != "\nSenha alterada com sucesso."){
								System.out.println("\nSenha inválida.");
								break;
							}
							else{
								found = true;
								do{
									do{
										System.out.println("\n0 - Sair."); // Menu do cliente após a inserção da senha
										System.out.println("\n1 - Realizar saque.");
										System.out.println("\n2 - Realizar depósito.");
										System.out.println("\n3 - Visualizar informações da conta.");
										System.out.println("\n4 - Alterar senha.");
										System.out.println("\n-> ");
										op = input.nextInt();
									}while(op > 0 || op > 4);
									switch(op){
									case 1:
										System.out.println("\nInsira o valor a ser sacado: ");
										real = input.nextFloat();
										Saving.withdraw(real);
										break;
									case 2:
										System.out.println("\nInsira o valor a ser depositado: ");
										real = input.nextFloat();
										Saving.deposit(real);
										break;
									case 3:
										Saving.Mensagens();
										break;
									case 4:
										System.out.println("Insira a nova senha: ");
										newpassword = input.next();
										Saving.changePassword(password, newpassword);
										break;
									}
								}while(op != 0);
								Savings.set(i, Saving);
								break;
							}
						}
					}	
				}
				break;
			}
			
		}while(option < 0 || option > 2);
		
		/*
		while(option != 0){
			System.out.println("\nEscolha uma opção: ");
			System.out.println("\n1 - Criar conta automaticamente.");
			System.out.println("\n2 - Criar conta.");
			System.out.println("\n3 - Exibir informações das contas.");
			System.out.println("\n4 - Acessar conta.");
			System.out.println("\n-> ");
			option = input.nextInt();
			switch(option){
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					System.out.println("\n4 - Trocar senha.");
					System.out.println("\n5 - Efetuar depósito.");
					System.out.println("\n6 - Efetuar saque.");
					break;
			}
			
		}
		*/
		
		
		
		/*bank[0] = new BankAccount();
		
		System.out.println("Entre com o numero da conta: ");
		num = input.nextInt();
		bank[0].setNumero_Conta(num);
		System.out.println();
		
		System.out.println("Entre com o nome do correntista: ");
		nome = input.next();
		bank[0].setNome_Correntista(nome);
		System.out.println();
		
		
		System.out.println("Entre com o saldo da conta: ");
		real = input.nextFloat();
		bank1.setSaldo(real);
		System.out.println();
		
		
		System.out.println("Entre com o limite da conta: ");
		real = input.nextFloat();
		bank[0].setLimite(real);
		System.out.println();
		
		//#########################################################
		
		bank[1] = new BankAccount();
				
		System.out.println("Entre com o numero da conta: ");
		num = input.nextInt();
		//bank2.setNumero_Conta(num);
		System.out.println();
		
		System.out.println("Entre com o nome do correntista: ");
		nome = input.next();
		//bank2.setNome_Correntista(nome);
		System.out.println();
		
		
		System.out.println("Entre com o saldo da conta: ");
		real = input.nextFloat();
		bank2.setSaldo(real);
		System.out.println();
		
		
		System.out.println("Entre com o limite da conta: ");
		real = input.nextFloat();
		//bank2.setLimite(real);
		System.out.println();
		
		System.out.println("Entre com a data de criação: ");
		System.out.println("\nDia: ");
		dia = input.nextInt();
		System.out.println("\nMês: ");
		mes = input.nextInt();
		System.out.println("\nAno: ");
		ano = input.nextInt();
		data = new Date(dia,mes,ano);
		
		bank[1] = new BankAccount(nome,num,real,data);
		
		
		System.out.println("Entre com o numero da conta: ");
		num = input.nextInt();
		bank[2].setNumero_Conta(num);
		System.out.println();
		
		System.out.println("Entre com o nome do correntista: ");
		nome = input.next();
		bank[2].setNome_Correntista(nome);
		System.out.println();
		
		
		
		System.out.println("Entre com o saldo da conta: ");
		real = input.nextFloat();
		bank[2].setSaldo(real);
		System.out.println();
		
		
		
		System.out.println("Entre com o limite da conta: ");
		real = input.nextFloat();
		bank[2].setLimite(real);
		System.out.println();
		
		
		//BankAccount	bank3 = new BankAccount("ze",1010,(float) 500.00);
		bank[2] = new BankAccount();
		
		for(int i = 0; i < 3; i++){
			bank[i].Mensagens();
			System.out.printf("\n");
		}
		*/
	}
}
