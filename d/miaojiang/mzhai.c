// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���򵥵����ݣ��ݶ��ɺ�����Ҷ��ɡ����Ϸ��ż������������˷�
����Ͳ��һ���Ϻ����������ݽǵĲ��
LONG
        );

        set("exits", ([
                 "south" : __DIR__"jiedao4",
        ]));
        set("objects",([
                __DIR__"npc/laohan" : 1,

        ]));

    
//     set("outdoors", "miaojiang");

        setup();

}
