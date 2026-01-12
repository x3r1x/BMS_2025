----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:20:21 01/11/2026 
-- Design Name: 
-- Module Name:    divider - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity divider is
    Port ( C : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (1 downto 0));
end divider;

architecture Behavioral of divider is
signal sig: STD_LOGIC_VECTOR(1 downto 0):= "00";
begin
	process(c)
	variable cnt: integer := 0;
	begin
		if (C'event and C='1') then
			if cnt = 200000 then
				cnt := 0;
				sig <= sig + 1;
			else
				cnt := cnt + 1;
			end if;
		end if;
	end process;
	
	Q <= sig;
end Behavioral;

