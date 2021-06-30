-- PROJETO 003 - 06/04/2020

library ieee;
use ieee.std_logic_1164.all;

entity Exp3 is

   port
   (
      P1   			: in std_logic;
      P2  			: in std_logic;
      P3   			: in std_logic;
		P4   			: in std_logic;
      output    		: out std_logic
	
   );

end entity;

architecture rtl of Exp3 is

 
begin

	 output <= ((P4) and (P1 or P2 or P3));


end rtl;
