// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�������ܵĹ�ľԽ��Խ�ߣ�����խխ��С·����һ��������ľ���г���
���ߴܳ���������һ���亹��
LONG
        );

        set("exits", ([
                "westup" : __DIR__"slu3",
                "northup" : __DIR__"slu7",
             ]));
     
        set("objects",([
                __DIR__"npc/dushe" : 1,

        ]));

       
        set("outdoors", "�置");

        setup();

}
