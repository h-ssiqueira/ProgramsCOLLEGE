LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- pagina 465 pdf
ENTITY REGS IS
	PORT( RegWrite, load, reset		:IN	STD_LOGIC; 							-- sinal do controlador e sinais de load e reset
			regA, writeR					:IN	STD_LOGIC_VECTOR(1 DOWNTO 0); -- Controle dos registradores a serem usados
			data								:IN	STD_LOGIC_VECTOR(7 DOWNTO 0); -- Informações a serem escritas em um registrador
			R0									:BUFFER STD_LOGIC_VECTOR(7 DOWNTO 0); -- Registradores
			Rdata1							:OUT STD_LOGIC_VECTOR(7 DOWNTO 0)); -- saída de informações dos registradores
END REGS;
	
	ARCHITECTURE options OF REGS IS
	--SIGNAL R0						: STD_LOGIC_VECTOR(7 DOWNTO 0);
	BEGIN
	PROCESS (RegWrite, regA, writeR, data, load, reset, R0)
	BEGIN
	
		CASE RESET IS -- RESET zera todos os registradores
		
			WHEN '1' =>
				R0 <= "00000000";
				Rdata1 <= "00000000";
				
			WHEN OTHERS => NULL;
			
		END CASE;
		
		CASE LOAD IS	-- Load carrega os valores de 0 a 3 em cada registrador
		
			WHEN '1' =>
				R0 <= "00000001";
				Rdata1 <= "00000000";
				
			WHEN OTHERS => NULL;
			
		END CASE;
		
		cASE RegWrite IS
		
			WHEN '0' => -- Sem escrita
				CASE regA IS
				
					WHEN "00" =>
						Rdata1 <= R0; -- Lê de R0 para a saída A
								
					WHEN OTHERS => NULL;
					
				END CASE;
			
			WHEN '1' => -- Com escrita
				CASE writeR IS
				
					WHEN "00" =>
						R0 <= data; -- Escreve em R0
						Rdata1 <= "00000000";
						
					WHEN OTHERS => NULL;
					
				END CASE;
				
			WHEN OTHERS => NULL;
			
		END CASE;
	END PROCESS;
	END options;
				
		