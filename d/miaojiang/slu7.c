// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
���ܿ����е�����Խ��Ũ������е�����������ľԽ��Խ�ߣ��𽥵�ס��
���ߡ��谵֮�У������С������ǰ�С�
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"slu8",
                "southdown" : __DIR__"slu5",
             ]));
     
        set("objects",([
//                __DIR__"npc/dushe1" : 1,

        ]));

       
        set("outdoors", "�置");

        setup();

}
