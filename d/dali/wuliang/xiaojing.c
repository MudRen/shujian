// Room: xiaojing.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG
�����ڹ��е�һ��С���ϣ�����ʮ�ֻ�Ƨ��ͷ����һЩ��֪����С������
����ȥ�����ܴ����ܲ����ʻ��̲��������֡�
LONG
        );
        set("exits", ([
            "north" : __DIR__"caodi",
            "south" : __DIR__"guzhong",
        ]));
        
        set("outdoors", "����");

        setup();
}
