LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

ENTITY ULA IS
	PORT( 	X, Y		:IN	STD_LOGIC_VECTOR(7 DOWNTO 0);
			S			:OUT	STD_LOGIC_VECTOR(7 DOWNTO 0));
END ULA;
	
ARCHITECTURE option OF ULA IS
BEGIN
	S <= X + Y;
END option;