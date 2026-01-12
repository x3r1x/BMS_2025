<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Q" />
        <signal name="D" />
        <signal name="XLXN_3" />
        <signal name="C" />
        <signal name="XLXN_5" />
        <signal name="XLXN_7" />
        <port polarity="Output" name="Q" />
        <port polarity="Input" name="D" />
        <port polarity="Input" name="C" />
        <blockdef name="rs_nor">
            <timestamp>2026-1-11T19:36:53</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
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
        <block symbolname="rs_nor" name="XLXI_1">
            <blockpin signalname="XLXN_7" name="R" />
            <blockpin signalname="XLXN_5" name="S" />
            <blockpin signalname="Q" name="Q" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_3" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_5">
            <blockpin signalname="D" name="I" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="2032" y="1360" name="XLXI_1" orien="R0">
        </instance>
        <branch name="Q">
            <wire x2="2528" y1="1264" y2="1264" x1="2416" />
        </branch>
        <instance x="1632" y="1296" name="XLXI_2" orien="R0" />
        <instance x="1632" y="1504" name="XLXI_3" orien="R0" />
        <branch name="D">
            <wire x2="1232" y1="1168" y2="1168" x1="1152" />
            <wire x2="1632" y1="1168" y2="1168" x1="1232" />
            <wire x2="1232" y1="1168" y2="1440" x1="1232" />
            <wire x2="1312" y1="1440" y2="1440" x1="1232" />
        </branch>
        <instance x="1312" y="1472" name="XLXI_5" orien="R0" />
        <branch name="XLXN_3">
            <wire x2="1632" y1="1440" y2="1440" x1="1536" />
        </branch>
        <branch name="C">
            <wire x2="1536" y1="1232" y2="1232" x1="1152" />
            <wire x2="1632" y1="1232" y2="1232" x1="1536" />
            <wire x2="1536" y1="1232" y2="1376" x1="1536" />
            <wire x2="1632" y1="1376" y2="1376" x1="1536" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1952" y1="1200" y2="1200" x1="1888" />
            <wire x2="1952" y1="1200" y2="1328" x1="1952" />
            <wire x2="2032" y1="1328" y2="1328" x1="1952" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1904" y1="1408" y2="1408" x1="1888" />
            <wire x2="1904" y1="1264" y2="1408" x1="1904" />
            <wire x2="2032" y1="1264" y2="1264" x1="1904" />
        </branch>
        <iomarker fontsize="28" x="1152" y="1168" name="D" orien="R180" />
        <iomarker fontsize="28" x="1152" y="1232" name="C" orien="R180" />
        <iomarker fontsize="28" x="2528" y="1264" name="Q" orien="R0" />
    </sheet>
</drawing>