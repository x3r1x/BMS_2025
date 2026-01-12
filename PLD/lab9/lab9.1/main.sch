<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="q(0)" />
        <signal name="q(1)" />
        <signal name="q(1:0)" />
        <signal name="sw(3:0)" />
        <signal name="sw(3)" />
        <signal name="sw(2)" />
        <signal name="sw(1)" />
        <signal name="sw(0)" />
        <port polarity="Output" name="q(1:0)" />
        <port polarity="Input" name="sw(3:0)" />
        <blockdef name="rs_nor">
            <timestamp>2026-1-11T19:36:53</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="rs_nand">
            <timestamp>2026-1-11T19:39:11</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <block symbolname="rs_nor" name="XLXI_1">
            <blockpin signalname="sw(3)" name="R" />
            <blockpin signalname="sw(2)" name="S" />
            <blockpin signalname="q(1)" name="Q" />
        </block>
        <block symbolname="rs_nand" name="XLXI_2">
            <blockpin signalname="sw(1)" name="R" />
            <blockpin signalname="sw(0)" name="S" />
            <blockpin signalname="q(0)" name="Q" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1328" y="1312" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1328" y="1520" name="XLXI_2" orien="R0">
        </instance>
        <branch name="q(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1776" y="1424" type="branch" />
            <wire x2="1776" y1="1424" y2="1424" x1="1712" />
            <wire x2="1792" y1="1424" y2="1424" x1="1776" />
        </branch>
        <branch name="q(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1776" y="1216" type="branch" />
            <wire x2="1776" y1="1216" y2="1216" x1="1712" />
            <wire x2="1792" y1="1216" y2="1216" x1="1776" />
        </branch>
        <branch name="q(1:0)">
            <wire x2="2080" y1="1040" y2="1040" x1="1888" />
            <wire x2="1888" y1="1040" y2="1216" x1="1888" />
            <wire x2="1888" y1="1216" y2="1424" x1="1888" />
            <wire x2="1888" y1="1424" y2="1600" x1="1888" />
        </branch>
        <branch name="sw(3:0)">
            <wire x2="1184" y1="1120" y2="1120" x1="1104" />
            <wire x2="1184" y1="1120" y2="1216" x1="1184" />
            <wire x2="1184" y1="1216" y2="1280" x1="1184" />
            <wire x2="1184" y1="1280" y2="1424" x1="1184" />
            <wire x2="1184" y1="1424" y2="1488" x1="1184" />
            <wire x2="1184" y1="1488" y2="1616" x1="1184" />
        </branch>
        <branch name="sw(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1296" y="1216" type="branch" />
            <wire x2="1296" y1="1216" y2="1216" x1="1280" />
            <wire x2="1328" y1="1216" y2="1216" x1="1296" />
        </branch>
        <branch name="sw(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1296" y="1280" type="branch" />
            <wire x2="1296" y1="1280" y2="1280" x1="1280" />
            <wire x2="1328" y1="1280" y2="1280" x1="1296" />
        </branch>
        <branch name="sw(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1296" y="1424" type="branch" />
            <wire x2="1296" y1="1424" y2="1424" x1="1280" />
            <wire x2="1328" y1="1424" y2="1424" x1="1296" />
        </branch>
        <branch name="sw(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1296" y="1488" type="branch" />
            <wire x2="1296" y1="1488" y2="1488" x1="1280" />
            <wire x2="1328" y1="1488" y2="1488" x1="1296" />
        </branch>
        <bustap x2="1280" y1="1216" y2="1216" x1="1184" />
        <bustap x2="1280" y1="1280" y2="1280" x1="1184" />
        <bustap x2="1280" y1="1424" y2="1424" x1="1184" />
        <bustap x2="1280" y1="1488" y2="1488" x1="1184" />
        <bustap x2="1792" y1="1216" y2="1216" x1="1888" />
        <bustap x2="1792" y1="1424" y2="1424" x1="1888" />
        <iomarker fontsize="28" x="1104" y="1120" name="sw(3:0)" orien="R180" />
        <iomarker fontsize="28" x="2080" y="1040" name="q(1:0)" orien="R0" />
    </sheet>
</drawing>