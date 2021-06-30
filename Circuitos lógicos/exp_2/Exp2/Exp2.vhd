-- pROJETO 002 - 24/03/2020

library ieee;
use ieee.std_logic_1164.all;

entity Exp2 is

   port
   (
      S   			: in std_logic;
      E  			: in std_logic;
      A   			: in std_logic;
		P   			: in std_logic;
      output    		: out std_logic
	
   );

end entity;

architecture rtl of Exp2 is

 
begin

	 output <= (((not S)and (not E) and (not A) and (not P)) or (S and E));


end rtl;
