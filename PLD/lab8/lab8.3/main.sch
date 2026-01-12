<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Q(0)" />
        <signal name="Q(1)" />
        <signal name="AN(3:0)" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="AN(3)" />
        <signal name="AN(2)" />
        <signal name="AN(1)" />
        <signal name="AN(0)" />
        <signal name="XLXN_18(1:0)" />
        <signal name="CLK" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="XLXN_22" />
        <signal name="XLXN_25(1:0)" />
        <signal name="XLXN_33" />
        <signal name="S(6:0)" />
        <signal name="XLXN_32(3:0)" />
        <signal name="Q(1:0)" />
        <signal name="XLXN_45(3:0)" />
        <signal name="XLXN_46(3:0)" />
        <signal name="XLXN_47(3:0)" />
        <signal name="XLXN_48(3:0)" />
        <signal name="Mode(1:0)" />
        <signal name="sw(3:0)" />
        <signal name="enable" />
        <port polarity="Output" name="AN(3:0)" />
        <port polarity="Input" name="CLK" />
        <port polarity="Output" name="S(6:0)" />
        <port polarity="Input" name="Mode(1:0)" />
        <port polarity="Input" name="sw(3:0)" />
        <port polarity="Input" name="enable" />
        <blockdef name="d2_4_vhd">
            <timestamp>2026-1-11T18:8:21</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="inv4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="160" y1="-96" y2="-96" x1="224" />
            <line x2="160" y1="-160" y2="-160" x1="224" />
            <line x2="160" y1="-224" y2="-224" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-96" y2="-96" x1="0" />
            <line x2="64" y1="-160" y2="-160" x1="0" />
            <line x2="64" y1="-224" y2="-224" x1="0" />
            <line x2="128" y1="-256" y2="-224" x1="64" />
            <line x2="64" y1="-224" y2="-192" x1="128" />
            <line x2="64" y1="-192" y2="-256" x1="64" />
            <circle r="16" cx="144" cy="-32" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="128" y1="-128" y2="-96" x1="64" />
            <line x2="64" y1="-96" y2="-64" x1="128" />
            <line x2="64" y1="-64" y2="-128" x1="64" />
            <circle r="16" cx="144" cy="-96" />
            <line x2="128" y1="-192" y2="-160" x1="64" />
            <line x2="64" y1="-160" y2="-128" x1="128" />
            <line x2="64" y1="-128" y2="-192" x1="64" />
            <circle r="16" cx="144" cy="-160" />
            <circle r="16" cx="144" cy="-224" />
        </blockdef>
        <blockdef name="divider">
            <timestamp>2026-1-11T18:24:28</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="hex2seg">
            <timestamp>2026-1-11T15:1:2</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="mux4b_4inU">
            <timestamp>2026-1-11T18:39:53</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="demul_w_enable">
            <timestamp>2026-1-11T19:10:19</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-140" height="24" />
            <line x2="0" y1="-128" y2="-128" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-236" height="24" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <rect width="64" x="320" y="-172" height="24" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="d2_4_vhd" name="XLXI_1">
            <blockpin signalname="Q(0)" name="X0" />
            <blockpin signalname="Q(1)" name="X1" />
            <blockpin signalname="XLXN_8" name="Y0" />
            <blockpin signalname="XLXN_9" name="Y1" />
            <blockpin signalname="XLXN_10" name="Y2" />
            <blockpin signalname="XLXN_11" name="Y3" />
        </block>
        <block symbolname="inv4" name="XLXI_2">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="XLXN_10" name="I1" />
            <blockpin signalname="XLXN_9" name="I2" />
            <blockpin signalname="XLXN_8" name="I3" />
            <blockpin signalname="AN(0)" name="O0" />
            <blockpin signalname="AN(1)" name="O1" />
            <blockpin signalname="AN(2)" name="O2" />
            <blockpin signalname="AN(3)" name="O3" />
        </block>
        <block symbolname="divider" name="XLXI_3">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="Q(1:0)" name="Q(1:0)" />
        </block>
        <block symbolname="mux4b_4inU" name="XLXI_7">
            <blockpin signalname="XLXN_45(3:0)" name="D0(3:0)" />
            <blockpin signalname="XLXN_46(3:0)" name="D1(3:0)" />
            <blockpin signalname="XLXN_47(3:0)" name="D2(3:0)" />
            <blockpin signalname="XLXN_48(3:0)" name="D3(3:0)" />
            <blockpin signalname="Q(1:0)" name="A(1:0)" />
            <blockpin signalname="XLXN_32(3:0)" name="Q(3:0)" />
        </block>
        <block symbolname="hex2seg" name="XLXI_4">
            <blockpin signalname="XLXN_32(3:0)" name="D(3:0)" />
            <blockpin signalname="S(6:0)" name="S(6:0)" />
        </block>
        <block symbolname="demul_w_enable" name="XLXI_12">
            <blockpin signalname="enable" name="enable" />
            <blockpin signalname="sw(3:0)" name="sw(3:0)" />
            <blockpin signalname="Mode(1:0)" name="mode(1:0)" />
            <blockpin signalname="XLXN_45(3:0)" name="Q0(3:0)" />
            <blockpin signalname="XLXN_46(3:0)" name="Q1(3:0)" />
            <blockpin signalname="XLXN_47(3:0)" name="Q2(3:0)" />
            <blockpin signalname="XLXN_48(3:0)" name="Q3(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1040" y="1632" name="XLXI_1" orien="R0">
        </instance>
        <branch name="Q(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="1408" type="branch" />
            <wire x2="976" y1="1408" y2="1408" x1="960" />
            <wire x2="1040" y1="1408" y2="1408" x1="976" />
        </branch>
        <branch name="Q(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="1600" type="branch" />
            <wire x2="976" y1="1600" y2="1600" x1="960" />
            <wire x2="1040" y1="1600" y2="1600" x1="976" />
        </branch>
        <branch name="AN(3:0)">
            <wire x2="2048" y1="1200" y2="1200" x1="1888" />
            <wire x2="1888" y1="1200" y2="1408" x1="1888" />
            <wire x2="1888" y1="1408" y2="1472" x1="1888" />
            <wire x2="1888" y1="1472" y2="1536" x1="1888" />
            <wire x2="1888" y1="1536" y2="1600" x1="1888" />
            <wire x2="1888" y1="1600" y2="1680" x1="1888" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1488" y1="1408" y2="1408" x1="1424" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="1488" y1="1472" y2="1472" x1="1424" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="1488" y1="1536" y2="1536" x1="1424" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="1488" y1="1600" y2="1600" x1="1424" />
        </branch>
        <instance x="1488" y="1632" name="XLXI_2" orien="R0" />
        <branch name="AN(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1760" y="1408" type="branch" />
            <wire x2="1760" y1="1408" y2="1408" x1="1712" />
            <wire x2="1792" y1="1408" y2="1408" x1="1760" />
        </branch>
        <branch name="AN(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1760" y="1472" type="branch" />
            <wire x2="1760" y1="1472" y2="1472" x1="1712" />
            <wire x2="1792" y1="1472" y2="1472" x1="1760" />
        </branch>
        <branch name="AN(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1760" y="1536" type="branch" />
            <wire x2="1760" y1="1536" y2="1536" x1="1712" />
            <wire x2="1792" y1="1536" y2="1536" x1="1760" />
        </branch>
        <branch name="AN(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1760" y="1600" type="branch" />
            <wire x2="1760" y1="1600" y2="1600" x1="1712" />
            <wire x2="1792" y1="1600" y2="1600" x1="1760" />
        </branch>
        <bustap x2="1792" y1="1408" y2="1408" x1="1888" />
        <bustap x2="1792" y1="1472" y2="1472" x1="1888" />
        <bustap x2="1792" y1="1536" y2="1536" x1="1888" />
        <bustap x2="1792" y1="1600" y2="1600" x1="1888" />
        <iomarker fontsize="28" x="2048" y="1200" name="AN(3:0)" orien="R0" />
        <branch name="CLK">
            <wire x2="416" y1="1216" y2="1216" x1="320" />
        </branch>
        <bustap x2="960" y1="1408" y2="1408" x1="864" />
        <bustap x2="960" y1="1600" y2="1600" x1="864" />
        <instance x="416" y="1248" name="XLXI_3" orien="R0">
        </instance>
        <iomarker fontsize="28" x="320" y="1216" name="CLK" orien="R180" />
        <branch name="Q(1:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="848" y="1216" type="branch" />
            <wire x2="848" y1="1216" y2="1216" x1="800" />
            <wire x2="864" y1="1216" y2="1216" x1="848" />
            <wire x2="864" y1="1216" y2="1408" x1="864" />
            <wire x2="864" y1="1408" y2="1600" x1="864" />
            <wire x2="864" y1="1600" y2="1680" x1="864" />
            <wire x2="912" y1="1216" y2="1216" x1="864" />
            <wire x2="912" y1="1024" y2="1216" x1="912" />
            <wire x2="960" y1="1024" y2="1024" x1="912" />
        </branch>
        <branch name="S(6:0)">
            <wire x2="2096" y1="768" y2="768" x1="1904" />
        </branch>
        <instance x="960" y="1056" name="XLXI_7" orien="R0">
        </instance>
        <instance x="1520" y="800" name="XLXI_4" orien="R0">
        </instance>
        <branch name="XLXN_32(3:0)">
            <wire x2="1520" y1="768" y2="768" x1="1344" />
        </branch>
        <iomarker fontsize="28" x="2096" y="768" name="S(6:0)" orien="R0" />
        <branch name="XLXN_45(3:0)">
            <wire x2="960" y1="768" y2="768" x1="800" />
        </branch>
        <branch name="XLXN_46(3:0)">
            <wire x2="960" y1="832" y2="832" x1="800" />
        </branch>
        <branch name="XLXN_47(3:0)">
            <wire x2="960" y1="896" y2="896" x1="800" />
        </branch>
        <branch name="XLXN_48(3:0)">
            <wire x2="960" y1="960" y2="960" x1="800" />
        </branch>
        <branch name="Mode(1:0)">
            <wire x2="416" y1="960" y2="960" x1="240" />
        </branch>
        <iomarker fontsize="28" x="240" y="960" name="Mode(1:0)" orien="R180" />
        <instance x="416" y="992" name="XLXI_12" orien="R0">
        </instance>
        <branch name="sw(3:0)">
            <wire x2="416" y1="864" y2="864" x1="240" />
        </branch>
        <branch name="enable">
            <wire x2="416" y1="768" y2="768" x1="240" />
        </branch>
        <iomarker fontsize="28" x="240" y="768" name="enable" orien="R180" />
        <iomarker fontsize="28" x="240" y="864" name="sw(3:0)" orien="R180" />
    </sheet>
</drawing>