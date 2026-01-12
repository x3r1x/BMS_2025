<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="D_Q" />
        <signal name="T_Q" />
        <signal name="JK_Q" />
        <signal name="D" />
        <signal name="D_C" />
        <signal name="T" />
        <signal name="J" />
        <signal name="JK_C" />
        <signal name="K" />
        <port polarity="Output" name="D_Q" />
        <port polarity="Output" name="T_Q" />
        <port polarity="Output" name="JK_Q" />
        <port polarity="Input" name="D" />
        <port polarity="Input" name="D_C" />
        <port polarity="Input" name="T" />
        <port polarity="Input" name="J" />
        <port polarity="Input" name="JK_C" />
        <port polarity="Input" name="K" />
        <blockdef name="d_trigger">
            <timestamp>2026-1-11T20:0:0</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="t_trig">
            <timestamp>2026-1-11T20:9:55</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="default_jk_trigger">
            <timestamp>2026-1-11T20:23:38</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <block symbolname="d_trigger" name="XLXI_9">
            <blockpin signalname="D" name="D" />
            <blockpin signalname="D_C" name="C" />
            <blockpin signalname="D_Q" name="Q" />
        </block>
        <block symbolname="t_trig" name="XLXI_10">
            <blockpin signalname="T" name="T" />
            <blockpin signalname="T_Q" name="Q" />
        </block>
        <block symbolname="default_jk_trigger" name="XLXI_11">
            <blockpin signalname="J" name="j" />
            <blockpin signalname="JK_C" name="c" />
            <blockpin signalname="K" name="k" />
            <blockpin signalname="JK_Q" name="q" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1072" y="864" name="XLXI_9" orien="R0">
        </instance>
        <instance x="1072" y="1024" name="XLXI_10" orien="R0">
        </instance>
        <instance x="1072" y="1312" name="XLXI_11" orien="R0">
        </instance>
        <branch name="D_Q">
            <wire x2="1568" y1="768" y2="768" x1="1456" />
        </branch>
        <branch name="T_Q">
            <wire x2="1568" y1="992" y2="992" x1="1456" />
        </branch>
        <branch name="JK_Q">
            <wire x2="1568" y1="1152" y2="1152" x1="1456" />
        </branch>
        <branch name="D">
            <wire x2="1072" y1="768" y2="768" x1="960" />
        </branch>
        <branch name="D_C">
            <wire x2="1072" y1="832" y2="832" x1="960" />
        </branch>
        <branch name="T">
            <wire x2="1072" y1="992" y2="992" x1="960" />
        </branch>
        <branch name="J">
            <wire x2="1072" y1="1152" y2="1152" x1="960" />
        </branch>
        <branch name="JK_C">
            <wire x2="1072" y1="1216" y2="1216" x1="960" />
        </branch>
        <branch name="K">
            <wire x2="1072" y1="1280" y2="1280" x1="960" />
        </branch>
        <iomarker fontsize="28" x="960" y="768" name="D" orien="R180" />
        <iomarker fontsize="28" x="960" y="832" name="D_C" orien="R180" />
        <iomarker fontsize="28" x="960" y="992" name="T" orien="R180" />
        <iomarker fontsize="28" x="960" y="1152" name="J" orien="R180" />
        <iomarker fontsize="28" x="960" y="1216" name="JK_C" orien="R180" />
        <iomarker fontsize="28" x="960" y="1280" name="K" orien="R180" />
        <iomarker fontsize="28" x="1568" y="768" name="D_Q" orien="R0" />
        <iomarker fontsize="28" x="1568" y="992" name="T_Q" orien="R0" />
        <iomarker fontsize="28" x="1568" y="1152" name="JK_Q" orien="R0" />
    </sheet>
</drawing>