// /d/hmy/xiuxishi.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
�����������Ů������Ϣ�ң��Ǽ�������᷿�����ߺ��㡣�Ƕ���ĺõ�
���������м�����ʰ����������Ĵ󴲣����ž�������˯����
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
	set("exits", ([ 
	  "south" : __DIR__"changlang4",
	]));
        setup();
}


