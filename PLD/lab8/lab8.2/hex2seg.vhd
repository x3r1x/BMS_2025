----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:52:36 01/11/2026 
-- Design Name: 
-- Module Name:    hex2seg - Behavioral 
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

entity hex2seg is
    Port ( D : in  STD_LOGIC_VECTOR (3 downto 0);
           S : out  STD_LOGIC_VECTOR (6 downto 0));
end hex2seg;

architecture Behavioral of hex2seg is
begin
	process(D)
	begin
		case(D) is
			when "0000" => S <= "0000001";
			when "0001" => S <= "1001111";
			when "0010" => S <= "0010010";
			when "0011" => S <= "0000110";
			when "0100" => S <= "1001100";
			when "0101" => S <= "0100100";
			when "0110" => S <= "0100000";
			when "0111" => S <= "0001111";
			when "1000" => S <= "0000000";
			when "1001" => S <= "0000100"; --9
			when "1010" => S <= "0001000";
			when "1011" => S <= "1100000";
			when "1100" => S <= "0110001";
			when "1101" => S <= "1000010";
			when "1110" => S <= "0110000";
			when "1111" => S <= "0111000"; --15
			when others => S <= "0000001"; 
		end case;
	end process;
end Behavioral;

