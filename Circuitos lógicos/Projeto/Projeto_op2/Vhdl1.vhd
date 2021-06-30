-- Example State machine to control trains-- File: Tcontrol.vhd 
-- 
-- These libraries are required in all VHDL source files 
LIBRARY IEEE; 
USE  IEEE.STD_LOGIC_1164.ALL; 
USE  IEEE.STD_LOGIC_ARITH.ALL; 
USE  IEEE.STD_LOGIC_UNSIGNED.ALL; 

			-- This section defines state machine inputs and outputs
			-- No modifications should be needed in this section 
ENTITY Tcontrol IS
Port( reset, clock, sensor1, sensor2, 
	  sensor3, sensor4, sensor5			: IN 	STD_LOGIC; -- sensor5 parece que não será utilizado
	  switch1, switch2, switch3			: OUT	STD_LOGIC; -- switch3 parece que não será utilizado
			-- dirA and dirB are 2-bit logic vectors(i.e. an array of 2 bits) 
	dirA, dirB    						: OUT STD_LOGIC_VECTOR( 1 DOWNTO 0 ));
END Tcontrol; 

			-- This code describes how the state machine operates     
			-- This section will need changes for a different  state machine 
ARCHITECTURE a OF Tcontrol IS 

			-- Define local signals (i.e. non input or output signals) here 
			-- Define local signals (i.e. non input or output signals) here  
	TYPE STATE_TYPE IS ( ABout, Ain, Bin, Astop, Bstop );  
	SIGNAL state: STATE_TYPE;  
	SIGNAL sensor12, sensor13, sensor24   : STD_LOGIC_VECTOR(1 DOWNTO 0); 
	
BEGIN
			-- This section describes how the state machine behaves     
			-- this process runs once every time reset or the clock changes  
PROCESS ( reset, clock )  	
BEGIN 
			-- Reset to this state (i.e. asynchronous reset)   
	IF reset = '1' THEN    
		state <= ABout;   
	ELSIF clock'EVENT AND clock = '1' THEN 

			-- clock'EVENT means value of clock just changed
			--This section will execute once on each positive clock edge
			--Signal assignments in this section will generate D flip-flops     
			-- Case statement to determine next state 
	CASE state IS     
		WHEN ABout =>       
			-- This Case checks both sensor1 and sensor2 bits
		CASE Sensor12 IS
			-- Note: VHDL's use of double quote for bit vector versus
			-- a single quote for only one bit!
			WHEN "00" => state <= About;
			WHEN "01" => state <= Bin; 
			WHEN "10" => state <= Ain;
			WHEN "11" => state <= Ain;
			-- Default case is always required
			WHEN OTHERS => state <= ABout;
		END CASE; 
		
		WHEN Ain =>
		CASE Sensor24 IS
			WHEN "00" => state <= Ain;
			WHEN "01" => state <= ABout;
			WHEN "10" => state <= Bstop;
			WHEN "11" => state <= ABout;
			WHEN OTHERS => state <= ABout;
		END CASE; 

		WHEN Bin =>
		CASE Sensor13 IS
			WHEN "00" => state <= Bin;
			WHEN "01" => state <= ABout;
			WHEN "10" => state <= Astop;
			WHEN "11" => state <= About;
			WHEN OTHERS => state <= ABout;
		END CASE; 
		
		WHEN Astop =>
		IF Sensor3 = '1' THEN
			state <= Ain;
		ELSE
			state <= Astop;
		END IF;
		
		WHEN Bstop =>
		IF Sensor4 = '1' THEN
			state <= Bin;
		ELSE   
			state <= Bstop;
		END IF;
	END CASE;
	END IF;
END PROCESS; 
			-- combine sensor bits for case statements above
			-- "&" operator combines bits
sensor12 <= sensor1 & sensor2;
sensor13 <= sensor1 & sensor3;
sensor24 <= sensor2 & sensor4;

			-- These outputs do not depend on the state
    Switch3 <= '0'; 
			-- Outputs that depend on state, use state to select value    -- Be sure to specify every output for every state     
			-- values will not default to zero!  
WITH state SELECT 
	Switch1  <=		'0' 	WHEN ABout,
					'0'		WHEN Ain,
					'1'		WHEN Bin,                    
					'1'    	WHEN Astop,                    
					'0'    	WHEN Bstop; 
WITH state SELECT   
	Switch2  <=		'0'		WHEN ABout,
					'0' 	WHEN Ain,
					'1' 	WHEN Bin,
					'1'    	WHEN Astop,                    
					'0'    	WHEN Bstop; 
 WITH state SELECT
	DirA  	<=	 	"01" 	WHEN ABout,
					"01" 	WHEN Ain,
					"01" 	WHEN Bin,
					"00"	WHEN Astop,                     
					"01"	WHEN Bstop; 
 WITH state SELECT   
	DirB  	<=		"01"	WHEN ABout,
					"01" 	WHEN Ain,     
					"01" 	WHEN Bin,                    
					"01" 	WHEN Astop,                 
					"00"	WHEN Bstop; 
 END a; 