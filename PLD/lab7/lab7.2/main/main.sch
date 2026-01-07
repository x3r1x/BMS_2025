<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="btn1" />
        <signal name="btn2" />
        <signal name="btn3" />
        <signal name="btn4" />
        <signal name="sw(7:0)" />
        <signal name="sw(7)" />
        <signal name="sw(6)" />
        <signal name="sw(5)" />
        <signal name="sw(4)" />
        <signal name="sw(3)" />
        <signal name="sw(2)" />
        <signal name="sw(1)" />
        <signal name="sw(0)" />
        <signal name="led(5:0)" />
        <signal name="led(5)" />
        <signal name="led(4)" />
        <signal name="led(3)" />
        <signal name="led(2)" />
        <signal name="led(1)" />
        <signal name="led(0)" />
        <port polarity="Input" name="btn1" />
        <port polarity="Input" name="btn2" />
        <port polarity="Input" name="btn3" />
        <port polarity="Input" name="btn4" />
        <port polarity="Input" name="sw(7:0)" />
        <port polarity="Output" name="led(5:0)" />
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
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
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
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <blockdef name="xnor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
            <circle r="8" cx="220" cy="-96" />
            <line x2="256" y1="-96" y2="-96" x1="228" />
            <line x2="60" y1="-28" y2="-28" x1="60" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="btn2" name="I0" />
            <blockpin signalname="btn1" name="I1" />
            <blockpin signalname="led(5)" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_2">
            <blockpin signalname="btn4" name="I0" />
            <blockpin signalname="btn3" name="I1" />
            <blockpin signalname="led(4)" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="sw(6)" name="I0" />
            <blockpin signalname="sw(7)" name="I1" />
            <blockpin signalname="led(3)" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_4">
            <blockpin signalname="sw(4)" name="I0" />
            <blockpin signalname="sw(5)" name="I1" />
            <blockpin signalname="led(2)" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_5">
            <blockpin signalname="sw(2)" name="I0" />
            <blockpin signalname="sw(3)" name="I1" />
            <blockpin signalname="led(1)" name="O" />
        </block>
        <block symbolname="xnor2" name="XLXI_6">
            <blockpin signalname="sw(0)" name="I0" />
            <blockpin signalname="sw(1)" name="I1" />
            <blockpin signalname="led(0)" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1040" y="928" name="XLXI_1" orien="R0" />
        <instance x="1040" y="1072" name="XLXI_2" orien="R0" />
        <instance x="1040" y="1232" name="XLXI_3" orien="R0" />
        <instance x="1040" y="1392" name="XLXI_4" orien="R0" />
        <instance x="1040" y="1536" name="XLXI_5" orien="R0" />
        <instance x="1040" y="1680" name="XLXI_6" orien="R0" />
        <branch name="btn1">
            <wire x2="1040" y1="800" y2="800" x1="800" />
        </branch>
        <branch name="btn2">
            <wire x2="1040" y1="864" y2="864" x1="800" />
        </branch>
        <branch name="btn3">
            <wire x2="1040" y1="944" y2="944" x1="800" />
        </branch>
        <branch name="btn4">
            <wire x2="1040" y1="1008" y2="1008" x1="800" />
        </branch>
        <branch name="sw(7:0)">
            <wire x2="816" y1="1072" y2="1072" x1="736" />
            <wire x2="816" y1="1072" y2="1104" x1="816" />
            <wire x2="816" y1="1104" y2="1168" x1="816" />
            <wire x2="816" y1="1168" y2="1264" x1="816" />
            <wire x2="816" y1="1264" y2="1328" x1="816" />
            <wire x2="816" y1="1328" y2="1408" x1="816" />
            <wire x2="816" y1="1408" y2="1472" x1="816" />
            <wire x2="816" y1="1472" y2="1552" x1="816" />
            <wire x2="816" y1="1552" y2="1616" x1="816" />
            <wire x2="816" y1="1616" y2="1664" x1="816" />
        </branch>
        <branch name="sw(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="1104" type="branch" />
            <wire x2="944" y1="1104" y2="1104" x1="912" />
            <wire x2="960" y1="1104" y2="1104" x1="944" />
            <wire x2="1040" y1="1104" y2="1104" x1="960" />
        </branch>
        <branch name="sw(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="1168" type="branch" />
            <wire x2="944" y1="1168" y2="1168" x1="912" />
            <wire x2="960" y1="1168" y2="1168" x1="944" />
            <wire x2="1040" y1="1168" y2="1168" x1="960" />
        </branch>
        <branch name="sw(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="1264" type="branch" />
            <wire x2="944" y1="1264" y2="1264" x1="912" />
            <wire x2="960" y1="1264" y2="1264" x1="944" />
            <wire x2="1040" y1="1264" y2="1264" x1="960" />
        </branch>
        <branch name="sw(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="1328" type="branch" />
            <wire x2="944" y1="1328" y2="1328" x1="912" />
            <wire x2="960" y1="1328" y2="1328" x1="944" />
            <wire x2="1040" y1="1328" y2="1328" x1="960" />
        </branch>
        <branch name="sw(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="1408" type="branch" />
            <wire x2="944" y1="1408" y2="1408" x1="912" />
            <wire x2="960" y1="1408" y2="1408" x1="944" />
            <wire x2="1040" y1="1408" y2="1408" x1="960" />
        </branch>
        <branch name="sw(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="1472" type="branch" />
            <wire x2="944" y1="1472" y2="1472" x1="912" />
            <wire x2="960" y1="1472" y2="1472" x1="944" />
            <wire x2="1040" y1="1472" y2="1472" x1="960" />
        </branch>
        <branch name="sw(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="1552" type="branch" />
            <wire x2="944" y1="1552" y2="1552" x1="912" />
            <wire x2="960" y1="1552" y2="1552" x1="944" />
            <wire x2="1040" y1="1552" y2="1552" x1="960" />
        </branch>
        <branch name="sw(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="1616" type="branch" />
            <wire x2="944" y1="1616" y2="1616" x1="912" />
            <wire x2="960" y1="1616" y2="1616" x1="944" />
            <wire x2="1040" y1="1616" y2="1616" x1="960" />
        </branch>
        <branch name="led(5:0)">
            <wire x2="1600" y1="736" y2="736" x1="1440" />
            <wire x2="1440" y1="736" y2="832" x1="1440" />
            <wire x2="1440" y1="832" y2="976" x1="1440" />
            <wire x2="1440" y1="976" y2="1136" x1="1440" />
            <wire x2="1440" y1="1136" y2="1296" x1="1440" />
            <wire x2="1440" y1="1296" y2="1440" x1="1440" />
            <wire x2="1440" y1="1440" y2="1584" x1="1440" />
            <wire x2="1440" y1="1584" y2="1680" x1="1440" />
        </branch>
        <branch name="led(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1312" y="832" type="branch" />
            <wire x2="1312" y1="832" y2="832" x1="1296" />
            <wire x2="1344" y1="832" y2="832" x1="1312" />
        </branch>
        <branch name="led(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="976" type="branch" />
            <wire x2="1328" y1="976" y2="976" x1="1296" />
            <wire x2="1344" y1="976" y2="976" x1="1328" />
        </branch>
        <branch name="led(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="1136" type="branch" />
            <wire x2="1328" y1="1136" y2="1136" x1="1296" />
            <wire x2="1344" y1="1136" y2="1136" x1="1328" />
        </branch>
        <branch name="led(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="1296" type="branch" />
            <wire x2="1328" y1="1296" y2="1296" x1="1296" />
            <wire x2="1344" y1="1296" y2="1296" x1="1328" />
        </branch>
        <branch name="led(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="1440" type="branch" />
            <wire x2="1328" y1="1440" y2="1440" x1="1296" />
            <wire x2="1344" y1="1440" y2="1440" x1="1328" />
        </branch>
        <branch name="led(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="1584" type="branch" />
            <wire x2="1328" y1="1584" y2="1584" x1="1296" />
            <wire x2="1344" y1="1584" y2="1584" x1="1328" />
        </branch>
        <bustap x2="1344" y1="1584" y2="1584" x1="1440" />
        <bustap x2="1344" y1="1440" y2="1440" x1="1440" />
        <bustap x2="1344" y1="1296" y2="1296" x1="1440" />
        <bustap x2="1344" y1="1136" y2="1136" x1="1440" />
        <bustap x2="1344" y1="976" y2="976" x1="1440" />
        <bustap x2="1344" y1="832" y2="832" x1="1440" />
        <bustap x2="912" y1="1104" y2="1104" x1="816" />
        <bustap x2="912" y1="1168" y2="1168" x1="816" />
        <bustap x2="912" y1="1264" y2="1264" x1="816" />
        <bustap x2="912" y1="1328" y2="1328" x1="816" />
        <bustap x2="912" y1="1408" y2="1408" x1="816" />
        <bustap x2="912" y1="1472" y2="1472" x1="816" />
        <bustap x2="912" y1="1552" y2="1552" x1="816" />
        <bustap x2="912" y1="1616" y2="1616" x1="816" />
        <iomarker fontsize="28" x="736" y="1072" name="sw(7:0)" orien="R180" />
        <iomarker fontsize="28" x="800" y="1008" name="btn4" orien="R180" />
        <iomarker fontsize="28" x="800" y="944" name="btn3" orien="R180" />
        <iomarker fontsize="28" x="800" y="864" name="btn2" orien="R180" />
        <iomarker fontsize="28" x="800" y="800" name="btn1" orien="R180" />
        <iomarker fontsize="28" x="1600" y="736" name="led(5:0)" orien="R0" />
    </sheet>
</drawing>