library IEEE;
use IEEE.STD_LOGIC_1164.ALL;  
use IEEE.NUMERIC_STD.ALL;
entity divider is
    Port ( 
        C : in  STD_LOGIC;
        Q : out STD_LOGIC_VECTOR (1 downto 0)
    ); 
end divider;

architecture Behavioral of divider is
    signal sig : unsigned(1 downto 0) := "00";
    signal cnt : integer range 0 to 200000 := 0;  
begin

process(C)
begin
    if rising_edge(C) then
        if cnt = 200000 then
            cnt <= 0;
            sig <= sig + 1;
        else
            cnt <= cnt + 1;
        end if;
    end if;     
end process;

    Q <= std_logic_vector(sig);
    
end Behavioral;