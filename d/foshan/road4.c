//road4.c by Xiaoyao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ��ï�ܣ���
�����棬��λ��·Ҫʮ��С�ġ�
LONG);
        set("objects", ([
		__DIR__"npc/snake": 1,
	]));
	set("outdoors", "��ɽ");
	set("exits",([ /* sizeof() == 1 */
		"southwest" : "/d/group/entry/fsroad5",
		"southeast" : __DIR__"road3",
	]));
	setup();
}
