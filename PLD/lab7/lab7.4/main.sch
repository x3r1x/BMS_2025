<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="A" />
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="F" />
        <signal name="notA" />
        <signal name="B" />
        <signal name="notB" />
        <signal name="C" />
        <signal name="notC" />
        <port polarity="Input" name="A" />
        <port polarity="Output" name="F" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="C" />
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
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
        </blockdef>
        <blockdef name="or3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
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
        <block symbolname="inv" name="XLXI_5">
            <blockpin signalname="A" name="I" />
            <blockpin signalname="notA" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_6">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="notB" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_7">
            <blockpin signalname="C" name="I" />
            <blockpin signalname="notC" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_2">
            <blockpin signalname="notC" name="I0" />
            <blockpin signalname="notB" name="I1" />
            <blockpin signalname="A" name="I2" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_3">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="notA" name="I2" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_4">
            <blockpin signalname="XLXN_3" name="I0" />
            <blockpin signalname="XLXN_2" name="I1" />
            <blockpin signalname="XLXN_1" name="I2" />
            <blockpin signalname="F" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="A">
            <wire x2="336" y1="480" y2="480" x1="256" />
            <wire x2="336" y1="480" y2="592" x1="336" />
            <wire x2="512" y1="592" y2="592" x1="336" />
            <wire x2="336" y1="592" y2="816" x1="336" />
            <wire x2="976" y1="816" y2="816" x1="336" />
            <wire x2="336" y1="816" y2="960" x1="336" />
            <wire x2="336" y1="960" y2="1488" x1="336" />
            <wire x2="976" y1="960" y2="960" x1="336" />
        </branch>
        <instance x="512" y="624" name="XLXI_5" orien="R0" />
        <instance x="560" y="704" name="XLXI_6" orien="R0" />
        <instance x="592" y="784" name="XLXI_7" orien="R0" />
        <instance x="976" y="944" name="XLXI_1" orien="R0" />
        <instance x="976" y="1152" name="XLXI_2" orien="R0" />
        <instance x="976" y="1376" name="XLXI_3" orien="R0" />
        <instance x="1488" y="1168" name="XLXI_4" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1488" y1="848" y2="848" x1="1232" />
            <wire x2="1488" y1="848" y2="976" x1="1488" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1296" y1="1024" y2="1024" x1="1232" />
            <wire x2="1296" y1="1024" y2="1040" x1="1296" />
            <wire x2="1488" y1="1040" y2="1040" x1="1296" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="1488" y1="1248" y2="1248" x1="1232" />
            <wire x2="1488" y1="1104" y2="1248" x1="1488" />
        </branch>
        <branch name="F">
            <wire x2="1840" y1="1040" y2="1040" x1="1744" />
        </branch>
        <branch name="notA">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="592" type="branch" />
            <wire x2="832" y1="592" y2="592" x1="736" />
            <wire x2="880" y1="592" y2="592" x1="832" />
            <wire x2="880" y1="592" y2="1184" x1="880" />
            <wire x2="976" y1="1184" y2="1184" x1="880" />
        </branch>
        <branch name="B">
            <wire x2="400" y1="544" y2="544" x1="256" />
            <wire x2="400" y1="544" y2="672" x1="400" />
            <wire x2="560" y1="672" y2="672" x1="400" />
            <wire x2="400" y1="672" y2="880" x1="400" />
            <wire x2="976" y1="880" y2="880" x1="400" />
            <wire x2="400" y1="880" y2="1248" x1="400" />
            <wire x2="400" y1="1248" y2="1488" x1="400" />
            <wire x2="976" y1="1248" y2="1248" x1="400" />
        </branch>
        <branch name="notB">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="864" y="672" type="branch" />
            <wire x2="864" y1="672" y2="672" x1="784" />
            <wire x2="912" y1="672" y2="672" x1="864" />
            <wire x2="912" y1="672" y2="1024" x1="912" />
            <wire x2="976" y1="1024" y2="1024" x1="912" />
        </branch>
        <branch name="C">
            <wire x2="480" y1="640" y2="640" x1="256" />
            <wire x2="480" y1="640" y2="752" x1="480" />
            <wire x2="592" y1="752" y2="752" x1="480" />
            <wire x2="480" y1="752" y2="1312" x1="480" />
            <wire x2="480" y1="1312" y2="1488" x1="480" />
            <wire x2="976" y1="1312" y2="1312" x1="480" />
        </branch>
        <branch name="notC">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="896" y="752" type="branch" />
            <wire x2="896" y1="752" y2="752" x1="816" />
            <wire x2="944" y1="752" y2="752" x1="896" />
            <wire x2="944" y1="752" y2="1088" x1="944" />
            <wire x2="976" y1="1088" y2="1088" x1="944" />
        </branch>
        <iomarker fontsize="28" x="256" y="480" name="A" orien="R180" />
        <iomarker fontsize="28" x="256" y="544" name="B" orien="R180" />
        <iomarker fontsize="28" x="256" y="640" name="C" orien="R180" />
        <iomarker fontsize="28" x="1840" y="1040" name="F" orien="R0" />
    </sheet>
</drawing>