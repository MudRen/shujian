// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ��Сɽ�£�·���Ի������������滨��ݣ��������󣬵�Ҳ�����
���ľ���ս��
LONG
        );

        set("exits", ([
                "eastdown" : __DIR__"slu5",
                "westdown" : __DIR__"slu2",
                "northup" : __DIR__"slu6",
                
        ]));
     
        set("objects",([
//                __DIR__"npc/dushe" : 1,

        ]));
       
        set("outdoors", "�置");

        setup();

}
