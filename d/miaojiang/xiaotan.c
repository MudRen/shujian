// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "С̯");
        set("long", @LONG
��������˸���ˮ���������С�ԡ�һ��������Ů���ں��棬���Ϸ�������
��Ц�ݡ�
LONG
        );

        set("exits", ([
               
                 "west" : __DIR__"jiedao2", 
        ]));
        set("objects",([
                __DIR__"npc/girl" : 1,

        ]));

        set("no_clean_up", 0);
        set("outdoors", "�置");

        setup();

}
