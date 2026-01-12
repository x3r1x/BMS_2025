<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Q" />
        <signal name="XLXN_3" />
        <signal name="R" />
        <signal name="S" />
        <port polarity="Output" name="Q" />
        <port polarity="Input" name="R" />
        <port polarity="Input" name="S" />
        <blockdef name="nor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
        </blockdef>
        <block symbolname="nor2" name="XLXI_1">
            <blockpin signalname="XLXN_3" name="I0" />
            <blockpin signalname="R" name="I1" />
            <blockpin signalname="Q" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_2">
            <blockpin signalname="S" name="I0" />
            <blockpin signalname="Q" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1072" y="1168" name="XLXI_1" orien="R0" />
        <instance x="1072" y="1408" name="XLXI_2" orien="R0" />
        <branch name="Q">
            <wire x2="1408" y1="1168" y2="1168" x1="992" />
            <wire x2="992" y1="1168" y2="1280" x1="992" />
            <wire x2="1072" y1="1280" y2="1280" x1="992" />
            <wire x2="1408" y1="1072" y2="1072" x1="1328" />
            <wire x2="1680" y1="1072" y2="1072" x1="1408" />
            <wire x2="1408" y1="1072" y2="1168" x1="1408" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="1024" y1="1104" y2="1232" x1="1024" />
            <wire x2="1376" y1="1232" y2="1232" x1="1024" />
            <wire x2="1376" y1="1232" y2="1312" x1="1376" />
            <wire x2="1072" y1="1104" y2="1104" x1="1024" />
            <wire x2="1376" y1="1312" y2="1312" x1="1328" />
        </branch>
        <branch name="R">
            <wire x2="1072" y1="1040" y2="1040" x1="800" />
        </branch>
        <branch name="S">
            <wire x2="1056" y1="1344" y2="1344" x1="800" />
            <wire x2="1072" y1="1344" y2="1344" x1="1056" />
        </branch>
        <iomarker fontsize="28" x="800" y="1040" name="R" orien="R180" />
        <iomarker fontsize="28" x="800" y="1344" name="S" orien="R180" />
        <iomarker fontsize="28" x="1680" y="1072" name="Q" orien="R0" />
    </sheet>
</drawing>