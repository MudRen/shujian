// /d/hmy/baichi.c �����

inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
��������ڣ������Ϻ�������������������ʯ�ף�ɽ��ʮ�ֶ��͡�
LONG
        );
        set("exits", ([ 
	  "westup" : __DIR__"shijie",
	  "eastup" : __DIR__"suo",
	  "south" : __DIR__"meimao",
	  "eastdown" : __DIR__"shandao2"
]));
        set("outdoors", "��ľ��");

        setup();
}
 
