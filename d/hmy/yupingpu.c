// /d/hmy/yupingpu.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
���������٣�����ľ����������Ա��⣬һ������Ө������ٲ���
����к��������˵���������ɶ�������ϴ�칬�������������µؽ������е�
ʥˮ��
LONG
        );
        set("exits", ([ 
	  "east" : __DIR__"lianhua",
	  "westdown" : __DIR__"baizhang",
	  "north" : __DIR__"guanpu",
]));
	set("objects", ([
                __DIR__"npc/wolf": 1,
]));

        set("outdoors", "��ľ��");

        setup();
}
 
