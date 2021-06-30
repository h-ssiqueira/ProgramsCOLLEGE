LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- pagina 465 pdf
ENTITY REGS IS
	PORT( RegWrite, load, reset		:IN	STD_LOGIC; 							-- sinal do controlador e sinais de load e reset
			regA, regB, writeR			:IN	STD_LOGIC_VECTOR(1 DOWNTO 0); -- Controle dos registradores a serem usados
			data								:IN	STD_LOGIC_VECTOR(7 DOWNTO 0); -- Informações a serem escritas em um registrador
			R0, R1, R2, R3					:BUFFER STD_LOGIC_VECTOR(7 DOWNTO 0); -- Registradores
			Rdata1, Rdata2					:OUT STD_LOGIC_VECTOR(7 DOWNTO 0)); -- saída de informações dos registradores
END REGS;
	
	ARCHITECTURE options OF REGS IS
	--SIGNAL R0, R1, R2, R3				: STD_LOGIC_VECTOR(7 DOWNTO 0);
	BEGIN
	PROCESS (RegWrite, regA, regB, writeR, data, load, reset, R0, R1, R2, R3)
	BEGIN
	
		CASE RESET IS -- RESET zera todos os registradores
		
			WHEN '1' =>
				R0 <= "00000000";
				R1 <= "00000000";
				R2 <= "00000000";
				R3 <= "00000000";
				Rdata1 <= "00000000";
				Rdata2 <= "00000000";
				
			WHEN OTHERS => NULL;
			
		END CASE;
		
		CASE LOAD IS	-- Load carrega os valores de 0 a 3 em cada registrador
		
			WHEN '1' =>
				R0 <= "00000000";
				R1 <= "00000001";
				R2 <= "00000010";
				R3 <= "00000011";
				Rdata1 <= "00000000";
				Rdata2 <= "00000000";
				
			WHEN OTHERS => NULL;
			
		END CASE;
		
		cASE RegWrite IS
		
			WHEN '0' => -- Sem escrita
				CASE regA IS
				
					WHEN "00" =>
						Rdata1 <= R0; -- Lê de R0 para a saída A
						
					WHEN "01" =>
						Rdata1 <= R1; -- Lê de R1 para a saída A
						
					WHEN "10" =>
						Rdata1 <= R2; -- Lê de R2 para a saída A
						
					WHEN "11" =>
						Rdata1 <= R3; -- Lê de R3 para a saída A
						
					WHEN OTHERS => NULL;
					
				END CASE;
				
				CASE regB IS
				
					WHEN "00" =>
						Rdata2 <= R0; -- Lê de R0 para a saída B
						
					WHEN "01" =>
						Rdata2 <= R1; -- Lê de R1 para a saída B
						
					WHEN "10" =>
						Rdata2 <= R2; -- Lê de R2 para a saída B
						
					WHEN "11" =>
						Rdata2 <= R3; -- Lê de R3 para a saída B
						
					WHEN OTHERS => NULL;
					
				END CASE;
			WHEN '1' => -- Com escrita
				CASE writeR IS
				
					WHEN "00" =>
						R0 <= data; -- Escreve em R0
						Rdata1 <= "00000000";
						Rdata2 <= "00000000";
						
					WHEN "01" =>
						R1 <= data; -- Escreve em R1
						Rdata1 <= "00000000";
						Rdata2 <= "00000000";
						
					WHEN "10" =>
						R2 <= data; -- Escreve em R2
						Rdata1 <= "00000000";
						Rdata2 <= "00000000";
						
					WHEN "11" =>
						R3 <= data; -- Escreve em R3
						Rdata1 <= "00000000";
						Rdata2 <= "00000000";
						
					WHEN OTHERS => NULL;
					
				END CASE;
				
			WHEN OTHERS => NULL;
			
		END CASE;
	END PROCESS;
	END options;
				
		