----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:04:25 01/11/2026 
-- Design Name: 
-- Module Name:    mux4b_4in - Behavioral 
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

entity mux4b_4inU is
    Port ( D0 : in  STD_LOGIC_VECTOR (3 downto 0);
           D1 : in  STD_LOGIC_VECTOR (3 downto 0);
           D2 : in  STD_LOGIC_VECTOR (3 downto 0);
           D3 : in  STD_LOGIC_VECTOR (3 downto 0);
           A : in  STD_LOGIC_VECTOR (1 downto 0);
           Q : out  STD_LOGIC_VECTOR (3 downto 0));
end mux4b_4inU;

architecture Behavioral of mux4b_4inU is
begin
	process(D0, D1, D2, D3, A)
	begin
		case(A) is
			when "00" => Q <= D0;
			when "01" => Q <= D1;
			when "10" => Q <= D2;
			when others => Q <= D3;
		end case;
	end process;
end Behavioral;

