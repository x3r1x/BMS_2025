--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : main.vhf
-- /___/   /\     Timestamp : 01/07/2026 05:35:50
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3e -flat -suppress -vhdl /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab7/lab7.1/main.vhf -w /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab7/lab7.1/main.sch
--Design Name: main
--Device: spartan3e
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
   port ( btn1 : in    std_logic; 
          btn2 : in    std_logic; 
          btn3 : in    std_logic; 
          btn4 : in    std_logic; 
          sw   : in    std_logic_vector (7 downto 0); 
          led  : out   std_logic_vector (5 downto 0));
end main;

architecture BEHAVIORAL of main is
   attribute BOX_TYPE   : string ;
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component NAND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of NAND2 : component is "BLACK_BOX";
   
   component OR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR2 : component is "BLACK_BOX";
   
   component NOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of NOR2 : component is "BLACK_BOX";
   
   component XOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XOR2 : component is "BLACK_BOX";
   
   component XNOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XNOR2 : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND2
      port map (I0=>btn2,
                I1=>btn1,
                O=>led(5));
   
   XLXI_2 : NAND2
      port map (I0=>btn4,
                I1=>btn3,
                O=>led(4));
   
   XLXI_3 : OR2
      port map (I0=>sw(6),
                I1=>sw(7),
                O=>led(3));
   
   XLXI_4 : NOR2
      port map (I0=>sw(4),
                I1=>sw(5),
                O=>led(2));
   
   XLXI_5 : XOR2
      port map (I0=>sw(2),
                I1=>sw(3),
                O=>led(1));
   
   XLXI_6 : XNOR2
      port map (I0=>sw(0),
                I1=>sw(1),
                O=>led(0));
   
end BEHAVIORAL;


