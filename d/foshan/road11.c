// by xiaoyao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ�������棬��λ��
·Ҫʮ��С�ġ�
LONG);
        set("objects", ([
		__DIR__"obj/shikuai": 1,
		__DIR__"npc/tufei": 1,
        ]));
        set("outdoors", "��ɽ");
        set("exits",([ /* sizeof() == 1 */
		"northeast" : "/d/group/entry/fsroad13",
		"southwest" : __DIR__"road10",
	]));
	setup();
}
