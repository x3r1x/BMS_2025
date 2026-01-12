<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Q" />
        <signal name="XLXN_2" />
        <signal name="R" />
        <signal name="S" />
        <port polarity="Output" name="Q" />
        <port polarity="Input" name="R" />
        <port polarity="Input" name="S" />
        <blockdef name="nand2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
        </blockdef>
        <block symbolname="nand2" name="XLXI_1">
            <blockpin signalname="XLXN_2" name="I0" />
            <blockpin signalname="S" name="I1" />
            <blockpin signalname="Q" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_2">
            <blockpin signalname="R" name="I0" />
            <blockpin signalname="Q" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1456" y="1424" name="XLXI_1" orien="R0" />
        <instance x="1456" y="1632" name="XLXI_2" orien="R0" />
        <branch name="Q">
            <wire x2="1760" y1="1408" y2="1408" x1="1376" />
            <wire x2="1376" y1="1408" y2="1504" x1="1376" />
            <wire x2="1456" y1="1504" y2="1504" x1="1376" />
            <wire x2="1760" y1="1328" y2="1328" x1="1712" />
            <wire x2="2016" y1="1328" y2="1328" x1="1760" />
            <wire x2="1760" y1="1328" y2="1408" x1="1760" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1408" y1="1360" y2="1456" x1="1408" />
            <wire x2="1760" y1="1456" y2="1456" x1="1408" />
            <wire x2="1760" y1="1456" y2="1536" x1="1760" />
            <wire x2="1456" y1="1360" y2="1360" x1="1408" />
            <wire x2="1760" y1="1536" y2="1536" x1="1712" />
        </branch>
        <branch name="R">
            <wire x2="1456" y1="1568" y2="1568" x1="1296" />
        </branch>
        <branch name="S">
            <wire x2="1456" y1="1296" y2="1296" x1="1296" />
        </branch>
        <iomarker fontsize="28" x="1296" y="1296" name="S" orien="R180" />
        <iomarker fontsize="28" x="1296" y="1568" name="R" orien="R180" />
        <iomarker fontsize="28" x="2016" y="1328" name="Q" orien="R0" />
    </sheet>
</drawing>