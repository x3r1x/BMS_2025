--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : rs_nand.vhf
-- /___/   /\     Timestamp : 01/11/2026 22:42:49
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan6 -flat -suppress -vhdl /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab9/lab9.1/rs_nand.vhf -w /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab9/lab9.1/rs_nand.sch
--Design Name: rs_nand
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

entity rs_nand is
   port ( R : in    std_logic; 
          S : in    std_logic; 
          Q : out   std_logic);
end rs_nand;

architecture BEHAVIORAL of rs_nand is
   attribute BOX_TYPE   : string ;
   signal XLXN_2  : std_logic;
   signal Q_DUMMY : std_logic;
   component NAND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of NAND2 : component is "BLACK_BOX";
   
begin
   Q <= Q_DUMMY;
   XLXI_1 : NAND2
      port map (I0=>XLXN_2,
                I1=>S,
                O=>Q_DUMMY);
   
   XLXI_2 : NAND2
      port map (I0=>R,
                I1=>Q_DUMMY,
                O=>XLXN_2);
   
end BEHAVIORAL;


