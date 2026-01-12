--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : main_sch.vhf
-- /___/   /\     Timestamp : 01/11/2026 17:43:39
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan6 -flat -suppress -vhdl /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab8/lab8.1/main_sch.vhf -w /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab8/lab8.1/main_sch.sch
--Design Name: main_sch
--Device: spartan6
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity demux_4b_1in_MUSER_main_sch is
   port ( A0 : in    std_logic; 
          A1 : in    std_logic; 
          D0 : in    std_logic_vector (3 downto 0); 
          Q0 : out   std_logic; 
          Q1 : out   std_logic; 
          Q2 : out   std_logic; 
          Q3 : out   std_logic);
end demux_4b_1in_MUSER_main_sch;

architecture BEHAVIORAL of demux_4b_1in_MUSER_main_sch is
   attribute BOX_TYPE   : string ;
   signal XLXN_7  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_9  : std_logic;
   signal XLXN_11 : std_logic;
   component d2_4_vhd
      port ( X0 : in    std_logic; 
             X1 : in    std_logic; 
             Y0 : out   std_logic; 
             Y1 : out   std_logic; 
             Y2 : out   std_logic; 
             Y3 : out   std_logic);
   end component;
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
begin
   XLXI_1 : d2_4_vhd
      port map (X0=>A0,
                X1=>A1,
                Y0=>XLXN_7,
                Y1=>XLXN_8,
                Y2=>XLXN_9,
                Y3=>XLXN_11);
   
   XLXI_2 : AND2
      port map (I0=>XLXN_7,
                I1=>D0(0),
                O=>Q0);
   
   XLXI_3 : AND2
      port map (I0=>XLXN_8,
                I1=>D0(1),
                O=>Q1);
   
   XLXI_4 : AND2
      port map (I0=>XLXN_9,
                I1=>D0(2),
                O=>Q2);
   
   XLXI_5 : AND2
      port map (I0=>XLXN_11,
                I1=>D0(3),
                O=>Q3);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity main_sch is
   port ( A0  : in    std_logic; 
          A1  : in    std_logic; 
          sw  : in    std_logic_vector (3 downto 0); 
          led : out   std_logic_vector (3 downto 0));
end main_sch;

architecture BEHAVIORAL of main_sch is
   component demux_4b_1in_MUSER_main_sch
      port ( D0 : in    std_logic_vector (3 downto 0); 
             A0 : in    std_logic; 
             A1 : in    std_logic; 
             Q0 : out   std_logic; 
             Q1 : out   std_logic; 
             Q2 : out   std_logic; 
             Q3 : out   std_logic);
   end component;
   
begin
   XLXI_9 : demux_4b_1in_MUSER_main_sch
      port map (A0=>A0,
                A1=>A1,
                D0(3 downto 0)=>sw(3 downto 0),
                Q0=>led(3),
                Q1=>led(2),
                Q2=>led(1),
                Q3=>led(0));
   
end BEHAVIORAL;


