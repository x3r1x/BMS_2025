----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:59:10 01/11/2026 
-- Design Name: 
-- Module Name:    demul - Behavioral 
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

entity demul_w_enable is
    Port ( sw : in  STD_LOGIC_VECTOR (3 downto 0);
           mode : in  STD_LOGIC_VECTOR (1 downto 0);
			  enable: in STD_LOGIC;
           Q0 : out  STD_LOGIC_VECTOR (3 downto 0);
			  Q1 : out  STD_LOGIC_VECTOR (3 downto 0);
			  Q2 : out  STD_LOGIC_VECTOR (3 downto 0);
			  Q3 : out  STD_LOGIC_VECTOR (3 downto 0));
end demul_w_enable;

architecture Behavioral of demul_w_enable is

begin
	process(sw, mode)
	begin
		if (enable = '1') then
			case(mode) is
				when "00" => Q3 <= sw;
				when "01" => Q2 <= sw;
				when "10" => Q1 <= sw;
				when others => Q0 <= sw;
			end case;
		end if;
	end process;
end Behavioral;
