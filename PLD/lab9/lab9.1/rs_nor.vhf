--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : rs_nor.vhf
-- /___/   /\     Timestamp : 01/11/2026 22:42:49
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan6 -flat -suppress -vhdl /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab9/lab9.1/rs_nor.vhf -w /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab9/lab9.1/rs_nor.sch
--Design Name: rs_nor
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

entity rs_nor is
   port ( R : in    std_logic; 
          S : in    std_logic; 
          Q : out   std_logic);
end rs_nor;

architecture BEHAVIORAL of rs_nor is
   attribute BOX_TYPE   : string ;
   signal XLXN_3  : std_logic;
   signal Q_DUMMY : std_logic;
   component NOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of NOR2 : component is "BLACK_BOX";
   
begin
   Q <= Q_DUMMY;
   XLXI_1 : NOR2
      port map (I0=>XLXN_3,
                I1=>R,
                O=>Q_DUMMY);
   
   XLXI_2 : NOR2
      port map (I0=>S,
                I1=>Q_DUMMY,
                O=>XLXN_3);
   
end BEHAVIORAL;


