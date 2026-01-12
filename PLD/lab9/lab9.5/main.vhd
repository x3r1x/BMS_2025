----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:39:20 01/12/2026 
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

entity main is
    Port ( DS : in  STD_LOGIC;
           MR : in  STD_LOGIC;
           SHCP : in  STD_LOGIC;
           STCP : in  STD_LOGIC;
           OE : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR(7 downto 0);
			  NQ : out  STD_LOGIC_VECTOR(7 downto 0));
end main;

architecture Behavioral of main is
    signal serial : std_logic_vector(7 downto 0) := "11111111";
    signal parallel : std_logic_vector(7 downto 0) := "11111111";
begin   
	process(MR,SHCP)
	begin
		if MR = '1' 
		then
        serial <= (others => '1');
		elsif SHCP'event and SHCP = '1' 
		then
        for i in 7 downto 1 
		  loop
			  serial(i) <= serial(i-1);
        end loop;
        serial(0) <= DS;
     end if;
	end process;
 
	process(STCP)
	begin
      if STCP'event and STCP = '1' then
        parallel <= serial;
      end if;
	end process;

	process(OE, parallel)
	begin
      if OE = '1' 
		then
          Q <= parallel;
		    NQ <= not parallel;
      else
          Q <= (others => 'Z');
		    NQ <= (others => 'Z');
      end if;
	end process;
end Behavioral;

