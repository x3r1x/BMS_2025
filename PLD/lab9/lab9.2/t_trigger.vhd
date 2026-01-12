----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    23:08:06 01/11/2026 
-- Design Name: 
-- Module Name:    t_trigger - Behavioral 
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

entity t_trig is
    Port ( T : in  STD_LOGIC;
           Q : out  STD_LOGIC);
end t_trig;

architecture Behavioral of t_trig is
signal state: STD_LOGIC := '0';
begin
	Q <= state;
	process(T)
	begin
		if(T'event and T='1')
		then
			state <= not state;
		end if;
	end process;
end Behavioral;

