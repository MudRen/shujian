// yue lao ting wai ����ͤ��

inherit ROOM;

int do_get(string);

void create()
{
        set("short", "����ͤ��");
        set("long", @LONG
����������ͤ�⣬��������Ŷ���֣������Сͤ�Ӿ�����������������
ͤ�ˡ�ÿ�춼����������˵Ǽǻ���������һЩר�Ŵ��»������Ľη�֮��
�����ڴ��������⡣
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"dongdajie1.c",
                "south" : __DIR__"yuelaoting.c",
	]));

        set("objects", ([
                __DIR__"npc/jftou.c" : 1,
                __DIR__"npc/jiaofu.c" : 1,
                __DIR__"npc/lgshou.c" : 1,
                __DIR__"npc/snshou.c" : 1,
                __DIR__"obj/jiaozi.c" : 1,
	]));
	set("incity",1);
	setup();
}
