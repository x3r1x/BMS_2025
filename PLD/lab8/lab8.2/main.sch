<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="sw(3:0)" />
        <signal name="seg(6:0)" />
        <signal name="A(0)" />
        <signal name="A(1)" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="A(1:0)" />
        <signal name="XLXN_18(1:0)" />
        <signal name="AN(3:0)" />
        <signal name="AN(0)" />
        <signal name="AN(1)" />
        <signal name="AN(2)" />
        <signal name="AN(3)" />
        <port polarity="Input" name="sw(3:0)" />
        <port polarity="Output" name="seg(6:0)" />
        <port polarity="Input" name="A(1:0)" />
        <port polarity="Output" name="AN(3:0)" />
        <blockdef name="hex2seg">
            <timestamp>2026-1-11T15:1:2</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="d2_4_vhd">
            <timestamp>2026-1-7T16:6:32</timestamp>
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
        <block symbolname="hex2seg" name="XLXI_1">
            <blockpin signalname="sw(3:0)" name="D(3:0)" />
            <blockpin signalname="seg(6:0)" name="S(6:0)" />
        </block>
        <block symbolname="d2_4_vhd" name="XLXI_2">
            <blockpin signalname="A(0)" name="X0" />
            <blockpin signalname="A(1)" name="X1" />
            <blockpin signalname="XLXN_13" name="Y0" />
            <blockpin signalname="XLXN_14" name="Y1" />
            <blockpin signalname="XLXN_15" name="Y2" />
            <blockpin signalname="XLXN_16" name="Y3" />
        </block>
        <block symbolname="inv4" name="XLXI_4">
            <blockpin signalname="XLXN_16" name="I0" />
            <blockpin signalname="XLXN_15" name="I1" />
            <blockpin signalname="XLXN_14" name="I2" />
            <blockpin signalname="XLXN_13" name="I3" />
            <blockpin signalname="AN(3)" name="O0" />
            <blockpin signalname="AN(2)" name="O1" />
            <blockpin signalname="AN(1)" name="O2" />
            <blockpin signalname="AN(0)" name="O3" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1312" y="1184" name="XLXI_1" orien="R0">
        </instance>
        <branch name="sw(3:0)">
            <wire x2="1312" y1="1152" y2="1152" x1="1088" />
        </branch>
        <branch name="seg(6:0)">
            <wire x2="1952" y1="1152" y2="1152" x1="1696" />
        </branch>
        <iomarker fontsize="28" x="1088" y="1152" name="sw(3:0)" orien="R180" />
        <iomarker fontsize="28" x="1952" y="1152" name="seg(6:0)" orien="R0" />
        <instance x="1184" y="1680" name="XLXI_2" orien="R0">
        </instance>
        <branch name="A(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1136" y="1456" type="branch" />
            <wire x2="1136" y1="1456" y2="1456" x1="1120" />
            <wire x2="1184" y1="1456" y2="1456" x1="1136" />
        </branch>
        <branch name="A(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1136" y="1648" type="branch" />
            <wire x2="1136" y1="1648" y2="1648" x1="1120" />
            <wire x2="1184" y1="1648" y2="1648" x1="1136" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="1696" y1="1456" y2="1456" x1="1568" />
        </branch>
        <branch name="XLXN_14">
            <wire x2="1696" y1="1520" y2="1520" x1="1568" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="1696" y1="1584" y2="1584" x1="1568" />
        </branch>
        <branch name="XLXN_16">
            <wire x2="1696" y1="1648" y2="1648" x1="1568" />
        </branch>
        <branch name="A(1:0)">
            <wire x2="1024" y1="1824" y2="1824" x1="896" />
            <wire x2="1024" y1="1280" y2="1456" x1="1024" />
            <wire x2="1024" y1="1456" y2="1648" x1="1024" />
            <wire x2="1024" y1="1648" y2="1824" x1="1024" />
        </branch>
        <bustap x2="1120" y1="1456" y2="1456" x1="1024" />
        <bustap x2="1120" y1="1648" y2="1648" x1="1024" />
        <instance x="1696" y="1680" name="XLXI_4" orien="R0" />
        <branch name="AN(3:0)">
            <wire x2="2160" y1="1360" y2="1360" x1="2064" />
            <wire x2="2064" y1="1360" y2="1456" x1="2064" />
            <wire x2="2064" y1="1456" y2="1520" x1="2064" />
            <wire x2="2064" y1="1520" y2="1584" x1="2064" />
            <wire x2="2064" y1="1584" y2="1648" x1="2064" />
            <wire x2="2064" y1="1648" y2="1760" x1="2064" />
        </branch>
        <branch name="AN(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1952" y="1456" type="branch" />
            <wire x2="1952" y1="1456" y2="1456" x1="1920" />
            <wire x2="1968" y1="1456" y2="1456" x1="1952" />
        </branch>
        <branch name="AN(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1952" y="1520" type="branch" />
            <wire x2="1952" y1="1520" y2="1520" x1="1920" />
            <wire x2="1968" y1="1520" y2="1520" x1="1952" />
        </branch>
        <branch name="AN(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1936" y="1584" type="branch" />
            <wire x2="1936" y1="1584" y2="1584" x1="1920" />
            <wire x2="1968" y1="1584" y2="1584" x1="1936" />
        </branch>
        <branch name="AN(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1952" y="1648" type="branch" />
            <wire x2="1952" y1="1648" y2="1648" x1="1920" />
            <wire x2="1968" y1="1648" y2="1648" x1="1952" />
        </branch>
        <bustap x2="1968" y1="1456" y2="1456" x1="2064" />
        <bustap x2="1968" y1="1520" y2="1520" x1="2064" />
        <bustap x2="1968" y1="1584" y2="1584" x1="2064" />
        <bustap x2="1968" y1="1648" y2="1648" x1="2064" />
        <iomarker fontsize="28" x="896" y="1824" name="A(1:0)" orien="R180" />
        <iomarker fontsize="28" x="2160" y="1360" name="AN(3:0)" orien="R0" />
    </sheet>
</drawing>