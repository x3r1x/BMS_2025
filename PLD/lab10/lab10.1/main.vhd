----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:58:30 01/12/2026 
-- Design Name: 
-- Module Name:    main - Behavioral 
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

entity main is
    Port ( T : in  STD_LOGIC;
           CE : in  STD_LOGIC;
           DIR : in  STD_LOGIC;
           R : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (7 downto 0));
end main;

architecture Behavioral of main is
signal count: STD_LOGIC_VECTOR(7 downto 0) := "00000000";
begin
	process(T)
	begin
		if T='0' and T'event
		then
			if R='1'
			then
				count <= (others => '0');
			elsif CE='1'
			then
				if DIR='0'
				then
					count <= count + 1;
				else
					count <= count - 1;
				end if;
			end if;
		end if;
	end process;
	
	Q <= count;
end Behavioral;

