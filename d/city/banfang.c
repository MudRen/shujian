// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "�෿");
	set("long", @LONG
���������ŵİ෿�������ݸ�Ѳ���참����Ϣ�ĵط�������ǽ�Ϲ���һЩ
��������׾ߣ����ߣ��̾ߡ����׿�ǽ����һ�����������������ӣ��������
��ɭ�Ĳ�ͷ��������м�������վ���Աߣ���֪����˵��ʲô��
LONG
	);

	set("exits", ([
		"west" : __DIR__"menlang",
	]));
	set("objects", ([
        	__DIR__"npc/yayi" : 2,
	]));

	set("incity",1);
	setup();
}
