LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

ENTITY ULA IS
	PORT( 	Cin			:IN	STD_LOGIC;
			X, Y		:IN	STD_LOGIC_VECTOR(7 DOWNTO 0);
			S				:OUT	STD_LOGIC_VECTOR(7 DOWNTO 0);
			Cout, Overflow  :OUT	STD_LOGIC);
END ULA;
	
ARCHITECTURE Options OF ULA IS
	SIGNAL Sum: STD_LOGIC_VECTOR(8 DOWNTO 0);
BEGIN
	Sum <= ('0' & X) + Y + Cin;
	S <= Sum(7 DOWNTO 0);
	Cout <= Sum(8);
	Overflow <= Sum(8) XOR X(7) XOR Y(7) XOR Sum(7);
END Options;