<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="led(3)" />
        <signal name="led(2)" />
        <signal name="led(1)" />
        <signal name="XLXN_30" />
        <signal name="led(0)" />
        <signal name="led(3:0)" />
        <signal name="A0" />
        <signal name="A1" />
        <signal name="sw(3:0)" />
        <port polarity="Output" name="led(3:0)" />
        <port polarity="Input" name="A0" />
        <port polarity="Input" name="A1" />
        <port polarity="Input" name="sw(3:0)" />
        <blockdef name="demux_4b_1in">
            <timestamp>2026-1-11T14:26:59</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-128" y2="-128" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="demux_4b_1in" name="XLXI_9">
            <blockpin signalname="sw(3:0)" name="D0(3:0)" />
            <blockpin signalname="A0" name="A0" />
            <blockpin signalname="A1" name="A1" />
            <blockpin signalname="led(3)" name="Q0" />
            <blockpin signalname="led(2)" name="Q1" />
            <blockpin signalname="led(1)" name="Q2" />
            <blockpin signalname="led(0)" name="Q3" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1088" y="1968" name="XLXI_9" orien="R0">
        </instance>
        <branch name="led(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1536" y="1744" type="branch" />
            <wire x2="1536" y1="1744" y2="1744" x1="1472" />
            <wire x2="1552" y1="1744" y2="1744" x1="1536" />
        </branch>
        <branch name="led(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1536" y="1808" type="branch" />
            <wire x2="1536" y1="1808" y2="1808" x1="1472" />
            <wire x2="1552" y1="1808" y2="1808" x1="1536" />
        </branch>
        <branch name="led(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1536" y="1872" type="branch" />
            <wire x2="1536" y1="1872" y2="1872" x1="1472" />
            <wire x2="1552" y1="1872" y2="1872" x1="1536" />
        </branch>
        <branch name="led(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1536" y="1936" type="branch" />
            <wire x2="1536" y1="1936" y2="1936" x1="1472" />
            <wire x2="1552" y1="1936" y2="1936" x1="1536" />
        </branch>
        <branch name="led(3:0)">
            <wire x2="1712" y1="1680" y2="1680" x1="1648" />
            <wire x2="1648" y1="1680" y2="1744" x1="1648" />
            <wire x2="1648" y1="1744" y2="1808" x1="1648" />
            <wire x2="1648" y1="1808" y2="1872" x1="1648" />
            <wire x2="1648" y1="1872" y2="1936" x1="1648" />
            <wire x2="1648" y1="1936" y2="2000" x1="1648" />
        </branch>
        <branch name="A0">
            <wire x2="1088" y1="1840" y2="1840" x1="960" />
        </branch>
        <branch name="A1">
            <wire x2="1088" y1="1936" y2="1936" x1="960" />
        </branch>
        <bustap x2="1552" y1="1744" y2="1744" x1="1648" />
        <bustap x2="1552" y1="1808" y2="1808" x1="1648" />
        <bustap x2="1552" y1="1872" y2="1872" x1="1648" />
        <bustap x2="1552" y1="1936" y2="1936" x1="1648" />
        <iomarker fontsize="28" x="960" y="1840" name="A0" orien="R180" />
        <iomarker fontsize="28" x="960" y="1936" name="A1" orien="R180" />
        <iomarker fontsize="28" x="1712" y="1680" name="led(3:0)" orien="R0" />
        <branch name="sw(3:0)">
            <wire x2="1088" y1="1744" y2="1744" x1="624" />
        </branch>
        <iomarker fontsize="28" x="624" y="1744" name="sw(3:0)" orien="R180" />
    </sheet>
</drawing>