--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : main.vhf
-- /___/   /\     Timestamp : 01/07/2026 16:20:56
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan6 -flat -suppress -vhdl /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab7/lab7.4/main.vhf -w /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab7/lab7.4/main.sch
--Design Name: main
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

entity main is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          F : out   std_logic);
end main;

architecture BEHAVIORAL of main is
   attribute BOX_TYPE   : string ;
   signal notA   : std_logic;
   signal notB   : std_logic;
   signal notC   : std_logic;
   signal XLXN_1 : std_logic;
   signal XLXN_2 : std_logic;
   signal XLXN_3 : std_logic;
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component AND3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND3 : component is "BLACK_BOX";
   
   component OR3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR3 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND2
      port map (I0=>B,
                I1=>A,
                O=>XLXN_1);
   
   XLXI_2 : AND3
      port map (I0=>notC,
                I1=>notB,
                I2=>A,
                O=>XLXN_2);
   
   XLXI_3 : AND3
      port map (I0=>C,
                I1=>B,
                I2=>notA,
                O=>XLXN_3);
   
   XLXI_4 : OR3
      port map (I0=>XLXN_3,
                I1=>XLXN_2,
                I2=>XLXN_1,
                O=>F);
   
   XLXI_5 : INV
      port map (I=>A,
                O=>notA);
   
   XLXI_6 : INV
      port map (I=>B,
                O=>notB);
   
   XLXI_7 : INV
      port map (I=>C,
                O=>notC);
   
end BEHAVIORAL;


