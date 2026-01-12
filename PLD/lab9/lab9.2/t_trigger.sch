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
        <signal name="T" />
        <port polarity="Output" name="Q" />
        <port polarity="Input" name="T" />
        <blockdef name="d_trigger">
            <timestamp>2026-1-11T20:0:0</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="d_trigger" name="XLXI_1">
            <blockpin signalname="XLXN_2" name="D" />
            <blockpin signalname="T" name="C" />
            <blockpin signalname="Q" name="Q" />
        </block>
        <block symbolname="inv" name="XLXI_2">
            <blockpin signalname="Q" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1280" y="1472" name="XLXI_1" orien="R0">
        </instance>
        <branch name="Q">
            <wire x2="1680" y1="1200" y2="1200" x1="1568" />
            <wire x2="1680" y1="1200" y2="1376" x1="1680" />
            <wire x2="1856" y1="1376" y2="1376" x1="1680" />
            <wire x2="1680" y1="1376" y2="1376" x1="1664" />
        </branch>
        <instance x="1568" y="1168" name="XLXI_2" orien="R180" />
        <branch name="XLXN_2">
            <wire x2="1344" y1="1200" y2="1200" x1="1200" />
            <wire x2="1200" y1="1200" y2="1376" x1="1200" />
            <wire x2="1280" y1="1376" y2="1376" x1="1200" />
        </branch>
        <branch name="T">
            <wire x2="1280" y1="1440" y2="1440" x1="1104" />
        </branch>
        <iomarker fontsize="28" x="1104" y="1440" name="T" orien="R180" />
        <iomarker fontsize="28" x="1856" y="1376" name="Q" orien="R0" />
    </sheet>
</drawing>