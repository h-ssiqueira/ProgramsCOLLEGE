LIBRARY IEEE; 
USE  IEEE.STD_LOGIC_1164.ALL; 
USE  IEEE.STD_LOGIC_ARITH.ALL; 
USE  IEEE.STD_LOGIC_UNSIGNED.ALL; 

			--Inputs e outputs
ENTITY teste IS
Port( reset, clock, sensor1, sensor2, 
	  sensor3, sensor4, sensor5			: IN 	STD_LOGIC;
	  switch1, switch2, switch3			: OUT	STD_LOGIC;
			-- dirA e dirB possuem 2 bits
	dirA, dirB    						: OUT STD_LOGIC_VECTOR( 1 DOWNTO 0 ));
END teste; 

			-- maquina de estados
ARCHITECTURE a OF teste IS 

			-- Define os sinais locais
	TYPE STATE_TYPE IS ( ABout, Ain, Bin, Astop, Bstop, Aback, Bset, Bset2, STARTING );  
	SIGNAL state: STATE_TYPE;  
	SIGNAL sensor43, sensor42, sensor31, sensor52, sensor53, sensor45   : STD_LOGIC_VECTOR(1 DOWNTO 0); 
	
BEGIN
			-- Comportamento da maquina de estados
			-- Iniciando sempre no Reset ou mudanca de clock
PROCESS ( reset, clock )  	
BEGIN 
			-- Reseta o estado
	IF reset = '1' THEN    
		state <= Aback;   
	ELSIF clock'EVENT AND clock = '1' THEN 

			-- mudanca de clock
			-- Esta parte executara sempre que houver um clock positivo
			-- Sinais de tarefa geram flip-flops tipo D
			-- Conferencia de statys para determinar proximo estado
	CASE state IS 
		WHEN Aback	=>
		cASE Sensor45 IS
			WHEN "00" => state <= Aback;
			WHEN "01" => state <= Bset; 
			WHEN "10" => state <= Aback;
			WHEN "11" => state <= Bset;
			WHEN OTHERS => state <= Bset;
		END CASE; 
		
		WHEN Bset	=>
		cASE Sensor52 IS
			WHEN "00" => state <= Bset;
			WHEN "01" => state <= Bset; 
			WHEN "10" => state <= Bset;
			WHEN "11" => state <= Bset2;
			WHEN OTHERS => state <= Bset;
		END CASE; 
		
		WHEN Bset2	=>
		cASE Sensor53 IS
			WHEN "00" => state <= Bset2;
			WHEN "01" => state <= Bset2; 
			WHEN "10" => state <= Bset2;
			WHEN "11" => state <= STARTING;
			WHEN OTHERS => state <= STARTING;
		END CASE; 
		
		WHEN STARTING	=>
		cASE Sensor2 IS
			WHEN '0' => state <= STARTING;
			WHEN '1' => state <= ABout;
			WHEN OTHERS => state <= STARTING;
		END CASE; 

	
		WHEN ABout =>       
			-- checa os sensores 1 e 2
		CASE Sensor43 IS
			WHEN "00" => state <= ABout;
			WHEN "01" => state <= Bin; 
			WHEN "10" => state <= Ain;
			WHEN "11" => state <= ABout;
			-- Sempre necessario um estado inicial
			WHEN OTHERS => state <= ABout;
		END CASE; 
		
		WHEN Ain =>
		CASE Sensor31 IS
			WHEN "00" => state <= Ain;
			WHEN "01" => state <= ABout;
			WHEN "10" => state <= Bstop;
			WHEN "11" => state <= Bstop;
			WHEN OTHERS => state <= ABout;
		END CASE; 

		WHEN Bin =>
		CASE Sensor42 IS
			WHEN "00" => state <= Bin;
			WHEN "01" => state <= ABout;
			WHEN "10" => state <= Astop;
			WHEN "11" => state <= Astop;
			WHEN OTHERS => state <= ABout;
		END CASE; 
		
		WHEN Astop =>
		IF Sensor2 = '1' THEN
			state <= Ain;
		ELSE
			state <= Astop;
		END IF;
		
		WHEN Bstop =>
		IF Sensor1 = '1' THEN
			state <= Bin;
		ELSE   
			state <= Bstop;
		END IF;
	END CASE;
	END IF;
END PROCESS; 
			-- Combinar estado dos sensores
			-- "&" Combina os bits
sensor45 <= sensor4 & sensor5;
sensor53 <= sensor5 & sensor3;
sensor52 <= sensor5 & sensor2;
sensor43 <= sensor4 & sensor3;
sensor42 <= sensor4 & sensor2;
sensor31 <= sensor3 & sensor1;

			-- Outputs que dependem do estado anterior
WITH state SELECT 
	Switch1  <= '0' 		WHEN Aback,
					'1'		WHEN Bset,                    
					'1'		WHEN Bset2,                    
					'1'		WHEN STARTING,                    
					'0' 		WHEN ABout,
					'0'		WHEN Ain,
					'1'		WHEN Bin,                    
					'1'    	WHEN Astop,                    
					'0'    	WHEN Bstop; 
WITH state SELECT   
	Switch2  <=	'0' 		WHEN Aback,
					'1'		WHEN Bset,                    
					'1'		WHEN Bset2,                    
					'1'		WHEN STARTING, 	
					'0'		WHEN ABout,
					'0' 		WHEN Ain,
					'1' 		WHEN Bin,
					'1'    	WHEN Astop,                    
					'0'    	WHEN Bstop;
WITH state SELECT 
	Switch3  <= '1' 		WHEN Aback,
					'0'		WHEN Bset,                    
					'1'		WHEN Bset2,                    
					'1'		WHEN STARTING,                    
					'0' 		WHEN ABout,
					'0'		WHEN Ain,
					'0'		WHEN Bin,                    
					'0'    	WHEN Astop,                    
					'0'    	WHEN Bstop; 	
 WITH state SELECT
	DirA  	<=	"01" 	WHEN Aback,
					"00" 	WHEN Bset,
					"00" 	WHEN Bset2,
					"10"	WHEN STARTING,                 
					"10" 	WHEN ABout,
					"10" 	WHEN Ain,
					"10" 	WHEN Bin,
					"00"	WHEN Astop,                     
					"10"	WHEN Bstop; 
 WITH state SELECT   
	DirB  	<=	"00" 	WHEN Aback,
					"10" 	WHEN Bset,
					"10" 	WHEN Bset2,
					"10"	WHEN STARTING,
					"10"	WHEN ABout,
					"10" 	WHEN Ain,     
					"10" 	WHEN Bin,                    
					"10" 	WHEN Astop,                 
					"00"	WHEN Bstop; 
 END a; 