public class Date{
	private int day,month,year;
	private boolean leap;
	
	public Date(int da,int mo,int ye){
		if(mo < 1 || mo > 12){ // Verifica o intervalo correto do mês
			throw new IllegalArgumentException("\nMês fora do intervalo (1-12)!");
		}
		if(ye > 0){ // Verifica se o ano é positivo
			if(ye % 4 == 0 && ye % 100 == 0 && ye % 400 != 0){ // Verifica se é bissexto
				this.leap = true;
			}
			else{
				this.leap = false;
			}
		}
		else{ // Caso o ano seja negativo
			this.leap = false;
			throw new IllegalArgumentException("\nAno negativo!");
		}
		switch(mo){ // Conferência dos dias do mês
			case 1:
				if(da < 1 || da > 31){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-31)!");
				}
				break;
			case 2:
				if(this.leap && (da < 1 || da > 29)){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-29)!");
				}
				else if(!this.leap && (da < 1 || da > 28)){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-28)!");
				}
				break;
			case 3:
				if(da < 1 || da > 31){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-31)!");
				}
				break;
			case 4:
				if(da < 1 || da > 30){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-30)!");
				}
				break;
			case 5:
				if(da < 1 || da > 31){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-31)!");
				}
				break;
			case 6:
				if(da < 1 || da > 30){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-30)!");
				}
				break;
			case 7:
				if(da < 1 || da > 31){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-31)!");
				}
				break;
			case 8:
				if(da < 1 || da > 31){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-31)!");
				}
				break;
			case 9:
				if(da < 1 || da > 30){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-30)!");
				}
				break;
			case 10:
				if(da < 1 || da > 31){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-31)!");
				}
				break;
			case 11:
				if(da < 1 || da > 30){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-30)!");
				}
				break;
			case 12:
				if(da < 1 || da > 31){
					throw new IllegalArgumentException("\nDia fora do intervalo (1-31)!");
				}
				break;
		}
		this.year = ye;
		this.month = mo;
		this.day = da;
	}
	
	public String toString(){
		return String.format("%2d/%2d/%4d", day,month,year);		
	}
	
}
