// /d/hmy/guanpu.c

inherit ROOM;

void create()
{
        set("short", "����ͤ");
	set("long", @LONG
�����ٲ����������ͤ�����Ǿ��õ�����ʥ�أ�վ�ڴ˴����ɽ��������٣�
�羵�İ���Ȫ���޲������۵ס�
LONG
        );
        set("exits", ([ 
	  "south" : __DIR__"yupingpu",
	  "northup" : __DIR__"moyun",
	]));
        set("objects", ([
                __DIR__"npc/youke": 1,
	]));

        set("outdoors", "��ľ��");
        setup();
}
