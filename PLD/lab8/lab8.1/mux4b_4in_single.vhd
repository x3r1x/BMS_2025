----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:16:55 01/11/2026 
-- Design Name: 
-- Module Name:    mux4b_4in_single - Behavioral 
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

entity mux1b_2in_single is
    Port ( D0 : in  STD_LOGIC;
           D1 : in  STD_LOGIC;
           A0 : in  STD_LOGIC;
           Q : out  STD_LOGIC);
end mux1b_2in_single;

architecture Behavioral of mux1b_2in_single is
begin
	process(D0, D1, A0)
	begin
		Q <= (not (A0) and D0) or (A0 and D1);
	end process;
end Behavioral;

