library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Top_Level is
    Port ( 
        DS   : in  STD_LOGIC;
        MR   : in  STD_LOGIC;
        SH   : in  STD_LOGIC;
        CLK  : in  STD_LOGIC;
        STCP : in  STD_LOGIC;
        OE   : in  STD_LOGIC;
        Q7S  : out STD_LOGIC;
        Q    : out STD_LOGIC_VECTOR(7 downto 0)
    );
end Top_Level;

architecture Behavioral of Top_Level is
    signal cnt : integer range 0 to 1000000 := 0;
    signal slow_clk : std_logic := '0';
    
    signal sh_sync : std_logic := '0';
    signal stcp_sync : std_logic := '0';
    
    signal serial : std_logic_vector(7 downto 0) := (others => '0');
    signal parallel : std_logic_vector(7 downto 0) := (others => '0');
begin

    process(CLK)
    begin
        if (CLK'event and CLK = '1') then
            if cnt = 1000000 then
                cnt <= 0;
                slow_clk <= not slow_clk;
            else
                cnt <= cnt + 1;
            end if;
        end if;
    end process;

    process(slow_clk)
    begin
        if (slow_clk'event and slow_clk = '1') then
            sh_sync <= SH;
            stcp_sync <= STCP;
        end if;
    end process;

    process(MR, sh_sync)
    begin
        if MR = '0' then
            serial <= (others => '0');
        elsif (sh_sync'event and sh_sync = '1') then
            serial <= serial(6 downto 0) & DS;
        end if;
    end process;

    Q7S <= serial(7);

    process(stcp_sync)
    begin
        if (stcp_sync'event and stcp_sync = '1') then
            parallel <= serial;
        end if;
    end process;

    Q <= parallel when (OE = '0') else (others => 'Z');

end Behavioral;