----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    23:11:00 01/11/2026 
-- Design Name: 
-- Module Name:    default_jk_trigger - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity default_jk_trigger is
    Port ( j : in  STD_LOGIC;
           c : in  STD_LOGIC;
           k : in  STD_LOGIC;
           q : out  STD_LOGIC);
end default_jk_trigger;

architecture Behavioral of default_jk_trigger is
signal state: STD_LOGIC := '0';
begin
	q <= state;
	process(j, c, k)
	begin
		if(C'event and c = '1')
		then
			if(j = '1' and k = '1')
			then
				state <= not state;
			else
				if (j = '1')
				then
					state <= '1';
				elsif (k = '1')
				then
					state <= '0';
				end if;
			end if;
		end if;
	end process;
end Behavioral;

