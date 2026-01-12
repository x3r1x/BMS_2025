----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:57:53 01/07/2026 
-- Design Name: 
-- Module Name:    d2_4_vhd - Behavioral 
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

entity d2_4_vhd is
    Port ( X0 : in  STD_LOGIC;
           X1 : in  STD_LOGIC;
           Y0 : out  STD_LOGIC;
           Y1 : out  STD_LOGIC;
           Y2 : out  STD_LOGIC;
           Y3 : out  STD_LOGIC);
end d2_4_vhd;

architecture Behavioral of d2_4_vhd is
begin
	Y0 <= not X0 and not X1;
	Y1 <= X0 and not X1;
	Y2 <= not X0 and X1;
	Y3 <= X0 and X1;
end Behavioral;

