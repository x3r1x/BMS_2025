<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="D0(3:0)" />
        <signal name="Q0" />
        <signal name="Q1" />
        <signal name="Q2" />
        <signal name="Q3" />
        <signal name="D0(0)" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_11" />
        <signal name="D0(1)" />
        <signal name="D0(2)" />
        <signal name="D0(3)" />
        <signal name="A0" />
        <signal name="A1" />
        <port polarity="Input" name="D0(3:0)" />
        <port polarity="Output" name="Q0" />
        <port polarity="Output" name="Q1" />
        <port polarity="Output" name="Q2" />
        <port polarity="Output" name="Q3" />
        <port polarity="Input" name="A0" />
        <port polarity="Input" name="A1" />
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
        <block symbolname="d2_4_vhd" name="XLXI_1">
            <blockpin signalname="A0" name="X0" />
            <blockpin signalname="A1" name="X1" />
            <blockpin signalname="XLXN_7" name="Y0" />
            <blockpin signalname="XLXN_8" name="Y1" />
            <blockpin signalname="XLXN_9" name="Y2" />
            <blockpin signalname="XLXN_11" name="Y3" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="XLXN_7" name="I0" />
            <blockpin signalname="D0(0)" name="I1" />
            <blockpin signalname="Q0" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_8" name="I0" />
            <blockpin signalname="D0(1)" name="I1" />
            <blockpin signalname="Q1" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="XLXN_9" name="I0" />
            <blockpin signalname="D0(2)" name="I1" />
            <blockpin signalname="Q2" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="D0(3)" name="I1" />
            <blockpin signalname="Q3" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="D0(3:0)">
            <wire x2="1360" y1="64" y2="64" x1="1216" />
            <wire x2="1360" y1="64" y2="160" x1="1360" />
            <wire x2="1360" y1="160" y2="288" x1="1360" />
            <wire x2="1360" y1="288" y2="432" x1="1360" />
            <wire x2="1360" y1="432" y2="576" x1="1360" />
            <wire x2="1360" y1="576" y2="656" x1="1360" />
        </branch>
        <instance x="1664" y="704" name="XLXI_5" orien="R0" />
        <instance x="1120" y="1184" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1680" y="416" name="XLXI_3" orien="R0" />
        <instance x="1680" y="288" name="XLXI_2" orien="R0" />
        <branch name="Q0">
            <wire x2="2032" y1="192" y2="192" x1="1936" />
        </branch>
        <branch name="Q1">
            <wire x2="2032" y1="320" y2="320" x1="1936" />
        </branch>
        <branch name="Q3">
            <wire x2="2032" y1="608" y2="608" x1="1920" />
        </branch>
        <branch name="D0(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="160" type="branch" />
            <wire x2="1424" y1="160" y2="160" x1="1408" />
            <wire x2="1456" y1="160" y2="160" x1="1424" />
            <wire x2="1680" y1="160" y2="160" x1="1456" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1552" y1="960" y2="960" x1="1504" />
            <wire x2="1552" y1="224" y2="960" x1="1552" />
            <wire x2="1680" y1="224" y2="224" x1="1552" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1584" y1="1024" y2="1024" x1="1504" />
            <wire x2="1584" y1="352" y2="1024" x1="1584" />
            <wire x2="1680" y1="352" y2="352" x1="1584" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="1616" y1="1088" y2="1088" x1="1504" />
            <wire x2="1616" y1="496" y2="1088" x1="1616" />
            <wire x2="1664" y1="496" y2="496" x1="1616" />
        </branch>
        <instance x="1664" y="560" name="XLXI_4" orien="R0" />
        <branch name="Q2">
            <wire x2="2032" y1="464" y2="464" x1="1920" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="1648" y1="1152" y2="1152" x1="1504" />
            <wire x2="1648" y1="640" y2="1152" x1="1648" />
            <wire x2="1664" y1="640" y2="640" x1="1648" />
        </branch>
        <branch name="D0(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="288" type="branch" />
            <wire x2="1424" y1="288" y2="288" x1="1408" />
            <wire x2="1456" y1="288" y2="288" x1="1424" />
            <wire x2="1680" y1="288" y2="288" x1="1456" />
        </branch>
        <branch name="D0(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="432" type="branch" />
            <wire x2="1424" y1="432" y2="432" x1="1408" />
            <wire x2="1456" y1="432" y2="432" x1="1424" />
            <wire x2="1664" y1="432" y2="432" x1="1456" />
        </branch>
        <branch name="D0(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1440" y="576" type="branch" />
            <wire x2="1440" y1="576" y2="576" x1="1408" />
            <wire x2="1456" y1="576" y2="576" x1="1440" />
            <wire x2="1664" y1="576" y2="576" x1="1456" />
        </branch>
        <branch name="A0">
            <wire x2="1120" y1="960" y2="960" x1="1040" />
        </branch>
        <branch name="A1">
            <wire x2="1120" y1="1152" y2="1152" x1="1040" />
        </branch>
        <bustap x2="1456" y1="160" y2="160" x1="1360" />
        <bustap x2="1456" y1="288" y2="288" x1="1360" />
        <bustap x2="1456" y1="432" y2="432" x1="1360" />
        <bustap x2="1456" y1="576" y2="576" x1="1360" />
        <iomarker fontsize="28" x="1216" y="64" name="D0(3:0)" orien="R180" />
        <iomarker fontsize="28" x="1040" y="960" name="A0" orien="R180" />
        <iomarker fontsize="28" x="1040" y="1152" name="A1" orien="R180" />
        <iomarker fontsize="28" x="2032" y="192" name="Q0" orien="R0" />
        <iomarker fontsize="28" x="2032" y="320" name="Q1" orien="R0" />
        <iomarker fontsize="28" x="2032" y="464" name="Q2" orien="R0" />
        <iomarker fontsize="28" x="2032" y="608" name="Q3" orien="R0" />
    </sheet>
</drawing>