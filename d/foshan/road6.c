//road6.c by XiaoYao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ��ï�ܣ���
�����棬��λ��·Ҫʮ��С�ġ�
LONG);
        set("objects", ([
		__DIR__"obj/hua1": 1,
		__DIR__"npc/bee": 1,
        ]));
	set("outdoors", "��ɽ");
	set("exits",([ /* sizeof() == 1 */
		"west"  : "/d/dali/dalisouth/jiangbei",
		"east"  : "/d/group/entry/fsroad5",
        ]));
	setup();
}
