----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:22:52 01/11/2026 
-- Design Name: 
-- Module Name:    cd4_2_vhd - Behavioral 
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

entity cd4_2_vhd is
    Port ( X0 : in  STD_LOGIC;
           X1 : in  STD_LOGIC;
           X2 : in  STD_LOGIC;
           X3 : in  STD_LOGIC;
           Y0 : out  STD_LOGIC;
           Y1 : out  STD_LOGIC);
end cd4_2_vhd;

architecture Behavioral of cd4_2_vhd is
signal Xbus: STD_LOGIC_VECTOR(3 downto 0);
signal Ybus: STD_LOGIC_VECTOR(1 downto 0);
begin
	Xbus <= X3 & X2 & X1 & X0;
	Y1 <= Ybus(1);
	Y0 <= Ybus(0);
	process(Xbus)
	begin
		case(Xbus) is
			when "0001" => Ybus <= "00";
			when "0010" => Ybus <= "01";
			when "0100" => Ybus <= "10";
			when "1000" => Ybus <= "11";
			when others => Ybus <= "00";
		end case;
	end process;
end Behavioral;

